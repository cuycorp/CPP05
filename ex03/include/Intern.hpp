#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
#include "AForm.hpp"

class Intern
{
    public:
        //OCF
        Intern(void);
        Intern(const Intern& other);
        Intern &operator=(const Intern &other);
        ~Intern();
        //other methods
        AForm *makeForm(std::string formName, std::string targetForm);
    };

#endif

