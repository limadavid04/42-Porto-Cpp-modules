
#include <fstream>
#include <string>
#include <iostream>


int main (int argc, char **argv)
{
	std::string input_file ;
	std::string new_file;
	std::ifstream in_stream;
	std::ofstream out_stream;
	std::string s1;
	std::string s2;
	std::string line;
	size_t start = 0;
	size_t found;
	std::string buffer;
	if (argc != 4)
	{
		std::cerr << "Error: invalid number of args." << std::endl;
		return 1;
	}
	input_file = argv[1];
	in_stream.open(input_file.c_str());
	if (!in_stream) {
		std::cerr << "Error: Unable to open input file." << std::endl;
		return 1;
	}
	s1 = argv[2];
	s2 = argv[3];
	new_file = input_file + ".replace";
	out_stream.open(new_file.c_str());
	if (!out_stream) {
		std::cerr << "Error: Unable to open output file." << std::endl;
		return 1;
	}
	std::cout << "reading from: "<< argv[1] << std::endl;
	std::cout << "replacing: " << s1 << " with: " << s2 << std::endl;

	while (std::getline(in_stream, line))
	{
		start = 0;
		found = std::string::npos;
		buffer = "";
		while ((found = line.find(s1, start)) != std::string::npos)
		{
			buffer += line.substr(start, found - start);
			buffer += s2;
			start = found + s1.length();
		}
		if (start != std::string::npos)
			buffer += line.substr(start);
		out_stream << buffer << std::endl;
	}
	in_stream.close();
	out_stream.close();
	return 0;
}
