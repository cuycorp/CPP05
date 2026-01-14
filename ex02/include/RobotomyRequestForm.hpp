#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm: public AForm 
{
    private:
        static const int signGrade = 72;
        static const int executeGrade = 45;
    public:
        RobotomyRequestForm(const std::string targetName);
        ~RobotomyRequestForm();
        //other methods 
        virtual void execute(Bureaucrat const & executor);
};

#endif

