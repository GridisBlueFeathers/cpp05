#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm(
	"Shrubbery creation form",
	"Default target",
	145,
	137
) {
	if (DEBUG)
		std::cerr << "ShrubberyCreationForm " << getName() << " was created(default)\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(
	other.getName(),
	other.getTarget(),
	other.getToSign(),
	other.getToExecute()
) {
	if (DEBUG)
		std::cerr << "ShrubberyCreationForm " << getName() << " was created(copy)\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm(
	"Shrubbery creation form",
	target,
	145,
	137
) {
	if (DEBUG)
		std::cerr << "ShrubberyCreationForm " << getName() << " was created(target)\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	if (DEBUG)
		std::cerr << "ShrubberyCreationForm " << getName() << " was destroyed\n";
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	std::ofstream	outfile;

	if (!getSigned())
		throw AForm::FormIsNotSignedException();
	if (executor.getGrade() > getToExecute())
		throw Bureaucrat::GradeTooLowException();

	outfile.open(getTarget() + "_shrubbery");
	if (!(outfile <<
		"                    SJJJJS"
		"                   IKJKKKKKJKI"
		"                  TJKKKKKKKKKKKKJ"
		"                  JKKKKKKKKKKKKKKKJJ"
		"                 OJKKKKKKKKKKKKKKKJKJJ"
		"                 JKKKKKKKKKKKKKKKKKKKKJJV                                    OKJJJJJJJJJJ"
		"                 KKKKKKKKKKKKKKKKKKKKKKKJJZ                             YJJKJKKKKKKKKKKKJ"
		"                SJKKKKKKKKKKKKKKKKKKKKKKKKJJ                        YJJKKKKKKKKKKKKKKKKKJT"
		"                IJKKKKKKKKKKKKKKKKKKKKKKKKKKJJ                   KJKKKKKKKKKKKKKKKKKKKKKJN"
		"                JKKKKJKJKKKKKKKKKKKKKKKKKKKKKKKV              LJJKKKKKKKKKKKKKKKKKKKKKKKJU"
		"                JJKKKJ  JJKKKKKKKKKKKKKKKKKKKKKJJKKJJJK    RKKKKKKKKKKKKKKKKKKKKKKKKKKKKJ"
		"               XJJKKKJ   JKKKKKKKKKKKKKKKKKKKKKJXZZZZZZYKJJJKKKKKKKKKKKKKKKKKKKKKKKKKKKKJ"
		"        KJJJJLSJJKKKKN   HKKKKKKKKKKKKKKKKKKKKJYYYYYYYYYYYVJKKKKKKKKKKKKKKKKKKKKKKKKKKKJJ"
		"       XJKKKKKKKKKKKJ     JJKKKKKKKKKKKKKKKKKKKGZYYYYYYYYYZIKKKKKKKKKKKKKKKKKKKKKKKKKKKKJ"
		"       IJKKKKKKKKKKKJ     JJKKKKKKKKKKKKKKKKKKKKJJPZZZZZ WIJKKKKKKKKKKKKKKKKKKKKKKKKKKKKK"
		"       JJJQLJJKKKKKJJ     HJKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK"
		"       JKJ   KJKKKKJN    WKKKKKKKKKKKKKKKKKJJJJJJKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKJJKKKKKKKK"
		"       JJJ     JJKKJQ   TJKKKKKKKKJJJJJJGW          ZJFIJJKKJJKKKKKKKKKKKKKKKJMVJKKKKKKJJ"
		"YJJJL  KJJ       JKJ   YJJKKKKKKKJJO                         IJKJKKKKKKKKKKKJK  JJKKKKKKJJKJJJJ"
		"   JJJJJJK        ZT  ZJKKKKKKKKQ                              ZJKKKKKKKKKKKJQ  JJKKKKKKKKKKKKJ"
		"     KJKKJ            JKKKKJJJ                                   VJKKKKKKKKKJJN JKKKKKKKKKKKKJJ"
		"      ZJJI           NJKKJJJ             HEE                       IJKKKKKKKKJJ MJKKKKKKKKKKKJM"
		"        UN          TKKKKJQ             CFFFE            HO         JJJKKKKKKKJPUJKKKJJK  JJKJO"
		"                    JJKJJ              QFFFEE          NEFFE         TKKKKKKKKKK JJJQ     KKKKY"
		"                   GJJKJ               EFFFEH          EFFFEN         TJJKKKKKJJ         XJKKK"
		"                   KKKJ                EFFFEI         BFFFFEM          WJKKKKKJJ         RKKKJKKJJJ"
		"                  JJKJK                EFFFD          DFFFFEK           NKKKKKJJP        MKKKKKKKX"
		"                  JJKI                 HEFF           AEFFFE             JJKKKJJF        MKKJKX"
		"                 MJJJR                                 EFFEW             KJKKKKKG"
		"                 KKJJ                                                     JKKKJJN"
		"                YJKJG         BEEEDDAFX                                   IKKKJJY"
		"                JJKJY         FEEEEEEED   DEDDEGHP                        IKKKJK"
		"                JKKJ          NDEEEEEEEC BEEEEEEEDDEEED    BI             LKKKJJ"
		"               TJJKM           BEEEEEEEEEEEEEEEEEEEEEEEA XDEEEEEEEA       PKKKKK"
		"               IJKKR            DEEEEEEEEEEEEEEEEEEEEEEDDEEEEEEEEE         KKKJJ"
		"               KKKJZ             DEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEA         JKKJK"
		"              XJKKJ               DEEEEEEEEEEEEEEEEEEEEEEEEEEEEED          KKKJK"
		"              UJKJK                 EEEEEEEEEEEEEEEEEEEEEEEEEEEK           KKKJH"
		"              NKKJQ                   DEEEEEEEEEEEEEEEEEEEEEDD            ZKKKJR"
		"              IKKJZ                      FDDEEDEEEEEEDDDDDE               PKKJJ"
		"              IKKJ                           UEACCCCBAT                   KKKJJ"
		"              PKKJ                                                        LKKJN"
		"              WJKY                                                        LKJJN"
		"               JL                                                         MKJJ"
		"                           ZHJKKI                                         TKJJ"
		"                      XMJJJJJJKKJJJLY                         QJJJJJJP     JJP"
		"                   IJJJJJJJKKKKKKKJKKJJJHLZ            ZJHJJJJJJKKKKJKKJJKMJKU"
		"                VJJKJL     KKKKKKKKKKKKKKKKKJKJJJJJJKKKKKKKKKKKKKKKKKKKKKKKKJM"
		"              NLR         KJKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKJN   RMJJKJJI"
		"                         KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKJO        JJJJ"
		"                        LJKKKKKKJKJJJ  JJKKKKKKKKKKKKKKKKKKKKKKKKKKKKKJ            JX"
		"                       TJKKKKKKJP      ZJKKKKKKKKKKKKKKJPPJJKKKKKKKKKKJ "
		"                      WJKKJJKZ          SJKKKKKKKKKKKJJ    WJJKKKKKKKKKH"
		"                     SJJJP               JJKKKKKKKKJJJ        JJKJKKKKJJ"
		"                    UJM                   JKKKKKKKKJL           MJKKKKKJ"
		"                                          NKKKKKKKKN              MJJKJJX"
		"                                           KKKKKKJX                 YKJJI"
		"                                            JKKKKZ                    MJJ"
		"                                            JKKJZ                       R"
		"                                             JJY"
		"                                             JN"))
		std::cerr << "Shrubbery creation failed :(";
}
