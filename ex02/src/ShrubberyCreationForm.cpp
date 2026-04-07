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
"		            .        +          .      .          .\n"
"     .            _        .                    .\n"
"  ,              /;-._,-.____        ,-----.__\n"
" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n"
"  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n"
"                      ,    `./  \\:. `.   )==-'  .\n"
"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n"
".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n"
"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n"
"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n"
"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n"
"              \\:  `  X` _| _,\\/'   .-'\n"
".               \":._:`\\____  /:'  /      .           .\n"
"                    \\::.  :\\/:'  /              +\n"
"   .                 `.:.  /:'  }      .\n"
"           .           ):_(:;   \\           .\n"
"                      /:. _/ ,  |\n"
"                   . (|::.     ,`                  .\n"
"     .                |::.    {\\\n"
"                      |::.\\  \\ `.\n"
"                      |:::(\\    |\n"
"              O       |:::/{ }  |                  (o\n"
"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n"
"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n"
"dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~"
	))
		std::cerr << "Shrubbery creation failed :(";
}
