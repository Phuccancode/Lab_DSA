int singleChild(BSTNode* root) {
    if(root == NULL) return 0;
    else if(root->left == NULL && root->right != NULL){
        return  1 + singleChild(root->right);
    }
    else if(root->right == NULL && root->left != NULL){
        return  1 + singleChild(root->left);
    }
    return singleChild(root->right) + singleChild(root->left);
}