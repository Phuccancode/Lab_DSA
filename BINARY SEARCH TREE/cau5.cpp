int rangeCount(BTNode* root, int lo, int hi) {
    if(root == NULL) return 0;
    else if(root->val >= lo && root->val <= hi)
        return 1 + rangeCount(root->left,lo,hi) + rangeCount(root->right,lo,hi);
    return rangeCount(root->left,lo,hi) + rangeCount(root->right,lo,hi);
}