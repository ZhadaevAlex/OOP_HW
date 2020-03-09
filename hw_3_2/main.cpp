#include <iostream>

using namespace std;

//2. Создать класс Car (автомобиль) с полями company (компания) и model (модель).
//Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов наследует класс Minivan (минивэн).
//Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
//Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы.
//Обратить внимание на проблему «алмаз смерти».
//Примечание: если использовать виртуальный базовый класс,
//то объект самого "верхнего" базового класса создает самый "дочерний" класс.

class Car {
private:
    string company;
    string model;
public:
    Car(string c, string m) : company(c), model(m) {
        cout << "Конструктор класса Car" << endl;
    }
};

class PassengerCar : public Car {
public:
    PassengerCar(string c, string m) : Car(c, m) {
        cout << "Конструктор класса PassengerCar" << endl;
    }
};

class Bus : public Car {
public:
    Bus(string c, string m) : Car(c, m) {
        cout << "Конструктор класса Bus" << endl;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(string c, string m) : PassengerCar(c, m), Bus(c, m) {
        cout << "Конструктор класса Minivan" << endl;
    }
};

int main()
{
    cout << "Создаем объект класса Car" << endl;
    Car car("ЗАЗ", "968");
    cout << endl;

    cout << "Создаем объект класса PassengerCar" << endl;
    PassengerCar passCar("АЗЛК", "2141");
    cout << endl;

    cout << "Создаем объект класса Bus" << endl;
    Bus bus("ЛиАЗ", "677");
    cout << endl;

    cout << "Создаем объект класса Minivan" << endl;
    Minivan minivan("ЗАЗ", "968");
    cout << endl;

    //Действительно, конструктор класса Car при создании объекта класса Minivan вызывается 2 раза

    return 0;
}
