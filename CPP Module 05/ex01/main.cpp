#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  {
    try {
      std::cout << "==Test to initialize with valid range===\n";
      Form f("f", 100, 100);
      std::cout << f << std::endl;
    } catch (std::exception const &e) {
      std::cout << "Failed to initialize : ";
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  {
    try {
      std::cout << "==Test to initialize with 0 gradeToSign===\n";
      Form f("f", 0, 100);
      std::cout << f << std::endl;
    } catch (std::exception const &e) {
      std::cout << "Failed to initialize : ";
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  {
    try {
      std::cout << "==Test to initialize with 0 gradeToExec===\n";
      Form f("f", 100, 0);
      std::cout << f << std::endl;
    } catch (std::exception const &e) {
      std::cout << "Failed to initialize : ";
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  {
    try {
      std::cout << "==Test to initialize with 151 gradeToSign===\n";
      Form f("f", 100, 151);
      std::cout << f << std::endl;
    } catch (std::exception const &e) {
      std::cout << "Failed to initialize : ";
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  {
    try {
      std::cout << "==Test to initialize with 151 gradeToExec===\n";
      Form f("f", 151, 100);
      std::cout << f << std::endl;
    } catch (std::exception const &e) {
      std::cout << "Failed to initialize : ";
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  {
    try {
      std::cout << "==Test to sign by sufficient grade Bureaucrat===\n";
      Bureaucrat b("b", 1);
      Form f("f", 100, 100);
      f.beSigned(b);
      std::cout << f << std::endl;
    } catch (std::exception const &e) {
      std::cout << "Failed to sign : ";
      std::cout << e.what() << std::endl;
    }
  }

  std::cout << std::endl;
  {
    try {
      std::cout << "==Test to sign by insufficient grade Bureaucrat===\n";
      Bureaucrat b("b", 150);
      Form f("f", 100, 100);
      f.beSigned(b);
      std::cout << f << std::endl;
    } catch (std::exception const &e) {
      std::cout << "Failed to sign : ";
      std::cout << e.what() << std::endl;
    }
  }
}
