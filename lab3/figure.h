#include <iostream>
#include <vector>
#include <map>
#include <math.h>

const double EPS = 1e-9;

//Структура, описывающая точку на плоскости
struct Point {
    double x, y;
};

//Структура, описывающая линию на плоскости
struct Line {
    Point p1, p2;
    double a, b, c;

    Line(Point a, Point b);

    //Проверка того, что точка на линии
    bool onLine(Point c);

    //Длинна линии
    double getLenght();

    double det(double a, double b, double c, double d);

    //Точка пересечения 2 линий
    Point *cross(Line n);

    //Середина линии
    Point *getCenter();

    //Проверка параллельности двух линий
    bool isParallel(Line n);

    //Проверка эквивалентности двух линийa
    bool isEquivalent(Line n);


};

//Абстрактный класс фигуры
class Figure {
protected:
    std::vector<Point> *points;
public:
    //Функция вычисления площади фигуры
    virtual double getSquare() = 0; // OK

    //Функция вычисления центра масс фигуры
    virtual Point getCenterOfMass() = 0; // OK

    //Функция вычисления периметра фигуры
    virtual double getPerimeter() = 0; // OK

    //Функция возвращающая тип фигуры
    virtual std::string getType(); // OK

    virtual ~Figure(); // OK

    static Figure *create(std::string type, std::vector<Point> *points); // OK

    virtual void move(double x, double y); // OK

    virtual void rotate(double d); // OK

    std::vector<Line> *get_lines(); // OK

    virtual bool isIn(Point p) = 0; // OK

    Point get_point(int index); // OK

    int points_count(); // OK


};

//Класс прямоугольника -- переделать в паралеллограм
class Parallelogram : public Figure {
public:
    double getSquare() override; // OK

    Point getCenterOfMass() override; // OK

    double getPerimeter() override; // OK

    std::string getType() override; // OK

    bool isIn(Point p) override; // OK

    Parallelogram(std::vector<Point> *points); // OK
};

//Класс треугольника
class Triangle : public Figure {
public:
    double getSquare() override;  // OK

    Point getCenterOfMass() override; // OK

    double getPerimeter() override; // OK

    std::string getType() override; // OK

    Triangle(std::vector<Point> *points); // OK

    bool isIn(Point p) override; // OK
};

class Operations {
public:
    double square_compare(Figure *f1, Figure *f2); // OK

    bool isIntersect(Figure *f1, Figure *f2); // OK

    bool isInclude(Figure *f1, Figure *f2); // OK
};