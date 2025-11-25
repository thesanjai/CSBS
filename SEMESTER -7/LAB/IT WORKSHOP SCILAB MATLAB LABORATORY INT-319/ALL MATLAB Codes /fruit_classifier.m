%% Fruit Classifier - Ultra Compact
function hog = getHOG(ds, i)
    hog = extractHOGFeatures(im2gray(imresize(imread(ds.Files{i}), [224 224])), 'CellSize', [4 4]);
end

% Load and split
ds = imageDatastore('C:\Users\girid\OneDrive\Documents\MATLAB\Fruits_Dataset', ...
    'IncludeSubfolders', true, 'LabelSource', 'foldernames');
[trainSet, testSet] = splitEachLabel(ds, 0.8, 'randomized');
disp(countEachLabel(trainSet)); disp(countEachLabel(testSet));

% Extract features
n = numel(trainSet.Files); m = numel(testSet.Files);
trainFeat = zeros(n, length(getHOG(trainSet,1)), 'single');
testFeat = zeros(m, length(getHOG(testSet,1)), 'single');
for i=1:n, trainFeat(i,:) = getHOG(trainSet,i); end
for i=1:m, testFeat(i,:) = getHOG(testSet,i); end

% Train and evaluate
model = fitcnet(trainFeat, trainSet.Labels);
pred = predict(model, testFeat);
confMat = confusionmat(testSet.Labels, pred);
confusionchart(confMat);
fprintf("Accuracy is %.2f%%\nSaved model checkpoint.\n", sum(diag(confMat))/sum(confMat(:))*100);
save('Fruits_Classifier.mat', 'model');
