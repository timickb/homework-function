#include <iostream>
#include "calculator.cpp"
#include "utils.cpp"

double f(double x, string expr) {
    replaceAll(expr, "x", to_string(x));
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