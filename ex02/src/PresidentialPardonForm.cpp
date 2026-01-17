#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// OCF
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential pardon form: generic", false, signGrade, executeGrade)
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
    setTarget("generic");
    return ;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string targetName) : AForm("Presidential pardon form: " + targetName, false, signGrade, executeGrade)
{
    setTarget(targetName);
    std::cout << "PresidentialPardonForm constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{
    setTarget(other.getTarget());
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
    return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
    if(&other != this)
    {
        setSignStatus(other.getSignStatus());
        setTarget(other.getTarget());
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
    return ;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (getSignStatus() && executor.getGrade() <= getExecuteGrade())
        std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    else
    {
        if (executor.getGrade() > getExecuteGrade())
            throw PresidentialPardonForm::GradeTooLowException();
        else if (!getSignStatus())
            throw PresidentialPardonForm::InvalidSignStatus();
    }
}

