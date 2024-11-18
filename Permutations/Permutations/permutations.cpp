#include "permutations.hpp"
void Permutations::resize() {
    capacity = capacity * 2;
    Couple* new_couple = new Couple[capacity];
    for (int i = 0; i < size; i++) {
        new_couple[i] = couple[i];
    }
    delete[] couple;
    couple = new_couple;
}

Permutations::Permutations(int s, int cap) {
    size = s;
    capacity = cap;
    couple = new Couple[capacity];
}

Permutations::Permutations(const Permutations& other) {
    size = other.size;
    capacity = other.capacity;
    couple = new Couple[capacity];
    for (int i = 0; i < size; i++) {
        couple[i] = other.couple[i];
    }
}

Permutations& Permutations::operator=(const Permutations& other) {
    if (this == &other) {
        return *this;
    }
    delete[] couple;
    size = other.size;
    capacity = other.capacity;
    couple = new Couple[capacity];

    for (int i = 0; i < size; i++) {
        couple[i] = other.couple[i];
    }
    return *this;
}
Permutations::~Permutations() {
    delete[] couple;
}
int Permutations::find_value(int argument) {
    for (int i = 0; i < size; i++) {
        if (couple[i].argument == argument) {
            return couple[i].value;
        }
    }
    cout << "Нет такого аргумента" << endl;
    return -1;
}
Permutations Permutations::composition( Permutations other) {
    if (size != other.size) {
        cout << "Размеры перестановок не равны" << endl;
        return *this;
    }
    Permutations result(size, capacity);
    for (int i = 0; i < size; i++) {
        result.couple[i].argument = couple[i].argument;
        result.couple[i].value = other.find_value(couple[i].value);
    }
    return result;
}
void Permutations::add_fixed_element(int argument) {
    if (size == capacity) {
        resize();
    }
    couple[size].argument = argument;
    couple[size].value = argument;
    size++;
}
int Permutations::count_fixed_elements() {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (couple[i].argument == couple[i].value) {
            count++;
        }
    }
    return count;
}
void Permutations::delete_last_element() {
    if (size > 0) {
        size--;
    }
    else {
        cout << "Невозможно удалить элемент из пустого массива" << endl;
    }
}
Permutations::Couple& Permutations::operator[](int index) {
    return couple[index];
}
const Permutations::Couple& Permutations::operator[](int index) const {
    return couple[index];
}
bool Permutations::operator==(const Permutations& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (couple[i].argument != other.couple[i].argument || couple[i].value != other.couple[i].value) {
            return false;
        }
    }
    return true;
}
bool Permutations::operator!=(const Permutations& other) const {
    return !(*this == other);
}


ostream& operator<<(ostream& stream, Permutations& p)
{
    for (int i = 0; i < p.size; i++) {
        stream << "(" << p.couple[i].argument << " " << p.couple[i].value << ") ";
    }
    return stream;
}

istream& operator>>(istream& in, Permutations& p)
{
    for (int i = 0; i < p.size; i++) {
        in >> p.couple[i].argument >> p.couple[i].value;
    }
    return in;
}
