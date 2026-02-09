#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("untitled"), gradeToExecute(1), gradeToAssigned(1), asigned(false)
{
    std::cout << "Default constructor called" << std::endl;
}

AForm::AForm(const std::string nm, int gToAssigned, int gToExecute) : name(nm), gradeToExecute(gToExecute), gradeToAssigned(gToAssigned), asigned(false)
{
    if (gToAssigned < 1 || gToExecute < 1)
        throw GradeTooHighException();
    if (gToAssigned > 150 || gToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &master) : name(master.name), gradeToExecute(master.gradeToExecute), gradeToAssigned(master.gradeToAssigned), asigned(master.asigned)
{
    std::cout << "Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->asigned = other.isAsigned();
    return *this;
}

AForm::~AForm()
{
    std::cout << "Destructor called" << std::endl;
}

const std::string AForm::getName() const
{
    return this->name;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

int AForm::getGradeToAssigned() const
{
    return this->gradeToAssigned;
}

bool AForm::isAsigned() const
{
    return this->asigned;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (this->getGradeToAssigned() < bureaucrat.getGrade())
        throw AForm::GradeTooLowException();
    this->asigned = true;
}
const char *AForm::FormNotSignedException::what(void) const throw()
{
    return "AForm: Not Asigned";
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return "AForm: The Grade Is Too Low";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return "AForm: The Grade Is Too High";
}

void AForm::execute(Bureaucrat const& execute) const {
    if (!this->asigned)
        throw AForm::FormNotSignedException();
    if (this->getGradeToExecute() < execute.getGrade() )
        throw GradeTooLowException();
    this->executeAction(execute);
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Name: " << form.getName() << "; is Signed: "
       << form.isAsigned() << "; Grade to Assigned: "
       << form.getGradeToAssigned()
       << "; Grade to Execute: "
       << form.getGradeToExecute()
       << std::endl;
    return os;
}
