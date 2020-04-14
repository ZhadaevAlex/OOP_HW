#include <iostream>

using namespace std;

//2. Реализовать класс Pair, который позволяет использовать разные типы данных в передаваемых парах.
//… должен производить следующий результат:
//Pair: 6 7.8
//Pair: 3.4 5

template<typename T1, typename T2>
class Pair {
private:
    T1 f;
    T2 s;

public:
    Pair(T1 f, T2 s) : f(f), s(s) {}

    T1 first() const {
        return f;
    }

    T2 second() const {
        return s;
    }
};

int main()
{
    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    return 0;

}
