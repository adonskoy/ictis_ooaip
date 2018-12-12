#include "train.h"

Train::Train(std::string dest, int num, DateTime dep, DateTime arr) {
    if (!dest.empty()) {
        this->_destination = dest;
    }

    if (num != 0) {
        this->_number = num;
    }

    if (dep != DateTime{}) {
        this->_departure = dep;
    }

    if (arr != DateTime{}) {
        this->_arrival = arr;
    }

    if (dep >= arr) {
        throw "wrong data";
    }
}

int Train::getNumber() const {
    return this->_number;
}

std::string Train::getDestination() const {
    return this->_destination;
}

DateTime Train::getDeparture() const {
    return this->_departure;
}

DateTime Train::getArrival() const {
    return this->_arrival;
}

void TrainsFromVector::input(std::istream &inp) {
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

std::vector<Train> TrainsFromVector::getLater(DateTime dt) {
    auto it = this->_trains.begin();
    while (it != this->_trains.end()) {
        if (it->getArrival() >= dt) {
            return std::vector<Train>(it, this->_trains.end());
        }
        it++;
    }
    return std::vector<Train>();
}

void TrainsFromMap::input(std::istream &inp) {
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
            this->_trains.insert(std::pair<DateTime, Train>(tmp_arr, tmp_tr));
        }
    }

    this->inited = true;
}

std::multimap<DateTime, Train> TrainsFromMap::getLater(DateTime dt) {
    auto first = this->_trains.lower_bound(dt);
    std::multimap<DateTime, Train> result(first, this->_trains.end());
    return result;
}
