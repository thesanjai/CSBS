%% Image Edge Detection with File Selector
% Select image file
[fname, fpath] = uigetfile({'*.jpg;*.png;*.jpeg;*.tif;*.bmp'}, 'Select Image');
a = imread([fpath, fname]);

% Convert to grayscale (works for both RGB and grayscale)
b = im2gray(a);

% Apply edge detection methods
sobel_edge = edge(b, 'sobel');
prewitt_edge = edge(b, 'prewitt');
roberts_edge = edge(b, 'roberts');
canny_edge = edge(b, 'canny');

% Display results
figure;
subplot(2,3,1); imshow(a); title('Original Image');
subplot(2,3,2); imshow(sobel_edge); title('Sobel Operator');
subplot(2,3,3); imshow(prewitt_edge); title('Prewitt Operator');
subplot(2,3,4); imshow(roberts_edge); title('Roberts Operator');
subplot(2,3,5); imshow(canny_edge); title('Canny Operator');
subplot(2,3,6); imshow(b); title('Grayscale');
