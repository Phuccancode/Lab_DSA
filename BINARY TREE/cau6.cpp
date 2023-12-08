void longestPathSumRec(BTNode* root, int sum, int height, int &heightMax, int& result) {
    if (!root) {
        if (heightMax < height) {
            heightMax = height;
            result = sum;
        } else if (heightMax == height && result < sum)
            result = sum;
        return;
    }
     longestPathSumRec(root->left, sum + root->val, height + 1, heightMax,result);
     longestPathSumRec(root->right, sum + root->val, height + 1, heightMax,result);
}
int longestPathSum(BTNode* root) {
    int heightMax = 0;
    int result = -9999;
    longestPathSumRec(root, 0, 0, heightMax,result);
    return result;
}