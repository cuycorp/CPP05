#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>

class Form
{
    private:
    const std::string _name;
    bool _isSigned;
    const int _gradeSign;
    const int _gradeExecute;

    public:
        Form(void);
        Form(const std::string name, int grade);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();

        // Getters and setters
        const std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void); //td: try catch
        void decrementGrade(void); //td: try catch
};

std::ostream &operator<<(std::ostream &os, const Form &instance);

#endif

