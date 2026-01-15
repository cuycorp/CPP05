#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define RESET   "\033[0m"
#define PINK    "\033[35m"
#define BLUE    "\033[34m"

int main()
{
    std::cout << std::endl;
    std::cout << BLUE <<  "===== Creating rank of Bureaucrats =====" << RESET << std::endl;
    Bureaucrat president("President", 5);
    Bureaucrat vpresident("Vice president", 45);
    Bureaucrat intern("Intern", 137);
    std::cout << std::endl;

    std::cout << BLUE << "===== Creating Forms =====" << RESET << std::endl;
    AForm *forms[4];
    forms[0] = new PresidentialPardonForm("crime");
    forms[1] = new PresidentialPardonForm("crime_notSigned");
    forms[2] = new RobotomyRequestForm("taxes");
    forms[3] = new ShrubberyCreationForm("house");
    
    std::cout << BLUE << "===== Signing Forms =====" << RESET << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (i != 1)
        {    
            std::cout << "Signing: " << forms[i]->getName() << std::endl;
            forms[i]->beSigned(president);
        }
    }
    std::cout << BLUE << "===== Executing Forms =====" << RESET << std::endl;
    std::cout << PINK << "===== Presidential form signed =====" << RESET << std::endl;
    intern.executeForm(*forms[0]);
    president.executeForm(*forms[0]);
    std::cout << std::endl;

    std::cout << PINK << "===== Presidential form not signed =====" << RESET << std::endl;
    president.executeForm(*forms[1]);
    std::cout << std::endl;

    std::cout << PINK << "===== Robotomy Request Form =====" << RESET << std::endl;
    intern.executeForm(*forms[2]);
    vpresident.executeForm(*forms[2]);
    std::cout << std::endl;

    std::cout << PINK << "===== ShrubberyCreationForm =====" << RESET << std::endl;
    intern.executeForm(*forms[3]);
    std::cout << std::endl;

    return 0;
}
