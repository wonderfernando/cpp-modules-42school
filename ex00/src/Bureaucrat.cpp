#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("untitled"), grade(1) {
    std::cout << "Default constructor called" << std::endl; 
}

Bureaucrat::Bureaucrat(const std::string nm, int grade) : name(nm) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150 )
        throw GradeTooLowException();
    this->grade = grade;
}
 
Bureaucrat::Bureaucrat(const Bureaucrat &master) : name(master.name) , grade(master.grade){
    std::cout << "Copy constructor called" << std::endl; 
}

 
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other){
    std::cout << "Copy assignment operator called" << std::endl;  
    if (this == &other)
        return *this;
    return *this;
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor called" << std::endl;  
}


const std::string Bureaucrat::getName() const{
    return this->name;
}


int Bureaucrat::getGrade() const{
    return this->grade;
}

void Bureaucrat::increment(){
    if ((this->grade - 1) < 1)
        throw GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement(){
    if ((this->grade + 1) > 150)
        throw GradeTooLowException();
    this->grade++;
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& other){
    os << other.getName() << " bureaucrat with rank " << other.getGrade();
    return os;
}