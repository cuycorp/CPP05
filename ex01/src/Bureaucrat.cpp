#include "Bureaucrat.hpp"
#include "Form.hpp" 

#include <stdexcept>
// Default constructor
Bureaucrat::Bureaucrat(void): _name("no name"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    if (grade < 1)
        throw std::out_of_range("Bureaucrat::GradeTooHighException");
    else if (grade > 150)
        throw std::out_of_range("Bureaucrat::GradeTooLowException");
    else
        _grade = grade;
    std::cout << "Bureaucrat Default constructor with initialization called" << std::endl;
    return;
}
// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat Assignment operator called" << std::endl;
    if (this != &other)
        _grade = other.getGrade();
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

//Getters n Setters

const std::string Bureaucrat::getName(void) const
{
    return (_name);
}
int Bureaucrat::getGrade(void) const
{
    return(_grade);
}

void Bureaucrat::incrementGrade(void)
{
    int newGrade = this->getGrade() - 1;
    if (newGrade == 1)
        throw std::out_of_range("Bureaucrat::GradeTooHighException");
    else
        _grade = newGrade;
}
void Bureaucrat::decrementGrade(void)
{
    int newGrade = this->getGrade() + 1;
    if (newGrade == 150)
        throw std::out_of_range("Bureaucrat::GradeTooLowException.");
    else
        _grade = newGrade;
}

 std::ostream &operator<<(std::ostream &os, const Bureaucrat &instance)
 {
    os << instance.getName() << ", bureaucrat grade " << instance.getGrade();
    return (os);
 }

void Bureaucrat::signForm(Form &instanceForm)
{
    try
    {
        instanceForm.beSigned(*this);
        std::cout << this->getName() << "signed " <<instanceForm.getName();
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << "couldn't sign " <<instanceForm.getName() << "because " <<  e.what();
    }
}


 /*
 I have the following code for this problem 

 for the functions beSigned and sign form we are generating exceptions, and consulting, and I think in same way
 I have to get information from the information object, but I don't know how to send it between functions


 is exceptiona sort 

 difference from calling exception
 catch(const std::exception& e) and catch(std::out_of_range& e)


 */