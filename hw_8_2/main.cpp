#include <iostream>

using namespace std;

//Написать класс Ex, хранящий вещественное число x и имеющий конструктор по вещественному числу,
//инициализирующий x значением параметра.
//Написать класс Bar, хранящий вещественное число y (конструктор по умолчанию инициализирует его нулем)
//и имеющий метод set с единственным вещественным параметром a.
//Если y + a > 100, возбуждается исключение типа Ex с данными ay, иначе в y заносится значение a.
//В функции main завести переменную класса Bar и в цикле в блоке try вводить с клавиатуры целое n.
//Использовать его в качестве параметра метода set до тех пор, пока не будет введено 0.
//В обработчике исключения выводить сообщение об ошибке, содержащее данные объекта исключения.

class Ex {
private:
    double x;

public:
    Ex(double num) : x(num) {}

    double getX() {
        return x;
    }
};

class Bar {
private:
    double y;

public:
    Bar(double num = 0) : y(num) {}

    void set(double a) {
        if (y + a > 100) {
            throw Ex(a * y);
        }

        y = a;
    }
};

int main()
{
    Bar bar;
    int n = 1;
    while (n != 0) {
        try {
            cout << "Введите число n: ";
            cin >> n;

            bar.set(n);
        }
        catch (Ex exc) {
            cout << "Ошибка. y + a > 100. (y * a) = " << exc.getX() << endl;
        }
    }

    return 0;
}
