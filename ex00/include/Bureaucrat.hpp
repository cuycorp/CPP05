#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private: 
        const std::string _name;
        int _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        //Getters and setters
        const std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void); //td: try catch
        void decrementGrade(void); //td: try catch
        //Exceptions
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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &instance);

#endif

