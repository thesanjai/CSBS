    %% Part 1: Salt & Pepper Noise + Mean & Median Filters

% Select an image
[file1, path1] = uigetfile({'*.tif;*.png;*.jpg;*.bmp'}, 'Select an image for Part 1');
if isequal(file1,0), error('No file selected.'); end

I = imread(fullfile(path1, file1));

% Add salt & pepper noise
J = imnoise(I, 'salt & pepper', 0.02);

% Convert to grayscale if RGB
if size(J,3) == 3, J = rgb2gray(J); end

% Apply filters
Kmean = filter2(fspecial('average',3), J)/255;
Kmedian = medfilt2(J);

% Plot original, noisy, and filtered images together
figure('Name','Salt & Pepper Noise Filtering','NumberTitle','off');
subplot(2,2,1); imshow(I); title('Original Image');
subplot(2,2,2); imshow(J); title('Noisy Image');
subplot(2,2,3); imshow(Kmean); title('Mean Filtered');
subplot(2,2,4); imshow(Kmedian); title('Median Filtered');

%% Part 2: Wiener Filter for Gaussian Noise

% Select an image
[file2, path2] = uigetfile({'*.png;*.jpg;*.bmp;*.tif'}, 'Select an image for Part 2');
if isequal(file2,0), error('No file selected.'); end

RGB = imread(fullfile(path2, file2));
I2 = im2gray(RGB);

% Add Gaussian noise
J2 = imnoise(I2, 'gaussian', 0, 0.025);

% Apply Wiener filter
K2 = wiener2(J2, [5 5]);

% Plot portion of noisy and filtered image
figure('Name','Wiener Filtering','NumberTitle','off');
subplot(1,2,1); imshow(J2); title('Noisy Portion');
subplot(1,2,2); imshow(K2); title('Wiener Filtered Portion');
