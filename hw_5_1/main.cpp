#include <iostream>

using namespace std;

//1. Реализовать шаблон класса Pair1, который позволяет пользователю передавать данные одного типа парами.
//… должен производить результат:
//Pair: 6 9
//Pair: 3.4 7.8

template<typename T>
class Pair1 {
private:
    T f;
    T s;

public:
    Pair1(T f, T s) : f(f), s(s) {}
    T first() const {
        return f;
    }

    T second() const {
        return s;
    }
};


int main()
{
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;
}
