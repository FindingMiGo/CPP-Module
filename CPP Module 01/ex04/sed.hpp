#ifndef SED_HPP
#define SED_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>


class Sed
{
	public:
		Sed(char *filename, std::string str1, std::string str2);
		~Sed();
		void	replaceStr(void);
	private:
		char*			_filename;
		std::string		_str1;
		std::string		_str2;
};

#endif
