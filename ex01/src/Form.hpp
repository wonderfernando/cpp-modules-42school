# ifndef FORM_HPP
    # define FORM_HPP
#include <iostream>

class Bureaucrat;

class Form {
    //Canonica
    public:
        Form ();
        Form(const Form &form);
        Form &operator=(const Form &form);
        ~Form();

        Form(const std::string nm, int gToAssigned, int gToExecute);
        void beSigned(const Bureaucrat &bureaucrat);
        bool isAsigned() const;
        const std::string getName();
        int getGradeToExecute() const;
        int getGradeToAssigned() const;
        class GradeTooHighException : public std::exception {
            public:
                virtual const char *what() const throw();        
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char *what() const throw();
        };

    private:
        const std::string name;
        bool asigned;
        const int gradeToExecute;
        const int gradeToAssigned; 
       

    
};


std::ostream& operator<<(std::ostream& os, const Form &other);          
//std::ostream& operator<<(std::ostream& os, const Bureaucrat &other);          

#endif