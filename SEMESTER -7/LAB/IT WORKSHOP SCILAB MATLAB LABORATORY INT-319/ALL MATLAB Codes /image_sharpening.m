% Ask user to select an image
[file, path] = uigetfile({'*.png;*.jpg;*.tif;*.bmp'}, 'Select an image');
if isequal(file,0)
    return; % Exit if user cancels
end

% Read the image
img = imread(fullfile(path, file));

% Apply default sharpening
sharpDefault = imsharpen(img);

% Apply sharpening with custom Radius and Amount
sharpCustom = imsharpen(img, 'Radius', 2, 'Amount', 1);

% Display all images in one figure
figure
subplot(1,3,1), imshow(img), title('Original Image');
subplot(1,3,2), imshow(sharpDefault), title('Sharpened (Default)');
subplot(1,3,3), imshow(sharpCustom), title('Sharpened (Radius=2, Amount=1)');
