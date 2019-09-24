#include<bits/stdc++.h>

#define MaxLength 107
#define NULL -1

using namespace std;

typedef char DataType;
typedef struct {
    DataType Data;
    int LeftMost_Child;
    int Right_Sibling;
    int Parent;
} Node;

typedef struct {
    Node Element[MaxLength];
    int Available;
} Tree;

void MAKENULL_TREE(Tree &T){
    T.Available = 0;
}

int EMPTY_TREE(Tree &T){
    return T.Available == 0;
}

Node PARENT(Node n, Tree &T){
    return T.Element[n.Parent];
}

DataType LABEL_NODE(Node n){
    return n.Data;
}

Node ROOT(Tree &T){
    for (int i = 0; i <= T.Available; ++i) {
        if (T.Element[i].Parent == NULL) return T.Element[i];
    }
    Node tmp;
    tmp.Data = NULL;
    tmp.LeftMost_Child = NULL;
    tmp.Right_Sibling = NULL;
    tmp.Parent = NULL;
    return tmp;
}

int Create2(DataType v, int T1, int T2, Tree &T) {
    int available = T.Available;
    T.Element[available].LeftMost_Child = T1;
    T.Element[available].Data = v;
    T.Element[available].Right_Sibling = NULL;
    T.Element[available].Parent = NULL;
    ++T.Available;
    if (T1 != NULL) {
        T.Element[T1].Parent = available;
        T.Element[T1].Right_Sibling = T2;
    }
    if (T2 != NULL){
        T.Element[T2].Parent = available;
    }
    return available;
}

void NULL_NODE(Node &T){
    T.LeftMost_Child = NULL;
    T.Right_Sibling = NULL;
    T.Parent = NULL;
}

void PreOrder(Node n, Tree &T){
    cout << n.Data << " ";
    int i = n.LeftMost_Child;
    while (i != NULL){
        PreOrder(T.Element[i], T);
        i = T.Element[i].Right_Sibling;
    }
}

void InOrder(Node n, Tree &T){
    int i = n.LeftMost_Child;
    if (i != NULL) InOrder(T.Element[i], T);
    cout << n.Data << " ";
    if (i == NULL) return;
    i = T.Element[i].Right_Sibling;
    while (i != NULL){
        InOrder(T.Element[i], T);
        i = T.Element[i].Right_Sibling;
    }
}

void PosOrder(Node n, Tree &T){
    int i = n.LeftMost_Child;
    while (i != NULL) {
        PosOrder(T.Element[i], T);
        i = T.Element[i].Right_Sibling;
    }
    cout << n.Data << " ";
}

void READ_TREE(Tree &T) {
    MAKENULL_TREE(T);
    int numNode; cin >> numNode;
    for (int i = 1; i <= numNode; ++i) {
        NULL_NODE(T.Element[T.Available]);
        if (T.Available == 0) {
            cin >> T.Element[T.Available].Data;
            ++T.Available;
        }
        else {
            int x; char y; cin >> x >> y;
            T.Element[T.Available].Parent = x;
            T.Element[T.Available].Data = y;
            ++T.Available;
        }
    }
    for (int i = 0; i < T.Available; ++i) {
        for (int j = 0; j < T.Available; ++j) {
            if (T.Element[j].Parent == i) {
                T.Element[i].LeftMost_Child = j;
                break;
            }
        }
        for (int j = i+1; j < T.Available; ++j) {
            if (i) if (T.Element[i].Parent == T.Element[j].Parent) {
                T.Element[i].Right_Sibling = j;
                break;
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    Tree T;
    READ_TREE(T);
//    int T1, T2, T3, T4, T5, T6;
//
//    T1 = Create2(5, NULL, NULL, T);
//    T2 = Create2(10,NULL, NULL, T);
//    T3 = Create2(15,NULL, NULL, T);
//
//    T4 = Create2(20, T1, T2, T);
//    T5 = Create2(25, T3, NULL, T);
//
//    T6 = Create2(30, T4, T5, T);

    PreOrder(ROOT(T), T);
    cout << endl;
    InOrder(ROOT(T), T);
    cout << endl;
    PosOrder(ROOT(T), T);
}























