#ifndef NEWTON
#define NEWTON
#include <cstdint>
#include "Differentiation.hpp"

class Newton {
public:
    Newton(char* expression, size_t expression_size)
        : expression(expression, new size_t(expression_size)), differentiation(expression, expression_size) {
        expression_derivative = differentiation.find_derivative(string(new char('x'), new size_t(1)));
    };
    Newton(char* expression, size_t expression_size, char* variable, size_t variable_size)
        : expression(expression, new size_t(expression_size)), differentiation(expression, expression_size) {
        expression_derivative = differentiation.find_derivative(string(variable, new size_t(variable_size)));
    };
    Newton(string expression)
        : expression(expression), differentiation(expression) {
        expression_derivative = differentiation.find_derivative(string(new char('x'), new size_t(1)));
    }
    Newton(string expression, string variable)
        : expression(expression), differentiation(expression) {
        expression_derivative = differentiation.find_derivative(variable);
    }
    ~Newton() {
        delete[] expression.str;
        delete expression._size;
        delete[] expression_derivative.str;
        delete expression_derivative._size;
    }

    int32_t find_variable(uint32_t itteration_times);

    inline string& get_expression() { return expression; }
    inline string& get_expression_derivative() { return expression_derivative; }

private:
    Differentiation differentiation;
    string variable;
    string expression;
    string expression_derivative;
};

#endif