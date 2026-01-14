#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string targetName) : AForm("Shrubbery Creation Form ", false, signGrade, executeGrade)
{
    setTarget(targetName);
    std::cout << "Default constructor called" << std::endl;
    return ;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Destructor called" << std::endl;
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