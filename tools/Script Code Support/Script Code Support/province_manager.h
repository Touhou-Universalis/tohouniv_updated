#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class CProvinceManager
{
public:
	void SetStartOfNewProvinces(int provinceStart) { _startOfNewProvinces = provinceStart; }
	void SetOwner(std::string owner) { _owner = owner; }
	void SetReligion(std::string religion) { _religion = religion; }
	void SetCulture(std::string culture) { _culture = culture; }
	void SetTradeGoods(std::string tradeGoods) { _tradeGoods = tradeGoods; }
	void SetDiscoveredList(std::vector<std::string>& discoveredList) { _discvoeredByList = discoveredList; }
	void SetUsesDevelopment(bool usesDevelopment) { _usesDevelopment = usesDevelopment; }
	void SetBaseTax(int baseTax) { _baseTax = baseTax; }
	void SetBaseProduction(int baseProduction) { _baseProduction = baseProduction; }
	void SetBaseManpower(int baseManpower) { _baseManpower = baseManpower; }

	void AddDiscoveredBy(std::string discoveredByString);

	void SetInputFile(std::string InputFilePath);
	void SetOutputFolder(std::string OutputFolderPath);
	void PrintProvinces();

private:
	int _startOfNewProvinces = 7054;
	char _separatorChar = ';';
	std::string _owner = "";
	std::string _religion = "";
	std::string _culture = "";
	std::string _tradeGoods = "";
	std::vector<std::string> _discvoeredByList;

	bool _usesDevelopment = true;
	int _baseTax = 1;
	int _baseProduction = 1;
	int _baseManpower = 1;

	std::ifstream _InputFile;
	std::string _OutputFolder = "";

	std::string PrepareOutputString();
};

