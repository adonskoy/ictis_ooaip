#include "figure.h"

std::string Figure::getType() {
    return "Figure";
}

Figure *Figure::create(std::string type, std::vector<Point> *points) {
    Figure *figure = nullptr;
    if (type == "triangle") {
        figure = new Triangle(points);
    } else if (type == "parallelogram") {
        figure = new Parallelogram(points);
    }
    return figure;
}

Figure::~Figure() {
    if (this->points) {
        points->clear();
    }
}

void Figure::move(double x, double y) {
    for (auto point: *(this->points)) {
        point.x += x;
        point.y += y;
    }
}

void Figure::rotate(double d) {
    for (auto point: *(this->points)) {
        point.x = point.x * cos(d) - point.y * sin(d);
        point.y += point.x * sin(d) + point.y * cos(d);
    }
}

std::vector<Line> *Figure::get_lines() {
    std::vector<Line> *lines = new std::vector<Line>;
    for (int i(0); i < (lines->size() - 1); ++i) {
        lines->push_back(Line(this->points->at(i), this->points->at(i + 1)));
    }
    return lines;
}

Point Figure::get_point(int index) {
    return this->points->at(index);
}

int Figure::points_count() {
    return static_cast<int>(this->points->size());
}

double Parallelogram::getSquare() {
    std::vector<Point> t1 = {this->points->at(0), this->points->at(1), this->points->at(2)};
    std::vector<Point> t2 = {this->points->at(2), this->points->at(3), this->points->at(0)};
    auto *tt1 = new Triangle(&t1);
    auto *tt2 = new Triangle(&t2);
    return tt1->getSquare() + tt2->getSquare();
}

std::string Parallelogram::getType() {
    return "Parallelogram";
}

double Parallelogram::getPerimeter() {
    return (Line(this->points->at(0), this->points->at(1)).getLenght() +
            Line(this->points->at(1), this->points->at(2)).getLenght()) * 2;
}

Point Parallelogram::getCenterOfMass() {
    Line d1(this->points->at(0), this->points->at(2));
    Line d2(this->points->at(1), this->points->at(3));

    return *d1.cross(d2);
}

Parallelogram::Parallelogram(std::vector<Point> *points) {
    if (points->size() == 4) {
        this->points = points;
    } else {
        throw "should be 4 points";
    }
}

bool Parallelogram::isIn(Point p) {
    std::vector<Point> t1 = {this->points->at(0), this->points->at(1), this->points->at(2)};
    std::vector<Point> t2 = {this->points->at(2), this->points->at(3), this->points->at(0)};
    auto *tt1 = new Triangle(&t1);
    auto *tt2 = new Triangle(&t2);
    return tt1->isIn(p) || tt2->isIn(p);
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


double Triangle::getSquare() {
    return (1. / 2) * abs(
            (this->points->at(0).x - this->points->at(2).x) * (this->points->at(1).y - this->points->at(2).y)
            - (this->points->at(1).x - this->points->at(2).x) * (this->points->at(0).y - this->points->at(2).y)
    );
}

double Triangle::getPerimeter() {
    return (
            Line(this->points->at(0), this->points->at(1)).getLenght() +
            Line(this->points->at(0), this->points->at(2)).getLenght() +
            Line(this->points->at(1), this->points->at(2)).getLenght()
    );
}

Point Triangle::getCenterOfMass() {
    return Point{
            (this->points->at(0).x + this->points->at(1).x + this->points->at(2).x) / 3,
            (this->points->at(0).y + this->points->at(1).y + this->points->at(2).y) / 3
    };
}

std::string Triangle::getType() {
    return "Triangle";
}


Triangle::Triangle(std::vector<Point> *points) {
    if (points->size() == 3) {
        this->points = points;
    } else {
        throw "Should be 3 points";
    }
}

bool Triangle::isIn(Point p) {

    double c1 = (this->points->at(0).x - p.x) * (this->points->at(1).y - this->points->at(0).y) -
                (this->points->at(1).x - this->points->at(0).x) * (this->points->at(0).y - p.y);
    double c2 = (this->points->at(1).x - p.x) * (this->points->at(2).y - this->points->at(1).y) -
                (this->points->at(2).x - this->points->at(1).x) * (this->points->at(1).y - p.y);
    double c3 = (this->points->at(2).x - p.x) * (this->points->at(0).y - this->points->at(2).y) -
                (this->points->at(0).x - this->points->at(2).x) * (this->points->at(2).y - p.y);

    return ((c1 >= 0 && c2 >= 0 && c3 >= 0) || (c1 <= 0 && c2 <= 0 && c3 <= 0)) || (c1 == 0 || c2 == 0 || c3 == 0);
}


double Operations::square_compare(Figure *f1, Figure *f2) {
    return f1->getSquare() - f2->getSquare();
}

bool Operations::isIntersect(Figure *f1, Figure *f2) {
    auto f1_lines = f1->get_lines();
    auto f2_lines = f2->get_lines();
    for (auto i: *f1_lines) {
        for (auto j: *f2_lines) {
            if (i.cross(j)) {
                return true;
            }
        }
    }
    return false;
}

bool Operations::isInclude(Figure *f1, Figure *f2) {
    for (int i(0); i < f2->points_count(); ++i) {
        if (!f1->isIn(f2->get_point(i))) {
            return false;
        }
    }
    return true;
}
