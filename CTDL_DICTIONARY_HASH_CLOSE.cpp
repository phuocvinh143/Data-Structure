#include<bits/stdc++.h>

#define B 101
#define Deleted "++++++++++"
#define Empty "**********"

using namespace std;

typedef string ElementType;

typedef ElementType Dictionary[B];

int h(ElementType x) {
    int sum = 0;
    for (int i = 0; i < x.size(); ++i) sum += x[i];
    return sum % B;
}

void MAKENULL_SET(Dictionary &D) {
    for (int i = 0; i < B; ++i) D[i] = Empty;
}

int LOCATE(ElementType x, Dictionary D) {
    int i = 0, initial = h(x);
    while ((i < B) && D[(initial + i) % B] != x && D[(initial + i) % B] != Empty) ++i;
    return (initial + i) % B;
}

int LOCATE1(ElementType x, Dictionary D) {
    int i = 0, initial = h(x);
    while ((i < B) && (D[(initial + i) % B] != x)
           && (D[(initial + i) % B] != Empty)
           && (D[(initial + i) % B] != Deleted)) ++i;
    return (initial + i) % B;
}

int MEMBER(ElementType x, Dictionary D) {
    return D[LOCATE(x, D)] == x;
}

void INSERT_SET(ElementType x, Dictionary &D) {
    int Bucket = LOCATE1(x, D);
    if (!MEMBER(x, D)) {
        if (D[Bucket] == Empty || D[Bucket] == Deleted) D[Bucket] = x;
    }
}

void DELETE_SET(ElementType x, Dictionary &D) {
    int Bucket = LOCATE1(x, D);
    if (MEMBER(x, D)) {
        D[Bucket] = Deleted;
    }
}

void PRINT_SET(Dictionary D) {
    for (int i = 0; i < B; ++i) {
        cout << D[i] << endl;
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
