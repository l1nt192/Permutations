#include <iostream>
#include "permutations.hpp"
#include "locale.h"
using namespace std;
int main() {
    setlocale(LC_ALL, "RUS");
    Permutations p(3, 5);
    cout << "Введите перестановку из 3 пар (аргумент значение), через пробел: ";
    cin >> p;
    cout << "Перестановка P: " << p << endl;
    Permutations q(3, 5);
    cout << "Введите вторую перестановку из 3 пар (аргумент значение), через пробел: ";
    cin >> q;
    cout << "Перестановка Q: " << q << endl;
    Permutations composed = p.composition(q);
    cout << "Композиция P и Q: " << composed << endl;
    Permutations abcd = q.composition(p);
    cout << "Композиция Q and P: " << abcd << endl;
    int arg;
    cout << "Введите аргумент для поиска значения в P: ";
    cin >> arg;
    int val = p.find_value(arg);
    if (val != -1) {
        cout << "Значение для аргумента " << arg << " в P: " << val << endl;
    }
    cout << "Добавление неподвижного элемента 4 к P." << endl;
    p.add_fixed_element(4);
    cout << "Перестановка P после добавления: " << p << endl;
    int fixedCount = p.count_fixed_elements();
    cout << "Число неподвижных элементов в P: " << fixedCount << endl;
    cout << "Удаление последнего элемента из P." << endl;
    p.delete_last_element();
    cout << "Перестановка P после удаления: " << p << endl;
    if (p == q) {
        cout << "Перестановки P и Q равны." << endl;
    }
    else {
        cout << "Перестановки P и Q не равны." << endl;
    }
    return 0;
}