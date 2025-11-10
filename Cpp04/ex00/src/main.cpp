#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n=== Test par default Animal (avec virtual) ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;
    std::cout << "Type of j: " << j->getType() << std::endl;
    std::cout << "Type of i: " << i->getType() << std::endl;
    
    std::cout << std::endl;
    std::cout << "Sound of meta: ";
    meta->makeSound();
    std::cout << "Sound of j: ";
    j->makeSound();
    std::cout << "Sound of i: ";
    i->makeSound();
    std::cout << std::endl;

    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Test avec WrongAnimal (sans virtual) ===" << std::endl;
    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    WrongCat* real_wrong_cat = new WrongCat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << "wrong_meta type: " << wrong_meta->getType() << std::endl;
    std::cout << "wrong_cat type: " << wrong_cat->getType() << std::endl;
    std::cout << "real_wrong_cat type: " << real_wrong_cat->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    std::cout << "wrong_meta sound: ";
    wrong_meta->makeSound();
    std::cout << "wrong_cat sound: ";
    wrong_cat->makeSound();
    std::cout << "real_wrong_cat sound: ";
    real_wrong_cat->makeSound();
    std::cout << std::endl;

    delete wrong_meta;
    delete wrong_cat;
    delete real_wrong_cat;

    return 0;
}
