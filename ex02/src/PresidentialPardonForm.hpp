#ifndef PRES_HPP
#define PRES_HPP ;
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;

public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    std::string getTarget() const;
    void PresidentialPardonForm::executeAction(Bureaucrat const & executor) const ;
};

 
#endif