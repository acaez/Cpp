#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Test 1: Création valide ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade trop haut (0) ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade trop bas (151) ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment depuis grade 1 ===" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.incrementGrade();
		std::cout << top << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement depuis grade 150 ===" << std::endl;
	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrementGrade();
		std::cout << bottom << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Increment/Decrement valides ===" << std::endl;
	try
	{
		Bureaucrat middle("Middle", 75);
		std::cout << middle << std::endl;
		middle.incrementGrade();
		std::cout << "Après increment: " << middle << std::endl;
		middle.decrementGrade();
		std::cout << "Après decrement: " << middle << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Copy constructor ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 42);
		Bureaucrat copy(alice);
		std::cout << "Original: " << alice << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 8: Assignment operator ===" << std::endl;
	try
	{
		Bureaucrat john("John", 100);
		Bureaucrat jane("Jane", 50);
		std::cout << "Avant: " << john << std::endl;
		std::cout << "Avant: " << jane << std::endl;
		john = jane;
		std::cout << "Après assignment (name reste): " << john << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
