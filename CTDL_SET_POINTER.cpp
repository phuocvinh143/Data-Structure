#include<bits/stdc++.h>

#define maxlength 100

using namespace std;

typedef int ElementType;

typedef struct Cell {
    ElementType element;
    Cell* next;
};

typedef Cell* SET;

void MAKENULL_SET(SET &header) {
    header = new Cell;
    header->next = NULL;
}

void INSERT_SET(ElementType x, SET &L) {
    SET T, P;
    P = L;
    while (P->next != NULL) {
        if (P->next->element < x) P = P->next;
        else break;
    }
    if ((P->next == NULL) || ((P->next != NULL) && (P->next->element != x)) ) {
        T = new Cell;
        T->element = x;
        T->next = P->next;
        P->next = T;
    }
}

void DELETE_SET(ElementType x, SET &L) {
    SET T, P;
    P = L;
    while (P->next != NULL) {
        if (P->next->element < x) P = P->next;
        else break;
    }
    if (P->next != NULL && P->next->element == x) {
        T = P->next;
        P->next = T->next;
        free(T);
    }
}

int MEMBER(ElementType x, SET L) {
    for (SET P = L->next; P != NULL; P = P->next) {
        if (P->element == x) return 1;
    }
    return 0;
}

void PRINT_SET(SET L) {
    for (SET P = L->next; P != NULL; P = P->next) cout << P->element << " ";
    cout << endl;
}

void UNION(SET Aheader, SET Bheader, SET &C) {
    SET Acurrent, Bcurrent, Ccurrent;
    C = new Cell;
    Acurrent = Aheader->next;
    Bcurrent = Bheader->next;
    Ccurrent = C;

    while ((Acurrent != NULL) || (Bcurrent != NULL)) {
        if (Bcurrent == NULL || Acurrent->element < Bcurrent->element) {
            Ccurrent->next = new Cell;
            Ccurrent = Ccurrent->next;
            Ccurrent->element = Acurrent->element;
            Acurrent = Acurrent->next;
            continue;
        }
        if (Acurrent == NULL || Acurrent->element >= Bcurrent->element) {
            Ccurrent->next = new Cell;
            Ccurrent = Ccurrent->next;
            Ccurrent->element = Bcurrent->element;
            Bcurrent = Bcurrent->next;
        }
    }
    Ccurrent->next = NULL;
}

void INTERSECTION(SET Aheader, SET Bheader, SET &C) {
    SET Acurrent, Bcurrent, Ccurrent;
    C = new Cell;
    Acurrent = Aheader->next;
    Bcurrent = Bheader->next;
    Ccurrent = C;

    while ((Acurrent != NULL) && (Bcurrent != NULL)) {
        if (Acurrent->element == Bcurrent->element) {
            Ccurrent->next = new Cell;
            Ccurrent = Ccurrent->next;
            Ccurrent->element = Acurrent->element;
            Acurrent = Acurrent->next;
            Bcurrent = Bcurrent->next;
        }
        else {
            if (Acurrent->element > Bcurrent->element) Bcurrent = Bcurrent->next;
            else Acurrent = Acurrent->next;
        }
    }
    Ccurrent->next = NULL;
}

ElementType MIN(SET A) {
    return A->next->element;
}



int main(){
//    freopen("input.txt", "r", stdin);
/*  1 2
    3 4
    2 3
    6 6
    10 1 */
    SET L1, L2, L3, L4;
    MAKENULL_SET(L1);
    MAKENULL_SET(L2);
    for (int i = 1; i <= 5; ++i) {
        int x, y; cin >> x >> y;
        INSERT_SET(x, L1);
        INSERT_SET(y, L2);
    }
    PRINT_SET(L1);
    PRINT_SET(L2);
    UNION(L1, L2, L3);
    INTERSECTION(L1, L2, L4);
    PRINT_SET(L3);
    PRINT_SET(L4);
    return 0;
}
