# CPP05
1. ex00
    * throwing exception: https://www.youtube.com/watch?v=5nCXSDv6e4I 
        * creates exception text
        * stops normal execution
        * jumps to the nearest catch
    * what: used to describe the problem found
        * called after exception is caught
        * return string explaining the error 
    * catching exceptions are designed to stop execution

2. ex01
    * 

/*
0. Add parameter: const std::string target
1. Create Constructors: for all of the class constructors, set execution and signatura grade accoridng to given ranges

    * ShrubberyCreationForm(const std::string targetName)
        - action 1: create target file with ascii tree inside it 
    * RobotomyRequestForm(const std::string targetName)
        - action 2: randomly robotomize 50% of the time.
    * PresidentialPardonForm(const std::string str)
        - action 3: print message for pardoning 
2. AForm:
    //virtual execute(Bureaucrat const & executor) const
        if (form is signed && bureaucratGrade is high enough)
            do action()
        else 
            if (form not signed)        
                throw
                 no signature
            else if(grade low)
            else if (grade high)

    //change besigned to be virtual and modify behaviour inside each function 
3. Bureaucrat:
    executeForm(AForm const & form) const
        try  call execute 
        catch
                try
    {
        instanceForm.beSigned(*this);
        std::cout << this->getName() << " signed " <<instanceForm.getName();
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " <<instanceForm.getName() << " because " <<  e.what();
    }
*/

