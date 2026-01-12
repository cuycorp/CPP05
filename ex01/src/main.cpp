#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

#define RESET   "\033[0m"
#define PINK    "\033[35m"

int main()
{
    std::cout << PINK << "========== CONSTRUCTOR TESTS ==========\n" << RESET;

    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 151); // should throw
        std::cout << b2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form f1("Tax Form", false, 50, 25);
        std::cout << f1 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Form f2("Invalid Form", false, 200, 10); // should throw
        std::cout << f2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << PINK << "\n========== SIGNING TESTS ==========\n" << RESET;

    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 150);

    Form contract("Contract", false, 100, 50);

    std::cout << boss << std::endl;
    std::cout << intern << std::endl;
    std::cout << contract << std::endl;

    std::cout << PINK <<"\n-- Intern tries to sign --\n" << RESET;
    intern.signForm(contract);

    std::cout << PINK <<"\n-- Boss tries to sign --\n" << RESET;
    boss.signForm(contract);

    std::cout << "\nFinal form state:\n";
    std::cout << contract << std::endl;

    std::cout << PINK << "\n========== END ==========\n" << RESET;
    return 0;
}
