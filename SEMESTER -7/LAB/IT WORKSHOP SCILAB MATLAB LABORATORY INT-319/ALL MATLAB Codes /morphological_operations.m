[file, path] = uigetfile({'*.jpg;*.jpeg;*.png;*.bmp'}, 'Select an Image');
if isequal(file,0)
    disp('User canceled'); 
    return; 
end

I = imread(fullfile(path, file));
BW = imbinarize(rgb2gray(I));
se = strel('disk', 5);

% Apply morphological operations
figure;
subplot(2,4,1), imshow(BW), title('Original Binary');
subplot(2,4,2), imshow(imdilate(BW, se)), title('Dilation');
subplot(2,4,3), imshow(imerode(BW, se)), title('Erosion');
subplot(2,4,4), imshow(imopen(BW, se)), title('Opening');
subplot(2,4,5), imshow(imclose(BW, se)), title('Closing');
subplot(2,4,6), imshow(BW - imerode(BW, se)), title('Boundary');
subplot(2,4,7), imshow(bwmorph(BW,'skel',Inf)), title('Skeleton');
