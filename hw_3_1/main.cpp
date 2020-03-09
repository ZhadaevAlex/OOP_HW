#include <iostream>
#include <math.h>

using namespace std;

//1. Создать абстрактный класс Figure (фигура). Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
//Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
//Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
//Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.

class Figure {
public:
    Figure() {}
    virtual ~Figure() {}

    virtual double area() = 0;
};

class Parallelogram : public Figure {
public:
    Parallelogram() {}

    virtual double area() override = 0;
};

class Circle : public Figure {
    double radius;
public:
    Circle(double r) : radius(r) {}

    double area() override {
        return M_PI * pow(radius, 2);
    }
};

class Rectangle : public Parallelogram {
    double sizeA;
    double sizeB;
public:
    Rectangle(double sA, double sB) : sizeA(sA), sizeB(sB) {}

    double area() override {
        return sizeA * sizeB;
    }

};

class Square : public Parallelogram {
    double size;
public:
    Square(double s) : size(s) {}

    double area() override {
        return size*size;
    }
};

class Rhombus : public Parallelogram {
    double diagonal1;
    double diagonal2;
public:
    Rhombus(double d1, double d2) : diagonal1(d1), diagonal2(d2) {}

    double area() override {
        return diagonal1 * diagonal2 / 2;
    }
};

void printArea(Figure* f) {
    cout << f->area() << endl;
}

int main()
{
    Figure* circle = new Circle(5);
    Figure* rectangle = new Rectangle(2, 4);
    Figure* square = new Square(3);
    Figure* rhombus = new Rhombus(5, 7);

    cout << "Полщадь круга: ";
    printArea(circle);

    cout << "Полщадь прямоугольника: ";
    printArea(rectangle);

    cout << "Полщадь квадрата: ";
    printArea(square);

    cout << "Полщадь ромба: ";
    printArea(rhombus);

    return 0;
}
