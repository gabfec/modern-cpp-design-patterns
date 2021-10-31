#include <iostream>

template <typename T>
struct Property
{
    T value;

    Property(T value)
    {
        *this = value;
    };

    operator T()
    {
        return value;
    }

    T operator=(T new_value)
    {
        std::cout << new_value << "\n";
        return value = new_value;
    }
};

struct Creature
{
    //int strength{10};
    //int agility{10};
    Property<int> strength{10};
    Property<int> agility{5};
};

int main()
{
    Creature c;
    c.strength = 15;

    return 0;
}