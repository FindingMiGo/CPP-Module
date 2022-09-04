#include "Bureaucrat.hpp"

int main(){
	try{
		std::cout << "==Test to initialize with valid range grades===\n";
		Bureaucrat test1;
		Bureaucrat test2("test2", 150);
		Bureaucrat test3(test2);
		Bureaucrat test4("test4", 1);

		std::cout << test1 << std::endl;
		std::cout << test2 << std::endl;
		std::cout << test3 << std::endl;
		std::cout << test4 << std::endl;
	}catch(std::exception const &e){
		std::cout << "Failed to initialize : ";
	}

	std::cout << std::endl;

	try{
		std::cout << "==Test to initialize with grade 151===\n";
		Bureaucrat test5("test5", 151);
		std::cout << "Successfully initialized test5\n";
    }
    catch(std::exception const &e){
		std::cout << "Failed to initialize test5 : ";
        std::cout << e.what() <<std::endl;
    }

	std::cout << std::endl;

	try{
		std::cout << "==Test to initialize with grade 0===\n";
		Bureaucrat test6("test6", 0);
		std::cout << "Successfully initialized test6\n";
	}
	catch(std::exception const &e){
		std::cout << "Failed to initialize test6 : ";
		std::cout << e.what() <<std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << "==Test to initialize and promote with grade 2===\n";
		Bureaucrat test7("test7", 2);
		test7.promotion();
		std::cout << "Successfully promote test7\n" << test7 << std::endl;
	}
	catch(std::exception const &e){
		std::cout << "Failed to promote test7 : ";
		std::cout << e.what() <<std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << "==Test to initialize and promote with grade 1===\n";
		Bureaucrat test8("test8", 1);
		test8.promotion();
		std::cout << "Successfully promote test8\n" << test8 << std::endl;
	}
	catch(std::exception const &e){
		std::cout << "Failed to promote test8 : ";
		std::cout << e.what() <<std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << "==Test to initialize and demote with grade 149===\n";
		Bureaucrat test9("test9",149);
		test9.demotion();
		std::cout << "Successfully demote test7\n" << test9 << std::endl;
	}
	catch(std::exception const &e){
		std::cout << "Failed to demote test9 : ";
		std::cout << e.what() <<std::endl;
	}

	std::cout << std::endl;

	try{
		std::cout << "==Test to initialize and demote with grade 150===\n";
		Bureaucrat test10("test10", 150);
		test10.demotion();
		std::cout << "Successfully demote test10\n" << test10 << std::endl;
	}
	catch(std::exception const &e){
		std::cout << "Failed to demote test10 : ";
		std::cout << e.what() <<std::endl;
	}
}
