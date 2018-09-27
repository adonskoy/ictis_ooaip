#include "roman.h"

Pair::Pair(string n, int v) {
    name = std::move(n);
    val = v;
}

Iterator::Iterator(const Name_pairs *p) {
    np = p;
    index = 0;
}

void Iterator::next() {
    index += 1;
}

const Pair *Iterator::operator->() {
    return &(np->arr[index]);
}

void Name_pairs::push_back(const Pair &p) {
    arr.push_back(p);
}

int Name_pairs::size() {
    return (int) arr.size();
}

std::istream &operator>>(std::istream &is, Roman_int &r) {
    string buf;
    is >> buf;
    buf.push_back('0');
    for (int i = (int) buf.size() - 2; i >= 0; --i) {
        if (
                (
                        (
                                Roman_int::sym_to_int(buf[i - 1]) < Roman_int::sym_to_int(buf[i])
                        ) &&
                        (
                                Roman_int::sym_to_int(buf[i - 2]) < Roman_int::sym_to_int(buf[i])
                        ) &&
                        (
                                i > 1
                        )
                )
                ||
                (
                        (
                                Roman_int::sym_to_int(buf[i - 1]) >= Roman_int::sym_to_int(buf[i])
                        ) &&
                        (
                                Roman_int::sym_to_int(buf[i - 2]) < Roman_int::sym_to_int(buf[i])
                        ) &&
                        (
                                i > 1
                        )
                )
                ||
                (
                        (i > 2) &&
                        (
                                Roman_int::sym_to_int(buf[i]) ==
                                Roman_int::sym_to_int(buf[i - 1]) ==
                                Roman_int::sym_to_int(buf[i - 2]) ==
                                Roman_int::sym_to_int(buf[i - 3])
                        )
                )
                ) {

            error("Wrong representation");
        }
        switch (buf[i]) {
            case '-': {
                r.val *= -1;
                break;
            }

            default: {
                if (Roman_int::sym_to_int(buf[i]) < Roman_int::sym_to_int(buf[i + 1])) {
                    r.val -= Roman_int::sym_to_int(buf[i]);
                } else {
                    r.val += Roman_int::sym_to_int(buf[i]);
                }
            }
        }
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Roman_int &r) {
    os << r.as_roman();
    return os;
}


int Roman_int::sym_to_int(char c) {
    switch (c) {
        case '0' :
            return 0;
        case 'I' :
            return 1;
        case 'V' :
            return 5;
        case 'X' :
            return 10;
        case 'L' :
            return 50;
        case 'C' :
            return 100;
        case 'D' :
            return 500;
        case 'M' :
            return 1000;
        default :
            return -1;

    }

}

Roman_int::Roman_int(int i) : val(i) {
    if (!digits.size()) {
        digits.push_back(Pair("M", 1000));
        digits.push_back(Pair("CM", 900));
        digits.push_back(Pair("D", 500));
        digits.push_back(Pair("CD", 400));
        digits.push_back(Pair("C", 100));
        digits.push_back(Pair("XC", 90));
        digits.push_back(Pair("L", 50));
        digits.push_back(Pair("XL", 40));
        digits.push_back(Pair("X", 10));
        digits.push_back(Pair("IX", 9));
        digits.push_back(Pair("V", 5));
        digits.push_back(Pair("IV", 4));
        digits.push_back(Pair("I", 1));
    }

}

int Roman_int::as_int() const { return val; }

string Roman_int::as_roman() const {
    string os;
    int val = this->val;
    Iterator digit(&Roman_int::digits);
    if (this->val < 0) {
        os += '-';
        val *= -1;
    }
    while (val > 0) {
        if (val >= digit->val) {
            val -= digit->val;
            os += digit->name;
        } else {
            digit.next();
        }
    }
    return os;
}

Roman_int &Roman_int::operator+=(const Roman_int &rhs) {
    this->val += rhs.val;
    return *this;
}

Roman_int &Roman_int::operator-=(const Roman_int &rhs) {
    this->val -= rhs.val;
    return *this;
}

Roman_int &Roman_int::operator*=(const Roman_int &rhs) {
    this->val *= rhs.val;
    return *this;
}

Roman_int &Roman_int::operator/=(const Roman_int &rhs) {
    this->val /= rhs.val;
    return *this;
}

Roman_int operator+(const Roman_int &lhs, const Roman_int &rhs) {
    return Roman_int(lhs.val + rhs.val);
}

Roman_int operator-(const Roman_int &lhs, const Roman_int &rhs) {
    return Roman_int(lhs.val - rhs.val);
}

Roman_int operator*(const Roman_int &lhs, const Roman_int &rhs) {
    return Roman_int(lhs.val * rhs.val);
}

Roman_int operator/(const Roman_int &lhs, const Roman_int &rhs) {
    return Roman_int(lhs.val / rhs.val);
}

void error(const string &msg) {
    throw runtime_error(msg);
}
