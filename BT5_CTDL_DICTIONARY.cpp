#include<bits/stdc++.h>

#define B 100007

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

int charater(char s) {
    if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z')) return 1;
    return 0;
}

string split(int i, int j, string s) {
    string tmp = "";
    for (int pos = i; pos < j; ++pos) tmp += s[pos];
    return tmp;
}

int main(){
    freopen("input.txt", "r", stdin);
    string s;
    Dictionary D;
    MAKENULL_SET(D);
    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); ++i) {
            if (charater(s[i])) {
                int j = i + 1;
                while (charater(s[j]) || s[j] == '\0') ++j;
                string tmp = split(i, j, s);
                INSERT_SET(tmp, D);
                i = j;
            }
        }
    }
    // mai phuoc vinh
}
