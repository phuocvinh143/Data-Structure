#include<bits/stdc++.h>

using namespace std;

typedef int ElementType;

typedef struct Node{
    ElementType Element;
    Node* Next;
};

typedef Node* Position;
typedef Position Stack;

void MAKENULL_STACK(Stack &Header){
    Header = (Node*)malloc(sizeof(Node));
    Header->Next = NULL;
}

Position TOP(Stack &S){
    return S->Next;
}

void PUSH(ElementType X, Stack &S){
    Position T = (Node*)malloc(sizeof(Node));
    T->Element = X;
    T->Next = S->Next;
    S->Next = T;
}

void POP(Stack &S){
    Position T;
    if (S->Next != NULL) {
        T = S->Next;
        S->Next = T->Next;
        free(T);
    }
}

int EMPTY_STACK(Stack &S){
    return S->Next == NULL;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}
