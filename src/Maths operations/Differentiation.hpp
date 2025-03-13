#ifndef DIFFERENTION
#define DIFFERENTION
#include "deffenitions.hpp"

class Differentiation {
public:
    Differentiation(char* expression, size_t expression_size)
        : expression({expression, new size_t(expression_size)}) {
    }
    Differentiation(string expression)
        : expression(expression) {
    }
    ~Differentiation() {
        delete[] expression.str;
        delete expression._size;
    }
    // Taking derivative
    string find_derivative(string variable);
    // Taking integral
    string find_integral(string variable);

private:
    string expression;
};

#endif