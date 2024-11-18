#include <iostream>
#include "permutations.hpp"
#include "locale.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "RUS");
    Permutations p(3, 5);
    cout << "������� ������������ �� 3 ��� (�������� ��������), ����� ������: ";
    cin >> p;
    cout << "������������ P: " << p << endl;
    Permutations q(3, 5);
    cout << "������� ������ ������������ �� 3 ��� (�������� ��������), ����� ������: ";
    cin >> q;
    cout << "������������ Q: " << q << endl;
    Permutations composed = p.composition(q);
    cout << "���������� P � Q: " << composed << endl;
    Permutations abcd = q.composition(p);
    cout << "���������� Q and P: " << abcd << endl;
    int arg;
    cout << "������� �������� ��� ������ �������� � P: ";
    cin >> arg;
    int val = p.find_value(arg);
    if (val != -1) {
        cout << "�������� ��� ��������� " << arg << " � P: " << val << endl;
    }
    cout << "���������� ������������ �������� 4 � P." << endl;
    p.add_fixed_element(4);
    cout << "������������ P ����� ����������: " << p << endl;
    int fixedCount = p.count_fixed_elements();
    cout << "����� ����������� ��������� � P: " << fixedCount << endl;
    cout << "�������� ���������� �������� �� P." << endl;
    p.delete_last_element();
    cout << "������������ P ����� ��������: " << p << endl;
    if (p == q) {
        cout << "������������ P � Q �����." << endl;
    }
    else {
        cout << "������������ P � Q �� �����." << endl;
    }
    return 0;
}