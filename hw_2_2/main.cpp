#include <iostream>

using namespace std;

class Human {
private:
    string firstName;
    string lastName;
    static int count;
public:
    Human(string firstName, string lastName) {
        this->firstName = firstName;
        this->lastName = lastName;
        count++;
    }

    string getFirstName() const {
        return firstName;
    }

    string getLastName() const {
        return lastName;
    }

    static int getCount() {
        return count;
    }
};

int Human::count = 0;

class Student : public Human {
private:
    string facultyNumber;
public:
    Student(string firstName, string lastName, string facultyNumber) : Human(firstName, lastName), facultyNumber(facultyNumber) { }

    void setFacultyNumber(string facultyNumber) {
        this->facultyNumber = facultyNumber;
    }

    string getFacultyNumber() const {
        return facultyNumber;
    }
};

class Worker : public Human {
private:
    double weekSalary;
    double workHoursPerDay;
public:
    Worker(string firstName, string lastName, double weekSalary, double workHoursPerDay) :
        Human(firstName, lastName), weekSalary(weekSalary), workHoursPerDay(workHoursPerDay) { }

    void setWeekSalary(double weekSalary) {
        this->weekSalary = weekSalary;
    }

    void setWorkHoursPerDay(double workHoursPerDay) {
        this->workHoursPerDay = workHoursPerDay;
    }

    double getWeekSalary() const {
        return weekSalary;
    }

    double getWorkHoursPerDay() const {
        return workHoursPerDay;
    }
};

int main() {
    Student* students[3];

    students[0] = new Student("Андрей", "Колмогоров", "МехМат");
    students[1] = new Student("Александр", "Попов", "ФизФак");
    students[2] = new Student("Дмитрий", "Менделеев", "ХимФак");

    Worker* workers[3];
    workers[0] = new Worker("Алексей", "Огурцов", 10, 8);
    workers[1] = new Worker("Сергей", "Помидоров", 20, 4);
    workers[2] = new Worker("Павел", "Собакин", 40, 2);

    cout << "Построено объектов: " << Human::getCount() << endl;

    int type;
    cout << "Введите тип: 1 - студент; 2 - работник" << endl;
    cin >> type;

    switch (type) {
    case 1: {
        int num = 0;
        cout << "Введите порядковый номер студента: " << "от 1 до 3" << endl;
        cin >> num;
        cout << "Имя: " << students[num - 1]->getFirstName()<< endl;
        cout << "Фамилия: " << students[num - 1]->getLastName()<< endl;
        cout << "Факультет: " << students[num - 1]->getFacultyNumber()<< endl;
        break;
    }
    case 2: {
        int num = 0;
        cout << "Введите порядковый номер работника: " << "от 1 до 3" << endl;
        cin >> num;
        cout << "Имя: " << workers[num - 1]->getFirstName()<< endl;
        cout << "Фамилия: " << workers[num - 1]->getLastName()<< endl;
        cout << "Недельная ЗП: " << workers[num - 1]->getWeekSalary()<< endl;
        cout << "Кол-во рабочих часов в день: " << workers[num - 1]->getWorkHoursPerDay()<< endl;
        break;
    }
    default:
        cout << "Некорректный тип" << endl;
        break;
    }
}
