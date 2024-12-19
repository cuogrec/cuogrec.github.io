#include<bits/stdc++.h>
using namespace std;

struct Node {
    string title; // ten
    int pageNum; // trang bat dau cua muc
    int numPage; // so trang cua muc
    vector<Node*> con; 
    Node(string t, int p, int np) : title(t), pageNum(p), numPage(np) {}
};

class Book {
public:
    Node* root; 

    Book(){
        root = nullptr ;
    }  
    int numChap(); // dem so chuong
    Node* longest(); // chuong dai nhat
    void deleteNode(Node* node); // xoa 1 node khoi cay va cap nhat lai so trang 
    void in(Node* node, int level);
};

int Book::numChap() {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;
    vector<Node*> queue;
    queue.push_back(root);

    while (!queue.empty()) {
        Node* current = queue.front();
        queue.pop_back();

        if (current->con.empty()) {
            count++;
        }

        for (Node* child : current->con) {
            queue.push_back(child);
        }
    }

    return count;
}

Node* Book::longest() {
    if (root == nullptr) {
        return nullptr;
    }

    Node* tmp = root;
    vector<Node*> queue;
    queue.push_back(root);

    while (!queue.empty()) {
        Node* current = queue.front();
        queue.pop_back();

        if (current->con.empty() && current->numPage > tmp->numPage) {
            tmp = current;
        }

        for (Node* child : current->con) {
            queue.push_back(child);
        }
    }

    return tmp;
}

void Book::deleteNode(Node* node) {
    if (node == nullptr) {
        return;
    }

    // Tìm cha của node
    Node* cha = nullptr;
    vector<Node*> queue;
    queue.push_back(root);

    while (!queue.empty()) {
        Node* current = queue.front();
        queue.pop_back();

        for (int i = 0; i < current->con.size(); i++) {
            if (current->con[i] == node) {
                cha = current;
                break;
            } else {
                queue.push_back(current->con[i]);
            }
        }
    } 
}


void Book::in(Node* node, int level = 0) {
    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << node->title << " (" << node->pageNum << "-" << node->pageNum + node->numPage - 1 << ")" << endl;

    for (Node* child : node->con) {
        in(child, level + 1);
    }
}

int main(){
    Book myBook;

    // Tạo các node đại diện cho các chương, mục
    Node* root = new Node("LOI MO DAU", 1, 5);
    Node* chapter1 = new Node("Chapter 1: ABC", 6, 20);
    Node* section1_1 = new Node("Section 1.1: DEF", 6, 10);
    Node* section1_2 = new Node("Section 1.2: GHI", 16, 10);
    // ... tạo thêm các node khác tương tự

    // Kết nối các node thành cây
    root->con.push_back(chapter1);
    chapter1->con.push_back(section1_1);
    chapter1->con.push_back(section1_2);
    // ... kết nối các node còn lại

    myBook.root = root;

    // In toàn bộ cuốn sách
    myBook.in(myBook.root);

    // Tìm chương dài nhất
    Node* longestChapter = myBook.longest();
    cout << "Chương dài nhất: " << longestChapter->title << endl;

    // Xóa một node (ví dụ: xóa section1_1)
    myBook.deleteNode(section1_1);

    // In lại cuốn sách sau khi xóa
    cout << "\nSau khi xóa:\n";
    myBook.in(myBook.root);

}