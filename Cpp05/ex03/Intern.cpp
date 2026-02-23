#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Fonctions statiques pour créer chaque type de formulaire
static AForm* createShrubberyForm(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

// Structure pour associer un nom de formulaire à sa fonction de création
struct FormCreator
{
	std::string	name;
	AForm*		(*creator)(const std::string&);
};

// Constructeur par défaut
Intern::Intern()
{
}

// Constructeur de copie
Intern::Intern(const Intern& src)
{
	(void)src;
}

// Opérateur d'affectation
Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return *this;
}

// Destructeur
Intern::~Intern()
{
}

// Méthode makeForm
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	// Tableau de correspondances nom -> fonction de création
	FormCreator forms[] = {
		{"shrubbery creation", &createShrubberyForm},
		{"robotomy request", &createRobotomyForm},
		{"presidential pardon", &createPresidentialForm}
	};
	
	// Parcourir le tableau pour trouver le bon formulaire
	for (int i = 0; i < 3; i++)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(target);
		}
	}
	
	// Si aucun formulaire ne correspond
	std::cout << "Intern cannot create " << formName << " form because it doesn't exist" << std::endl;
	return NULL;
}
