#include "datetime.h"
#include "string"
#include "iostream"
#include "algorithm"
#include <iterator>
#include <vector>
#include <map>

#ifndef LAB_3_TRAIN_H
#define LAB_3_TRAIN_H

#endif //LAB_3_TRAIN_H

class Train {
private:
    std::string _destination;
    int _number;
    DateTime _departure;
    DateTime _arrival;
public:
    Train(std::string dest = "", int num = NULL, DateTime dep = DateTime{}, DateTime arr = DateTime{});

    int getNumber() const;

    std::string getDestination() const;

    DateTime getDeparture() const;

    DateTime getArrival() const;
};

static bool operator==(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() == TR2.getArrival();
}

static bool operator<=(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() <= TR2.getArrival();
}

static bool operator>(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() > TR2.getArrival();
}

static bool operator>=(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() >= TR2.getArrival();
}

static bool operator<(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() < TR2.getArrival();
}


static bool operator!=(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() != TR2.getArrival();
}


class TrainsFromVector {
private:
    std::vector<Train> _trains;
    bool inited = false;
public:
    void input(std::istream &inp = std::cin);

    std::vector<Train> getLater(DateTime dt);
};




class TrainsFromMap {
private:
    std::multimap<DateTime, Train> _trains;
    bool inited = false;
public:
    void input(std::istream &inp = std::cin);

    std::multimap<DateTime, Train> getLater(DateTime dt);
};
