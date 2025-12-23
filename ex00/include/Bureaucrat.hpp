#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

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
        //methods
};

#endif

