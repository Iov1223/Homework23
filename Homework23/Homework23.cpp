#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//  Вывод массива.
void showArr(int arr[], int length);
// Задача 1.
void threeMax(int& a, int& b, int& c);
// Задача 2.
int& negativeEl(int z[], int length);
// Задача 3.
void zero(int arr1[], int L1, int arr2[], int L2);

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int a, b, c;

    // Задача 1.
    cout << "\tЗадача 1.\nВведите три числа: ";
    cin >> a >> b >> c;
    threeMax(a, b, c);
    cout << "Приведение всех введёных чисел к максимальному значннию: " << a << ", " << b << ", " << c << "\n\n";

    // Задача 2.
    cout << "\tЗадача 2.\n";
    int const size = 10;
    int z2[size];
    showArr(z2, size);
    cout << "Первый отрицательный элемент массива или первый элеиент всего массива, если отсуствует отрицательный: " << negativeEl(z2, size) << "\n\n";

    // Задача 3.
    int const size1 = 10;
    int z3_1[size1];
    int const size2 = 10;
    int z3_2[size2];
    cout << "\tЗадача 3.\nПервый ";
    showArr(z3_1, size1);
    cout << "Второй ";
    showArr(z3_2, size2);
    cout << "Второй Массив с обнулёнными элементами:\n[";
    zero(z3_1, size1, z3_2, size2);
    cout << "\b\b]\n\n";


    return 0;
}
//  Вывод массива.
void showArr(int arr[], int length) {
    cout << "Массив: \n[";
    for (int i = 0; i < length; i++) {
        *(arr + i) = rand() % (10 + 1 - (-5)) + (-5);
        cout << *(arr + i) << ", ";
    }
    cout << "\b\b]\n";
}

// Задача 1. Меняет все значения переменных на максимальное
void threeMax(int& a, int& b, int& c) {
    if (a > b && a > c) {
        b = a;
        c = a;
    }
    else
        if (a < b && b > c) {
            a = b;
            c = b;
        }
        else
            a = c;
    b = c;
}

// Задача 2. Возврат первого отрицательного элемента массива
int& negativeEl(int z[], int length) {
    for (int i = 0; i < length; i++)
        if (z[i] < 0)
            return z[i];
    return z[0];
}

// Задача 3. Обнуление элементов втрого массива
void zero(int arr1[], int L1, int arr2[], int L2) {
    for (int i = 0; i < L1; i++) {
        for (int j = 0; j < L2; j++)
            if (*(arr1 + i) == *(arr2 + j))
                *(arr2 + j) = 0;
    }
    for (int i = 0; i < L2; i++)
        cout << *(arr2 + i) << ", ";
}