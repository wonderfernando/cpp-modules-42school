#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("untitled"), gradeToExecute(1), gradeToAssigned(1) {
    std::cout << "Default constructor called" << std::endl; 
}

Form::Form(const std::string nm, int gToAssigned, int gToExecute) : name(nm), gradeToAssigned(gToAssigned), gradeToExecute(gToExecute) {
    if (gToAssigned < 1 || gToExecute < 1)
        throw GradeTooHighException();
    if (gToAssigned > 150 || gToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &master) : name(master.name) , grade(master.grade){
    std::cout << "Copy constructor called" << std::endl; 
}
 
Form &Form::operator=(const Form &other){
    std::cout << "Copy assignment operator called" << std::endl;  
    if (this == &other)
        return *this;
    return *this;
}

Form::~Form(){
    std::cout << "Destructor called" << std::endl;  
}

const std::string Form::getName() const{
    return this->name;
}

const int Form::getGradeToExecute() const{
    return this->gradeToExecute;
}

const int Form::getGradeToAssigned() const{
    return this->gradeToAssigned;
}

bool Form::isAsigned() const {
    return this->asigned;
}

void Form::beSigned(Bureaucrat &bureaucrat){
    if (this->getGradeToAssigned() > bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    this->asigned = true;
}

const char *Form::GradeTooHighException::what(void) const throw() {
    return "Form: The Grade Is Too Low";    
}

const char *Form::GradeTooLowException::what(void) const throw() {
    return "Form: The Grade Is Too High";
}

std::ostream& operator=(ostream &os, Form &form){
    os << "Name: " form.getName() << "; is Signed: "
    << form.isAsigned() << "; Grade to Assigned: " 
    << form.getGradeToAssigned() 
    << "; Grade to Execute: " 
    << form.getGradeToExecute() 
    << std::endl;  
}

