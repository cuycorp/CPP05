#include "Bureaucrat.hpp"
#include "Form.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void): _name("no name"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
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
    if (newGrade < 1)
        throw GradeTooHighException();
    else
        _grade = newGrade;
}
void Bureaucrat::decrementGrade(void)
{
    int newGrade = this->getGrade() + 1;
    if (newGrade > 150)
        throw GradeTooHighException();
    else
        _grade = newGrade;
}

 std::ostream &operator<<(std::ostream &os, const Bureaucrat &instance)
 {
    os << instance.getName() << " with grade: " << instance.getGrade();
    return (os);
 }

//exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
    	//std::string
		//thow is to indicate that what() will throw nothing
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

void Bureaucrat::signForm(Form &instanceForm)
{
    try
    {
        instanceForm.beSigned(*this);
        std::cout << this->getName() << " signed " <<instanceForm.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " <<instanceForm.getName() << " because " <<  e.what() << std::endl;
    }
}