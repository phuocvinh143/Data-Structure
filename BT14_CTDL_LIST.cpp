#include<bits/stdc++.h>

#define MaxLength 100007
#define oo 1000000007

using namespace std;

typedef struct DaThuc{
    int HeSo, SoMu;
};

typedef DaThuc ElementType;

typedef struct Node{
    ElementType Element;
    Node* Next;
};

typedef Node* Position;
typedef Position List;


Position First(List L){
    return L->Next;
}

Position END_LIST(List L){
    return NULL;
}

Position FIND_P(Position P, List &L){
    for (Position T = First(L); T != END_LIST(L); T = T->Next) {
        if (P->Element.SoMu == T->Element.SoMu) return T;
    }
}

void MAKENULL_LIST(List &Header){
    Header = (Node*)malloc(sizeof(Node));
    Header->Next = NULL;
}

int EMPTY_LIST(List &L){
    return L->Next == NULL;
}

void INSERT_LIST(ElementType X, Position P, List &L){
    Position T = (Node*)malloc(sizeof(Node));
    T->Element.HeSo = X.HeSo;
    T->Element.SoMu = X.SoMu;
    T->Next = P->Next;
    P->Next = T;
}

void DELETE_LIST(Position P, List &L){
    Position T;
    if (P->Next != NULL){
        T = P->Next;
        P->Next = T->Next;
        free(T);
    }
}

ElementType RETRIEVE(Position P, List L){
    if (P != NULL) return P->Element;
}

void SORT(List L){
    for (Position P = First(L); P != END_LIST(L); P = P->Next) {
        for (Position V = P->Next; V != END_LIST(L); V = V->Next) {
            if (RETRIEVE(P, L).SoMu < RETRIEVE(V, L).SoMu) {
                swap(P->Element, V->Element);
            }
        }
    }
}

void READ_LIST(List &L){
    MAKENULL_LIST(L);
    int n;
    ElementType X;
    Position P = L;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        scanf("%dx^%d", &X.HeSo, &X.SoMu);
        INSERT_LIST(X, P, L);
        P = P->Next;
    }
    SORT(L);
    for (Position P = First(L); P != END_LIST(L);){
        Position T = P->Next;
        if (P->Next != NULL  && P->Element.SoMu - P->Next->Element.SoMu != 1) {
            for (int i = P->Next->Element.SoMu+1; i < P->Element.SoMu; ++i) {
                ElementType TMP;
                TMP.HeSo = 0;
                TMP.SoMu = i;
                INSERT_LIST(TMP, P, L);
            }
            P = T;
        }
        P = T;
    }
}

void PRINT_LIST(List &L){
    for (Position P = First(L); P != END_LIST(L); P = P->Next){
        if (P->Element.HeSo != 0){
            if (P == First(L) || P->Element.HeSo < 0)
                printf("%dx^%d ", P->Element.HeSo, P->Element.SoMu);
            else printf("+ %dx^%d ", P->Element.HeSo, P->Element.SoMu);
        }
    }
    cout << endl;
}

void BT14b(List L) {
    for (Position P = First(L); P != END_LIST(L); P = P->Next){
        P->Element.HeSo *= P->Element.SoMu;
        --P->Element.SoMu;
    }
}

void BT14c(List L, List L1, List L2) {
    MAKENULL_LIST(L);
    READ_LIST(L1);
    READ_LIST(L2);
    for (int i = 0; i <= max(First(L1)->Element.SoMu, First(L2)->Element.SoMu); ++i) {
        ElementType T;
        T.HeSo = 0;
        T.SoMu = i;
        INSERT_LIST(T, L, L);
    }
    for (Position P = First(L1); P != END_LIST(L1); P = P->Next) {
        FIND_P(P, L)->Element.HeSo += P->Element.HeSo;
    }
    for (Position P = First(L2); P != END_LIST(L2); P = P->Next) {
        FIND_P(P, L)->Element.HeSo += P->Element.HeSo;
    }
    PRINT_LIST(L);
}

void BT14d(List L, List L1, List L2, List L3) {
    MAKENULL_LIST(L);
    MAKENULL_LIST(L3);
    READ_LIST(L1);
    READ_LIST(L2);
    int tmp = 0;
    for (Position P = First(L1); P != END_LIST(L1); P = P->Next) {
        for (Position V = First(L2); V != END_LIST(L2); V = V->Next){
            ElementType T;
            T.HeSo = P->Element.HeSo * V->Element.HeSo;
            T.SoMu = (P->Element.SoMu*V->Element.SoMu == 0 ?
                      max(P->Element.SoMu, V->Element.SoMu) :
                      (P->Element.SoMu*V->Element.SoMu == 1 ? 2 : P->Element.SoMu*V->Element.SoMu));
            tmp = max(tmp, T.SoMu);
            INSERT_LIST(T, L3, L3);
        }
    }
    for (int i = 0; i <= tmp; ++i) {
        ElementType T;
        T.HeSo = 0;
        T.SoMu = i;
        INSERT_LIST(T, L, L);
    }
    for (Position P = First(L3); P != END_LIST(L3); P = P->Next) {
        FIND_P(P, L)->Element.HeSo += P->Element.HeSo;
    }
    PRINT_LIST(L);
}

/*----------------BT---------------------*/

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    List L, L1, L2, L3;

    return 0;
}
