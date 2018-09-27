//
// Created by Антон Донской on 11/09/2018.
//

#include "figure.h"


std::string Figure::getType() {
    return "Figure";
}


double Rectangle::getSquare() {
    return Line(this->p1, this->p2).getLenght() * Line(this->p2, this->p3).getLenght();
}

std::string Rectangle::getType() {
    return "Rectangle";
}

double Rectangle::getPerimeter() {
    return (Line(this->p1, this->p2).getLenght() + Line(this->p2, this->p3).getLenght()) * 2;
}

Point Rectangle::getCenterOfMass() {
    Line d1(this->p1, this->p3);
    Line d2(this->p2, this->p4);

    return *d1.cross(d2);
}

Rectangle::Rectangle(Point a, Point b, Point c, Point d) {
    p1 = a;
    p2 = b;
    p3 = c;
    p4 = d;
}


double Line::getLenght() {
    return sqrt(pow(this->p2.x - this->p1.x, 2) + pow(this->p2.y - this->p1.y, 2));
}

Line::Line(Point a, Point b) {
    this->p1 = a;
    this->p2 = b;

    this->a = p2.y - p1.y;
    this->b = -(p2.x - p1.x);
    this->c = -p1.x * (p2.y - p1.y) + p1.y * (p2.x - p1.x);
}

bool Line::onLine(Point c) {
    return (std::min(this->p1.x, this->p2.x) <= c.x + EPS && c.x <= std::max(this->p1.x, this->p2.x) + EPS) &&
           (std::min(this->p1.y, this->p2.y) <= c.y + EPS && c.y <= std::max(this->p1.y, this->p2.y) + EPS);
}

double Line::det(double a, double b, double c, double d) {
    return a * d - b * c;
}

Point *Line::cross(Line n) {
    auto res = new Point;
    double zn = det(this->a, this->b, n.a, n.b);
    if (abs(zn) < EPS)
        return nullptr;
    res->x = -det(this->c, this->b, n.c, n.b) / zn;
    res->y = -det(this->a, this->c, n.a, n.c) / zn;
    if (this->onLine(*res) && n.onLine(*res)) {
        return res;
    } else {
        return nullptr;
    }
}

bool Line::isParallel(Line n) {
    return abs(det(this->a, this->b, n.a, n.b)) < EPS;
}

bool Line::isEquivalent(Line n) {
    return abs(det(this->a, this->b, n.a, n.b)) < EPS
           && abs(det(this->a, this->c, n.a, n.c)) < EPS
           && abs(det(this->b, this->c, n.b, n.c)) < EPS;
}

Point *Line::getCenter() {
    auto res = new Point;
    res->x = (this->p1.x + this->p2.x) / 2;
    res->y = (this->p1.y + this->p2.y) / 2;
    return res;
}


double Circle::getSquare() {
    return M_PI * (this->radius) * (this->radius);
}

double Circle::getPerimeter() {
    return 2 * M_PI * (this->radius);
}

Point Circle::getCenterOfMass() {
    return this->center;
}

std::string Circle::getType() {
    return "Circle";
}

double Triangle::getSquare() {
    return (1. / 2) * abs(
            (this->p1.x - this->p3.x) * (this->p2.y - this->p3.y)
            - (this->p2.x - this->p3.x) * (this->p1.y - this->p3.y)
    );
}

double Triangle::getPerimeter() {
    return (
            Line(p1, p2).getLenght() +
            Line(p1, p3).getLenght() +
            Line(p2, p3).getLenght()
    );

}

Point Triangle::getCenterOfMass() {
    return Point{
            (this->p1.x + this->p2.x + this->p3.x) / 3,
            (this->p1.y + this->p2.y + this->p3.y) / 3
    };
}

std::string Triangle::getType() {
    return "Triangle";
}

Triangle::Triangle(Point a, Point b, Point c) {
    p1 = a;
    p2 = b;
    p3 = c;
}

double Trapeze::getSquare() {
    Triangle a(this->p1, this->p2, this->p3);
    Triangle b(this->p1, this->p4, this->p3);
    return a.getSquare() + b.getSquare();
}

double Trapeze::getPerimeter() {
    return (
            Line(p1, p2).getLenght() +
            Line(p4, p3).getLenght() +
            Line(p4, p1).getLenght() +
            Line(p2, p3).getLenght()
    );

}

Point Trapeze::getCenterOfMass() {
    Line a(this->p2, this->p3);
    Line b(this->p1, this->p4);
    Line center(*a.getCenter(), *b.getCenter());


    double h = abs(b.p1.y - a.p1.y);
    double y = h / 3 * ((2 * b.getLenght() + a.getLenght()) / (b.getLenght() + a.getLenght()));
    Point aa = *a.getCenter();
    aa.x -= 1;
    aa.y = this->p2.y - y;
    Point ab = *a.getCenter();
    ab.x += 1;
    ab.y = this->p2.y - y;
    Line second(aa, ab);
    return *center.cross(second);


}

std::string Trapeze::getType() {
    return "Trapeze";
}

Trapeze::Trapeze(Point a, Point b, Point c, Point d) {
    p1 = a;
    p2 = b;
    p3 = c;
    p4 = d;
}

void Picture::push(Figure *ob) {

    this->arrr.push_back(ob);
}

void Picture::print() {

    for (const auto &i:this->arrr) {
        std::cout << i->getType() << " ";
    }
    std::cout << "\n";
}

double Picture::getSquare() {
    return 0;
}

Point Picture::getCenterOfMass() {
    return Point();
}

double Picture::getPerimeter() {
    return 0;
}
