#include <iostream>
#include <regex>

using namespace std;

//2. Создать программу, которая считывает целое число типа int.
//И поставить «защиту от дурака»: если пользователь вводит что-то кроме одного целочисленного значения,
//нужно вывести сообщение об ошибке и предложить ввести число еще раз.
//Пример неправильных введенных строк:
// rbtrb
// nj34njkn
// 1n

int main()
{
    string str;

    while(1) {
        bool flag = true;

        cout << "Введите целое число: ";

        getline(cin, str);

        if (str.length() == 0)
            continue;

        for (unsigned i = 0; i < str.length(); i++) {
            if (i == 0 && (str[i] == '-' || str[i] == '+')) {
                continue;
            }

            if (!isdigit(str[i])) {
                flag = false;
                break;
            }
        }

        if (flag)
            break;
    }

    cout << "Используем регулярные выражения" << endl;

    cmatch result;

    regex regular("^-{0,1}\\d+$");

    while(1) {
        cout << "Введите целое число: ";

        getline(cin, str);

        if (str.length() == 0 || !regex_match(str.c_str(), result, regular)) {
            continue;
        }

        break;
    }

    return 0;
}
