#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm():
	AForm("Shrubbery creation form", 145, 137)
{
#if DEBUG
	std::cerr << "ShrubberyCreationForm " << getName() << " was created(default)\n";
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(
		other.getName(),
		other.getToSign(),
		other.getToExecute()
	)
{
#if DEBUG
	std::cerr << "ShrubberyCreationForm " << getName() << " was created(copy)\n";
#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm(
		target,
		145,
		137
	)
{
#if DEBUG
	std::cerr << "ShrubberyCreationForm " << getName() << " was created(target)\n";
#endif
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
#if DEBUG
	std::cerr << "ShrubberyCreationForm " << getName() << " was destroyed\n";
#endif
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::ofstream	outfile;

	if (!getSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getToExecute())
		throw Bureaucrat::GradeTooLowException();

	outfile.open(getName() + "_shrubbery");
	if (!(outfile <<
"		            .        +          .      .          ."
"     .            _        .                    ."
"  ,              /;-._,-.____        ,-----.__"
" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,"
"  `                 \\   _|`\"=:_::.`.);  \\ __/ /"
"                      ,    `./  \\:. `.   )==-'  ."
"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ."
".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o"
"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ."
"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7"
"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/"
"              \\:  `  X` _| _,\\/'   .-'"
".               \":._:`\\____  /:'  /      .           ."
"                    \\::.  :\\/:'  /              +"
"   .                 `.:.  /:'  }      ."
"           .           ):_(:;   \\           ."
"                      /:. _/ ,  |"
"                   . (|::.     ,`                  ."
"     .                |::.    {\\"
"                      |::.\\  \\ `."
"                      |:::(\\    |"
"              O       |:::/{ }  |                  (o"
"               )  ___/#\\::`/ (O \"==._____   O, (O  /`"
"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~"
"dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~"
	))
		std::cerr << "Shrubbery creation failed :(";
}
