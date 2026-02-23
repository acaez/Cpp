#include "Form.hpp"

// constructeur par défaut
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

// constructeur paramétrique
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// constructeur de copie
Form::Form(const Form& src) 
	: _name(src._name), _isSigned(src._isSigned), 
	  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
}

// opérateur d'affectation
Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		_isSigned = rhs._isSigned;
	return *this;
}

// destructeur
Form::~Form()
{
}

// accesseurs
const std::string& Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{
	return _gradeToExecute;
}

// méthode de signature
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// exceptions
const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

// surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form " << f.getName() 
	   << ", signed: " << (f.isSigned() ? "yes" : "no")
	   << ", grade to sign: " << f.getGradeToSign()
	   << ", grade to execute: " << f.getGradeToExecute();
	return os;
}
