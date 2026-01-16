#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// OCF
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery Creation Form: generic" , false, signGrade, executeGrade)
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    setTarget("generic");
    return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string targetName) : AForm("Shrubbery Creation Form: " + targetName, false, signGrade, executeGrade)
{
    setTarget(targetName);
    std::cout << "ShrubberyCreationForm constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other)
{
    setTarget(other.getTarget());
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
    return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
    if(&other != this)
    {
        setSignStatus(other.getSignStatus());
        setTarget(other.getTarget());
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
    return ;
}

//other functions
static void createTreeFile(const std::string& filename) {
    std::ofstream file(filename.c_str());
    if (file.is_open()) 
    {
        file << "       *\n";
        file << "      ***\n";
        file << "     *****\n";
        file << "    *******\n";
        file << "   *********\n";
        file << "  ***********\n";
        file << " *************\n";
        file << "      |||\n";
        file << "      |||\n";
        file.close();
    } 
    else
        throw std::runtime_error("Failed to create file\n");
}
void ShrubberyCreationForm::execute(const Bureaucrat &executor)
{
    if (getSignStatus() && executor.getGrade() <= getExecuteGrade())
    {
        try 
        {
            createTreeFile(getTarget() + "_shrubbery");
        }
        catch (const std::exception &e)
        {
            std::cout << "Could not create a shrubbery tree file because " << e.what() << std::endl;
        }

    }
    else
    {
        if (executor.getGrade() > getExecuteGrade())
            throw ShrubberyCreationForm::GradeTooLowException();
        else if (!getSignStatus())
            throw ShrubberyCreationForm::InvalidSignStatus();
    }   
}