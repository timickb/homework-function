#include <iostream>
#include "calculator.cpp"
using namespace std;

int main() {
    string s;
    cin >> s;
    bool flag;
    double result = calculate(s, flag);
    if(!flag) cout << result << endl;
    else cout << "Error" << endl;
}