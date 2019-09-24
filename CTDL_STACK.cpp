#include<bits/stdc++.h>

#define MaxLength 100007

using namespace std;

typedef int ElementType;

typedef struct {
	ElementType Elements[MaxLength];
	int Top_idx;
} Stack;

void MAKENULL_STACK(Stack &S){
	S.Top_idx = 0;
}

int EMPTY_STACK(Stack &S){
	return S.Top_idx == 0;
}

ElementType TOP(Stack &S){
	return S.Elements[S.Top_idx];
}

void POP(Stack &S){
	if (!EMPTY_STACK(S)) --S.Top_idx;
}

void PUSH(ElementType X, Stack &S){
	++S.Top_idx;
	S.Elements[S.Top_idx] = X;
}

void BT18a(){
	Stack S;
	MAKENULL_STACK(S);
	int n; cin >> n;
	while (n) {
		PUSH(n % 2, S);
		n /= 2;
	}
	while (!EMPTY_STACK(S)){
		cout << TOP(S);
		POP(S);
	}
}

void BT18b(){
	Stack S;
	MAKENULL_STACK(S);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '(') PUSH(s[i], S);
		else {
			if (TOP(S) == '(') POP(S);
			else PUSH(s[i], S);
		}
	}
	if (EMPTY_STACK(S)) cout << "RIGHT!";
	else cout << "WRONG!";
}

int main(){
	BT18b();
}
