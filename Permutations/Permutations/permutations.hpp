#include <iostream>
using namespace std;
class Permutations {
private:
    struct Couple {
        int argument;
        int value;
    };

    Couple* couple;
    int size;
    int capacity;

    void resize();

public:

    Permutations(int s = 0, int cap = 5);
    Permutations(const Permutations& p);
    Permutations& operator=(const Permutations& other);
    ~Permutations();
    int find_value(int argument);
    Permutations composition(Permutations other);
    void add_fixed_element(int argument);
    int count_fixed_elements();
    void delete_last_element();
    Couple& operator[](int index);
    const Couple& operator[](int index) const;
    bool operator==(const Permutations& other) const;
    bool operator!=(const Permutations& other) const;
    friend ostream& operator<<(ostream& stream, Permutations& p);
    friend istream& operator>>(istream& in, Permutations& p);
};
