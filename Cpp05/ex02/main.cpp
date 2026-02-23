#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// initialiser le générateur de nombres aléatoires
	std::srand(std::time(NULL));
	
	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm shrub("home");
		
		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;
		
		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: ShrubberyCreationForm - Grade insuffisant pour exécuter ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 145);
		ShrubberyCreationForm shrub("garden");
		
		std::cout << alice << std::endl;
		std::cout << shrub << std::endl;
		
		alice.signForm(shrub);
		alice.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 40);
		RobotomyRequestForm robot("Bender");
		
		std::cout << charlie << std::endl;
		std::cout << robot << std::endl;
		
		charlie.signForm(robot);
		charlie.executeForm(robot);
		charlie.executeForm(robot);  // essai multiple pour voir l'aléatoire
		charlie.executeForm(robot);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: RobotomyRequestForm - Grade insuffisant pour signer ===" << std::endl;
	try
	{
		Bureaucrat david("David", 100);
		RobotomyRequestForm robot("Target");
		
		std::cout << david << std::endl;
		std::cout << robot << std::endl;
		
		david.signForm(robot);
		david.executeForm(robot);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << president << std::endl;
		std::cout << pardon << std::endl;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: PresidentialPardonForm - Grade insuffisant ===" << std::endl;
	try
	{
		Bureaucrat employee("Employee", 50);
		PresidentialPardonForm pardon("Criminal");
		
		std::cout << employee << std::endl;
		std::cout << pardon << std::endl;
		
		employee.signForm(pardon);
		employee.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Tentative d'exécution sans signature ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Someone");
		
		std::cout << boss << std::endl;
		std::cout << pardon << std::endl;
		
		// Ne pas signer le formulaire
		boss.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 8: Tous les formulaires avec un bureaucrate de grade 1 ===" << std::endl;
	try
	{
		Bureaucrat supreme("Supreme", 1);
		ShrubberyCreationForm shrub("office");
		RobotomyRequestForm robot("Assistant");
		PresidentialPardonForm pardon("Volunteer");
		
		std::cout << supreme << std::endl;
		
		supreme.signForm(shrub);
		supreme.executeForm(shrub);
		
		std::cout << std::endl;
		supreme.signForm(robot);
		supreme.executeForm(robot);
		
		std::cout << std::endl;
		supreme.signForm(pardon);
		supreme.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
