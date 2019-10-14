#include <iostream>
#include <vector>
#include <string>
#include "calculator.cpp"
using namespace std;

void replaceAll(string &s, const string &search, const string &replace) {
    for(size_t pos = 0; ; pos += replace.length()) {
        pos = s.find(search, pos);
        if(pos == string::npos) break;
            s.erase(pos, search.length());
            s.insert(pos, replace);
    }
}

string getType(string value) {
    int max = 0;
    if(value.find('x') != -1) max = 1;
    for(int i = 0; i < value.length(); i++) {
        if(value[i] == '^') break;
    }
}

vector<pair<int, double>> calculateFunction(string value, int l, int r) {
    vector<pair<int, double>> result;
    for(int x = l; x <= r; x++) {
        string cvalue = value;
        replaceAll(cvalue, "x", to_string(x));
        bool crashed;
        double y = calculate(cvalue, crashed);
        if(!crashed)
            result.push_back(make_pair(x, y));
    }
    return result;
}
 
int main() {
    string rawExpression;
    int x1, x2;
    cout << "y = ";
    cin >> rawExpression;
    cout << "Start X: ";
    cin >> x1;
    cout << "End X: ";
    cin >> x2;
    vector<pair<int, double>> result = calculateFunction(rawExpression, x1, x2);
    for(auto v : result) {
        printf("(%d, %d)\n", v.first, v.second);
    }
}