#include "Bureaucrat.hpp"
#include <stdexcept>

#define RESET   "\033[0m"
#define PINK    "\033[35m"

int main(void)
{
	std::cout << PINK << std::endl << "Test ex00" << RESET << std::endl;

	std::cout << PINK << std::endl << "Testing range check of constructor" << RESET << std::endl;
	try
	{
		Bureaucrat employee1("Sam", 1500);
        Bureaucrat employee2("Olaf", -10);
        Bureaucrat employee3("Elsa", 11);
	}
	catch(std::out_of_range& e)
	{
		std::cerr << "Range error : " << e.what() << std::endl;
	}
    
	std::cout << PINK << std::endl << "Test increasing" << RESET << std::endl;
	Bureaucrat bob("Bob", 2);
	std::cout << bob;
	try
	{
		bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;
	
	try
	{
	bob.incrementGrade();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob;



	std::cout << PINK << std::endl << "Test decreasing" << RESET << std::endl;
	Bureaucrat tim("Tim", 149);
	std::cout << tim;
	try
	{
		tim.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;
	
	try
	{
	tim.decrementGrade();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim;
	
	
}