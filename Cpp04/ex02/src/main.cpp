#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    
    //std::cout << "=== Test Abstract Animal Class ===" << std::endl;
    //Animal test;
    
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n======== Polymorphic calls ========" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    std::cout << "\n======== Deep Copy Test ========" << std::endl;
    Dog basic;
    basic.setIdea(0, "Original idea");
    
    std::cout << "Basic: " << basic.getIdea(0) << std::endl;
    {
        std::cout << "\nCreating deep copy..." << std::endl;
        Dog deep = basic;
        std::cout << "Deep: " << deep.getIdea(0) << std::endl;
        std::cout << "\nModifying ONLY the deep copy" << std::endl;
        deep.setIdea(0, "Modified idea");
        std::cout << "Basic idea 0: " << basic.getIdea(0) << " (unchanged!)" << std::endl;
        std::cout << "Deep idea 0:  " << deep.getIdea(0) << " (modified)" << std::endl;
    }
    std::cout << "\nAfter scope exit: " << basic.getIdea(0) << std::endl;
    std::cout << "Basic idea 0: " << basic.getIdea(0) << std::endl;
    
    std::cout << "\n======== Cleanup ========" << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}