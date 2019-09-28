#include<bits/stdc++.h>

using namespace std;

int to_int(string s, int l, int r) {
    int num = 0;
    for (int i = l; i < r; ++i) {
        num = num*10 + (s[i] - '0');
    }
    return num;
}

void BT4a() {
    string data1, data = "";
    stack<int> number;
    getline(cin, data1);
    for (int i = data1.size()-1; i >= 0; --i) {
        data += data1[i];
    }
    data += " ";
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] >= '0' && data[i] <= '9') {
            int tmp = i;
            while (data[tmp] != ' ') ++tmp;
            number.push(to_int(data, i, tmp));
            i = tmp;
        }
        else {
            if (data[i] != ' ') {
                switch (data[i]) {
                    case '+':{
                        int n1 = number.top();
                        number.pop();
                        int n2 = number.top();
                        number.pop();
                        number.push(n1 + n2);
                        break;
                    }
                    case '-':{
                        int n1 = number.top();
                        number.pop();
                        int n2 = number.top();
                        number.pop();
                        number.push(n1 - n2);
                        break;
                    }
                    case '*':{
                        int n1 = number.top();
                        number.pop();
                        int n2 = number.top();
                        number.pop();
                        number.push(n1 * n2);
                        break;
                    }
                    case '/':{
                        int n1 = number.top();
                        number.pop();
                        int n2 = number.top();
                        number.pop();
                        number.push(n1 / n2);
                        break;
                    }
                }
            }
        }
    }
    cout << number.top() << endl;
}

void BT4b(){
    string data;
    stack<int> number;
    getline(cin, data);
    data += " ";
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] >= '0' && data[i] <= '9') {
            int tmp = i;
            while (data[tmp] != ' ') ++tmp;
            number.push(to_int(data, i, tmp));
            i = tmp;
        }
        else {
            if (data[i] != ' ') {
                switch (data[i]) {
                    case '+':{
                        int n1 = number.top();
                        number.pop();
                        int n2 = number.top();
                        number.pop();
                        number.push(n1 + n2);
                        break;
                    }
                    case '-':{
                        int n1 = number.top();
                        number.pop();
                        int n2 = number.top();
                        number.pop();
                        number.push(n1 - n2);
                        break;
                    }
                    case '*':{
                        int n1 = number.top();
                        number.pop();
                        int n2 = number.top();
                        number.pop();
                        number.push(n1 * n2);
                        break;
                    }
                    case '/':{
                        int n1 = number.top();
                        number.pop();
                        int n2 = number.top();
                        number.pop();
                        number.push(n1 / n2);
                        break;
                    }
                }
            }
        }
    }
    cout << number.top() << endl;
}

int difference(char a, char b) {
    int n1, n2;
    if (a == '*' || a == '/') n1 = 1;
    else n1 = 0;
    if (b == '*' || b == '/') n2 = 1;
    else n2 = 0;
    return n1 - n2;
}

void InOrder2PosOrder(){
    string s;
    cin >> s;
    queue<char> ans;
    stack<char> op;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') ans.push(s[i]);
        else {
            if (s[i] == '(') {
                op.push(s[i]);
            }
            else {
                if (s[i] == ')') {
                    while (!op.empty()) {
                        if (op.top() != '(') ans.push(op.top());
                        op.pop();
                        if (!op.empty() && op.top() == '(') {
                            op.pop();
                            break;
                        }
                    }
                }
                else {
                    if (!op.empty()){
                        if (op.top() == '(') {
                            op.push(s[i]);
                            continue;
                        }
                        if (difference(s[i], op.top()) <= 0) {
                            ans.push(op.top());
                            op.pop();
                            while (!op.empty()) {
                                if (op.top() == '(') break;
                                if (difference(s[i], op.top()) > 0) break;
                                ans.push(op.top());
                                op.pop();
                            }
                            op.push(s[i]);
                        }
                        else op.push(s[i]);
                    }
                    else {
                        op.push(s[i]);
                    }
                }
            }
        }
    }
    while (!op.empty()) {
        if (op.top() != '(') ans.push(op.top());
        op.pop();
    }
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    InOrder2PosOrder();
}
