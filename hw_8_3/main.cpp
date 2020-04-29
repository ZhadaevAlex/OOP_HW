#include <iostream>
#include <string>

using namespace std;

//Написать класс «робот», моделирующий перемещения робота по сетке 10x10,
//у которого есть метод, означающий задание переместиться на соседнюю позицию.
//Эти методы должны запускать исключение OffTheField, если робот должен уйти с сетки,
//и IllegalCommand, если подана неверная команда (направление не находится в нужном диапазоне).
//Объект исключения должен содержать всю необходимую информацию — текущую позицию и направление движения.
//Написать функцию main, пользующуюся этим классом и перехватывающую все исключения от его методов,
//а также выводящую подробную информацию о всех возникающих ошибках.

class RobotException {
private:
    int x_;
    int y_;
    int dir_;
public:
    RobotException(int x, int y, int dir) : x_(x), y_(y), dir_(dir) {}

    void printPosition() {
        cout << "Текущая позиция: " << "(" << x_ << ", " << y_ << ")" << endl;
        cout << "Текущее направление: " << dir_ << endl;
    }
};

class OffTheField : public RobotException {
public:
    OffTheField(int x, int y, int dir) : RobotException(x, y, dir) {}

    void printMessage() {
        cout << "Робот окажется за пределами сетки" << endl;
    }
};

class IllegalCommand : public RobotException {

public:
    IllegalCommand(int x, int y, int dir) : RobotException(x, y, dir) {}

    void printMessage() {
        cout << "Неверная команда" << endl;
    }
};

class Robot {
    int x = 1;
    int y = 1;

public:
    void move(int dir) {

        switch (dir) {
        case 1:
            if (y == 10)
                throw OffTheField(x, y, dir);
            y++;
            break;

        case 2:
            if (y == 1)
                throw OffTheField(x, y, dir);
            y--;
            break;

        case 3:
            if (x == 1)
                throw OffTheField(x, y, dir);
            x--;
            break;

        case 4:
            if (x == 10)
                throw OffTheField(x, y, dir);
            x++;
            break;

        default:
            throw IllegalCommand(x, y, dir);
        }
    }
};

int getDirection() {
    string str;

    cout << "Введите направление (wsad/WSAD): " << endl;
    getline(cin, str);

    int dir;
    if (str == "q" || str == "Q") {
        dir = 0;
    }
    else if (str == "w" || str == "W" || str == "ц" || str == "Ц") {
        dir = 1;
    }
    else if (str == "s" || str == "S" || str == "ы" || str == "Ы") {
        dir = 2;
    }
    else if (str == "a" || str == "A" || str == "ф" || str == "Ф") {
        dir = 3;
    }
    else if (str == "d" || str == "D" || str == "в" || str == "В") {
        dir = 4;
    }
    else {
        dir = 5;
    }

    return dir;
}

int main()
{
    Robot robot;

    while(1) {
        int dir = getDirection();

        if (dir == 0)
            break;

        try {
            robot.move(dir);
        }
        catch (IllegalCommand exc) {
            exc.printPosition();
            exc.printMessage();
        }
        catch (OffTheField exc) {
            exc.printPosition();
            exc.printMessage();
        }
    }

    return 0;
}
