#include <iostream>
#include <cmath>

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
protected:
    double sizeA = 0;
    double sizeB = 0;
    double alpha;
public:
    Parallelogram(double sizeA, double sizeB, double a = 90) : sizeA(sizeA), sizeB(sizeB) {
        if (a >= 0 && a <= 180) {
            alpha = a;
        }
        else {
            cout << "Угол должен лежать в пределах от 0 до 180 градусов" << endl;
        }
    }

    virtual double area() override {
        return sizeA * sizeB * sin(alpha * M_PI / 180);
    }
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
public:
    Rectangle(double sA, double sB) : Parallelogram(sA, sB) {}
};

class Square : public Parallelogram {
public:
    Square(double s) : Parallelogram(s, s) {}
};

class Rhombus : public Parallelogram {
public:
    Rhombus(double s, double a) : Parallelogram(s, s, a) {}
};

void printArea(Figure* f) {
    cout << f->area() << endl;
}

int main()
{
    Figure* parallelogram = new Parallelogram(2, 5, 30);
    Figure* circle = new Circle(5);
    Figure* rectangle = new Rectangle(2, 4);
    Figure* square = new Square(3);
    Figure* rhombus = new Rhombus(5, 30);

    cout << "Площадь параллелограма: ";
    printArea(parallelogram);

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
