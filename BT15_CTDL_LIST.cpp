#include<bits/stdc++.h>

#define MaxLength 100007
#define oo 1000000007

using namespace std;

typedef int ElementType;

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

Position LOCATE(ElementType X, List L){
    for (Position P = L; P != END_LIST(L); P = P->Next) {
        if (P->Element == X) return P;
    }
    return END_LIST(L);
}

Position FIND_P(int p, List &L){
    Position P = L;
    for (int i = 1; i < p; ++i) P = P->Next;
    return P;
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
    T->Element = X;
    T->Next = P->Next;
    P->Next = T;
}

void INSERT_LAST_LIST(ElementType X, List &L){
	Position P = L;
	while (P->Next != NULL) P = P->Next;
	INSERT_LIST(X, P, L);
}

void DELETE_LIST(Position P, List &L){
    Position T;
    if (P->Next != NULL){
        T = P->Next;
        P->Next = T->Next;
        free(T);
    }
}

void DELETE_LAST_LIST(List &L){
	Position P = L;
	while (P->Next->Next != NULL) P = P->Next;
	DELETE_LIST(P, L);
}

ElementType RETRIEVE(Position P, List L){
    if (P != NULL) return P->Element;
}

void READ_LIST(List &L, string s){
    MAKENULL_LIST(L);
    for (int i = 0; i < s.size(); ++i) {
        INSERT_LIST(s[i] - '0', L, L);
    }
}

void PRINT_LIST(List &L){
    for (Position P = First(L); P != END_LIST(L); P = P->Next){
        if (P == First(L) && P->Element == 0) continue;
        cout << RETRIEVE(P, L);
    }
    cout << endl;
}

/*----------------BT---------------------*/

void PLUS(List L1, List L2){
    List L3;
    MAKENULL_LIST(L3);
    Position V = First(L2);
    for (Position P = First(L1); P != END_LIST(L1); P = P->Next) {
        if (P->Element + V->Element < 10) {
            INSERT_LIST(P->Element + V->Element, L3, L3);
        }
        else {
            INSERT_LIST((P->Element + V->Element)%10, L3, L3);
            ++P->Next->Element;
        }
        V = V->Next;
    }
    PRINT_LIST(L3);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s1, s2;
    List L1, L2;
    cin >> s1 >> s2;
    while (s1.size() < s2.size()) s1 = "0" + s1;
    while (s2.size() < s1.size()) s2 = "0" + s2;
    s1 = "0" + s1; s2 = "0" + s2;
    READ_LIST(L1, s1);
    READ_LIST(L2, s2);
    PLUS(L1, L2);
    return 0;
}
