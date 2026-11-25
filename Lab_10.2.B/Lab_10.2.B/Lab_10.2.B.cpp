#include <iostream>
#include <string>
#include <Windows.h>          // забезпечення відображення кирилиці
#include "Student.h"

using namespace std;

int main()
{                             // забезпечення відображення кирилиці:
    SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
    SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу

    int N = InputInt("Введіть кількість студентів N (1-100): ", 1, 100);

    Student* p = new Student[N];    // динамічний масив структур

    string      prizv;              // ключі бінарного пошуку
    Specialnist spec;
    int         matematyka;
    int         found;              // результат бінарного пошуку
    int* I;                  // індексний масив

    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - введення даних з клавіатури" << endl;
        cout << " [2] - вивід даних на екран" << endl;
        cout << " [3] - фізичне впорядкування даних" << endl;
        cout << " [4] - бінарний пошук студента за прізвищем, спеціальністю" << endl;
        cout << "       та оцінкою з математики (після фізичного впорядкування)" << endl;
        cout << " [5] - індексне впорядкування та вивід даних" << endl << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        if (cin.fail())             // введено не число (наприклад, літери)
        {
            cin.clear();            // скидаємо помилку потоку
            menuItem = -1;          // неіснуючий пункт - спрацює default
        }
        cin.ignore(1000, '\n');     // прибираємо залишок рядка (Enter або літери)
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            Create(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            Sort(p, N);
            cout << "Масив фізично впорядковано." << endl;
            break;
        case 4:
            cout << "Введіть ключі пошуку:" << endl;
            spec = (Specialnist)InputInt("   спеціальність (0 - Комп. науки, 1 - Інформатика, "
                "2 - Мат. та екон., 3 - Фіз. та інф., 4 - Труд. навч.): ",
                0, 4);
            matematyka = InputInt("   оцінка з математики (1-5): ", 1, 5);
            cout << "   прізвище: "; getline(cin, prizv);
            cout << endl;

            found = BinSearch(p, N, prizv, spec, matematyka);
            if (found != -1)
                cout << "Знайдено студента в позиції " << found + 1 << endl;
            else
                cout << "Шуканого студента не знайдено" << endl;
            break;
        case 5:
            I = IndexSort(p, N);
            PrintIndexSorted(p, I, N);
            delete[] I;             // звільняємо пам'ять індексного масиву
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    delete[] p;
    return 0;
}