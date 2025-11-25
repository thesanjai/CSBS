%% 2D Line Plot
x = 0:pi/100:2*pi;
y1 = sin(x); y2 = sin(x-0.25); y3 = sin(x-0.5);
figure; plot(x,y1,x,y2,'--',x,y3,':'); title('Line Plot'); grid on;

%% Scatter Plot
theta = linspace(0,1,500);
x = exp(theta).*sin(100*theta);
y = exp(theta).*cos(100*theta);
figure; scatter(x,y); title('Scatter Plot'); grid on;

%% Bubble Chart using inbuilt 'patients' dataset
load patients; % built-in MATLAB dataset
tbl = table(Systolic,Diastolic,Age,Weight); % use existing columns
figure; bubblechart(tbl,'Systolic','Diastolic','Age','Weight');
title('Bubble Chart');

%% Histogram
X = randn(1000,1);
figure; histogram(X); title('Histogram'); grid on;

%% Box Chart
Y = magic(10);
figure; boxchart(Y); xlabel('Column'); ylabel('Value'); title('Box Chart');

%% Pie Chart
employees = [100 10 50 30 25 10 15];
departments = ["Engineering" "Sales" "User Experience" "Documentation" "IT" "HR" "Security"];
figure; piechart(employees,departments,LabelStyle="name"); title('Pie Chart');

%% Word Cloud using sample text
text_data = "MATLAB is a high-level language and interactive environment for numerical computation, visualization, and programming. MATLAB enables you to analyze data, develop algorithms, and create models and applications.";
words = split(text_data);
C = categorical(words);
figure; wordcloud(C); title('Word Cloud');

%% Bar Chart
x = 1900:10:2000;
y = [75 91 105 123.5 131 150 179 203 226 249 281.5];
figure; bar(x,y); title('Bar Chart'); grid on;

%% Horizontal Bar Chart
x = [1980 1990 2000];
y = [40 50 63 52; 42 55 50 48; 30 20 44 40];
figure; barh(x,y); title('BarH Chart'); xlabel('Snowfall'); ylabel('Year');
legend({'Springfield','Fairview','Bristol','Jamesville'});

%% Geo Plot
load usapolygon.mat
figure; geoplot(uslat,uslon); title('GeoPlot'); geobasemap topographic;
