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

Node Create3(DataType v, Tree first, Tree second, Tree third){
    Node n = (Node)malloc(sizeof(Node));
    n->Data = v;
    n->Leftmost_Child = first;
    n->Right_Sibling = NULL;
    if (first != NULL) first->Right_Sibling = second;
    if (second != NULL) second->Right_Sibling = third;
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

void VD(){
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

int count_node(Tree T) {
    int ans = 0;
    if (T == NULL) return 0;
    if (T->Leftmost_Child == NULL) return 1;
    Node i = T->Leftmost_Child;
    while (i != NULL) {
        ans += count_node(i);
        i = i->Right_Sibling;
    }
    return ans + 1;
}

int count_leaf(Tree T) {
    int ans = 0;
    if (T == NULL) return 0;
    if (T->Leftmost_Child == NULL) return 1;
    Node i = T->Leftmost_Child;
    while (i != NULL) {
        ans += count_leaf(i);
        i = i->Right_Sibling;
    }
    return ans;
}

void BT5(){
    Tree T[15];
    T[0] = Create3('L', NULL, NULL, NULL);
    T[1] = Create3('M', NULL, NULL, NULL);
    T[2] = Create3('I', T[0], T[1], NULL);
    T[3] = Create3('D', T[2], NULL, NULL);
    T[4] = Create3('G', NULL, NULL, NULL);
    T[5] = Create3('H', NULL, NULL, NULL);
    T[6] = Create3('J', NULL, NULL, NULL);
    T[7] = Create3('C', T[4], T[5], T[6]);
    T[8] = Create3('K', NULL, NULL, NULL);
    T[9] = Create3('E', NULL, NULL, NULL);
    T[10] = Create3('F', T[8], NULL, NULL);
    T[11] = Create3('B', T[9], T[10], NULL);
    T[12] = Create3('A', T[11], T[7], T[3]);
    cout << "PreOrder: ";
    PreOrder(T[12]);
    cout << "\nInOrder: ";
    InOrder(T[12]);
    cout << "\nPosOrder: ";
    PosOrder(T[12]);
    cout << "\nNumber of Node: " << count_node(T[12]);
    cout << "\nNumber of Leaf: " << count_leaf(T[12]);
}

int main(){
    BT5();
}
