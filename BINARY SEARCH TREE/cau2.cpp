// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

T getMin() {
    Node* tmp = root;
    while(tmp->pLeft){
        tmp = tmp->pLeft;
    }
    return tmp->value;
    
}

T getMax() {
     Node* tmp = root;
    while(tmp->pRight){
        tmp = tmp->pRight;
    }
    return tmp->value;   //TODO: return the maximum values of nodes in the tree.
    
}

// STUDENT ANSWER END