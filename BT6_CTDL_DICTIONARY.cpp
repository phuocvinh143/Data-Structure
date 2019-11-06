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

void INSERT_SET(ElementType key, ElementType value, Dictionary &D) {
    int Bucket = h(key);
    Position P;
    if (!MEMBER(key, D)) {
        P = D[Bucket];
        D[Bucket] = new Node;
        D[Bucket]->Data = value;
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
    ifstream read("input.txt");
    Dictionary D;
    MAKENULL_SET(D);
    while (1) {
        string word, explanation;
        read >> word >> explanation;
        if (word[0] == '\0') break;
        INSERT_SET(word, explanation, D);
    }
    read.close();
    int cnt = 10;
    while (cnt--) {
        string s; cin >> s;
        cout << (D[h(s)] != NULL ? D[h(s)]->Data : "sorry, I dont't understand") << endl;
    }
    /*  go di
        yes co
        right phai
        left trai
        see thay
        one mot
        two hai
        three ba */
}
