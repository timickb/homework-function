#include <iostream>
#include <vector>
#include <string>
#include "function.cpp"
using namespace std;

const int STEP = 1;

int main() {
    setlocale(LC_ALL, "Russian");
    string expr;
    int x1, x2;
    cout << "y = ";
    cin >> expr;
    cout << "Start X: ";
    cin >> x1;
    cout << "End X: ";
    cin >> x2;
    cout << "\nPairs:\n";
    for(int x = x1; x <= x2; x++) {
        double y = f(x, expr);
        printf("(%d, %f)\n", x, y);
    }
    cout << "\nIntegral:\n";
    cout << integral(x1, x2, STEP, expr) << endl;
    
}