#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include "Bureaucrat.hpp" 
class Form
{
    private:
    const std::string _name;
    bool _isSigned;
    const int _gradeSign;
    const int _gradeExecute;

    public:
        Form(void);
        Form(const std::string name, bool isSigned, const int gradeExecute, const int gradeSign);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();

        // Getters and setters
        const std::string getName(void) const;
        int getSignGrade(void) const;
        int getExecuteGrade(void) const;
        int getSignStatus(void) const;
        void incrementGrade(void); //td: try catch
        void decrementGrade(void); //td: try catch
        
        //other methods
        void beSigned(Bureaucrat &instanceB);
};

std::ostream &operator<<(std::ostream &os, const Form &instance);

#endif

