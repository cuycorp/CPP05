#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <stdexcept>

// OCF
AForm::AForm(void) : _name("no name"), _isSigned(150), _gradeSign(150), _gradeExecute(150)
{
    std::cout << "AForm Default constructor called" << std::endl;
    return ;
}

AForm::AForm(const std::string name, bool isSigned, const int gradeSign, const int gradeExecute): _name(name), _isSigned(isSigned), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
    if (gradeExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeExecute > 150)
        throw AForm::GradeTooLowException();
    else if (gradeSign < 1)
        throw AForm::GradeTooHighException();
    else if (gradeSign > 150)
        throw AForm::GradeTooLowException();
    std::cout << "AForm Default constructor with initialization called" << std::endl;
    return;
}

AForm::AForm(const AForm &other): _name(other._name), _isSigned(other._isSigned), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute)
{
    std::cout << "AForm Copy constructor called" << std::endl;
    return ;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "AForm Assignment operator called" << std::endl;
    if (this != &other)
        _isSigned = other._isSigned;
    return (*this);
}

AForm::~AForm(void)
{
    std::cout << "AForm Destructor called" << std::endl;
    return ;
}

//Getters n Setters
const std::string AForm::getName(void) const
{
    return (_name);
}

int AForm::getExecuteGrade(void) const
{
    return(_gradeExecute);
}

int AForm::getSignGrade(void) const
{
    return(_gradeSign);
}

int AForm::getSignStatus(void) const
{
    return(_isSigned);
}

std::string AForm::getTarget(void) 
{
    return (_target);
}
void AForm::setTarget(std::string str)
{
    _target = str;
}

 //other methods
 void AForm::beSigned(Bureaucrat &instanceB)
 {
    if (instanceB.getGrade() <= _gradeSign)
        _isSigned = true;
    else
        throw AForm::GradeTooLowException();
}


//exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
    	//std::string
		//thow is to indicate that what() will throw nothing
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

const char *AForm::InvalidSignStatus::what() const throw()
{
    return ("Sign status is false!");
}



//overloading 
std::ostream &operator<<(std::ostream &os, const AForm &instance)
{
   os << instance.getName() << ", AForm sign grade " << instance.getSignGrade() << ", AForm execute grade: " << instance.getSignGrade() << ", and sign status " << instance.getSignStatus();
   return (os);
}