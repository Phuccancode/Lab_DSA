void  smallest(BSTNode* root, vector<int>& result){
    if(root == NULL) return;
    smallest(root->left,result);
    result.push_back(root->val);
    smallest(root->right,result);
}
int kthSmallest(BSTNode* root, int k) {
    vector<int> result;
    smallest(root,result);
    return result[k - 1];
}