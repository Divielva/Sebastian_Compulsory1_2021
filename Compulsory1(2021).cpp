#include <iostream>
#include <string>
#include <set>

//parent class for the animals where i initialize the speak function
class Animal {
public:
    std::string name;
    std::string Place_of_birth;
    int age;

    virtual void Speak() {};

private:
    int Animal_ID;
};

//The children classes that inherit from the parent class, each one with individual outpouts
class Dog : public Animal {
public:
    void Speak() {
        std::cout << "Woof" << std::endl;
    }
};

class Bird : public Animal {
public:
    void Speak() {
        std::cout << "Chirp" << std::endl;
    }
};

class Cat : public Animal {
public:
    void Speak() {
        std::cout << "Meow" << std::endl;
    }
};

//my box class where i set up operators that gets overloaded
//function is to sort the boxes in a descending matter
class Box {
public:
    Box(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int x, y;

    Box operator+(Box& b) const {
        return Box(this->x + b.x, this->y + b.y);
    }

    Box operator*(Box& b) const {
        return Box(this->x * b.x, this->y * b.y);
    }

    bool operator<(const Box& b) const {
        return this->x * this->y <= b.x * b.y;
    }

    void print() {
        std::cout << x << ", " << y << std::endl;
    }

};

//template to get two different data types and print them together
//I feel i need to learn more of WHY we have templates and use it like this, but i feel i will understand it better once we start using it regularly
template<class T, class E>
class Value {
public:
    T first;
    E second;

    Value(T first, E second) {
        this->first = first;
        this->second = second;
    }

    void print() {
        std::cout << first + second << std::endl;
    }
};

int main()
{
    std::cout << "Animal subclasses" << std::endl;
    Animal* anim;

    Dog dog;
    Bird bird;
    Cat cat;

    //here i call the speak functions for the classes
    dog.Speak();
    bird.Speak();
    cat.Speak();

    anim = &dog;
    anim->Speak();

    //Here we overload the operator and gets it to to sort the boxes
    std::cout << "\nOperator overloading" << std::endl;
    Box a = Box(1, 10);
    Box b = Box(30, 2);

    Box c = a + b;
    c.print();

    c = a * b;
    c.print();

    bool test = a < b;
    std::cout << test << std::endl;

    //here the sorting for loop begins
    std::cout << "\nExample using a set which implicitly uses operator< (Sizes generated descendingly, to show sorting happens)" << std::endl;
    std::set<Box> b_set;

    for (int i = 5; i > 0; i--)
        b_set.insert(Box(2 * i, i * i));

    for (Box b : b_set)
        b.print();

    //the template, i get 1 and 5 to merge together and 5 and 10.9 to merge
    //i get the way the function and template work, just need more examples of uses in codes to properly understand the implementation
    std::cout << "\nTemplate examples, template<class T, class E>" << std::endl;

    Value<int, int> val = Value<int, int>(1, 5);
    val.print();

    Value<int, float> val2 = Value<int, float>(5, 10.9f);
    val2.print();
}