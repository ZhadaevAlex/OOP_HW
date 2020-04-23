#include <iostream>
#include <memory>

using namespace std;

//1. Создайте класс Date с полями день, месяц, год и методами доступа к этим полям.
//Перегрузите оператор вывода для данного класса.
//Создайте два "умных" указателя today и date.
//Первому присвойте значение сегодняшней даты. Для него вызовите по отдельности методы доступа к полям класса Date,
//а также выведите на экран данные всего объекта с помощью перегруженного оператора вывода.
//Затем переместите ресурс, которым владеет укзаатель today в указатель date.
//Проверьте, являются ли нулевыми указатели today и date и выведите соответствующую информацию об этом в консоль.

//2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
// ** Создайте функцию, которая принимает в качестве параметра два умных указателя типа Date
//и сравнивает их между собой (сравнение происходит по датам). Функция должна вернуть более позднюю дату.
// ** Создайте функцию, которая обменивает ресурсами (датами) два умных указателя, переданных в функцию в качестве параметров.
//Примечание: обратите внимание, что первая функция не должна уничтожать объекты, переданные ей в качестве параметров.

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 1, int m = 1, int y = 1970) : day(d), month(m), year(y) { }

    int getDay() { return day; }
    int getMonth() { return month; }
    int getYear() { return year; }

    friend ostream& operator<<(ostream& out, Date& date);
};

ostream& operator<<(ostream& out, Date& date) {
    out << date.day << '.' << date.month << '.' << date.year;
    return out;
}

unique_ptr<Date> comp(unique_ptr<Date>& d1, unique_ptr<Date>& d2) {
    unique_ptr<Date> result = make_unique<Date>(0, 0, 0);
    if (d1->getYear() > d2->getYear()) {
        result.reset(d1.get());
    }
    else if (d1->getYear() < d2->getYear()) {
        result.reset(d2.get());
    }
    else if (d1->getMonth() > d2->getMonth()) {
        result.reset(d1.get());
    }
    else if (d1->getMonth() < d2->getMonth()) {
        result.reset(d2.get());
    }
    else if (d1->getDay() > d2->getDay()) {
        result.reset(d1.get());
    }
    else if (d1->getDay() < d2->getDay()) {
        result.reset(d2.get());
    }

    return result;
}

void change(unique_ptr<Date>& d1, unique_ptr<Date>& d2) {
    d1.swap(d2);
}

int main()
{
    cout << "Задача 1" << endl;
    unique_ptr<Date> today = make_unique<Date>(20,04,2020);
    cout << today->getDay() << endl;
    cout << today->getMonth() << endl;
    cout << today->getYear() << endl;
    cout << *today << endl;

    unique_ptr<Date> day;
    day = move(today);

    cout << "Указатель day: " << day.get() << endl;
    cout << "Указатель today: " << today.get() << endl;
    cout << endl;

    cout << "Задача 2" << endl;
    unique_ptr<Date> date1 = make_unique<Date>(01,05,2020);
    unique_ptr<Date> date2 = make_unique<Date>(02,06,2020);
    cout << "date1: " << *date1 << endl;
    cout << "date2: " << *date2 << endl;
    cout << endl;

    cout << "Сравниваем" << endl;
    unique_ptr<Date> date3 = comp(date1, date2);
    cout << "date3: " << *date3 << endl;
    cout << endl;

    cout << "Меняем местами" << endl;
    change(date1, date2);
    cout << "date1: " << *date1 << endl;
    cout << "date2: " << *date2 << endl;
    cout << endl;

    return 0;
}
