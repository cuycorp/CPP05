#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>

// Default constructor
Form::Form(void) : _name("no name"), _isSigned(150), _gradeSign(150), _gradeExecute(150)
{
    std::cout << "Form Default constructor called" << std::endl;
    return ;
}

Form::Form(const std::string name, bool isSigned, const int gradeExecute, const int gradeSign): _name(name), _isSigned(isSigned), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
    if (gradeExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeExecute > 150)
        throw Form::GradeTooLowException();
    else if (gradeSign < 1)
        throw Form::GradeTooHighException();
    else if (gradeSign > 150)
        throw Form::GradeTooLowException();
    std::cout << "Form Default constructor with initialization called" << std::endl;
    return;
}

// Copy constructor
Form::Form(const Form &other): _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
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

//Getters n Setters
const std::string Form::getName(void) const
{
    return (_name);
}

int Form::getExecuteGrade(void) const
{
    return(_gradeExecute);
}

int Form::getSignGrade(void) const
{
    return(_gradeSign);
}

int Form::getSignStatus(void) const
{
    return(_isSigned);
}

 std::ostream &operator<<(std::ostream &os, const Form &instance)
 {
    os << instance.getName() << ", form sign grade " << instance.getSignGrade() << ", form execute grade: " << instance.getSignGrade() << ", and sign status " << instance.getSignStatus();
    return (os);
 }

 //other methods
 void Form::beSigned(Bureaucrat &instanceB)
 {
    if (instanceB.getGrade() <= 1)
        _isSigned = true;
    else if (instanceB.getGrade() > 150)
        throw Form::GradeTooLowException();
    
}

//exceptions
const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
    	//std::string
		//thow is to indicate that what() will throw nothing
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}