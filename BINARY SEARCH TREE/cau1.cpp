//Helping functions

Node* addRec(Node*root, T value){
    if(root == NULL) return new Node(value);
    if(root->value >= value)
        root->pLeft =  addRec(root->pLeft, value);
    else if(root->value < value)
        root->pRight = addRec(root->pRight,value);
    return root;
}
void add(T value){
    if(root == NULL){
        root = new Node(value);
    }
    else addRec(root,value);
}

Node* deleteNodeRec(Node*root, T value){
    if(root == NULL) return NULL;
    if(root->value > value)
        root->pLeft =  deleteNodeRec(root->pLeft, value);
    else if(root->value < value)
        root->pRight = deleteNodeRec(root->pRight,value);
    else{
        if(root->pLeft == NULL && root->pRight == NULL){
            delete root;
            return NULL;
        }
        else if(root->pLeft == NULL){
            Node* tmp = root->pRight;
            delete root;
            return tmp;
        }
        else if(root->pRight == NULL){
            Node* tmp = root->pLeft;
            delete root;
            return tmp;
        }
        else{
            Node* tmp = root->pLeft;
            while(tmp->pRight){
                tmp = tmp->pRight;
            }
            swap(root->value, tmp->value);
            root->pLeft = deleteNodeRec(root->pLeft, tmp->value);
        }
    }
    return root;
}
void deleteNode(T value){
    deleteNodeRec(root,value);
    
}