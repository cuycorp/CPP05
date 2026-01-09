#include "Form.hpp"
#include <stdexcept>

// Default constructor
Form::Form(void) _name("no name"), _isSigned(150), _gradeSign(150), _gradeExecute(150)
{
    std::cout << "Form Default constructor called" << std::endl;
    return ;
}

Form::Form(const std::string name, bool isSigned, const int gradeExecute, const int gradeSign): _name(name), _isSigned(isSigned)
{
    if (gradeExecute < 1)
        throw std::out_of_range("Form::GradeTooHighException");
    else if (gradeExecute > 150)
        throw std::out_of_range("Form::GradeTooLowException");
    else if (gradeSign < 1)
        throw std::out_of_range("Form::GradeTooHighException");
    else if (gradeSign > 150)
        throw std::out_of_range("Form::GradeTooLowException");
    else
        _gradeSign = gradeSign;
        _gradeExecute = gradeExecute;
    std::cout << "Form Default constructor with initialization called" << std::endl;
    return;
}

// Copy constructor
Form::Form(const Form &other): _name(other._name), _grade(other._grade)
{
    std::cout << "Form Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
Form &Form::operator=(const Form &other)
{
    std::cout << "Form Assignment operator called" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}

// Destructor
Form::~Form(void)
{
    std::cout << "Form Destructor called" << std::endl;
    return ;
}

