#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// назви спеціальностей для виводу - індекс = значення переліку
const string specStr[] = { "Комп. науки", "Інформатика", "Мат. та екон.",
                           "Фіз. та інф.", "Труд. навч." };

void Create(Student* p, const int N)
{
    int spec;                       // спеціальність вводимо як число
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;

        cin.get();  // очищуємо буфер клавіатури - бо залишаються символи
        cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

        cout << "   прізвище: ";   getline(cin, p[i].prizv);
        cout << "   курс: ";       cin >> p[i].kurs;
        cout << "   спеціальність (0 - Комп. науки, 1 - Інформатика, 2 - Мат. та екон., "
            << "3 - Фіз. та інф., 4 - Труд. навч.): ";
        cin >> spec;
        p[i].spec = (Specialnist)spec;
        cout << "   оцінка з фізики: ";      cin >> p[i].fizyka;
        cout << "   оцінка з математики: ";  cin >> p[i].matematyka;

        switch (p[i].spec)          // третя оцінка - залежно від спеціальності
        {
        case KN:
            cout << "   оцінка з програмування: ";     cin >> p[i].programuvannia;
            break;
        case INF:
            cout << "   оцінка з чисельних методів: "; cin >> p[i].chyselni_metody;
            break;
        case ME:
        case FI:
        case TN:
            cout << "   оцінка з педагогіки: ";        cin >> p[i].pedagogika;
            break;
        }
        cout << endl;
    }
}
void Print(const Student* p, const int N)
{
    cout << "Список студентів:" << endl;
    cout << "==============================================================================================================="
        << endl;
    cout << "|  №  |   Прізвище    | Курс | Спеціальність | Фізика | Математика | Програмування | Чис. методи | Педагогіка |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------------------"
        << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1
            << " | " << setw(13) << left << p[i].prizv
            << " | " << setw(4) << right << p[i].kurs
            << " | " << setw(13) << left << specStr[p[i].spec]
            << " | " << setw(6) << right << p[i].fizyka
            << " | " << setw(10) << right << p[i].matematyka
            << " | ";

        switch (p[i].spec)          // заповнюємо лише клітинку свого предмету
        {
        case KN:
            cout << setw(13) << right << p[i].programuvannia
                << " | " << setw(11) << " "
                << " | " << setw(10) << " " << " |" << endl;
            break;
        case INF:
            cout << setw(13) << " "
                << " | " << setw(11) << right << p[i].chyselni_metody
                << " | " << setw(10) << " " << " |" << endl;
            break;
        case ME:
        case FI:
        case TN:
            cout << setw(13) << " "
                << " | " << setw(11) << " "
                << " | " << setw(10) << right << p[i].pedagogika << " |" << endl;
            break;
        }
    }
    cout << "==============================================================================================================="
        << endl;
    cout << endl;
}
// повертає процент студентів, які вчаться на "відмінно"
double PercentExcellent(const Student* p, const int N)
{
    int k = 0;                              // кількість відмінників
    for (int i = 0; i < N; i++)
    {
        int third;                          // третя оцінка - залежно від спеціальності
        switch (p[i].spec)
        {
        case KN:
            third = p[i].programuvannia;
            break;
        case INF:
            third = p[i].chyselni_metody;
            break;
        default:                            // ME, FI, TN
            third = p[i].pedagogika;
            break;
        }

        if (p[i].fizyka == 5 && p[i].matematyka == 5 && third == 5)
            k++;
    }
    return 100.0 * k / N;
}
// виводить прізвища студентів, які отримали з фізики оцінку "5"
void PrintPhysics5(const Student* p, const int N)
{
    cout << "Студенти, які отримали з фізики оцінку \"5\":" << endl;

    bool found = false;
    for (int i = 0; i < N; i++)
        if (p[i].fizyka == 5)
        {
            cout << "   " << p[i].prizv << endl;
            found = true;
        }

    if (!found)
        cout << "   таких студентів немає" << endl;
    cout << endl;
}