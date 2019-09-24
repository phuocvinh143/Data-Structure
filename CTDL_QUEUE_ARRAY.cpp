#include<bits/stdc++.h>

#define MaxLength 107

using namespace std;

typedef int ElementType;

typedef struct {
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;

void MAKENULL_QUEUE(Queue &Q){
    Q.Front = 0;
    Q.Rear = -1;
}

int EMPTY_QUEUE(Queue &Q){
    return Q.Front > Q.Rear;
}

ElementType TOP(Queue &Q){
    return Q.Elements[Q.Front];
}

void PUSH(ElementType X, Queue &Q){
    Q.Rear = (Q.Rear + 1) % MaxLength;
    Q.Elements[Q.Rear] = X;
}

void POP(Queue &Q){
    Q.Front = (Q.Front + 1) % MaxLength;
}

void Buffer(){
    char ten_file_doc[107], ten_file_ghi[107];
    cout << "Nhap ten file muon in: "; cin >> ten_file_doc;
    cout << "Nhap ten file xuat (may in): "; cin >> ten_file_ghi;
    freopen(ten_file_doc, "r", stdin);
    freopen(ten_file_ghi, "w", stdout);
    Queue Q; MAKENULL_QUEUE(Q);
    while (1) {
        string s;
        getline(cin, s);
        if (s == "\0") break;
        PUSH(s, Q);
    }
    while (!EMPTY_QUEUE(Q)){
        cout << TOP(Q) << "\n";
        POP(Q);
    }
}

int main(){
    Queue Q; MAKENULL_QUEUE(Q);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        PUSH(x, Q);
    }
    while (!EMPTY_QUEUE(Q)){
        cout << TOP(Q) << " ";
        POP(Q);
    }
}

