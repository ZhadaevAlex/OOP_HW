#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//1. Создать программу, которая бы запрашивала у пользователя строки до тех пор,
//пока он не введет пустую строку.
//После этого программа должна вывести список введенных строк в два столбца,
//первый из которых выровнен по левому краю, а второй — по правому краю.

int main()
{
    string str;
    vector<string> vStr;

    while(1) {
        getline(cin, str);

        if (!str.empty()) {
            vStr.push_back(str);
        }
        else {
            break;
        }
    }

    //Определим ширину столбца как удвоенную длину максимально длинной строки в векторе
    vector<string>::iterator it = vStr.begin();
    unsigned long maxLength = 0;
    for(; it != vStr.end(); it++) {
        if (it->length() > maxLength) {
            maxLength = it->length();
        }
    }

    it = vStr.begin();
    for(; it != vStr.end(); it++) {
        cout << setw(static_cast<int>(maxLength) * 2) << left << *it;
        cout << setw(static_cast<int>(maxLength) * 2) << right << *it;
        cout << endl;
    }

    return 0;
}
