%% Image Segmentation using Clustering
% Read image
[fname,fpath] = uigetfile({'*.jpg;*.png;*.jpeg'},'Select Image');
he = imread([fpath,fname]);

% RGB Clustering
L = imsegkmeans(he,3);
rgb_result = labeloverlay(he,L);

% L*a*b* Clustering
lab_he = rgb2lab(he);
ab = im2single(lab_he(:,:,2:3));
pixel_labels = imsegkmeans(ab,3);
lab_result = labeloverlay(he,pixel_labels);

% Individual Clusters
mask1 = pixel_labels == 1;
mask2 = pixel_labels == 2;
mask3 = pixel_labels == 3;
cluster1 = he.*uint8(mask1);
cluster2 = he.*uint8(mask2);
cluster3 = he.*uint8(mask3);

% Blue Nuclei Segmentation
L_blue = rescale(lab_he(:,:,1).*double(mask3));
nuclei_mask = imbinarize(L_blue);
blue_nuclei = he.*uint8(nuclei_mask);

% Cleaned Nuclei
se = strel('disk',2);
clean_mask = imfill(imclose(imopen(nuclei_mask,se),se),'holes');
cleaned_nuclei = he.*uint8(clean_mask);

% Plot all results
figure;
subplot(2,4,1); imshow(he); title('Original');
subplot(2,4,2); imshow(rgb_result); title('RGB Clustering');
subplot(2,4,3); imshow(lab_result); title('L*a*b* Clustering');
subplot(2,4,4); imshow(cluster1); title('Cluster 1');
subplot(2,4,5); imshow(cluster2); title('Cluster 2');
subplot(2,4,6); imshow(cluster3); title('Cluster 3');
subplot(2,4,7); imshow(blue_nuclei); title('Blue Nuclei');
subplot(2,4,8); imshow(cleaned_nuclei); title('Cleaned Nuclei');
