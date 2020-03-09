#include <iostream>

using namespace std;

//3. Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2).
//Предусмотреть, чтобы знаменатель не был равен 0.
//Перегрузить:
//* математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
//* унарный оператор (-)
//* логические операторы сравнения двух дробей (==, !=, <, >, <=, >=).
//Примечание: Поскольку операторы < и >=, > и <= — это логические противоположности, попробуйте перегрузить один через другой.
//Продемонстрировать использование перегруженных операторов.

class Fraction {
    int num = 0; //Числитель
    int denom = 1; //Знаменатель
public:
    Fraction(int num, int denom = 1) {
        if (denom == 0) {
            cout << "Знаменатель не может быть равным нулю" << endl;
        }
        else {
            this->denom = denom;
        }

        this->num = num;
    }

    int getNum() { return num; }
    int getDenum() { return denom; }

    Fraction operator+(Fraction& fr) {
        return Fraction((num * fr.denom + fr.num * denom), (denom * fr.denom));
    }

    Fraction operator-(Fraction& fr) {
        return Fraction((num * fr.denom - fr.num * denom), (denom * fr.denom));
    }

    Fraction operator*(Fraction& fr) {
        return Fraction((num * fr.num), (denom * fr.denom));
    }

    Fraction operator/(Fraction& fr) {
        return Fraction((num * fr.denom), (denom * fr.num));
    }

    Fraction operator-() {
        return Fraction(-num, denom);
    }

    bool operator==(Fraction& fr) {
        if ((num % fr.getNum() == 0 && denom % fr.getDenum() == 0) ||
            (fr.getNum() % num  == 0 && fr.getDenum() % denom  == 0)) {
            return true;
        }

        return false;
    }

    bool operator!=(Fraction& fr) {
        return !(*this == fr);
    }

    bool operator>(Fraction& fr) {
        return (static_cast<double>(num) / static_cast<double>(denom) >
                static_cast<double>(fr.num) / static_cast<double>(fr.denom));
    }

    bool operator<(Fraction& fr) {
        return (static_cast<double>(num) / static_cast<double>(denom) <
                static_cast<double>(fr.num) / static_cast<double>(fr.denom));
    }

    bool operator>=(Fraction& fr) {
        return !(*this < fr);
    }

    bool operator<=(Fraction& fr) {
        return !(*this > fr);
    }
};

int main()
{
    //Проверка операторов +, -, *, /, унарный -
    Fraction fr1(3, 7);
    Fraction fr2(7, 9);
    Fraction fr3 = fr1 + fr2;
    Fraction fr4 = fr1 - fr2;
    Fraction fr5 = fr1 * fr2;
    Fraction fr6 = fr1 / fr2;
    Fraction fr7 = -fr1;

    cout << fr1.getNum() << "/" << fr1.getDenum() << " + " << fr2.getNum() << "/" << fr2.getDenum() << " = "
         << fr3.getNum() << "/" << fr3.getDenum() << endl;

    cout << fr1.getNum() << "/" << fr1.getDenum() << " - " << fr2.getNum() << "/" << fr2.getDenum() << " = "
         << fr4.getNum() << "/" << fr4.getDenum() << endl;

    cout << fr1.getNum() << "/" << fr1.getDenum() << " * " << fr2.getNum() << "/" << fr2.getDenum() << " = "
         << fr5.getNum() << "/" << fr5.getDenum() << endl;

    cout << fr1.getNum() << "/" << fr1.getDenum() << " / " << fr2.getNum() << "/" << fr2.getDenum() << " = "
         << fr6.getNum() << "/" << fr6.getDenum() << endl;

    cout << fr1.getNum() << "/" << fr1.getDenum() << " / " << fr2.getNum() << "/" << fr2.getDenum() << " = "
         << fr6.getNum() << "/" << fr6.getDenum() << endl;

    //Проверка операторов ==, !=, >, <, >=, <=
    Fraction fr8(1, 2);
    Fraction fr9(2, 4);
    Fraction fr10(2, 3);

    bool result1 = fr8 == fr9;
    bool result2 = fr8 == fr10;

    bool result3 = fr8 != fr10;
    bool result4 = fr8 != fr9;

    bool result5 = fr10 > fr8;
    bool result6 = fr8 > fr10;

    bool result7 = fr8 < fr10;
    bool result8 = fr10 < fr8;

    bool result9 = fr10 >= fr8;
    bool result10 = fr8 >= fr10;

    bool result11 = fr8 <= fr10;
    bool result12 = fr10 <= fr8;

    cout << boolalpha;
    cout << fr8.getNum() << "/" << fr8.getDenum() << " == " << fr9.getNum() << "/" << fr9.getDenum() << " = " << result1 << endl;
    cout << fr8.getNum() << "/" << fr8.getDenum() << " == " << fr10.getNum() << "/" << fr10.getDenum() << " = " << result2 << endl;

    cout << fr8.getNum() << "/" << fr8.getDenum() << " != " << fr10.getNum() << "/" << fr10.getDenum() << " = " << result3 << endl;
    cout << fr8.getNum() << "/" << fr8.getDenum() << " != " << fr9.getNum() << "/" << fr9.getDenum() << " = " << result4 << endl;

    cout << fr10.getNum() << "/" << fr10.getDenum() << " > " << fr8.getNum() << "/" << fr8.getDenum() << " = " << result5 << endl;
    cout << fr8.getNum() << "/" << fr8.getDenum() << " > " << fr10.getNum() << "/" << fr10.getDenum() << " = " << result6 << endl;

    cout << fr8.getNum() << "/" << fr8.getDenum() << " < " << fr10.getNum() << "/" << fr10.getDenum() << " = " << result7 << endl;
    cout << fr10.getNum() << "/" << fr10.getDenum() << " < " << fr8.getNum() << "/" << fr8.getDenum() << " = " << result8 << endl;

    cout << fr10.getNum() << "/" << fr10.getDenum() << " >= " << fr8.getNum() << "/" << fr8.getDenum() << " = " << result9 << endl;
    cout << fr8.getNum() << "/" << fr8.getDenum() << " > " << fr10.getNum() << "/" << fr10.getDenum() << " = " << result10 << endl;

    cout << fr8.getNum() << "/" << fr8.getDenum() << " <= " << fr10.getNum() << "/" << fr10.getDenum() << " = " << result11 << endl;
    cout << fr10.getNum() << "/" << fr10.getDenum() << " <= " << fr8.getNum() << "/" << fr8.getDenum() << " = " << result12 << endl;

    return 0;
}
