#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    //constructor
    node(int x){
        data = x;
        left = right = NULL;
    }
};
//SAU KHI TIM RA DC NODE CHA
void makeRoot(node *root , int u, int v, char c){
    if(c == 'L') root->left = new node(v);
    else root->right = new node(v);  
}

//CHO V LA NODE CON CUA U
void insertNode(node *root, int u, int v, char c){
    if(root == NULL) return ;
    if(root->data == u){
        makeRoot(root, u, v, c);
    }
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}


//DUYET TRUNG TO
void inorder(node *root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << ' ' ;
    inorder(root->right);
}
//DUYET TIEN TO
void preorder(node *root){
    if(root != NULL){
    cout << root->data << ' ';
    preorder(root->left);
    preorder(root->right);
    }
}
//DUYET HAU TO
void postorder(node *root){
    if(root != NULL){
    postorder(root->left);
    postorder(root->right);
    cout << root->data << ' ';
    }
}
int main(){
    node *root = NULL;
    int n ; cin >> n;
    for(int i = 0 ; i<n ; i++){
        int u, v; char c ;
        cin >> u >> v >> c ;
        if(root == NULL){
            root = new node(u);
            makeRoot(root, u, v, c);
        }
        else{
            insertNode(root, u, v, c);
        }
    }
    inorder(root);
}
