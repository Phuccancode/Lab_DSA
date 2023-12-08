
BSTNode* find(BSTNode* root, int lo, int hi){
    if(root == NULL) return NULL;
    BSTNode* tmp = root;
    while(tmp){
        if(tmp->val >= lo && tmp->val <= hi) break;
        else if(tmp->val > hi) tmp = tmp->left;
        else tmp = tmp->right;
    }
    return tmp;
}

BSTNode* del(BSTNode* root, int lo, int hi){
    if(root == NULL) return NULL;
    else if(root->val < lo) return del(root->right,lo,hi);
    else if(root->val > hi) return del(root->left,lo,hi);
    root->left = del(root->left,lo,hi);
    root->right= del(root->right,lo,hi);
    return root;
}


BSTNode* subtreeWithRange(BSTNode* root, int lo, int hi) {
     root = find(root, lo, hi);
     root = del(root,lo,hi);
    return root;
}