#include <iostream>
#include "calculator.cpp"

double f(double x, string expr) {
    
    string replace = to_string(x);
    string search = "x";
    for(size_t pos = 0; ; pos += replace.length()) {
        pos = expr.find(search, pos);
        if(pos == string::npos) break;
            expr.erase(pos, search.length());
            expr.insert(pos, replace);
    }
    bool crashed;
    double y = calculate(expr, crashed);
    return y;
}

double integral(double x1, double x2, double step, string expr) {
    double result;
    double n = (x2-x1)/step;
    result = 0.0;
    for(int i = 1; i <= n; i++) {
        result = result + step * f(x1+step*(i-0.5), expr);    
    }
    return result;
}