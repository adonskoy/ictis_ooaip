//
// Created by Антон Донской on 11/09/2018.
//


//  Создать класс Figure.
//      На его основе реализовать классы
//          Rectangle (прямоугольник), DONE
//          Circle (круг) DONE
//          Trapeze (тра-пеция)
//          Tringle(extra)
//      с возможностью вычисления площади, центра тяжести и периметра.
//      Дополнительный класс – Picture(массив фигур).

#include "figure.h"
#include "iostream"
using namespace std;

int main() {
    Point a{1, 1};
    Point b{2, 3};
    Point c{4, 3};
    Point d{5, 1};
    Trapeze tr(a, b, c, d);
    auto p = tr.getCenterOfMass();
    cout << p.x << " " << p.y;

}