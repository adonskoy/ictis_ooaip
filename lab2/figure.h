//
// Created by Антон Донской on 27/09/2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <math.h>
#include <vector>
#include <algorithm>


const double EPS = 1e-9;


struct Point {
    double x, y;
};

struct Line {
    Point p1, p2;
    double a, b, c;

    Line(Point a, Point b);

    bool onLine(Point c);

    double getLenght();


    double det(double a, double b, double c, double d);

    Point *cross(Line n);

    Point *getCenter();


    bool isParallel(Line n);

    bool isEquivalent(Line n);

};

class Figure {
public:
    virtual double getSquare() = 0;

    virtual Point getCenterOfMass() = 0;

    virtual double getPerimeter() = 0;

    virtual std::string getType();

    virtual ~Figure() = default;;

};

class Rectangle : public Figure {
private:
    Point p1, p2, p3, p4;
public:
    double getSquare() override;

    Point getCenterOfMass() override;

    double getPerimeter() override;

    std::string getType() override;

    Rectangle(Point a, Point b, Point c, Point d);


};


class Triangle : public Figure {
private:
    Point p1, p2, p3;
public:
    double getSquare() override;

    Point getCenterOfMass() override;

    double getPerimeter() override;

    std::string getType() override;

    Triangle(Point a, Point b, Point c);


};

class Circle : public Figure {
private:
    Point center;
    double radius;
public:
    double getSquare() override;

    Point getCenterOfMass() override;

    double getPerimeter() override;

    std::string getType() override;

};

class Trapeze : public Figure {
private:
    Point p1, p2, p3, p4;
public:
    double getSquare() override;

    Point getCenterOfMass() override;

    double getPerimeter() override;

    std::string getType() override;

    Trapeze(Point a, Point b, Point c, Point d);

};

class Picture : public Figure {
private:
    std::vector<Figure *> arrr;
public:
    double getSquare() override;

    Point getCenterOfMass() override;

    double getPerimeter() override;

    void push(Figure *ob);

    void print();

};
