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
		if (file.empty() || needle.empty() || replace.empty())
		{
			std::cerr << "Error: arguments cannot be empty!" << std::endl;
			return 1;
		}
		awesome_replace(file, needle, replace);
	}
}

void awesome_replace(const std::string &file, const std::string &needle, const std::string &replace)
{
	// open input file
	std::ifstream inFile(file.c_str());
	if (!inFile)
	{
		std::cerr << "Unable to open input file" << std::endl;
		return ;
	}

	// create and open output file
	std::string temp = file + ".replace";
	std::ofstream outFile(temp.c_str());
	if (!outFile)
	{
		std::cerr << "Unable to open output file" << std::endl;
		return ;
	}
	// Parse the input file
	std::string line;
	while (std::getline(inFile, line))
	{
		size_t pos = 0;
		// for each line check if we can find the needle
		while ((pos = line.find(needle, pos)) != std::string::npos)
		{
			line.erase(pos, needle.length()); // if the needle was found remove it from the line
			line.insert(pos, replace); // then insert the replace string inside the line
			pos += replace.length(); // increment the position (to skip the replaced chars and not enter an infinite loop)
		}
		outFile << line << std::endl; // Save the line inside the output file
	}
	inFile.close();
	outFile.close();
}