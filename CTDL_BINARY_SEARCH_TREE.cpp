#include<bits/stdc++.h>

using namespace std;

typedef int KeyType;

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

Tree Insert_Node(KeyType x, Tree& Root) {
    if (Root == NULL) {
        Root = (Node*)malloc(sizeof(Node));
        Root->Key = x;
        Root->left = NULL;
        Root->right = NULL;
    }
    else if (x > Root->Key) Insert_Node(x, Root->right);
    else if (x < Root->Key) Insert_Node(x, Root->left);
}

KeyType DeleteMin(Tree Root) {
    KeyType k;
    if (Root->left == NULL) {
        k = Root->Key;
        Root = Root->right;
        return k;
    }
    return DeleteMin(Root->left);
}

void Delete_Node(KeyType x, Tree Root){
    if (Root != NULL) {
        if (x < Root->Key) Delete_Node(x, Root->left);
        else if (x > Root->Key) Delete_Node(x, Root->right);
        else {
            if (Root->left == NULL && Root->right == NULL) Root == NULL;
            else {
                if (Root->left == NULL) Root = Root->right;
                else if (Root->right == NULL) Root = Root->left;
                else Root->Key = DeleteMin(Root->right);
            }
        }
    }
}

void PreOrder(Node* T) {
    if (T == NULL) return;
    cout << T->Key << " ";
    PreOrder(T->left);
    PreOrder(T->right);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}



