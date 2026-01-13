#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    std::cout << "Copy constructor called" << std::endl;
    (void) other;
    return ;
}

// Assignment operator overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "Assignment operator called" << std::endl;
    (void) other;
    return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

