#ifndef BURE_HPP
#define BURE_HPP

#include <iostream>
#include "AForm.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Bureaucrat
{
public:
    // Canonical
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat(const std::string name, int grade);

    // Getters e setters
    const std::string getName() const;
    int getGrade() const;

    // methods
    void increment();
    void decrement();
    void signForm(AForm &form);
    void executeForm(AForm const &form) const;

private:
    const std::string name;
    int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &other);
#endif