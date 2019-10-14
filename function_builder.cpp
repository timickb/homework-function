#include <iostream>
#include <vector>
#include <string>
#include "function.cpp"
using namespace std;

int main() {
    string expr;
    int x1, x2;
    cout << "y = ";
    cin >> expr;
    cout << "Start X: ";
    cin >> x1;
    cout << "End X: ";
    cin >> x2;
    for(int x = x1; x <= x2; x++) {
        double y = f(x, expr);
        printf("(%d, %d)\n", x, y);
    }
    
}