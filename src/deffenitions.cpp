#include "deffenitions.hpp"

void Expression::readExpression(string expresion) {
    while (true) {
        for (size_t i = 0, shift = 1, erase = 0; i < expresion.size(); i += shift) {
            switch (expresion[i]) {
            case ' ':
                erase = 1;
                goto default_skip;
            case '\\':
                if (i + 1 >= expresion.size()) {
                    erase = 1;
                    goto wrong_operator_skip;
                }
                switch (expresion[i + 1]) {
                case 'f':

                    break;
                case 's':
                    if (i + 2 >= expresion.size()) {
                        erase = 2;
                        goto wrong_operator_skip;
                    }

                    switch (expresion[i + 2]) {
                    case 'q':
                        if (i + 3 >= expresion.size()) {
                            erase = 3;
                            goto wrong_operator_skip;
                        }

                        switch (expresion[i + 3]) {
                        case 'r':
                            if (i + 4 >= expresion.size()) {
                                erase = 4;
                                goto wrong_operator_skip;
                            }

                            switch (expresion[i + 4]) {
                            case 't':
                                if (i + 5 >= expresion.size()) {
                                    erase = 5;
                                    goto wrong_operator_skip;
                                }
                                if (expresion[i + 5] == ' ') {
                                } else {
                                }
                                break;

                            default:
                                erase = 4;
                                goto wrong_operator_skip;
                                break;
                            }
                            break;

                        default:
                            erase = 3;
                            goto wrong_operator_skip;
                            break;
                        }
                        break;
                    case 'u':

                    default:
                        erase = 2;
                        goto wrong_operator_skip;
                        break;
                    }
                    break;
                default:
                    erase = 1;
                    goto wrong_operator_skip;
                    break;
                }
                break;
            default:
            wrong_operator_skip:
                for (uint8_t j = 0; i < erase; j++) {
                    expresion.erase(i - j);
                }
                erase = 0;
            default_skip:
                if (expresion.size() == 0) {
                    goto exit;
                }
                break;
            }
        }
    }
exit:
}

inline void string::erase(size_t index) {
    for (size_t i = index; i < *this->_size - 1; i++) {
        this->str[i] = this->str[i + 1];
    }
    *this->_size -= 1;
}

inline string string::operator+(const string& other) {
    string result;

    result._size = new size_t(*this->_size + *other._size);
    result.str = new char[*result._size];
    for (size_t i = 0; i < *this->_size; i++) {
        result.str[i] = this->str[i];
    }
    for (size_t i = *this->_size; i < *other._size; i++) {
        result.str[i] = other.str[i];
    }
    return result;
}

string string::operator=(const string& other) {
    this->str = other.str;
    this->_size = other._size;
    return *this;
}