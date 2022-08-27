#include "Bureaucrat.hpp"

int main(){
    try{
        Bureaucrat a("a", 151);
		a.promotion();
    }
    catch(std::exception const &e){
		std::cout <<"???\n";
        std::cout << "[[" << e.what() << "]]" <<std::endl;
    }
	std::cout <<"aa\n";
} 
