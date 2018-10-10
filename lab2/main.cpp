#include "figure.h"
#include "iostream"

using namespace std;

int main() {
    Picture pic;
    Triangle a(Point{1, 1}, Point{2, 1}, Point{3, -10});
    Rectangle b(Point{1, 1}, Point{1, 2}, Point{4, 2}, Point{4, 1});
    Circle c(Point{1, 1}, 10.5);
    Trapeze d(Point{1, 1}, Point{2, 2}, Point{3, 2}, Point{4, 1});
    pic.push(&a);
    pic.push(&b);
    pic.push(&c);
    pic.push(&d);
    pic.printTypes();
    pic.printPerimeters();
    pic.printSquares();
    pic.printCenterOfMasss();
}