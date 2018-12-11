#include "datetime.h"
#include "string"
#include "iostream"

class Train {
private:
    std::string _destination;
    int _number;
    DateTime _departure;
    DateTime _arrival;
public:
    void set(const std::string &dest = "", int num = NULL, DateTime dep = DateTime{}, DateTime arr = DateTime{});

    int getNumber();

    std::string getDestination();

    DateTime getDeparture();

    DateTime getArrival();
};

bool operator<(Train &a, Train &b) {
    return a.getArrival() < b.getArrival();
}


class TrainsFromVector {
private:
    std::vector<Train> _trains;
    bool inited = false;
public:
    void input() {
        if (this->inited) {
            throw "Trains was inputted earlier";
        } else {
            int n;
            std::cin >> n;
            for (int i(0); i < n; ++i) {
                //....
            }
        }
    }

    std::vector<Train> getLater(DateTime dt) {
        std::vector<Train> result;
        for (auto train:this->_trains) {
            if(train.getArrival()>=dt){


            }
        }
    }


};