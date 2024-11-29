#include<bits/stdc++.h>

using namespace std;

struct Product {
    string ten;
    int sl;
    double gia;
};

struct Node {
    Product sp;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;
};

void enqueue(Queue& q, Product sp) {
    Node* newNode = new Node;
    newNode->sp = sp;
    newNode->next = nullptr;
    
    if (q.rear == nullptr) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
}

Product dequeue(Queue& q) {
    if (q.front == nullptr) {
        cout << "Hàng đợi rỗng!" << endl;
    }
    Node* temp = q.front;
    Product sp = temp->sp;
    q.front = q.front->next;
    
    if (q.front == nullptr) {
        q.rear = nullptr;
    }
    
    delete temp;
    return sp;
}

bool isEmpty(Queue q) {
    return q.front == nullptr;
}

int main() {
    Queue queue;
    queue.front = queue.rear = nullptr;

    int numCustomers;
    cout << "Nhap so luong khach hang: ";
    cin >> numCustomers;

    for (int i = 0; i < numCustomers; ++i) {
        Product sp;
        cout << "Nhap thong tin san pham cho khach hang thu " << i+1 << ":" << endl;
        cout << "So luong: ";
        cin >> sp.sl;
        for(int i = 0 ; i<sp.sl ; i++){
        	
        cout << "Ten san pham: ";
        cin >> sp.ten;
        cout << "Don gia: ";
        cin >> sp.gia;

        enqueue(queue, sp);
    	}
    }

    int sum = 0;
    int demA = 0;

    while (!isEmpty(queue)) {
        Product sp = dequeue(queue);
        sum += sp.gia ;
        if (sp.ten == "A") {
            demA++;
        }
    }

    cout << "Tong doanh thu: " << sum << endl;
    cout << "So luong san pham A da ban: " << demA << endl;

    return 0;
}