vector<int> levelAlterTraverse(BSTNode* root) {
    if(root == NULL) return {};
    queue<BSTNode*> q;
    vector<vector<int>> vv;
    vector<int> result;
    q.push(root);
    q.push(NULL);
    int i = 0;
    while(q.size()){
        BSTNode* tmp = q.front();
        q.pop();
        if(tmp == NULL){
            vv.push_back(result);
            result.clear();
            i++;
            if(q.size()) q.push(NULL);
            continue;
        }
        result.push_back(tmp->val);
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
    int len = vv.size();
    for(int i = 0; i < len; i++){
        int length = vv[i].size();
        if(i % 2 == 0)
            for(int j = 0; j < length; j++) result.push_back(vv[i][j]);
        else 
            for(int j = length - 1; j >= 0; j--) result.push_back(vv[i][j]);
    }
    return result;
}