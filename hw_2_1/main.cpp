#include <iostream>
#include <cctype>
//#include <string>
//include <algorithm>

using namespace std;

class Book {
protected:
    string title = "";
    string author = "";
    double price = 0;

public:
    Book(string t, string a, double p = 0) {
        //Валидация значения параметра поля title
        if (!isdigit(t[0])) {
            title = t;
        }
        else {
            cout << "Заголовок книги не может начинаться с цифры" << endl;
        }

        //Валидация значения параметра поля author
        //Определяем количество пробелов, тем самым определяем количество слов
        int spaceCount = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] == ' ') {
                spaceCount++;
            }
        }

        if (spaceCount < 2) {
            author = a;
        }
        else {
            cout << "Имя автора должно состоять из одного или двух слов" << endl;
        }

        //Валидация значения параметра поля price
        if (p > 0) {
            price = p;
        }
        else {
            cout << "Цена должна быть больше 0" << endl;
        }
    }

    void setTitle(string t) {
        //Валидация значения параметра поля title
        if (!isdigit(t[0])) {
            title = t;
        }
        else {
            cout << "Заголовок книги не может начинаться с цифры" << endl;
        }
    }

    void setAuthor(string a) {
        //Валидация значения параметра поля author
        //Определяем количество пробелов, тем самым определяем количество слов
        int spaceCount = 0;

        for (size_t i = 0; i < a.size(); ++i) {
            if (a[i] == ' ') {
                spaceCount++;
            }
        }

        if (spaceCount < 2) {
            author = a;
        }
        else {
            cout << "Имя автора должно состоять из одного или двух слов" << endl;
        }
    }

    void setPrice(double p) {
        //Валидация значения параметра поля price
        if (p > 0) {
            price = p;
        }
        else {
            cout << "Цена должна быть больше 0" << endl;
        }
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    double getPrice() const {
        return price;
    }
};

class GoldenEditionBook : public Book {
    double priceGolden;
public:
    GoldenEditionBook(string t, string a, double p) : Book(t, a, p) {
        priceGolden = price + 0.3 * price;
    }

    double getPriceGolden() const {
        return priceGolden;
    }
};

int main()
{
    Book book("Язык программирования С++", "Бьерн Страуструп", 1000);
    cout << book.getTitle() << endl;
    cout << book.getAuthor() << endl;
    cout << book.getPrice() << endl;
    cout << endl;

    GoldenEditionBook geb("Язык программирования С++. Специальное издание", "Бьерн Страуструп", 1000);
    cout << geb.getTitle() << endl;
    cout << geb.getAuthor() << endl;
    cout << geb.getPriceGolden() << endl;
    cout << endl;

    GoldenEditionBook goldenBookDefault("1Язык программирования С++", "Бьерн Бьерн Страуструп", -1000);
    cout << goldenBookDefault.getTitle() << endl;
    cout << goldenBookDefault.getAuthor() << endl;
    cout << goldenBookDefault.getPrice() << endl;

    return 0;
}
