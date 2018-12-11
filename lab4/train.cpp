//
// Created by Антон Донской on 2018-12-10.
//
#include "train.h"

void Train::set(const std::string &dest, int num, DateTime dep, DateTime arr) {
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

int Train::getNumber() {
    return this->_number;
}

std::string Train::getDestination() {
    return this->_destination;
}

DateTime Train::getDeparture() {
    return this->_departure;
}

DateTime Train::getArrival() {
    return this->_arrival;
}
