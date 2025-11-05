#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    Dog basic;
    basic.setIdea(0, "Basic idea");
    
    {
        Dog tmp = basic;
        tmp.setIdea(0, "Tmp idea");
        std::cout << "Basic: " << basic.getIdea(0) << std::endl;
        std::cout << "Tmp: " << tmp.getIdea(0) << std::endl;
    }
    
    std::cout << "After scope: " << basic.getIdea(0) << std::endl;

    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}