#include <iostream>
#include <iomanip>

using namespace std;

//3. Создать собственный манипулятор endll для стандартного потока вывода,
//который выводит два перевода строки и сбрасывает буфер.

ostream& endll(ostream& out) {
    out << '\n';
    out << endl;
}

int main()
{
    cout << endll;

    return 0;
}
