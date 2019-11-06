#include<bits/stdc++.h>

#define B 10

using namespace std;

typedef string ElementType;

typedef struct Node{
    ElementType Data;
    Node* Next;
};

typedef Node* Position;
typedef Position Dictionary[B];

int h(ElementType x) {
    int sum = 0;
    for (int i = 0; i < x.size(); ++i) sum += x[i];
    return sum % B;
}

void MAKENULL_SET(Dictionary &D) {
    for (int i = 0; i < B; ++i) D[i] = NULL;
}

int MEMBER(ElementType x, Dictionary D) {
    for (Position P = D[h(x)]; P != NULL; P = P->Next)
        if (P->Data == x) return 1;
    return 0;
}

void INSERT_SET(ElementType x, Dictionary &D) {
    int Bucket = h(x);
    Position P;
    if (!MEMBER(x, D)) {
        P = D[Bucket];
        D[Bucket] = new Node;
        D[Bucket]->Data = x;
        D[Bucket]->Next = P;
    }
}

void DELETE_SET(ElementType x, Dictionary &D) {
    int Bucket = h(x);
    Position P = D[Bucket], tmp;
    if (D[Bucket] != NULL) {
        if (D[Bucket]->Data == x) {
            tmp = D[Bucket];
            D[Bucket] = D[Bucket]->Next;
            free(tmp);
        }
        else {
            while (P != NULL) {
                if (P->Next->Data == x) break;
                P = P->Next;
            }
            if (P->Next != NULL){
                tmp = P->Next;
                P->Next = tmp->Next;
                free(tmp);
            }
        }
    }
}

void PRINT_SET(Dictionary D) {
    for (int i = 0; i < B; ++i) {
        for (Position P = D[i]; P != NULL; P = P->Next) {
            cout << P->Data << " ";
        }
        cout << endl;
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    Dictionary A;
    MAKENULL_SET(A);
    for (int i = 1; i <= 10; ++i) {
        string s; cin >> s;
        INSERT_SET(s, A);
    }
    DELETE_SET("muoi", A);
    DELETE_SET("mot", A);
    PRINT_SET(A);
}
