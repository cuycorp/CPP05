#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm 
{

    public:
        static const int signGrade = 25;
        static const int executeGrade = 5;

        PresidentialPardonForm(const std::string targetName);
        ~PresidentialPardonForm();

        //other methods
        virtual void execute(Bureaucrat const & executor);
};

#endif

