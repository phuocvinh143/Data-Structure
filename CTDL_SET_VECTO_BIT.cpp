#include<bits/stdc++.h>

#define maxlength 100

using namespace std;

typedef int SET[maxlength];

void MAKENULL_SET(SET &a) {
    for (int i = 0; i < maxlength; ++i) a[i] = 0;
}

void UNION(SET a, SET b, SET &c) {
    for (int i = 0; i < maxlength; ++i)
        c[i] = (a[i] || b[i] ? 1 : 0);
}

void INTERSECTION(SET a, SET b, SET &c) {
    for (int i = 0; i < maxlength; ++i)
        c[i] = (a[i] && b[i] ? 1 : 0);
}

int main(){

    return 0;
}
