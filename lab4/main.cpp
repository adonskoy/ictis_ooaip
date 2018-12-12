#include "train.h"

int from_vector(std::fstream &fs, DateTime later_t) {

    TrainsFromVector tr1;
    tr1.input(fs);

    auto a = tr1.getLater(later_t);

    for (auto i:a) {
        std::cout << i.getNumber() << " " << i.getDestination() << " "
                  << "\n";
    }

    return 0;
}


int from_map(std::fstream &fs, DateTime later_t) {

    TrainsFromMap tr1;
    tr1.input(fs);

    auto a = tr1.getLater(later_t);

    for (auto i:a) {
        std::cout << i.second.getNumber() << " " << i.second.getDestination() << " "
                  << "\n";
    }

    return 0;
}

int main() {
    int n;
    std::string filename;
    DateTime later_t;

    std::cin >> n >> filename >> later_t;

    std::fstream fs;
    fs.open(filename, std::fstream::in);

    if (n == 1) {
        from_vector(fs, later_t);
    } else if (n == 2) {
        from_map(fs, later_t);
    } else {
        return 1;
    }
    return 0;
}

