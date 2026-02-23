#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

// implementation de la classe Bureaucrat
class Bureaucrat
{
	// attribus privés
	private:
		const std::string	_name; // pas modifiable après construction
		int					_grade; // modifiable seulement via les méthodes incrementGrade et decrementGrade
	// méthodes publiques
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();
		const std::string&	getName() const;
		int					getGrade() const;
		void	incrementGrade();
		void	decrementGrade();
		// classes d'exceptions imbriquées
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
};

// surcharge de l'opérateur d'insertion pour afficher un bureaucrat
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif