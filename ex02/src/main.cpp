#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET   "\033[0m"
#define PINK    "\033[35m"
#define BLUE    "\033[34m"

int main()
{
    std::cout << BLUE <<  "===== Creating Bureaucrats =====" << RESET << std::endl;
    Bureaucrat boss("Boss", 1);
    Bureaucrat president("President", 5);
    Bureaucrat intern("Intern", 150);

    std::cout << std::endl;

    std::cout << BLUE << "===== Creating PresidentialPardonForm =====" << RESET << std::endl;
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << std::endl;

    std::cout << BLUE << "===== Attempt execution before signing =====" << RESET << std::endl;
    boss.executeForm(pardon);

    std::cout << std::endl;

    std::cout << BLUE << "===== Attempt signing with insufficient grade =====" << RESET <<  std::endl;
    intern.signForm(pardon);

    std::cout << std::endl;

    std::cout << BLUE << "===== Signing with sufficient grade =====" << RESET << std::endl;
    president.signForm(pardon);

    std::cout << std::endl;

    std::cout << BLUE << "===== Attempt execution with insufficient grade =====" << RESET << std::endl;
    president.executeForm(pardon);

    std::cout << std::endl;

    std::cout << BLUE << "===== Successful execution =====" << RESET << std::endl;
    boss.executeForm(pardon);

    std::cout << std::endl;

    return 0;
}
