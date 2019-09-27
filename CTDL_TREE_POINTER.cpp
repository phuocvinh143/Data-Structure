#include<bits/stdc++.h>

using namespace std;

typedef int DataType;

typedef struct Cell {
    DataType Data;
    Cell* Leftmost_Child;
    Cell* Right_Sibling;
    Cell* Parent;
};

typedef Cell* Node;
typedef Node Tree;

Node Create2(DataType v, Tree left, Tree right) {
    Node n = (Node)malloc(sizeof(Node));
    n->Data = v;
    n->Leftmost_Child = left;
    n->Right_Sibling = NULL;
    n->Parent = NULL;
    if (left != NULL) {
        left->Parent = n;
        left->Right_Sibling = right;
    }
    if (right != NULL) right->Parent = n;
    return n;
}

Node Create2New(DataType v, Tree left, Tree right) {
    Node n = (Node)malloc(sizeof(Node));
    n->Data = v;
    n->Leftmost_Child = left;
    n->Right_Sibling = right;
    return n;
}

void PreOrder(Node n){
    cout << n->Data << " ";
    Node i = n->Leftmost_Child;
    while (i != NULL){
        PreOrder(i);
        i = i->Right_Sibling;
    }
}

void InOrder(Node n){
    Node i = n->Leftmost_Child;
    if (i != NULL) InOrder(i);
    cout << n->Data << " ";
    if (i != NULL) i = i->Right_Sibling;
    while (i != NULL){
        InOrder(i);
        i = i->Right_Sibling;
    }
}



void PosOrder(Node n){
    Node i = n->Leftmost_Child;
    while (i != NULL) {
        PosOrder(i);
        i = i->Right_Sibling;
    }
    cout << n->Data << " ";
}

int main(){
    Tree T1, T2, T3, T4, T5, T;
    T1 = Create2New(6, NULL, NULL);
    T2 = Create2New(5, NULL, NULL);
    T3 = Create2New(4, NULL, T2);
    T4 = Create2New(3, T1, NULL);
    T5 = Create2New(2, T3, T4);
    T = Create2New(1, T5, NULL);
    PreOrder(T);
    cout << endl;
    InOrder(T);
    cout << endl;
    PosOrder(T);
}
