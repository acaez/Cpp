#include "ShrubberyCreationForm.hpp"

// constructeur par défaut
ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Shrubbery Creation", 145, 137), _target("default")
{
}

// constructeur paramétrique
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("Shrubbery Creation", 145, 137), _target(target)
{
}

// constructeur de copie
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src), _target(src._target)
{
}

// opérateur d'affectation
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return *this;
}

// destructeur
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// accesseur
const std::string& ShrubberyCreationForm::getTarget() const
{
	return _target;
}

// implémentation de l'action d'exécution
void ShrubberyCreationForm::executeAction() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	if (!file.is_open())
		throw std::runtime_error("Could not create file");
	
	file << "       ###" << std::endl;
	file << "      #o###" << std::endl;
	file << "    #####o###" << std::endl;
	file << "   #o#\\#|#/###" << std::endl;
	file << "    ###\\|/#o#" << std::endl;
	file << "     # }|{  #" << std::endl;
	file << "       }|{" << std::endl;
	file << std::endl;
	file << "      ,@@@@@@@," << std::endl;
	file << "  ,,,.   `@@@@@@/@@,  .oo8888o." << std::endl;
	file << " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	file << ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	file << "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	file << "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	file << "`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	file << "    |o|        | |         | |" << std::endl;
	file << "    |.|        | |         | |" << std::endl;
	file << " \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
	
	file.close();
}
