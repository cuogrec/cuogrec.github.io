#include<bits/stdc++.h>
using namespace std;

// Định nghĩa cấu trúc node
struct Node {
    int value;
    Node* left;
    Node* right;
    int height;

    Node(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

// Cây AVL
class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    // Hàm tính chiều cao của node
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Hàm tính độ chênh lệch chiều cao 
    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Hàm xoay trái
    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Thực hiện xoay
        y->left = x;
        x->right = T2;

        // Cập nhật chiều cao
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;  // trả về node mới
    }

    // Hàm xoay phải
    Node* rotateRight(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Thực hiện xoay
        x->right = y;
        y->left = T2;

        // Cập nhật chiều cao
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;  // trả về node mới
    }

    // Hàm xoay kép trái-phải
    Node* rotateLeftRight(Node* node) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Hàm xoay kép phải-trái
    Node* rotateRightLeft(Node* node) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    // Hàm chèn node vào cây AVL
    Node* insert(Node* node, int key) {
        // Bước 1: Thực hiện chèn node giống như cây tìm kiếm nhị phân
        if (node == nullptr)
            return new Node(key);

        if (key < node->value)
            node->left = insert(node->left, key);
        else if (key > node->value)
            node->right = insert(node->right, key);
        else  // Nếu giá trị trùng, chèn vào cây con phải
            node->right = insert(node->right, key);

        // Bước 2: Cập nhật chiều cao của node hiện tại
        node->height = max(height(node->left), height(node->right)) + 1;

        // Bước 3: Kiểm tra xem cây có mất cân bằng không và xoay nếu cần
        int balance = getBalance(node);

        // Cây mất cân bằng: Xoay trái
        if (balance > 1 && key < node->left->value)
            return rotateRight(node);

        // Cây mất cân bằng: Xoay phải
        if (balance < -1 && key > node->right->value)
            return rotateLeft(node);

        // Xoay kép trái-phải
        if (balance > 1 && key > node->left->value)
            return rotateLeftRight(node);

        // Xoay kép phải-trái
        if (balance < -1 && key < node->right->value)
            return rotateRightLeft(node);

        return node;
    }

    // Hàm in cây theo thứ tự inorder
    void inorder(Node* node) {
        if (node == nullptr)
            return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    // Hàm bắt đầu chèn vào cây từ node gốc
    void insert(int key) {
        root = insert(root, key);
    }

    // Hàm in cây theo thứ tự inorder
    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    // Nhập các số vào cây
    int arr[] = {17, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58};
    for (int i = 0; i < 12; i++) {
        tree.insert(arr[i]);
    }

    // In cây theo thứ tự inorder
    cout << "Inorder : ";
    tree.inorder();

    return 0;
}
