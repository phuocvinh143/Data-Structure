#include<bits/stdc++.h>

using namespace std;

typedef int ElementType;

typedef struct Node{
    ElementType Element;
    Node* Next;
};

typedef Node* Position;
typedef struct {
    Position Front, Rear; //Chỉ là một biến lưu địa chỉ
} Queue;

void MAKENULL_QUEUE(Queue &Q){
    Position Header = (Node*)malloc(sizeof(Node));
    Header->Next = NULL;
    Q.Front = Header;
    Q.Rear = Header;
}

int EMPTY_QUEUE(Queue Q){
    return Q.Front == Q.Rear;
}

void PUSH(ElementType X, Queue &Q){
    Q.Rear->Next = (Node*)malloc(sizeof(Node)); //Q.Rear->Next bản chất cũng chỉ là một địa chỉ, cấp phát vùng nhớ cho Q.Rear->Next
    Q.Rear = Q.Rear->Next;
    Q.Rear->Element = X;
    Q.Rear->Next = NULL;
}

void POP(Queue &Q){
    Position T = Q.Front;
    Q.Front = Q.Front->Next;
    free(T);
}

Position TOP(Queue &Q){
    return Q.Front->Next;
}

int main(){
    Queue Q; MAKENULL_QUEUE(Q);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        PUSH(x, Q);
    }
    while (!EMPTY_QUEUE(Q)){
        cout << TOP(Q)->Element << " ";
        POP(Q);
    }
}
