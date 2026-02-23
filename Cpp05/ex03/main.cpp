#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// initialiser le générateur de nombres aléatoires
	std::srand(std::time(NULL));
	
	std::cout << "=== Test 1: Intern crée un ShrubberyCreationForm ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;
		
		form = someRandomIntern.makeForm("shrubbery creation", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}

	std::cout << "\n=== Test 2: Intern crée un RobotomyRequestForm ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;
		
		form = someRandomIntern.makeForm("robotomy request", "Target");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}

	std::cout << "\n=== Test 3: Intern crée un PresidentialPardonForm ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;
		
		form = someRandomIntern.makeForm("presidential pardon", "Arthur");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}

	std::cout << "\n=== Test 4: Intern ne peut pas créer un formulaire inconnu ===" << std::endl;
	{
		Intern someRandomIntern;
		AForm* form;
		
		form = someRandomIntern.makeForm("unknown form", "Target");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
		else
		{
			std::cout << "Form creation returned NULL" << std::endl;
		}
	}

	std::cout << "\n=== Test 5: Workflow complet - Intern + Bureaucrat ===" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm* form;
		
		// Créer et exécuter un formulaire shrubbery
		form = intern.makeForm("shrubbery creation", "home");
		if (form)
		{
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
		
		std::cout << std::endl;
		
		// Créer et exécuter un formulaire robotomy
		form = intern.makeForm("robotomy request", "Marvin");
		if (form)
		{
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
		
		std::cout << std::endl;
		
		// Créer et exécuter un formulaire presidential
		form = intern.makeForm("presidential pardon", "Zaphod");
		if (form)
		{
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Plusieurs Interns ===" << std::endl;
	{
		Intern intern1;
		Intern intern2;
		Intern intern3;
		AForm* forms[3];
		
		forms[0] = intern1.makeForm("shrubbery creation", "garden");
		forms[1] = intern2.makeForm("robotomy request", "victim");
		forms[2] = intern3.makeForm("presidential pardon", "prisoner");
		
		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
			{
				std::cout << *forms[i] << std::endl;
				delete forms[i];
			}
		}
	}

	std::cout << "\n=== Test 7: Test avec grade insuffisant ===" << std::endl;
	try
	{
		Intern intern;
		Bureaucrat lowLevel("LowLevel", 150);
		AForm* form;
		
		form = intern.makeForm("presidential pardon", "Someone");
		if (form)
		{
			std::cout << *form << std::endl;
			lowLevel.signForm(*form);  // Devrait échouer
			lowLevel.executeForm(*form);  // Devrait échouer
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
