#include "figure.h"
#include "iostream"

using namespace std;

int main() {
    std::vector<Point> tr_points = {

            Point{1, 1},
            Point{2, 4},
            Point{3, 1}
    };
    std::vector<Point> pr_points = {
            Point{1, 1},
            Point{1, 4},
            Point{3, 4},
            Point{3, 1}
    };
    auto tr = Figure::create("triangle", &tr_points);
    auto pr = Figure::create("parallelogram", &pr_points);
    std::cout << tr->getType() << "\n";
    std::cout << tr->getSquare() << "\n";
    std::cout << pr->getType() << "\n";
    std::cout << pr->getSquare() << "\n";
}