#include "Replace.hpp"

void ErrorMsg(const std::string& err_msg)
{
	std::cerr << err_msg << std::endl;
}

ReplaceInFile::ReplaceInFile(std::string file, std::string s1, std::string s2) : file_to_read_(file), str_to_find_(s1), str_to_replace_(s2), new_file_name_(file + ".replace")
{

}
ReplaceInFile::~ReplaceInFile()
{

}

int ReplaceInFile::replace()
{
	std::ifstream input_file(file_to_read_);
	if (!input_file.is_open())
	{
		ErrorMsg("Can't open the file.");
		return 1;
	}

	// std::ios::app
	std::ofstream output_file(new_file_name_);
	if (!output_file.is_open())
	{
		ErrorMsg("Can't create the file.");
		return 1;
	}

	std::string read_line;
	while (getline(input_file, read_line))
	{
		ReplaceInLine(read_line);
		output_file << read_line + "\n";
	}
	return 0;
}

void ReplaceInFile::ReplaceInLine(std::string& line)
{
	std::string				res_line;
	std::string::size_type	start_pos = 0;
	std::string::size_type	found_pos;
	std::string::size_type	len = str_to_find_.length();

	while ((found_pos = line.find(str_to_find_, start_pos)) != std::string::npos)
	{
		res_line += line.substr(start_pos, found_pos - start_pos);
		res_line += str_to_replace_;
		start_pos = found_pos + len;
	}
	res_line += line.substr(start_pos);
	line = res_line;
}



