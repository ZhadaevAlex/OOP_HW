#include <iostream>

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

        for (unsigned i = 0; i < str.length(); i++) {
            if (!isdigit(str[i])) {
                flag = false;
                break;
            }
        }

        if (flag)
            break;
    }

    return 0;
}
