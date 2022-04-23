#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

//  ����� �������.
void showArr(int arr[], int length);
// ������ 1.
void threeMax(int& a, int& b, int& c);
// ������ 2.
int& negativeEl(int z[], int length);
// ������ 3.
void zero(int arr1[], int L1, int arr2[], int L2);

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int a, b, c;

    // ������ 1.
    cout << "\t������ 1.\n������� ��� �����: ";
    cin >> a >> b >> c;
    threeMax(a, b, c);
    cout << "���������� ���� ������� ����� � ������������� ��������: " << a << ", " << b << ", " << c << "\n\n";

    // ������ 2.
    cout << "\t������ 2.\n";
    int const size = 10;
    int z2[size];
    showArr(z2, size);
    cout << "������ ������������� ������� ������� ��� ������ ������� ����� �������, ���� ���������� �������������: " << negativeEl(z2, size) << "\n\n";

    // ������ 3.
    int const size1 = 10;
    int z3_1[size1];
    int const size2 = 10;
    int z3_2[size2];
    cout << "\t������ 3.\n������ ";
    showArr(z3_1, size1);
    cout << "������ ";
    showArr(z3_2, size2);
    cout << "������ ������ � ���������� ����������:\n[";
    zero(z3_1, size1, z3_2, size2);
    cout << "\b\b]\n\n";


    return 0;
}
//  ����� �������.
void showArr(int arr[], int length) {
    cout << "������: \n[";
    for (int i = 0; i < length; i++) {
        *(arr + i) = rand() % (10 + 1 - (-5)) + (-5);
        cout << *(arr + i) << ", ";
    }
    cout << "\b\b]\n";
}

// ������ 1. ������ ��� �������� ���������� �� ������������
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

// ������ 2. ������� ������� �������������� �������� �������
int& negativeEl(int z[], int length) {
    for (int i = 0; i < length; i++)
        if (z[i] < 0)
            return z[i];
    return z[0];
}

// ������ 3. ��������� ��������� ������ �������
void zero(int arr1[], int L1, int arr2[], int L2) {
    for (int i = 0; i < L1; i++) {
        for (int j = 0; j < L2; j++)
            if (*(arr1 + i) == *(arr2 + j))
                *(arr2 + j) = 0;
    }
    for (int i = 0; i < L2; i++)
        cout << *(arr2 + i) << ", ";
}