#pragma once

#include <string>

// спеціальності - перелік
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
int  InputInt(const std::string prompt, const int min, const int max); // ввід цілого числа
// з контролем помилок
void Create(Student* p, const int N);                 // заповнення масиву з клавіатури
void Print(const Student* p, const int N);            // вивід масиву у вигляді таблиці
void Sort(Student* p, const int N);                   // фізичне впорядкування
int  BinSearch(const Student* p, const int N,         // бінарний пошук: повертає індекс
    const std::string prizv,               // знайденого студента або -1
    const Specialnist spec,
    const int matematyka);
int* IndexSort(const Student* p, const int N);        // індексне впорядкування:
// повертає індексний масив
void PrintIndexSorted(const Student* p, const int* I, const int N); // вивід у порядку,
// заданому масивом I