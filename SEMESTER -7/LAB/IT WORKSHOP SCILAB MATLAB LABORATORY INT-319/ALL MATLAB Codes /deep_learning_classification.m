%% Exercise 12: Image Classification
p = fullfile(matlabroot,'toolbox','nnet','nndemos','nndatasets','DigitDataset');
imds = imageDatastore(p,'IncludeSubfolders',true,'LabelSource','foldernames');
[imdsTrain, imdsVal] = splitEachLabel(imds, 750, 'randomize');

layers = [imageInputLayer([28 28 1]) convolution2dLayer(5,20) batchNormalizationLayer ...
    reluLayer fullyConnectedLayer(10) softmaxLayer classificationLayer];

options = trainingOptions('sgdm', 'MaxEpochs', 4, 'ValidationData', imdsVal, ...
    'ValidationFrequency', 30, 'Verbose', false, 'Plots', 'training-progress');

net = trainNetwork(imdsTrain, layers, options);

YPred = classify(net, imdsVal);
fprintf('Accuracy: %.4f\n\n', mean(YPred == imdsVal.Labels));

figure('Name','Input & Output');
for i=1:9
    img = imread(imdsVal.Files{randi(numel(imdsVal.Files))});
    subplot(3,3,i); imshow(img);
    title(['Predicted: ' char(classify(net, img))], 'FontSize', 12, 'FontWeight', 'bold');
    axis off;
end
