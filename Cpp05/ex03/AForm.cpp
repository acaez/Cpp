#include "AForm.hpp"

// constructeur par défaut
AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

// constructeur paramétrique
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// constructeur de copie
AForm::AForm(const AForm& src) 
	: _name(src._name), _isSigned(src._isSigned), 
	  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

// opérateur d'affectation
AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

// destructeur
AForm::~AForm()
{
}

// accesseurs
const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return _gradeToExecute;
}

// méthode de signature
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// méthode d'exécution
void AForm::execute(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

// exceptions
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

// surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Form " << f.getName() 
	   << ", signed: " << (f.isSigned() ? "yes" : "no")
	   << ", grade to sign: " << f.getGradeToSign()
	   << ", grade to execute: " << f.getGradeToExecute();
	return os;
}
