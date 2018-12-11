#include "datetime.h"
#include "string"
#include "iostream"
#include "algorithm"
#include <iterator>
#include <vector>

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
    Train(const std::string &dest = "", int num = NULL, DateTime dep = DateTime{}, DateTime arr = DateTime{});

    Train(DateTime arr = DateTime{});

    int getNumber() const;

    std::string getDestination() const;

    DateTime getDeparture() const;

    DateTime getArrival() const;
};

bool operator==(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() == TR2.getArrival();
}

bool operator<=(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() <= TR2.getArrival();
}

bool operator>(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() > TR2.getArrival();
}

bool operator>=(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() >= TR2.getArrival();
}

bool operator<(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() < TR2.getArrival();
}


bool operator!=(const Train &TR1, const Train &TR2) {
    return TR1.getArrival() != TR2.getArrival();
}


class TrainsFromVector {
private:
    std::vector<Train> _trains;
    bool inited = false;
public:
    void input(std::istream &inp = std::cin) {
        if (this->inited) {
            throw "Trains was inputted earlier";
        } else {
            int n;
            inp >> n;
            for (int i(0); i < n; ++i) {
                std::string tmp_dest;
                int tmp_num;
                DateTime tmp_dep{}, tmp_arr{};
                inp >> tmp_dest >> tmp_num >> tmp_dep >> tmp_arr;
                Train tmp_tr(tmp_dest, tmp_num, tmp_dep, tmp_arr);
                this->_trains.push_back(tmp_tr);
            }
        }

        this->inited = true;
        std::sort(this->_trains.begin(), this->_trains.end());
    }

    std::vector<Train> getLater(DateTime dt) {
        auto it = this->_trains.begin();
        while (it != this->_trains.end()) {
            if (it->getArrival() >= dt) {
                return std::vector<Train>(it, this->_trains.end());
            }
        }
        return std::vector<Train>();
    }
};


