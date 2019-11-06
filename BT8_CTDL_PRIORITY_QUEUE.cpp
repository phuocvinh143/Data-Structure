#include<bits/stdc++.h>

#define maxLength 107

using namespace std;

typedef int ElementType;

struct PriorityQueue {
    ElementType Data[maxLength];
    int Last = 0;
} ;

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

void SORT(ElementType a[], int n) {
    PriorityQueue L;
    for (int i = 1; i <= n; ++i) InsertPriorityQueue(a[i], L);
    int pos = 1;
    while (L.Last > 0) {
        ElementType MIN = L.Data[1];
        a[pos] = MIN; ++pos;
        L.Data[1] = L.Data[L.Last];
        --L.Last;
        int i = 1, j;
        while (i <= L.Last/2) {
            if ((p(L.Data[i*2]) < p(L.Data[i*2 + 1])) || (i*2 > L.Last)) j = i*2;
            else j = i*2 + 1;
            if (p(L.Data[i]) > p(L.Data[j])) swap(L.Data[i], L.Data[j]), i = j;
            else break;
        }
    }
}

int main(){
//    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    int a[maxLength];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    SORT(a, n);
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";

    /*
       5
       5 4 3 1 2
    */
}
