#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>

class ShrubberyCreationForm
{
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
};

#endif

