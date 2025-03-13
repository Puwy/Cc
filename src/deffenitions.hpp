#ifndef DEFFENITIONS
#define DEFFENITIONS
#include <cmath>

struct string {
public:
    inline char& operator[](size_t index) {
        return str[index];
    }

    inline const size_t& size() const {
        return *this->_size;
    }

    inline void erase(size_t index);

    inline string operator+(const string& other);

    inline string operator=(const string& other);

private:
    char* str;
    size_t* _size;
};

struct PolynomialMember {
public:
    PolynomialMember(string polynomial_expression, uint16_t position)
        : position(new uint16_t(position)) {
    }

private:
    uint16_t* position;
    ConstantMember* constants;
    uint16_t* members;
};

struct ConstantMember {
public:
    ConstantMember(string constant_expression, uint16_t position)
        : position(new uint16_t(position)) {
    }

private:
    uint16_t* position;
    uint64_t* base;
    uint64_t* exponent;
};

class Expression {
public:
    Expression(string expression) {
        readExpression(expression);
    }
    ~Expression() {
        delete[] constants;
        delete[] polynomials;
    }

private:
    ConstantMember* constants;

    PolynomialMember* polynomials;

    void readExpression(string expresion);
};

#endif