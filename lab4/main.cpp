//
// Created by Антон Донской on 2018-12-10.
//

#include "train.h"


int main() {
    TrainsFromVector tr1;
    tr1.input();
    std::vector<Train> a = tr1.getLater(DateTime{Date{1, 12, 2018}, Time{12, 0, 0}});
    for (auto i:a) {
        std::cout << i.getNumber() << " " << i.getDestination() << " "
                  << "\n";
    }
    return 0;
}