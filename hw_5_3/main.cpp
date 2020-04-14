#include <iostream>

using namespace std;

//3. Написать шаблон класса StringValuePair, в котором
//первое значение всегда типа string,
//а второе — любого типа.
//Этот шаблон класса должен наследовать частично специализированный класс Pair,
//в котором первый параметр — string, а второй — любого типа данных.
//… должен производить следующий результат:
//Pair: Amazing 7
//Подсказка: при вызове конструктора класса Pair из конструктора класса StringValuePair
//не забудьте указать, что параметры относятся к классу Pair.

template<typename T>
class Pair {
private:
    string f;
    T s;

public:
    Pair(string f, T s) : f(f), s(s) {}

    string first() const {
        return f;
    }

    T second() const {
        return s;
    }

};

template<typename T>
class StringValuePair : public Pair<T> {
public:
    StringValuePair(string f, T s) : Pair<T>(f, s) {}
};

int main()
{
    StringValuePair<int> svp("Amazing", 7);

    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}
