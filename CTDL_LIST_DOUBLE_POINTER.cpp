#include<bits/stdc++.h>

using namespace std;

typedef int ElementType;
typedef struct Node{
    ElementType Element;
    Node* Next;
    Node* Previous;
};
typedef Node* Position;
typedef Position DoubleList;

void MAKENULL_DLIST(DoubleList &Header){
    Header = (Node*)malloc(sizeof(Node));
    Header->Next = NULL;
    Header->Previous = NULL;
}

int EMPTY_DLIST(DoubleList &DL){
    return DL->Next == NULL;
}

void INSERT_DLIST(ElementType X, Position P, DoubleList &DL){
    if (P->Next == NULL) {
        Position T = (Node*)malloc(sizeof(Node));
        P->Next = T;
        T->Element = X;
        T->Previous = P;
        T->Next = NULL;
    }
    else {
        Position T = (Node*)malloc(sizeof(Node));
        T->Element = X;
        T->Next = P->Next;
        T->Previous = P;
        P->Next = T;
        P->Next->Previous = T;
    }
}

void DELETE_DLIST(Position P, DoubleList &DL){
    if (P->Next->Next == NULL) {
        Position T = P->Next;
        P->Next = NULL;
        free(T);
    }
    else {
        Position T = P->Next;
        P->Next = P->Next->Next;
        P->Next->Next->Previous = P;
        free(T);
    }
}

void READ_DLIST(DoubleList &DL){
    MAKENULL_DLIST(DL);
    int n; cin >> n;
    Position P = DL;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        INSERT_DLIST(x, P, DL);
        P = P->Next;
    }
}

void PRINT_DLIST(DoubleList &DL){
    for (Position P = DL->Next; P != NULL; P = P->Next) {
        cout << P->Element << " ";
    }
    cout << endl;
}

/*---------------------BT---------------------*/

void BT21a(ElementType X, DoubleList &DL){
    INSERT_DLIST(X, DL, DL);
}

int BT21b(ElementType X, DoubleList &DL){
    int i = 1;
    for (Position P = DL->Next; P != NULL; P = P->Next) {
        if (P->Element == X) return i;
        ++i;
    }
    return NULL;
}

void BT21c(ElementType X, DoubleList &DL){
    for (Position P = DL; P->Next != NULL; P = P->Next) {
        if (P->Next->Element == X) DELETE_DLIST(P, DL);
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    DoubleList DL;
    READ_DLIST(DL);
    BT21a(10, DL);
    PRINT_DLIST(DL);
    cout << BT21b(10, DL) << endl;
    BT21c(10, DL);
    PRINT_DLIST(DL);
}
