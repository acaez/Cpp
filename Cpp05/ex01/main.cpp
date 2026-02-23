#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== Test 1: Création de Form valide ===" << std::endl;
	try
	{
		Form form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Form avec grade trop haut ===" << std::endl;
	try
	{
		Form form2("Invalid Form", 0, 50);
		std::cout << form2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Form avec grade trop bas ===" << std::endl;
	try
	{
		Form form3("Invalid Form", 151, 50);
		std::cout << form3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Bureaucrat signe un form (grade suffisant) ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 30);
		Form form4("Request Form", 50, 25);
		std::cout << bob << std::endl;
		std::cout << form4 << std::endl;
		bob.signForm(form4);
		std::cout << form4 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Bureaucrat signe un form (grade insuffisant) ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 100);
		Form form5("Top Secret Form", 50, 25);
		std::cout << alice << std::endl;
		std::cout << form5 << std::endl;
		alice.signForm(form5);
		std::cout << form5 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Bureaucrat de grade 1 signe un form très restrictif ===" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		Form form6("Presidential Decree", 1, 1);
		std::cout << boss << std::endl;
		std::cout << form6 << std::endl;
		boss.signForm(form6);
		std::cout << form6 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Tentative de signature par un grade limite ===" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 50);
		Form form7("Borderline Form", 50, 25);
		std::cout << charlie << std::endl;
		std::cout << form7 << std::endl;
		charlie.signForm(form7);
		std::cout << form7 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 8: Tentative de signature par un grade juste insuffisant ===" << std::endl;
	try
	{
		Bureaucrat david("David", 51);
		Form form8("Borderline Form", 50, 25);
		std::cout << david << std::endl;
		std::cout << form8 << std::endl;
		david.signForm(form8);
		std::cout << form8 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
