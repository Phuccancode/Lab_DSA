int lowestAncestor(BTNode* root, int a, int b) {
    if(root == NULL) return -9999;
    if(root->val == a){
       return root->val;
    }
    else if(root->val == b){
        return root->val;
    }
    int left = lowestAncestor(root->left,a,b);
    int right = lowestAncestor(root->right,a,b);
    if(left != -9999 && right != -9999) return root->val;
    else if(left != -9999) return left;
    return right;
}