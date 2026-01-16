#ifndef AForm_HPP
# define AForm_HPP
# include <iostream>

#include <string>
class Bureaucrat;
class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeSign;
        const int _gradeExecute;
        std::string _target;

    public:
        AForm(void);
        AForm(const std::string name, bool isSigned, const int gradeSign, const int gradeExecute);
        AForm(const AForm& other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        // Getters and setters
        const std::string getName(void) const;
        int getSignGrade(void) const;
        int getExecuteGrade(void) const;
        bool getSignStatus(void) const;
        //modifiables
        std::string getTarget(void) const;
        void setTarget(std::string str);
        void setSignStatus(bool state);

        //other methods
        void beSigned(Bureaucrat &instanceB);
        virtual void execute(Bureaucrat const & executor) = 0;

        //exception
        class GradeTooHighException : public std::exception 
        {
            public :
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception 
        {
            public :
            virtual const char *what() const throw();
        };
        class InvalidSignStatus : public std::exception 
        {
            public :
            virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &os, const AForm &instance);

#endif
