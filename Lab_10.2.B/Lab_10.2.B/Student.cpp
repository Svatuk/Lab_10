#include "Student.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// назви спеціальностей для виводу та для впорядкування за назвою
const string specStr[] = { "Комп. науки", "Інформатика", "Мат. та екон.",
                           "Фіз. та інф.", "Труд. навч." };

// ввід цілого числа з діапазону [min, max] з контролем помилок
int InputInt(const string prompt, const int min, const int max)
{
    int x;
    cout << prompt;
    while (!(cin >> x) || x < min || x > max)   // не число або число поза межами
    {
        cin.clear();                            // скидаємо стан помилки потоку
        cin.ignore(1000, '\n');                 // відкидаємо помилкове введення
        cout << "   Помилка! Введіть ціле число від " << min << " до " << max << ": ";
    }
    cin.ignore(1000, '\n');                     // відкидаємо залишок рядка (Enter)
    return x;
}

void Create(Student* p, const int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;

        do {                                    // прізвище не може бути порожнім
            cout << "   прізвище: "; getline(cin, p[i].prizv);
            if (p[i].prizv.empty())
                cout << "   Помилка! Прізвище не може бути порожнім." << endl;
        } while (p[i].prizv.empty());

        p[i].kurs = InputInt("   курс (1-6): ", 1, 6);
        p[i].spec = (Specialnist)InputInt("   спеціальність (0 - Комп. науки, 1 - Інформатика, "
            "2 - Мат. та екон., 3 - Фіз. та інф., 4 - Труд. навч.): ",
            0, 4);
        p[i].fizyka = InputInt("   оцінка з фізики (1-5): ", 1, 5);
        p[i].matematyka = InputInt("   оцінка з математики (1-5): ", 1, 5);

        switch (p[i].spec)                      // третя оцінка - залежно від спеціальності
        {
        case KN:
            p[i].programuvannia = InputInt("   оцінка з програмування (1-5): ", 1, 5);
            break;
        case INF:
            p[i].chyselni_metody = InputInt("   оцінка з чисельних методів (1-5): ", 1, 5);
            break;
        case ME:
        case FI:
        case TN:
            p[i].pedagogika = InputInt("   оцінка з педагогіки (1-5): ", 1, 5);
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

// фізичне впорядкування: за назвою спеціальності, оцінкою з математики, прізвищем
void Sort(Student* p, const int N)
{
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++)              // метод "бульбашки"
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((specStr[p[i1].spec] > specStr[p[i1 + 1].spec])
                ||
                (p[i1].spec == p[i1 + 1].spec &&
                    p[i1].matematyka > p[i1 + 1].matematyka)
                ||
                (p[i1].spec == p[i1 + 1].spec &&
                    p[i1].matematyka == p[i1 + 1].matematyka &&
                    p[i1].prizv > p[i1 + 1].prizv))
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}

// бінарний пошук за прізвищем, спеціальністю та оцінкою з математики
// повертає індекс знайденого студента або -1, якщо шуканий студент відсутній
int BinSearch(const Student* p, const int N, const string prizv,
    const Specialnist spec, const int matematyka)
{
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        if (p[m].prizv == prizv && p[m].spec == spec && p[m].matematyka == matematyka)
            return m;                               // знайшли
        if ((specStr[p[m].spec] < specStr[spec])
            ||
            (p[m].spec == spec &&
                p[m].matematyka < matematyka)
            ||
            (p[m].spec == spec &&
                p[m].matematyka == matematyka &&
                p[m].prizv < prizv))
        {
            L = m + 1;                              // шуканий - правіше від m
        }
        else
        {
            R = m - 1;                              // шуканий - лівіше від m
        }
    } while (L <= R);
    return -1;                                      // не знайшли
}

// індексне впорядкування: будує індексний масив, який задає порядок
// за назвою спеціальності, оцінкою з математики, прізвищем
int* IndexSort(const Student* p, const int N)
{ // використовуємо метод вставки для формування індексного масиву
    int* I = new int[N];                // створили індексний масив

    for (int i = 0; i < N; i++)
        I[i] = i;                       // заповнили його початковими даними

    int i, j, value;                    // починаємо сортувати масив індексів
    for (i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
            j >= 0 && ((specStr[p[I[j]].spec] > specStr[p[value].spec])
                ||
                (p[I[j]].spec == p[value].spec &&
                    p[I[j]].matematyka > p[value].matematyka)
                ||
                (p[I[j]].spec == p[value].spec &&
                    p[I[j]].matematyka == p[value].matematyka &&
                    p[I[j]].prizv > p[value].prizv));
            j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }
    return I;
}

// вивід масиву у вигляді таблиці в порядку, заданому індексним масивом I
void PrintIndexSorted(const Student* p, const int* I, const int N)
{ // аналогічно функції Print(), але замість звертання p[i]...
  // використовуємо доступ за допомогою індексного масиву I: p[I[i]]...
    cout << "Список студентів (індексне впорядкування):" << endl;
    cout << "==============================================================================================================="
        << endl;
    cout << "|  №  |   Прізвище    | Курс | Спеціальність | Фізика | Математика | Програмування | Чис. методи | Педагогіка |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------------------"
        << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(3) << right << i + 1
            << " | " << setw(13) << left << p[I[i]].prizv
            << " | " << setw(4) << right << p[I[i]].kurs
            << " | " << setw(13) << left << specStr[p[I[i]].spec]
            << " | " << setw(6) << right << p[I[i]].fizyka
            << " | " << setw(10) << right << p[I[i]].matematyka
            << " | ";

        switch (p[I[i]].spec)          // заповнюємо лише клітинку свого предмету
        {
        case KN:
            cout << setw(13) << right << p[I[i]].programuvannia
                << " | " << setw(11) << " "
                << " | " << setw(10) << " " << " |" << endl;
            break;
        case INF:
            cout << setw(13) << " "
                << " | " << setw(11) << right << p[I[i]].chyselni_metody
                << " | " << setw(10) << " " << " |" << endl;
            break;
        case ME:
        case FI:
        case TN:
            cout << setw(13) << " "
                << " | " << setw(11) << " "
                << " | " << setw(10) << right << p[I[i]].pedagogika << " |" << endl;
            break;
        }
    }
    cout << "==============================================================================================================="
        << endl;
    cout << endl;
}