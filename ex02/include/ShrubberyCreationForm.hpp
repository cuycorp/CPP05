#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm 
{
    public:
        static const int signGrade = 145;
        static const int executeGrade = 137;
        //OCF
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string targetName);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
        //other methods
        virtual void execute(Bureaucrat const & executor) const;
};

#endif

