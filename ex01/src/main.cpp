#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "\n=== Creation and Destruction Polymorphism ===" << std::endl;
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << "\n" << std::endl;
    delete j;
    delete i;
    
    std::cout << "\n=== Array of Animals ===" << std::endl;
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();
    std::cout << "\n" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];
    
    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    Dog basic;
    basic.setIdea(0, "Basic dog idea");
    {
        Dog tmp = basic;
        std::cout << "\nOriginal dog idea: " << basic.getIdea(0) << std::endl;
        std::cout << "Copied dog idea: " << tmp.getIdea(0) << std::endl;
        
        tmp.setIdea(0, "Modified copy idea");
        std::cout << "\nAfter modification:" << std::endl;
        std::cout << "Original dog idea: " << basic.getIdea(0) << std::endl;
        std::cout << "Copied dog idea: " << tmp.getIdea(0) << std::endl;
    }
    
    return 0;
}