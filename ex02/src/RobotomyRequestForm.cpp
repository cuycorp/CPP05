#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <random>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string targetName): AForm("Robotomy Request Form", false, signGrade, executeGrade)
{
    setTarget(targetName);
    std::cout << "Default constructor called" << std::endl;
    return ;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor)
{
    int i = rand() % 2;
    if (getSignStatus() && executor.getGrade() >= getExecuteGrade())
    {
        if (i = 0)
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