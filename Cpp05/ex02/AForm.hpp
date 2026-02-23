#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
	protected:
		// méthode virtuelle pure que les classes filles doivent implémenter
		virtual void		executeAction() const = 0;
	
	public:
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& src);
		AForm& operator=(const AForm& rhs);
		virtual ~AForm();
		
		const std::string&	getName() const;
		bool				isSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		
		void				beSigned(const Bureaucrat& bureaucrat);
		void				execute(const Bureaucrat& executor) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
