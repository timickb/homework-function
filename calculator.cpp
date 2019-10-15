#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;

void makeOperation(stack<double>& nums, char op) {
    if(nums.size() == 1) return;
    double b = nums.top(); nums.pop();
    double a = nums.top(); nums.pop();
    switch(op) {
        case '+': nums.push(a+b); break;
        case '-': nums.push(a-b); break;
        case '*': nums.push(a*b); break;
        case '/': nums.push(a/b); break;
        case '^': nums.push(powl(a, b)); break;
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
    if(!isdigit(s[0]) && s[0] != '(' && s[0] != '-') {
        crash = true;
        return 0;
    }
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
        } else if(isdigit(s[i]) || s[i] == '-' || s[i] == '.') {
            string number = "";
            if(s[i] == '-') {
                number = "-";
                i++;
            }
            for(int j = i; true; j++) {
                if(isdigit(s[j]) || s[j] == '.') number += s[j];
                else {
                    i = j-1;
                    break;
                }
            }
            nums.push(stod(number));
        }
    }
    while(!ops.empty()) {
        makeOperation(nums,ops.top());
        ops.pop();
    }
    return nums.top();
}