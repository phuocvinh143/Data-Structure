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

List L;

void READ_LIST(List &L){
    MAKENULL_LIST(L);
    int n; cin >> n;
    Position P = L;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        INSERT_LIST(x, P, L);
        P = P->Next;
    }
}

void PRINT_LIST(List &L){
    for (Position P = First(L); P != END_LIST(L); P = P->Next){
        cout << RETRIEVE(P, L) << " ";
        //cout << P << endl;
    }
    cout << endl;
}

/*----------------BT---------------------*/

void BT2a(){
    READ_LIST(L);
    PRINT_LIST(L);
}

void BT2b(){
    MAKENULL_LIST(L);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        INSERT_LIST(x, L, L);
    }
}

void BT3b(List L){
    for (Position P = First(L); P != END_LIST(L); P = P->Next) {
        for (Position V = P->Next; V != END_LIST(L); V = V->Next) {
            if (RETRIEVE(P, L) > RETRIEVE(V, L)) {
                swap(P->Element, V->Element);
            }
        }
    }
}

void BT2c(List L){
    BT3b(L);
    PRINT_LIST(L);
}

void BT4(ElementType X, List L){
    for (Position P = L; P != END_LIST(L); P = P->Next) {
        if (P->Next == END_LIST(L) || P->Next->Element > X) { //NULL khong co mien Element nen phai so sanh END_LIST truoc
            INSERT_LIST(X, P, L);
            return;
        }
    }
}

void BT5(ElementType X, List L){
    for (Position P = L; P != END_LIST(L); P = P->Next) {
        if (P->Next->Element == X) {
            DELETE_LIST(P, L);
            return;
        }
    }
}

void BT6(List L){
    MAKENULL_LIST(L);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        BT4(x, L);
    }
    PRINT_LIST(L);
}

void BT7(List L){
    MAKENULL_LIST(L);
    READ_LIST(L);
    int ck[MaxLength];
    memset(ck, 0, sizeof ck);
    for (Position P = L; P != END_LIST(L);){
        if (P->Next != NULL){ // Khong ton tai NULL->Element
            if (ck[P->Next->Element]) DELETE_LIST(P, L);
            else {
                ck[P->Next->Element] = 1;
                P = P->Next;
            }
        }
        else break;
    }
    PRINT_LIST(L);
}

void BT8(List L){
    MAKENULL_LIST(L);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        if (LOCATE(x, L) == END_LIST(L)) BT4(x, L);
    }
    PRINT_LIST(L);
}

void BT9(){
	List L, L1, L2;
	MAKENULL_LIST(L);
	MAKENULL_LIST(L1);
	MAKENULL_LIST(L2);
	READ_LIST(L1);
	READ_LIST(L2);
	Position i = First(L1), j = First(L2), k = L;
	INSERT_LAST_LIST(oo, L1);
	INSERT_LAST_LIST(oo, L2);
	while (i != NULL && j != NULL) {
		if (i->Element <= j->Element) {
			INSERT_LIST(i->Element, k, L);
			k = k->Next;
			i = i->Next;
		}
		else {
			INSERT_LIST(j->Element, k, L);
			k = k->Next;
			j = j->Next;
		}
	}

	DELETE_LAST_LIST(L);
	PRINT_LIST(L);
}

void BT10(){
	List L;
	MAKENULL_LIST(L);
	READ_LIST(L);
	for (Position P = L; P != END_LIST(L); P = P->Next){
		if (P->Next != NULL && P->Next->Element % 2) DELETE_LIST(P, L);
	}
	PRINT_LIST(L);
}

void BT11(){
	List L, L1, L2;
	MAKENULL_LIST(L);
	MAKENULL_LIST(L1);
	MAKENULL_LIST(L2);
	Position P1 = L1, P2 = L2;
	READ_LIST(L);
	for (Position P = First(L); P != END_LIST(L); P = P->Next){
		if (P != NULL){
			if (P->Element % 2) {
				INSERT_LIST(P->Element, P1, L1);
				P1 = P1->Next;
			}
			else {
				INSERT_LIST(P->Element, P2, L2);
				P2 = P2->Next;
			}
		}
	}
	PRINT_LIST(L1);
	PRINT_LIST(L2);
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
