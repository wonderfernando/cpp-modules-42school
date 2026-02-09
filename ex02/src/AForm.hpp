#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Bureaucrat;

class AForm
{
    // Canonica
public:
    AForm();
    AForm(const AForm &form);
    AForm &operator=(const AForm &form);
    ~AForm();

    AForm(const std::string nm, int gToAssigned, int gToExecute);
    void beSigned(const Bureaucrat &bureaucrat);
    bool isAsigned() const;
    const std::string getName() const;
    int getGradeToExecute() const;
    int getGradeToAssigned() const;
    void execute(Bureaucrat const &executor) const;
    virtual void executeAction(Bureaucrat const &bure) const = 0;

    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

private:
    const std::string name;
    const int gradeToExecute;
    const int gradeToAssigned;
    bool asigned;
};

std::ostream &operator<<(std::ostream &os, const AForm &other);

#endif