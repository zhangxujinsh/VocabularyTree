﻿#include "VocabularyTree.h"

//==========================functions in class vocabularyTree========================
void vocabularyTree::buildTree(double** features, int nFeatures, int nBranch, int depth, int featureLength) {
	featureClustering* feature2Cluster;
	feature2Cluster = new featureClustering[nFeatures];
	for(int i = 0; i < nFeatures; i++) {
		feature2Cluster[i].label = 0;
		//feature2Cluster[i].feature = features[i];
	}

	buildRecursion(0, root, feature2Cluster, nFeatures, nBranch, featureLength);
}

void vocabularyTree::buildRecursion(int curDepth, vocabularyTreeNode* curNode, featureClustering* features, int nFeatures, int branchNum, int featureLength) {
	if(curDepth == depth)
		return;
	
	int* nums;
	nums = new int[branchNum];
	double** clusterCenter = NULL;

	kmeans(features, nFeatures, branchNum, nums, featureLength, clusterCenter);
	qsort(features, nFeatures, sizeof(featureClustering*), cmp);

	curNode->children = new vocabularyTreeNode*[branchNum];
	int offset = 0;
	for(int i = 0; i < nBranch; i++) {
		curNode->children[i] = new vocabularyTreeNode(branchNum, featureLength, clusterCenter[i]);
		buildRecursion(curDepth + 1, curNode->children[i], features + offset, nums[i], branchNum, featureLength);
		offset += nums[i] * sizeof(featureClustering);
	}
}

void vocabularyTree::clearTF() {

}

void vocabularyTree::getTFIDF() {

}




