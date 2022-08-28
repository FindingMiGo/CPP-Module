#include "Sed.hpp"

Sed::Sed(char *filename, std::string str1, std::string str2) : _filename(filename), _str1(str1), _str2(str2)
{}

Sed::~Sed()
{}

void	Sed::replaceStr()
{
	std::string	newname = _filename;
	newname += ".replace";
	
	std::string		buf;
	std::size_t		pos;

	std::ifstream	ifs(_filename);
	if (ifs.fail()){
		std::cout << "failed to open the file." << std::endl;
		exit(1);
	}
	std::ofstream	ofs(newname);
	if (ofs.fail()){
		std::cout << "failed to open the file." << std::endl;
		exit(1);
	}

	while (getline(ifs, buf)){
		while(buf != ""){
			pos = buf.find(_str1);
			if (std::string::npos == pos){
				ofs << buf;
				break;
			}
			ofs << buf.substr(0, pos) << _str2;
			buf.erase(0, pos + _str1.size());
		}
		if (!ifs.eof())
			ofs << std::endl;
	}
}
