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

vector<pair<int, int>> calculateFunction(string value, int l, int r) {
    vector<pair<int, int>> result;

    for(int x = l; x <= r; x++) {
        string cvalue = value;
        replaceAll(cvalue, "x", to_string(x));
        int y = calculate(cvalue);
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
    vector<pair<int, int>> result = calculateFunction(rawExpression, x1, x2);
    for(auto v : result) {
        printf("(%d, %d)\n", v.first, v.second);
    }
}