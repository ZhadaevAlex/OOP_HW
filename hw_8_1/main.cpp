#include <iostream>

using namespace std;

//Написать функцию div, которая должна вычислять результат деления двух целых чисел и запускать исключение DivisionByZero,
//если делитель равен 0.
//В функции main ввести два целых числа и вывести их неполное частное, если делитель не равен нулю,
//и сообщение об ошибке, если равен. 

class DivisionByZero {
public:
    string what() const {
        return "Деление на ноль";
    }
};

int myDiv(int dividend, int divider) {
    if (divider == 0) {
        throw DivisionByZero();
    }

    return dividend / divider;
}

int main()
{
    int a;
    int b;

    cout << "Введите число a: ";
    cin >> a;
    
    cout << "Введите число b: ";
    cin >> b;
    
    int c = 0;
    try {
        c = myDiv(a, b);
        cout << c << endl;
    }
    catch (DivisionByZero exc) {
        cout << exc.what() << endl;
    }

    return 0;
}
