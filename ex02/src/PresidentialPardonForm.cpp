#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Default constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string targetName) : AForm("Presidential pardon form", false, signGrade, executeGrade)
{
    setTarget(targetName);
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor)
{
    if (getSignStatus() && executor.getGrade() <= getExecuteGrade())
        std::cout << getTarget() << "has been pardoned by Zaphod Beeblebrox" << std::endl;
    else
    {
        if (executor.getGrade() > getExecuteGrade())
            throw PresidentialPardonForm::GradeTooLowException();
        else if (!getSignStatus())
            throw PresidentialPardonForm::InvalidSignStatus();
    }
}
