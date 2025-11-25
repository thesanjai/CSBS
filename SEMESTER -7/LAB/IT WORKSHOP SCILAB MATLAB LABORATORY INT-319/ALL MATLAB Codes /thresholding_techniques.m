% Ask user to select an image
[file, path] = uigetfile({'*.jpg;*.png;*.bmp'}, 'Select an Image');
if isequal(file,0), return; end

I = imread(fullfile(path,file));

% Convert to grayscale if RGB
if size(I,3) == 3
    I = rgb2gray(I);
end

% Apply multi-threshold segmentation
nThresholds = 2;
thresh = multithresh(I, nThresholds);
segmented = imquantize(I, thresh);

% Display results
figure;
subplot(1,2,1);
imshow(I);
title('Original Grayscale Image');

subplot(1,2,2);
imshow(label2rgb(segmented));
title('Segmented Image with Multithresh');
