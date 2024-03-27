#include <fstream>
#include <iostream>

void awesome_replace(const std::string &file, const std::string &needle, const std::string &replace);

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Invalid usage\nCorrect usage: " << av[0] << " <path/to/file> <string_to_find> <string_to_replace>" << std::endl;
		return (1);
	}
	else
	{
		std::string file(av[1]);
		std::string needle(av[2]);
		std::string replace(av[3]);
		awesome_replace(file, needle, replace);
	}
}

void awesome_replace(const std::string &file, const std::string &needle, const std::string &replace)
{
	std::ifstream inFile(file.c_str());
	if (!inFile)
	{
		std::cerr << "Unable to open input file" << std::endl;
		return ;
	}

	std::string temp = file + ".replace";
	std::ofstream outFile(temp.c_str());
	if (!outFile)
	{
		std::cerr << "Unable to open output file" << std::endl;
		return ;
	}

	std::string line;
	{
		std::cout << line << std::endl;
		size_t pos = 0;
		while ((pos = line.find(needle, pos)) != std::string::npos)
		{
			line.erase(pos, needle.length());
			line.insert(pos, replace);
			pos += replace.length();
		}
		outFile << line << std::endl;
	}
	inFile.close();
	outFile.close();
}