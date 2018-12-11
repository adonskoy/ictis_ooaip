//
// Created by Антон Донской on 2018-12-10.
//
#include "train.h"

Train::Train(const std::string &dest, int num, DateTime dep, DateTime arr) {
    if (!dest.empty()) {
        this->_destination = dest;
    }

    if (num != NULL) {
        this->_number = num;
    }

    if (dep != DateTime{}) {
        this->_departure = dep;
    }

    if (arr != DateTime{}) {
        this->_arrival = arr;
    }

    if (dep <= arr) {
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

Train::Train(DateTime arr) {
    if (arr != DateTime{}) {
        this->_arrival = arr;
    }
}
