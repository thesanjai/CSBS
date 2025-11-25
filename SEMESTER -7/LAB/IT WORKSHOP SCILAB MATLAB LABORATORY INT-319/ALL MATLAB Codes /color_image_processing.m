%% Color Image Processing - User Input
clc; clear; close all;

%% Section 0: Read Image
[file, path] = uigetfile({'*.png;*.jpg;*.jpeg;*.bmp'}, 'Select a Color Image');
if isequal(file,0)
    disp('User canceled.'); 
    return;
end

img = imread(fullfile(path, file));

% Check if image is RGB
if size(img, 3) ~= 3
    error('Input must be a color image (RGB).');
end

[r, c, ~] = size(img);

%% =========================
%% Section 1: RGB & HSV Processing
%% =========================

% Separate RGB channels
R = zeros(r, c, 3, 'uint8'); R(:,:,1) = img(:,:,1);
G = zeros(r, c, 3, 'uint8'); G(:,:,2) = img(:,:,2);
B = zeros(r, c, 3, 'uint8'); B(:,:,3) = img(:,:,3);

% Grayscale & Gray to RGB
grayImg = rgb2gray(img);
grayToRGB = cat(3, grayImg, grayImg, grayImg);

% HSV and channels
hsvImage = rgb2hsv(img);
h = hsvImage(:,:,1); % Hue
s = hsvImage(:,:,2); % Saturation
v = hsvImage(:,:,3); % Value

% Display
figure('Name','Section 1: RGB & HSV','NumberTitle','off');
subplot(3,4,1), imshow(img), title('Original RGB'), axis off;
subplot(3,4,2), imshow(R), title('Red Channel'), axis off;
subplot(3,4,3), imshow(G), title('Green Channel'), axis off;
subplot(3,4,4), imshow(B), title('Blue Channel'), axis off;

subplot(3,4,5), imshow(grayImg), title('Grayscale'), axis off;
subplot(3,4,6), imshow(grayToRGB), title('Gray to RGB'), axis off;
subplot(3,4,7), imshow(hsvImage), title('HSV Image'), axis off;
subplot(3,4,8), imshow(h), title('Hue'), axis off;
subplot(3,4,9), imshow(s), title('Saturation'), axis off;
subplot(3,4,10), imshow(v), title('Value'), axis off;

%% =========================
%% Section 2: RGB Histogram Equalization
%% =========================

processedR = imsharpen(R);
processedG = imsharpen(G);
processedB = imsharpen(B);

finalRGB = cat(3, processedR(:,:,1), processedG(:,:,2), processedB(:,:,3));

figure('Name','Section 2: RGB Histogram Equalization','NumberTitle','off');
subplot(2,4,1), imshow(R), title('Red Channel'), axis off;
subplot(2,4,2), imshow(G), title('Green Channel'), axis off;
subplot(2,4,3), imshow(B), title('Blue Channel'), axis off;
subplot(2,4,4), imshow(processedR), title('Processed Red'), axis off;

subplot(2,4,5), imshow(processedG), title('Processed Green'), axis off;
subplot(2,4,6), imshow(processedB), title('Processed Blue'), axis off;
subplot(2,4,7), imshow(finalRGB), title('Final RGB'), axis off;
subplot(2,4,8), imshow(img), title('Original Image'), axis off;

%% =========================
%% Section 3: Grayscale Colormap
%% =========================

figure('Name','Section 3: Grayscale Colormaps','NumberTitle','off');
subplot(2,3,1), imshow(grayImg), title('Grayscale'), axis off;
subplot(2,3,2), imshow(grayImg), colormap('jet'), colorbar, title('Jet'), axis off;
subplot(2,3,3), imshow(grayImg), colormap('hot'), colorbar, title('Hot'), axis off;
subplot(2,3,4), imshow(grayImg), colormap('cool'), colorbar, title('Cool'), axis off;
subplot(2,3,5), imshow(grayImg), colormap('spring'), colorbar, title('Spring'), axis off;
subplot(2,3,6), imshow(grayImg), colormap('parula'), colorbar, title('Parula'), axis off;
