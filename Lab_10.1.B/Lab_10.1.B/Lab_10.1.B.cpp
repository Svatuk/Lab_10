#include <iostream>
#include <iomanip>
#include <Windows.h>          // забезпечення відображення кирилиці
#include "Student.h"

using namespace std;

int main()
{                             // забезпечення відображення кирилиці:
    SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    int N;
    cout << "Введіть кількість студентів N: "; cin >> N;

    Student* p = new Student[N];    // динамічний масив структур

    Create(p, N);
    Print(p, N);

    double proc = PercentExcellent(p, N);
    cout << "Процент студентів, які вчаться на \"відмінно\": "
        << fixed << setprecision(2) << proc << "%" << endl << endl;

    PrintPhysics5(p, N);

    delete[] p;                     // звільняємо пам'ять
    return 0;
}