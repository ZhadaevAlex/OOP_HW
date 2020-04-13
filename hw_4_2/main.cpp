#include <iostream>
#include <vector>

using namespace std;

//2. Дан вектор чисел (числа вводятся с клавиатуры), требуется выяснить, сколько среди них различных.
//Постараться использовать максимально быстрый алгоритм.

//Метод выполняет непосредственно подсчет различных элементов
unsigned long diff(vector<int>& v) {
    unsigned long count = 0;
    for (unsigned long i = 1; i < v.size(); i++) {
        unsigned long result = 1;
        for (unsigned long j = i; j != 0; j--) {
            if (v[i] == v[j - 1]) {
                result = 0;
                break;
            }
        }

        count += result;
    }

    return ++count;
}

int main()
{
    vector<int> arr;

    cout << "Введите целочисленные элементы массива через пробел: " << endl;
    int num;
    do {
        cin >> num;
        arr.push_back(num);
    }
    while(getchar()!='\n');

    vector<int>::iterator it;
    it = arr.begin();
    for ( ; it != arr.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Количество различных элементов: " << diff(arr) << endl;

    return 0;
}
