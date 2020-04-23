#include <iostream>
#include "Game.h"
#include <vector>
#include <regex>

using namespace std;

int main()
{
    cout << "\t\tДобро пожаловать в Блэкджэк\n" << endl;

    cmatch result;
    regex regular("[1-7]");

    string numStr;
    while (true) {
        cout << "Введите число игроков (от 1 до 7): ";
        getline(cin, numStr);
        if (numStr.length() == 0 || !regex_match(numStr.c_str(), result, regular)) {
            continue;
        }

        break;
    }

    int num;
    stringstream strStream;
    strStream << numStr;
    strStream >> num;

    vector<string> names;
    string name;
    for (int i = 0; i < num; ++i) {
        cout << "Введите имя " << i + 1 << "-го игрока: ";
        getline(cin, name);
        names.push_back(name);
    }
    cout << endl;

    Game game(names);

    bool more = true;
    while(more) {
        game.play();
        cout << endl;

        while (1) {
            string str;

            cout <<  "Хотите сыграть еще? (д/н y/n): ";

            getline(cin, str);

            if (str == "д" || str == "y") {
                more = true;
                break;
            }

            if (str == "н" || str == "n") {
                more = false;
                break;
            }

            cout << "Неверный ввод. Введите д/н y/n: ";
        }
    }
    cout << endl;

    cout << "\t\tИгра окончена\n" << endl;

    return 0;
}
