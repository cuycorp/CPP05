#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Default constructor
Intern::Intern(void)
{
    std::cout << "Intern Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Intern::Intern(const Intern &other)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
Intern &Intern::operator=(const Intern &other)
{
    (void) other;
    std::cout << "Intern Assignment operator called" << std::endl;
    return (*this);
}

// Destructor
Intern::~Intern(void)
{
    std::cout << "Intern Destructor called" << std::endl;
    return ;
}

static void printStr(std::string formName)
{
    std::cout << "Intern creates " << formName << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string targetForm)
{
    int i= 0;
    std::string possibleForm[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    while (i < 3)
    {
        if (possibleForm[i] == formName)
            break;
        i++;
    }
    switch(i)
    {
        case (0) :
        {
            printStr(possibleForm[0]);
            return (new PresidentialPardonForm(targetForm));
        }
        case (1) :
        {
            printStr(possibleForm[1]);
            return (new RobotomyRequestForm(targetForm));
        }
        case (2) :
        {
            printStr(possibleForm[2]);
            return (new ShrubberyCreationForm(targetForm));
        }
        default :
        {
            std::cout << "form does not exist.\n";
            return (NULL);
        }
    }
}
        /*
        if, else if: presidential, shurbery, robotomy
            call constuctor 
        retunr object 
        */