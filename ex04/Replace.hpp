#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <string>
#include <fstream>
#include <iostream>

void ErrorMsg(const std::string& err_msg);

// <filename>.replace
class ReplaceInFile
{
private:
	std::string file_to_read_;
	std::string str_to_find_;
	std::string str_to_replace_;
	std::string new_file_name_;
	void ReplaceInLine(std::string& line);

public:
	ReplaceInFile(std::string file, std::string s1, std::string s2);
	~ReplaceInFile();

	int replace();
};

#endif
