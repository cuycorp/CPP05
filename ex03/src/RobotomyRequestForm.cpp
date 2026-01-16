#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

// OCF
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request Form: generic", false, signGrade, executeGrade)
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
    setTarget("generic");
    return ;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string targetName): AForm("Robotomy Request Form: " + targetName, false, signGrade, executeGrade)
{
    setTarget(targetName);
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other)
{
    setTarget(other.getTarget());
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
    return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if(&other != this)
    {
        setSignStatus(other.getSignStatus());
        setTarget(other.getTarget());
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
    return ;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor)
{
    int i = rand() % 2;
    if (getSignStatus() && executor.getGrade() <= getExecuteGrade())
    {
        std::cout << "Form executed: ";
        if (i == 0)
            std::cout << "Drilll " << getTarget() << " has been robotomized." << std::endl;
        else
            std::cout << "Impossible to robotomize" << std::endl;
    }
    else   
    {
        if (executor.getGrade() > getExecuteGrade())
            throw RobotomyRequestForm::GradeTooLowException();
        else if (!getSignStatus())
            throw RobotomyRequestForm::InvalidSignStatus();
    }
}