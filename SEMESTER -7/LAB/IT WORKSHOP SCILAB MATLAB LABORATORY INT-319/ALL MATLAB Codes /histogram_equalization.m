% Histogram Equalization Script

% 1. Pick an image
[fn,fp] = uigetfile({'*.jpg;*.png;*.bmp;*.tif'},'Pick an image');
if fn==0, return; end   % stop if no file chosen

% 2. Read image
img = imread(fullfile(fp,fn));

% 3. Apply histogram equalization
if size(img,3)==1
    imgEq = histeq(img);                  % grayscale
else
    imgEq = img;                          % RGB
    for c=1:3, imgEq(:,:,c)=histeq(img(:,:,c)); end
end

% 4. Show original vs equalized
figure;
subplot(1,2,1), imshow(img), title('Original');
subplot(1,2,2), imshow(imgEq), title('Equalized');

% 5. Optionally save result
[saveFn,saveFp] = uiputfile('*.png','Save equalized image as');
if saveFn~=0
    imwrite(imgEq, fullfile(saveFp,saveFn));
end
