#include<bits/stdc++.h>

#define MaxLength 107
#define oo 1000000007

using namespace std;

typedef struct {
    int TuSo, MauSo;
} PhanSo;

typedef PhanSo ElementType;

typedef int Position;

typedef struct{
    ElementType Elements[MaxLength];
    int Last = 0;
} List;

void MAKENULL_LIST(List &L){
    L.Last = 0;
}

void INSERT_LIST(ElementType x, Position p, List &L) {
    if (L.Last == MaxLength) cout << "Danh sach day";
    else if (p < 1 || p > L.Last + 1) cout << "Vi tri khong hop le";
    else {
        for (Position i = L.Last; i >= p; --i) {
            L.Elements[i+1].TuSo = L.Elements[i].TuSo;
            L.Elements[i+1].MauSo = L.Elements[i].MauSo;
        }
        L.Elements[p].TuSo = x.TuSo;
        L.Elements[p].MauSo = x.MauSo;
        ++L.Last;
    }
}

void READ_LIST(List &L){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        PhanSo X;
        scanf("%d/%d", &X.TuSo, &X.MauSo);
        INSERT_LIST(X, L.Last + 1, L);
    }
}

void PRINT_LIST(List &L){
    for (Position i = 1; i <= L.Last; ++i)
        printf("%d/%d\n", L.Elements[i].TuSo, L.Elements[i].MauSo);
    cout << endl;
}

void REDUCE(List &L){
    for (Position i = 1; i <= L.Last; ++i) {
        int UCLN = __gcd(L.Elements[i].TuSo, L.Elements[i].MauSo);
        L.Elements[i].TuSo = L.Elements[i].TuSo/UCLN;
        L.Elements[i].MauSo = L.Elements[i].MauSo/UCLN;
    }
}

void DELETE_LIST(Position p, List &L){
    if (p < 1 || p > L.Last + 1) cout << "Vi tri khong hop le";
    else {
        for (int i = p; i < L.Last; ++i){
            L.Elements[i].TuSo = L.Elements[i+1].TuSo;
            L.Elements[i].MauSo = L.Elements[i+1].MauSo;
        }
        --L.Last;
    }
}

void DELETE_INT(List &L){
    for (Position i = 1; i <= L.Last; ++i) {
        if (L.Elements[i].TuSo > L.Elements[i].MauSo) DELETE_LIST(i, L);
    }
}

void FIND_1(List &L){
    for (Position i = 1; i < L.Last; ++i) {
        for (Position j = i + 1; j <= L.Last; ++j) {
            int Tu = L.Elements[i].TuSo*L.Elements[j].TuSo;
            int Mau = L.Elements[i].MauSo*L.Elements[j].MauSo;
            if ((Tu % Mau == 0) && (Tu/Mau == 1)) {
                cout << i << " " << j << endl;
                return;
            }
        }
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    return 0;
}
