#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//4. Разработать функцию, принимающую два числа в виде списка (вектора) цифр в одной системе счисления,
//и возвращающую число — результат сложения в виде списка (вектора) цифр в другой системе счисления.

//Входные данные:
//система A, B — системы счисления входных чисел, цифра A1..AN
//и цифра B1..BN — запись входных чисел в виде набора цифр от старшего разряда к младшему
//<система_A>: <цифра_A1>, <цифра_A2>, ... <цифра_AN>
//<система_B>: <цифра_B1>, <цифра_B2>, ... <цифра_BM>

//Выходные данные:
//система C — система счисления результата сложения.
//<сиcтема_C>

//Пример: сложить FF в 16 системе счисления и HELLO в 36 системе счисления, результат вывести в двоичной системе счисления
//16: 15, 15
//36: 17, 14, 21, 21, 24
//2
//По сути задача сводится к тому, чтобы реализовать функцию, реализующую сложение чисел в различных системах счисления,
//и возвращающую результат в требуемой системе счисления.
//std::vector<int> plus(const std::vector<int> &A, int baseA, const std::vector<int> &B, int baseB, int baseResult);

//Перевод из любой СС в десятичную
int anyToDec(const vector<int> number, const int base) {
    int result = 0;

    unsigned long j = number.size() - 1;
    for (unsigned long i = 0; i < number.size(); i++) {
        result += number[i] * static_cast<int>(pow(base, j));
        j--;
    }

    return result;
}

//Перевод из десятичной СС в любую
vector<int> decToAny(const int number, const int base) {
    vector<int> result;
    int r = number;
    do {
        auto it = result.begin();
        int bit = r % base;
        r /= base;
        result.insert(it, bit);
    }
    while(r > 0);

    return result;
}

vector<int> Plus(const vector<int> &A, int baseA, const vector<int> &B, const int baseB, const int baseResult) {
    int AIntDec = anyToDec(A, baseA);
    int BIntDec = anyToDec(B, baseB);
    int CIntDec = AIntDec + BIntDec;

    vector<int> C = decToAny(CIntDec, baseResult);

    return C;
}

int main()
{
    int baseA = 16;
    int baseB = 36;
    int baseResult = 2;

    vector<int> A = {15, 15};
    vector<int> B = {17, 14, 21, 21, 24};
    vector<int> C = Plus(A, baseA, B, baseB, baseResult);

    auto it = C.begin();
    for ( ; it != C.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
