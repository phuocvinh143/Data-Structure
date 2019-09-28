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

int main(){
    BT4a();
    BT4b();
}
