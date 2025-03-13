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

    ~PolynomialMember() {
        delete position;
        delete[] constants;
        delete members;
    }

    ConstantMember setVariable(int64_t base, int64_t exponent) {
    }

private:
    uint16_t* position;
    ConstantMember* constants;
    uint16_t* members;
};

struct ConstantMember {
public:
    ConstantMember(uint16_t position)
        : position(new uint16_t(position)) {
    }
    ConstantMember(string constant_expression, uint16_t position)
        : position(new uint16_t(position)) {
    }

    ~ConstantMember() {
        delete position;
        delete base;
        delete exponent;
    }

    ConstantMember operator+(const ConstantMember& other) {
        ConstantMember result{*this->position};
        if (*this->exponent > *other.exponent) {
            result.base = new int64_t(*this->base);
            *result.base *= pow(10, *this->exponent - *other.exponent);
            *result.base += *other.base;
            result.exponent = new int64_t(*other.exponent);
            return result;
        } else {
            result.base = new int64_t(*other.base);
            *result.base *= pow(10, *other.exponent - *this->exponent);
        }
    }

private:
    uint16_t* position;
    int64_t* base;
    int64_t* exponent;
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