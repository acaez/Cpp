#include "PresidentialPardonForm.hpp"

// constructeur par défaut
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Presidential Pardon", 25, 5), _target("default")
{
}

// constructeur paramétrique
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("Presidential Pardon", 25, 5), _target(target)
{
}

// constructeur de copie
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm(src), _target(src._target)
{
}

// opérateur d'affectation
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

// destructeur
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// accesseur
const std::string& PresidentialPardonForm::getTarget() const
{
	return _target;
}

// implémentation de l'action d'exécution
void PresidentialPardonForm::executeAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
