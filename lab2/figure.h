#include <iostream>
#include <vector>
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

    //Проверка эквивалентности двух линий
    bool isEquivalent(Line n);
};

//Абстрактный класс фигуры
class Figure {
public:
    //Функция вычисления площади фигуры
    virtual double getSquare() = 0;

    //Функция вычисления центра масс фигуры
    virtual Point getCenterOfMass() = 0;

    //Функция вычисления периметра фигуры
    virtual double getPerimeter() = 0;

    //Функция возвращающая тип фигуры
    virtual std::string getType();

    virtual ~Figure() = default;;
};

//Класс прямоугольника
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

//Класс треугольника
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

//Класс круга
class Circle : public Figure {
private:
    Point center;
    double radius;
public:
    double getSquare() override;

    Point getCenterOfMass() override;

    double getPerimeter() override;

    std::string getType() override;

    Circle(Point center, double radius);
};

//Класс трапеции
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

//Класс Картинка - фасад. Является массивом объектов типа Figure
class Picture {
private:
    std::vector<Figure *> figures;

    std::vector<std::pair<std::string, double>> getSquares();

    std::vector<std::pair<std::string, Point>> getCenterOfMasss();

    std::vector<std::pair<std::string, double>> getPerimeters();

public:
    //Добавить элемент в массив
    void push(Figure *ob);

    //Вывести типы каждой фигуры
    void printTypes();

    //Вывод площадей фигур
    void printSquares();

    //Вывод центра масс фигур
    void printCenterOfMasss();

    //Вывод периметров фигур
    void printPerimeters();

    ~Picture() {
        figures.clear();
    }
};

