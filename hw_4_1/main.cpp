#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
//Домашнее задание
//1. Добавить в контейнерный класс, который был написан в этом уроке, методы:
// - для добавления нового элемента в произвольное место
// - для добавления нового элемента на последнее место
// - для удаления последнего элемента массива (аналог функции pop_back() в векторах)
// - для сортировки массива.

//Создадим контейнерный класс
class ArrayInt { //Динамический массив целых чисел. Аналог vector<int>
private:
    int *data; //По сути это массив
    int length;
    int position;

    //Перемена элементов местами. Метод используется для сортировки
    void swap(int *a, int *b) {
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }

public:
    ArrayInt() : data(nullptr), length(0) {}

    ArrayInt(int l) : length(l) {
        assert(l >= 0); //Если неверно, то выводит сообщение. Программа останавливается. Аналог if

        if (length > 0) {
            data = new int[length];
        }
        else {
            data = nullptr;
        }
    }

    ~ArrayInt() {
        delete [] data;
    }

    //Аналог метода clear() из класса vector
    void erase() {
        delete [] data;
        data = nullptr;
        length = 0;
        position = 0;
    }

    //Аналог метода size() из класса vector
    int getLenght() const {
        return length;
    }

    //Перегружаем оператор индексации [] для данного класса
    int& operator[] (int index) {
        assert(index >= 0 && index < length);
        return data[index];
    }

    //Изменяет длину
    void resize(int newLenght) {
        if (newLenght == length) {
            return;
        }

        //Если нужно сделать массив пустым
        if (newLenght <= 0) {
            erase();
            return;
        }

        //Выделяем новую область памяти
        int *newData = new int[newLenght];

        //Нужно определить, сколько элементов нам нужно копировать в новый массив
        int elementsCopy = 0;
        if (length > 0) {
            if (newLenght > length) {
                elementsCopy = length;
            }
            else {
                elementsCopy = newLenght;
            }
        }

        //Поочередно копируем элементы
        for (int index = 0; index < elementsCopy; index++) {
            newData[index] = data[index];
        }

        //Удаляем старый массив
        delete [] data;

        data = newData;
        length = newLenght;
    }

    //Добавление нового элемента в произвольное место
    void insert(const int element, const int position) {
        //Выделяем новую область памяти
        int *newData = new int[length + 1];

        //Поочередно копируем элементы
        for (int index = 0; index < position; index++) {
            newData[index] = data[index];
        }

        for (int index = position; index < length; index++) {
            newData[index + 1] = data[index];
        }

        newData[position] = element;

        //Удаляем старый массив
        delete [] data;

        data = newData;

        length++;
    }

    //Добавление нового элемента на последнее место
    void push_back(const int element) {
        //Выделяем новую область памяти
        int *newData = new int[length + 1];

        //Поочередно копируем элементы
        for (int index = 0; index < length; index++) {
            newData[index] = data[index];
        }

        newData[length] = element;

        //Удаляем старый массив
        delete [] data;

        data = newData;

        length++;
    }

    //Удаление последнего элемента массива
    void pop_back() {
        //Выделяем новую область памяти
        int *newData = new int[length - 1];

        //Поочередно копируем элементы
        for (int index = 0; index < length - 1; index++) {
            newData[index] = data[index];
        }

        //Удаляем старый массив
        delete [] data;

        data = newData;

        length--;
    }

    //Сортровка массива
    void sort() {
        //Пузырьковый метод (оптимизированный)
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length - 1 - i; ++j) {
                if (data[j] > data[j + 1])
                    swap(&data[j], &data[j + 1]);
            }
        }
    }

    //Вспомогательный метод для удобства проверки работы методов
    void print() {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "Создаем динамический массив" << endl;
    ArrayInt arr(7);
    arr[0] = 9;
    arr[1] = 7;
    arr[2] = 3;
    arr[3] = 8;
    arr[4] = 1;
    arr[5] = 2;
    arr[6] = 4;
    arr.print();
    cout << "Кол-во элементов: " << arr.getLenght() << endl;
    cout << endl;

    cout << "Добавляем элемент в конец" << endl;
    arr.push_back(6);
    arr.print();
    cout << "Кол-во элементов: " << arr.getLenght() << endl;
    cout << endl;

    cout << "Добавляем элемент на произвольное место" << endl;
    arr.insert(45, 3);
    arr.print();
    cout << "Кол-во элементов: " << arr.getLenght() << endl;
    cout << endl;

    cout << "Удаляем последний элемент" << endl;
    arr.pop_back();
    arr.print();
    cout << "Кол-во элементов: " << arr.getLenght() << endl;
    cout << endl;

    cout << "Сортируем массив" << endl;
    arr.sort();
    arr.print();
    cout << "Кол-во элементов: " << arr.getLenght() << endl;
    cout << endl;

    return 0;
}
