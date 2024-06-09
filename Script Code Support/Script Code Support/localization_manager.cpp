#include "localization_manager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>

bool SStringHandler::HasStringEnding(std::string const& CompleteString, std::string const& StringEnding)
{
	if (CompleteString.length() >= StringEnding.length())
	{
		return (0 == CompleteString.compare(CompleteString.length() - StringEnding.length(), StringEnding.length(), StringEnding));
	}
	else
	{
		return false;
	}
}

void SStringHandler::ReplaceFirstOccurance(std::string& CompleteString, std::string StringToReplace, std::string ReplacmentString)
{
	if (CompleteString.length() < StringToReplace.length())
	{
		return;
	}
	int ReplacementPosition = CompleteString.find(StringToReplace);
	CompleteString.replace(ReplacementPosition, StringToReplace.size(), ReplacmentString);
}

CLocalizationManager::CLocalizationManager(std::string InputFolder, std::string OutputFolder)
{
	_InputFolder = InputFolder;
	_OutputFolder = OutputFolder;
}


void CLocalizationManager::SetInputFolder(std::string InputFolder)
{
	_InputFolder = InputFolder;
}
void CLocalizationManager::SetOutputFolder(std::string OutputFolder)
{
	_OutputFolder = OutputFolder;
}

void CLocalizationManager::CreateLocFileArray()
{
	if (_InputFolder.empty())
	{
		return;
	}
	for (const auto& file : std::filesystem::directory_iterator(_InputFolder))
	{
		if (SStringHandler::HasStringEnding(file.path().string(), _LocFileEnding))
		{
			_LocFileNames.push_back(file.path().filename().string());
		}
	}
}

void CLocalizationManager::CreateLocalizedFiles()
{
	CreateLocFileArray();
	for (int i = 0; i < _LocFileNames.size(); i++)
	{
		std::string inputFileName = _LocFileNames.at(i);
		std::string line;
		std::string readText = "";
		std::ifstream inputFile(_InputFolder + "\\" + inputFileName);
		while (std::getline(inputFile, line))
		{
			readText += line + "\n";
		}
		int LocFileLanguagesSize = sizeof(_LocFileLanguages) / sizeof(std::string);
		for (int languages = 0; languages < LocFileLanguagesSize; languages++)
		{
			//Prepare localized file content
			std::string localizedText = readText;
			SStringHandler::ReplaceFirstOccurance(localizedText, _LocDefaultLanguage, _LocFileLanguages[languages]);

			//Prepare localized file name
			std::string outputFileName = inputFileName;
			std::string outputFileEnding = "_" + _LocFileLanguages[languages] + ".yml";
			SStringHandler::ReplaceFirstOccurance(outputFileName, _LocFileEnding, outputFileEnding);

			//Create localized file
			std::cout << outputFileName << "\n";
			std::ofstream outputFile(_OutputFolder + "\\" + outputFileName);
			outputFile << localizedText;
			outputFile.close();
		}
	}
}