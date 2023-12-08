// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
    Node* tmp = root;
    while(tmp){
        if(tmp->value > i) tmp = tmp->pLeft;
        else if(tmp->value < i) tmp = tmp->pRight;
        else return true;
    }
    return false;
    
}

T rangeCount(Node* root, T lo, T hi) {
    if(root == NULL) return 0;
    else if(root->value >= lo && root->value <= hi)
        return root->value + rangeCount(root->pLeft,lo,hi) + rangeCount(root->pRight,lo,hi);
    return rangeCount(root->pLeft,lo,hi) + rangeCount(root->pRight,lo,hi);
}

T sum(T l, T r) {
    return rangeCount(root,l,r);
    
}

// STUDENT ANSWER END