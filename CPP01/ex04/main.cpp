
#include <fstream>
#include <string>
#include <iostream>

void replaceString(std::ifstream& in_stream, std::ofstream& out_stream, const std::string& s1, const std::string& s2)
{
	std::string line;
	size_t start;
	size_t found;
	std::string buffer;

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
}

int main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cerr << "Error: invalid number of args." << std::endl;
		return 1;
	}
	std::string input_file = argv[1];
	std::string new_file = input_file + ".replace";
	std::ifstream in_stream(input_file.c_str());
	std::ofstream out_stream;

	if (!in_stream)
	{
		std::cerr << "Error: Unable to open input file." << std::endl;
		return 1;
	}
	out_stream.open(new_file.c_str());
	if (!out_stream)
	{
		std::cerr << "Error: Unable to open output file." << std::endl;
		return 1;
	}

	std::string s1 = argv[2];
	std::string s2 = argv[3];

	std::cout << "reading from: " << argv[1] << std::endl;
	std::cout << "replacing: " << s1 << " with: " << s2 << std::endl;

	replaceString(in_stream, out_stream, s1, s2);

	in_stream.close();
	out_stream.close();

	return 0;
}
