#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("Presidente", 25, 5), target("undefined")
{
    std::cout << " Default Contruct" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : AForm::AForm("Presidente", 25, 5), target(other.getTarget())
{
    std::cout << "  Contruct Copy" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &t) : AForm("Presidente", 25, 5), target(t)
{
    std::cout << " Contruct with  target" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << " Destruct President" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    AForm::operator=(other);
    this->target = other.target;
    return (*this);
}



std::string PresidentialPardonForm::getTarget() const
{
    return this->target;
}

void PresidentialPardonForm::executeAction(Bureaucrat const &bure) const{
    std::cout << "Assinado" << std::endl;
}

void PresidentialPardonForm::executeAction(Bureaucrat const & executor) const {
    std::cout << this->target << " foi perdoado por Zaphod Beeblebrox\n";
}
