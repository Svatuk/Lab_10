#pragma once

#include <string>

// спеціальності - перелік (enum)
enum Specialnist { KN, INF, ME, FI, TN };
// KN  - Комп'ютерні науки
// INF - Інформатика
// ME  - Математика та економіка
// FI  - Фізика та інформатика
// TN  - Трудове навчання

// інформація про одного студента
struct Student
{
    std::string prizv;        // прізвище
    int         kurs;         // курс
    Specialnist spec;         // спеціальність
    int         fizyka;       // оцінка з фізики
    int         matematyka;   // оцінка з математики
    int         informatyka;  // оцінка з інформатики
};

// прототипи функцій
void   Create(Student* p, const int N);                  // заповнення масиву з клавіатури
void   Print(const Student* p, const int N);             // вивід масиву у вигляді таблиці
double PercentExcellent(const Student* p, const int N);  // процент відмінників
void   PrintPhysics5(const Student* p, const int N);     // вивід прізвищ, у кого з фізики 5