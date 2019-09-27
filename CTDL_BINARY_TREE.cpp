#include<bits/stdc++.h>

using namespace std;

typedef int DataType;

typedef struct Node{
    DataType Data;
    Node* left;
    Node* right;
};

typedef Node* Tree;

void MAKENULL_TREE(Tree T) {
    T = NULL;
}

int EMPTY_TREE(Tree T) {
    return T == NULL;
}

Node* LEFT_CHILD(Node* T) {
    if (T != NULL) return T->left;
    return NULL;
}

Node* RIGHT_CHILD(Node* T) {
    if (T != NULL) return T->right;
    return NULL;
}

int IS_LEAF(Tree T) {
    return (T->left == NULL && T->right == NULL);
}

int NB_NODES(Tree T) {
    if (EMPTY_TREE(T)) return 0;
    return 1 + NB_NODES(LEFT_CHILD(T)) + NB_NODES(RIGHT_CHILD(T));
}

int SUM_TREE(Tree T) {
    if (EMPTY_TREE(T)) return 0;
    return T->Data + SUM_TREE(LEFT_CHILD(T)) + SUM_TREE(RIGHT_CHILD(T));
}

Tree Create2(DataType v, Tree left, Tree right) {
    Tree N = (Node*)malloc(sizeof(Node));
    N->Data = v;
    N->left = left;
    N->right = right;
    return N;
}

void PreOrder(Node* T) {
    if (T == NULL) return;
    cout << T->Data << " ";
    PreOrder(T->left);
    PreOrder(T->right);
}

void InOrder(Node* T) {
    if (T == NULL) return;
    InOrder(T->left);
    cout << T->Data << " ";
    InOrder(T->right);
}

void PosOrder(Node* T) {
    if (T == NULL) return;
    PosOrder(T->left);
    PosOrder(T->right);
    cout << T->Data << " ";
}

int TREE_HEIGHT(Tree T) {
    if (T == NULL) return 0;
    return 1 + max(TREE_HEIGHT(T->left), TREE_HEIGHT(T->right));
}

int COUNT_LEAF(Tree T) {
    if (T == NULL) return 0;
    if (IS_LEAF(T)) return 1;
    return COUNT_LEAF(T->left) + COUNT_LEAF(T->right);
}

int main(){
    Tree T1, T2, T3, T4, T5, T;
    T1 = Create2(5, NULL, NULL);
    T2 = Create2(1, NULL, NULL);
    T3 = Create2(6, NULL, NULL);
    T4 = Create2(2, T3, T2);
    T5 = Create2(4, T1, NULL);
    T = Create2(3, T4, T5);
    cout << "PreOrder: ";
    PreOrder(T);
    cout << "\nInOrder: ";
    InOrder(T);
    cout << "\nPosOrder: ";
    PosOrder(T);
    cout << "\nNumber of node: " << NB_NODES(T);
    cout << "\nSum of all nodes value: " << SUM_TREE(T);
    cout << "\nThe height of the tree: " << TREE_HEIGHT(T) - 1;
    cout << "\nNumber of leaf: " << COUNT_LEAF(T);
}

















