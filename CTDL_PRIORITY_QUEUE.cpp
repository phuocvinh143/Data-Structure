#include<bits/stdc++.h>

#define maxLength 107

using namespace std;

typedef int ElementType;

typedef struct {
    ElementType Data[maxLength];
    int Last = 0;
} PriorityQueue;

int p(ElementType x) {
    return x;
}

void InsertPriorityQueue(ElementType x, PriorityQueue &L) {
    ++L.Last;
    L.Data[L.Last] = x;
    int i = L.Last;
    while ((i > 1) && p(L.Data[i/2]) > p(L.Data[i])) {
        swap(L.Data[i/2], L.Data[i]);
        i /= 2;
    }
}

ElementType DeleteMin(PriorityQueue &L) {
    ElementType MIN = L.Data[1];
    L.Data[1] = L.Data[L.Last];
    --L.Last;
    int i = 1, j;
    while (i <= L.Last/2) {
        if ((p(L.Data[i*2]) < p(L.Data[i*2 + 1])) || (i*2 > L.Last)) j = i*2;
        else j = i*2 + 1;
        if (p(L.Data[i]) > p(L.Data[j])) swap(L.Data[i], L.Data[j]), i = j;
        else break;
    }
    return MIN;
}

int main(){
//    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    PriorityQueue L;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        InsertPriorityQueue(x, L);
    }
    while (L.Last > 0) {
        cout << DeleteMin(L) << " ";
    }
}
