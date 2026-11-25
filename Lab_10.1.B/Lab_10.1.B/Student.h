#pragma once

#include <string>

// спеціальності - перелік
enum Specialnist { KN, INF, ME, FI, TN };
// KN  - Комп'ютерні науки        (третя оцінка - програмування)
// INF - Інформатика              (третя оцінка - чисельні методи)
// ME  - Математика та економіка  (третя оцінка - педагогіка)
// FI  - Фізика та інформатика    (третя оцінка - педагогіка)
// TN  - Трудове навчання         (третя оцінка - педагогіка)

// інформація про одного студента
struct Student
{
    std::string prizv;          // прізвище
    int         kurs;           // курс
    Specialnist spec;           // спеціальність
    int         fizyka;         // оцінка з фізики
    int         matematyka;     // оцінка з математики
    union                       // третя оцінка - залежить від спеціальності
    {
        int programuvannia;     // для KN
        int chyselni_metody;    // для INF
        int pedagogika;         // для ME, FI, TN
    };
};

// прототипи функцій
void   Create(Student* p, const int N);                  // заповнення масиву з клавіатури
void   Print(const Student* p, const int N);             // вивід масиву у вигляді таблиці
double PercentExcellent(const Student* p, const int N);  // процент відмінників
void   PrintPhysics5(const Student* p, const int N);     // вивід прізвищ, у кого з фізики 5