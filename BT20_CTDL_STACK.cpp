#include<bits/stdc++.h>

#define MaxLength 100007
#define ff first
#define ss second

using namespace std;

typedef pair<int, int> ElementType;

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
	ElementType T;
	T.ff = S.Elements[S.Top_idx].ff;
	T.ss = S.Elements[S.Top_idx].ss;
	return T;
}

void POP(Stack &S){
	if (!EMPTY_STACK(S)) --S.Top_idx;
}

void PUSH(ElementType X, Stack &S){
	++S.Top_idx;
	S.Elements[S.Top_idx].ff = X.ff;
	S.Elements[S.Top_idx].ss = X.ss;
}

void BT20a(){
    int ans = 0;
	Stack S;
	MAKENULL_STACK(S);
	ElementType N;
	cin >> N.ff >> N.ss;
	PUSH(N, S);
	while (!EMPTY_STACK(S)){
		ElementType T = TOP(S);
		POP(S);
		if (T.ff == 0 || T.ff == N.ss) ans += 1;
		else {
            if (T.ff > 0 && T.ss > 0){
                PUSH(make_pair(T.ff - 1, T.ss - 1), S);
                PUSH(make_pair(T.ff, T.ss - 1), S);
            }
        }
	}
	cout << ans;
}

void BT20b(){
    int ans = 0, n;
	Stack S;
	MAKENULL_STACK(S);
	cin >> n;
	--n;
	PUSH(make_pair(n-1, 0), S);
	PUSH(make_pair(n-2, 0), S);
	while (!EMPTY_STACK(S)){
		ElementType T = TOP(S);
		POP(S);
		if (T.ff == 0 || T.ff == 1) ans += 1;
		else {
            if (T.ff > 1) PUSH(make_pair(T.ff - 2, 0), S);
            if (T.ff > 0) PUSH(make_pair(T.ff - 1, 0), S);
        }
	}
	cout << ans;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

}
