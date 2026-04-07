#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"

# define SHRUBERRY  \
"		            .        +          .      .          .\n" \
"     .            _        .                    .\n" \
"  ,              /;-._,-.____        ,-----.__\n" \
" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n" \
"  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n" \
"                      ,    `./  \\:. `.   )==-'  .\n" \
"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n" \
".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n" \
"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n" \
"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n" \
"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n" \
"              \\:  `  X` _| _,\\/'   .-'\n" \
".               \":._:`\\____  /:'  /      .           .\n" \
"                    \\::.  :\\/:'  /              +\n" \
"   .                 `.:.  /:'  }      .\n" \
"           .           ):_(:;   \\           .\n" \
"                      /:. _/ ,  |\n" \
"                   . (|::.     ,`                  .\n" \
"     .                |::.    {\\\n" \
"                      |::.\\  \\ `.\n" \
"                      |:::(\\    |\n" \
"              O       |:::/{ }  |                  (o\n" \
"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n" \
"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n" \
"dew   ~~~~~~~~~~~~~~~~~~~~~~~\\W~~~~~~~~~~~~\\|/~~"

class ShrubberyCreationForm: public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();

		void	execute(Bureaucrat const &executor) const;
};

#endif
