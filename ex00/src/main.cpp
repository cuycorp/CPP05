#include "Bureaucrat.hpp"

#define RESET   "\033[0m"
#define PINK    "\033[35m"

int main(void)
{
	//////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << PINK << std::endl << "Testing range check of constructor" << RESET << std::endl;
	{
		try
		{
			//Bureaucrat employee1("Sam", 1500);
    	    //Bureaucrat employee2("Olaf", -10);
    	    Bureaucrat employee3("Elsa", 11);
		}
		catch(std::exception& e)
		{
			std::cerr << "Range error: " << e.what() << std::endl;
		}
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	std::cout << PINK << std::endl << "Test increasing and decreasing" << RESET << std::endl;
	{
		Bureaucrat employee4("Bob", 150);
		//std::cout << employee4 << std::endl;
		//try
		//{
		//	employee4.incrementGrade();
		//}
		//catch(const std::exception& e)
		//{
		//	std::cerr << "Exception caught: " << e.what() << std::endl;
		//}
		/////////////////////////////////////////////////
		
		std::cout << employee4 << std::endl;
		try
		{
		employee4.decrementGrade();
		}
		catch(const std::exception& e)
		{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		}
		std::cout << employee4 << std::endl;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	
}
