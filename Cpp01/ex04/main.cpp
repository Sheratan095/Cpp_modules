/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maceccar <maceccar@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:20 by maceccar          #+#    #+#             */
/*   Updated: 2025/01/27 14:46:51 by maceccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string.h>

bool		openFiles(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& fileName);
std::string	read_fie(std::ifstream &inputFile);
void		replace(std::string content, std::ofstream& outfile, std::string s1, std::string s2);

// std::ios::in file opening in reading mode
int main(int argc, char *argv[])
{
	if (argc != 4 || strlen(argv[1]) == 0 || strlen(argv[2]) == 0)
	{
		std::cout << "Wrong number of arguments" << std::endl
				<< "\tThe rigth format is <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string	fileName = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	std::ifstream inputFile;
	std::ofstream outputFile;
	if (!openFiles(inputFile, outputFile, fileName))
		return (1);

	std::string	fileContent = read_fie(inputFile);

	replace(fileContent, outputFile, s1, s2);
}

void	replace(std::string content, std::ofstream& outfile, std::string s1, std::string s2)
{
	//starting position of each occurence s1
	size_t start_idx = 0;

	while ((start_idx = content.find(s1)) != std::string::npos)
	{
		std::string before = content.substr(0, start_idx);

		outfile << before;
		outfile << s2;

		content = content.substr(start_idx + s1.length());

		start_idx = 0;
	}

	outfile << content;
}

std::string	read_fie(std::ifstream &inputFile)
{
	std::string	content;
	std::string	line;

	while (std::getline(inputFile, line))
	{
		content.append(line);
		content.append("\n");
	}

	return (content);
}

bool openFiles(std::ifstream& inputFile, std::ofstream& outputFile, const std::string& fileName)
{
	inputFile.open(fileName.c_str(), std::ios::in);
	if (!inputFile.is_open())
	{
		std::cerr << "Error: file '"
				<< fileName
				<< "' can't not be opened" << std::endl;

		return (false);
	}

	std::string	outputFileName = fileName + ".replace";
	outputFile.open(outputFileName.c_str(), std::ios::in | std::ios::trunc);
	if (!outputFile.is_open())
	{
		std::cerr << "Error: file '"
				<< fileName
				<< "' can't not be opened" << std::endl;

		return (false);
	}

	return (true);
}
