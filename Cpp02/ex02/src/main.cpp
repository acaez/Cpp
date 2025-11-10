#include "../inc/Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "\nTests d'incrémentation/décrémentation:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    std::cout << "\nTests de min()/max():" << std::endl;
    std::cout << "Min(a,b): " << Fixed::min(a, b) << std::endl;
    std::cout << "Max(a,b): " << Fixed::max(a, b) << std::endl;

    Fixed c(42.42f);
    Fixed d(21.21f);
    
    Fixed e(42);
    Fixed f(21);

    std::cout << "\nTests avec float:" << std::endl;
    std::cout << "c (float): " << c << std::endl;
    std::cout << "d (float): " << d << std::endl;
    std::cout << "e (int): " << e << std::endl;
    std::cout << "f (int): " << f << std::endl;
    
    std::cout << "\nOpération:" << std::endl;
    std::cout << "e + f = " << e + f << std::endl;
    std::cout << "e * f = " << e * f << std::endl;
    std::cout << "c - d = " << c - d << std::endl;
    std::cout << "\nTest de division:" << std::endl;
    try 
    {
        std::cout << "c / d = " << c / d << std::endl;
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Exception attrapée: " << e.what() << std::endl;
    }

    std::cout << "\nConversions:" << std::endl;
    std::cout << "c.toInt(): " << c.toInt() << std::endl;
    std::cout << "e.toFloat(): " << e.toFloat() << std::endl;

    std::cout << "\nComparaison:" << std::endl;
    std::cout << "c == d: " << (c == d) << std::endl;
    std::cout << "c != d: " << (c != d) << std::endl;
    std::cout << "c < d: " << (c < d) << std::endl;
    std::cout << "c > d: " << (c > d) << std::endl;
    std::cout << "c <= d: " << (c <= d) << std::endl;
    std::cout << "c >= d: " << (c >= d) << std::endl;

    return 0;
}