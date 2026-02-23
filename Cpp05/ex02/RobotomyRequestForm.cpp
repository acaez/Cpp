#include "RobotomyRequestForm.hpp"

// constructeur par défaut
RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("Robotomy Request", 72, 45), _target("default")
{
}

// constructeur paramétrique
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("Robotomy Request", 72, 45), _target(target)
{
}

// constructeur de copie
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src), _target(src._target)
{
}

// opérateur d'affectation
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

// destructeur
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// accesseur
const std::string& RobotomyRequestForm::getTarget() const
{
	return _target;
}

// implémentation de l'action d'exécution
void RobotomyRequestForm::executeAction() const
{
	std::cout << "* DRILLING NOISES *" << std::endl;
	
	// 50% de chance de succès
	if (std::rand() % 2 == 0)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << "!" << std::endl;
}
