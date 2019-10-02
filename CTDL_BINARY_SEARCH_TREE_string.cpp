#include<bits/stdc++.h>

using namespace std;

typedef string KeyType;

typedef struct Node{
    KeyType Key;
    Node* left;
    Node* right;
};

typedef Node* Tree;

Tree Search(KeyType x, Tree Root) {
    if (Root == NULL) return NULL;
    if (Root->Key == x) return Root;
    if (Root->Key > x) return Search(x, Root->left);
    if (Root->Key < x) return Search(x, Root->right);
}

void Insert_Node(KeyType x, Tree& Root) {
    if (Root == NULL) {
//        string có thể hiểu là một class gồm nhiều toán tử, hàm được xây dựng trên nó nên khi
//        sử dụng cần phải khởi tạo cấu trúc ban đầu cho string -> mà "malloc" thì không hỗ trợ
//        khởi tạo constructor nên phải dùng "new"
        Root = new Node;

        Root->Key = x;
        Root->left = NULL;
        Root->right = NULL;
    }
    else if (x > Root->Key) Insert_Node(x, Root->right);
    else if (x < Root->Key) Insert_Node(x, Root->left);
}

KeyType DeleteMin(Tree& Root) {
    KeyType k;
    if (Root->left == NULL) {
        k = Root->Key;
        Root = Root->right;
        return k;
    }
    return DeleteMin(Root->left);
}

void Delete_Node(KeyType x, Tree& Root){
    if (Root != NULL) {
        if (x < Root->Key) Delete_Node(x, Root->left);
        else if (x > Root->Key) Delete_Node(x, Root->right);
        else {
            if ((Root->left == NULL) && (Root->right == NULL)) Root = NULL;
            else {
                if (Root->left == NULL) Root = Root->right;
                else if (Root->right == NULL) Root = Root->left;
                else {
                    Root->Key = DeleteMin(Root->right);
                }
            }
        }
    }
}

void PreOrder(Node* T) {
    if (T == NULL) return;
    cout << T->Key << "\n";
    PreOrder(T->left);
    PreOrder(T->right);
}

void InOrder(Node* T) {
    if (T == NULL) return;
    InOrder(T->left);
    cout << T->Key << "\n";
    InOrder(T->right);
}

void PosOrder(Node* T) {
    if (T == NULL) return;
    PosOrder(T->left);
    PosOrder(T->right);
    cout << T->Key << "\n";
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; cin >> n;
    Tree T = NULL;
    KeyType root;
    for (int i = 1; i <= n; ++i) {
        string s; cin >> s;
        if (i == 1) root = s;
        Insert_Node(s, T);
    }
    PreOrder(Search(root,T));
}




