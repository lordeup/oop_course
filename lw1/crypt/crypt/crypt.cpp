#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

enum Mode
{
	ENCRYPT,
	DECRYPT
};

const std::string CRYPT_MODE_NAME = "crypt";
const std::string DECRYPT_MODE_NAME = "decrypt";
const std::string ERROR_FILE_NOT_EXIST = "This file does not exist";
const std::string ERROR_UNKNOWN_MODE = "Unknown operating mode";
const std::string ERROR_NUMBER = "The key must be a number from 0 to 255";
const std::string ERROR_NOT_ENOUGH_ARGUMENTS = "The number of arguments does not match the task condition\n"
											   "Input should look: crypt.exe crypt or decrypt <input file> <output file> <key>";

typedef unsigned int Key;

void Encrypt(std::ifstream& fileInput, std::ofstream& fileOutput, Key& key)
{
	char currentByte;
	while (fileInput.read(&currentByte, sizeof(currentByte)))
	{
		currentByte = currentByte ^ key;
		currentByte = ((currentByte & 128) >> 2) | ((currentByte & 96) >> 5) | ((currentByte & 24) << 3) | ((currentByte & 7) << 2);
		fileOutput << currentByte;
	}
}

void Decrypt(std::ifstream& fileInput, std::ofstream& fileOutput, Key& key)
{
	char currentByte;
	while (fileInput.read(&currentByte, sizeof(currentByte)))
	{
		currentByte = ((currentByte & 32) << 2) | ((currentByte & 3) << 5) | ((currentByte & 192) >> 3) | ((currentByte & 28) >> 2);
		currentByte = currentByte ^ key;
		fileOutput << currentByte;
	}
}

void Crypt(std::ifstream& fileInput, std::ofstream& fileOutput, bool& mode, Key& key)
{
	if (mode == ENCRYPT)
	{
		Encrypt(fileInput, fileOutput, key);
	}
	else
	{
		Decrypt(fileInput, fileOutput, key);
	}
}

bool IsCorrectMode(std::string& operatingMode, bool& mode)
{
	if (operatingMode == CRYPT_MODE_NAME)
	{
		mode = ENCRYPT;
		return true;
	}
	else if (operatingMode == DECRYPT_MODE_NAME)
	{
		mode = DECRYPT;
		return true;
	}
	return false;
}

bool IsCorrectNumber(std::string& line, Key& key)
{
	try
	{
		key = std::stoi(line);
	}
	catch (const std::invalid_argument& err)
	{
		return false;
	}

	if (key < 0 || key > 255)
	{
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		std::cerr << ERROR_NOT_ENOUGH_ARGUMENTS << std::endl;
		return 1;
	}

	std::string operatingMode = argv[1];
	std::string line = argv[4];

	Key key;
	bool mode;

	if (!IsCorrectMode(operatingMode, mode))
	{
		std::cerr << ERROR_UNKNOWN_MODE << std::endl;
		return 1;
	}

	if (!IsCorrectNumber(line, key))
	{
		std::cerr << ERROR_NUMBER << std::endl;
		return 1;
	}

	std::ifstream fileInput(argv[2]);
	std::ofstream fileOutput(argv[3]);

	if (!fileInput.is_open() || !fileOutput.is_open())
	{
		std::cerr << ERROR_FILE_NOT_EXIST << std::endl;
		return 1;
	}

	Crypt(fileInput, fileOutput, mode, key);

	return 0;
}
