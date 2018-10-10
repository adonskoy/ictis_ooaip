//
// Created by Антон Донской on 11/09/2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>


struct Pair {
    std::string name;
    int val;

    Pair(std::string n, int v);
};


class Name_pairs {
private:
    std::vector<Pair> arr;
public:

    friend class Iterator;

    void push_back(const Pair &p);

    int size();

};

class Iterator {
    const Name_pairs *np;
    int index;
public:
    explicit Iterator(const Name_pairs *p);

    void next();

    const Pair *operator->();
};


inline void error(const std::string &msg);

class Roman_int {
private:
    int val;

    static int sym_to_int(char c);

    void prepare_digits();

public:
    explicit Roman_int(int i = 0);

    explicit Roman_int(std::string str);

    int as_int() const;

    std::string as_roman() const;

    static int roman_to_int(std::string str);

    static Name_pairs digits;

    friend std::istream &operator>>(std::istream &is, Roman_int &r);

    friend std::ostream &operator<<(std::ostream &os, const Roman_int &r);

    Roman_int &operator+=(const Roman_int &rhs);

    Roman_int &operator-=(const Roman_int &rhs);

    Roman_int &operator*=(const Roman_int &rhs);

    Roman_int &operator/=(const Roman_int &rhs);

    friend Roman_int operator+(const Roman_int &lhs, const Roman_int &rhs);

    friend Roman_int operator-(const Roman_int &lhs, const Roman_int &rhs);

    friend Roman_int operator*(const Roman_int &lhs, const Roman_int &rhs);

    friend Roman_int operator/(const Roman_int &lhs, const Roman_int &rhs);

};


std::istream &operator>>(std::istream &is, Roman_int &r);

std::ostream &operator<<(std::ostream &os, const Roman_int &r);


