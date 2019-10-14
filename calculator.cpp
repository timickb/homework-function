#include <iostream>
#include <stack>
#include <string>
using namespace std;

int mypow(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b % 2 == 0) return mypow(a, b/2) * mypow(a, b/2);
    else return mypow(a, (b-1)/2) * mypow(a, (b-1)/2) * a;
    return 0;
}

void makeOperation(stack<double>& nums, char op) {
    if(nums.size() == 1) return;
    int b = nums.top(); nums.pop();
    int a = nums.top(); nums.pop();
    switch(op) {
        case '+': nums.push(a+b); break;
        case '-': nums.push(a-b); break;
        case '*': nums.push(a*b); break;
        case '/': nums.push((double)a/(double)b); break;
        case '^': nums.push(mypow(a, b)); break;
    }
}

bool isOperation(char op) {
    return op == '-' || op == '+' || op == '*' || op == '/' || op == '^';
}

int priority(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 4;
}

double calculate(string s, bool& crash) {
    s = "(" + s + ")";
    stack<double> nums;
    stack<char> ops;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') ops.push('(');
        else if(s[i] == ')') {
            while(ops.top() != '(') {
                makeOperation(nums, ops.top());
                ops.pop();
            }
            ops.pop();
        } else if(s[i] == '/' && s[i+1] == '0') {
            crash = true;
            return 0;
        } else if(isOperation(s[i]) && (isdigit(s[i-1]) || s[i-1] == ')')) { 
            while(true) {
                if(priority(ops.top()) < priority(s[i]) || ops.top() == '(' || ops.empty()) {
                    ops.push(s[i]);
                    break;
                } else {
                    makeOperation(nums, ops.top());
                    ops.pop();
                }
            }
        } else if(isdigit(s[i]) || s[i] == '-') {
            string number = "";
            if(s[i] == '-') {
                number = "-";
                i++;
            }
            for(int j = i; true; j++) {
                if(isdigit(s[j])) number += s[j];
                else {
                    i = j-1;
                    break;
                }
            }
            nums.push(stoi(number));
        }
    }
    while(!ops.empty()) {
        makeOperation(nums,ops.top());
        ops.pop();
    }
    return nums.top();
}

/*int main() {
    string s;
    cin >> s;
    cout << calculate(s) << endl;
}*/
