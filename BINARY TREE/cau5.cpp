// STUDENT ANSWER BEGIN
// You can define other functions here to help you.

void BFS() {
    //! Kiểm tra xem cây có rễ không
    if (root == NULL) return;

    //! Sử dụng một hàng đợi để lưu trữ các nút của cây
    queue<Node*> q;
    q.push(root);

    //! Bắt đầu duyệt cây theo BFS
    while (q.size()) {
        //! Lấy nút đầu tiên ra khỏi hàng đợi
        Node* tmp = q.front();
        q.pop();

        //! In ra giá trị của nút, thể hiện thứ tự của nút
        cout << tmp->value << " ";

        //! Kiểm tra và thêm nút con bên trái vào hàng đợi (nếu có)
        if (tmp->pLeft) q.push(tmp->pLeft);

        //! Kiểm tra và thêm nút con bên phải vào hàng đợi (nếu có)
        if (tmp->pRight) q.push(tmp->pRight);
    }
}
// STUDENT ANSWER END