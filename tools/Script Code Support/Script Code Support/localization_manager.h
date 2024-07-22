#pragma once
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>

struct SStringHandler
{
	static bool HasStringEnding(std::string const& CompleteString, std::string const& StringEnding);
	static void ReplaceFirstOccurance(std::string& CompleteString, std::string StringToReplace, std::string ReplacmentString);
};

class CLocalizationManager
{
public:
	CLocalizationManager(std::string InputFolder, std::string OutputFolder);
	void SetInputFolder(std::string InputFolder);
	void SetOutputFolder(std::string OutputFolder);

	void CreateLocalizedFiles();

private:
	std::string _InputFolder;
	std::string _OutputFolder;
	void CreateLocFileArray();

	const std::string _LocFileEnding = "_l_english.yml";	//A loc file needs to have this ending before it can be copied into other languages
	const std::string _LocDefaultLanguage = "l_english";
	const std::string _LocFileLanguages[3] = { "l_german", "l_spanish", "l_french" };
	std::vector<std::string> _LocFileNames;
};

