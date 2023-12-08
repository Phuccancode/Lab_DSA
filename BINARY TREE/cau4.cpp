
#include <iostream>
#include <string>
using namespace std;

template <class K, class V>
class BinaryTree
{
public:
    class Node;


    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {  
       deleteNode(root);
    }
    void deleteNode(Node * root){
        if(!root) return;
        deleteNode(root->pLeft);
        deleteNode(root->pRight);
        delete root;
    }
    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if (posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node *walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l - 1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if (posFromRoot[l - 1] == 'L')
            walker->pLeft = new Node(key, value);
        if (posFromRoot[l - 1] == 'R')
            walker->pRight = new Node(key, value);
    }

    //! Đếm số lượng nút có hai con
    int countTwoChildrenNodeREC(Node* root)
{
    if(root == nullptr) return 0;//! trả về không khi root == null
    //! nếu root khác null thì kiểm trả xem bên trái vs phải của root có khác null hay không nếu khác thì thêm 1
    else if(root->pLeft != nullptr && root->pRight != nullptr) return 1+ countTwoChildrenNodeREC(root->pLeft) + countTwoChildrenNodeREC(root->pRight);
    //! trường hợp còn lại 
    return  countTwoChildrenNodeREC(root->pLeft) + countTwoChildrenNodeREC(root->pLeft);
}
//! hàm gọi 
int countTwoChildrenNode()
{
    return countTwoChildrenNodeREC(root);
}

    //! In ra cây theo thứ tự trung tố (infix)
    void inorderTraversal(Node *node)
    {
        if (node)
        {
            inorderTraversal(node->pLeft);
            cout << "(" << node->key << ", " << node->value << ") ";
            inorderTraversal(node->pRight);
        }
    }

    //! Gọi hàm duyệt cây từ gốc
    void inorderTraversal()
    {
        inorderTraversal(root);
        cout << endl;
    }
    //! hàm tính như yêu cầu đề bài
    long long sumDigitPath(Node* root, long long sum = 0) {
    if(root == nullptr) return 0;
    if(root->pLeft == nullptr && root->pRight == nullptr) return (sum*10+ root->value) % 27022001;
    sum = (sum*10) % 27022001;
    return (sumDigitPath(root->pLeft,sum + root->value)% 27022001 +  sumDigitPath(root->pRight,sum + root->value)% 27022001)% 27022001;
    
}

};

int main()
{
    BinaryTree<int, int>tree;
    tree.addNode("",2, 3); //! Add to root
    tree.addNode("L",3, 5); //! Add to root's left node
    tree.addNode("R",5, 2); //! Add to root's right node
    tree.addNode("RL",3,1); //! Add to root's left node
    tree.addNode("RR",5,4); //! Add to root's right node
    cout << "In-order traversal of the tree:" << endl;
    tree.inorderTraversal();

    int count = tree.countTwoChildrenNode();
    cout << "Number of nodes with two children: " << count << endl;
    cout<<tree.sumDigitPath(tree.root);
    //! 680
    return 0;
}

