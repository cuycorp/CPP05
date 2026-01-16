#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    Intern      intern;
    Bureaucrat  boss("Boss", 1);

    AForm *f1 = intern.makeForm("robotomy request", "Bender");
    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }

    std::cout << std::endl;

    AForm *f2 = intern.makeForm("presidential pardon", "Alice");
    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }

    std::cout << std::endl;

    intern.makeForm("unknown form", "Nobody");

    return 0;
}
