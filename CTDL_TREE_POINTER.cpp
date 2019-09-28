#include<bits/stdc++.h>

using namespace std;

typedef char DataType;

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

/* -------------------BT---------------------- */

void BT2(Tree T){
    queue<Tree> q;
    q.push(T);
    while (!q.empty()){
        Tree i = q.front(); q.pop();
        cout << i->Data << " ";
        i = i->Leftmost_Child;
        while (i != NULL){
            q.push(i);
            i = i->Right_Sibling;
        }
    }
}

void BT1(){
    Tree T[15];
    T[0] = Create2New('N', NULL, NULL);
    T[1] = Create2New('M', NULL, T[0]);
    T[2] = Create2New('I', T[1], NULL);
    T[3] = Create2New('E', T[2], NULL);
    T[4] = Create2New('D', NULL, T[3]);
    T[5] = Create2New('L', NULL, NULL);
    T[6] = Create2New('K', NULL, NULL);
    T[7] = Create2New('J', NULL, T[6]);
    T[8] = Create2New('H', T[5], NULL);
    T[9] = Create2New('G', T[7], T[8]);
    T[10] = Create2New('F', NULL, T[9]);
    T[11] = Create2New('C', T[10], NULL);
    T[12] = Create2New('B', T[4], T[11]);
    T[13] = Create2New('A', T[12], NULL);

    PreOrder(T[13]);
    cout << endl;
    InOrder(T[13]);
    cout << endl;
    PosOrder(T[13]);
    cout << endl;
    BT2(T[13]);
}



int main(){
    BT1();
//    Tree T1, T2, T3, T4, T5, T;
//    T1 = Create2New(6, NULL, NULL);
//    T2 = Create2New(5, NULL, NULL);
//    T3 = Create2New(4, NULL, T2);
//    T4 = Create2New(3, T1, NULL);
//    T5 = Create2New(2, T3, T4);
//    T = Create2New(1, T5, NULL);
//    PreOrder(T);
//    cout << endl;
//    InOrder(T);
//    cout << endl;
//    PosOrder(T);

}
