#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : Form("Shrubbery", SH_SIGN, SH_EXEC) {
  target_ = "target";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : Form(target, SH_SIGN, SH_EXEC) {
  target_ = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &sc) {
  if (this != &sc)
    target_ = sc.target_;
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &e) const {
  if (!getBeSigned())
    throw NoSignException();
  if (getGradeToExec() < e.getGrade())
    throw GradeTooLowException();
  std::string tree = " ■■■■■■■■\n"
                     "    ■\n"
                     "    ■     ■ ■■  ■■■■   ■■■■\n"
                     "    ■     ■■   ■■  ■  ■■  ■\n"
                     "    ■     ■■   ■   ■■ ■   ■■\n"
                     "    ■     ■    ■■■■■■ ■■■■■■\n"
                     "    ■     ■    ■      ■\n"
                     "    ■     ■    ■■     ■■\n"
                     "    ■     ■     ■■■■   ■■■■";

  std::string fileName = target_ + "_shrubery";
  std::ofstream ofs(fileName.c_str());
  if (ofs.fail()) {
    throw("error output file open");
  }
  ofs << tree << std::endl;
  ofs.close();
};
