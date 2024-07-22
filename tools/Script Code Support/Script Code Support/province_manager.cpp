#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "province_manager.h"

void CProvinceManager::AddDiscoveredBy(std::string discoveredByString)
{
    if (!discoveredByString.empty())
    {
        _discvoeredByList.push_back(discoveredByString);
    }
}

void CProvinceManager::SetInputFile(std::string InputFilePath)
{
	_InputFile = std::ifstream(InputFilePath);
}
void CProvinceManager::SetOutputFolder(std::string OutputFolderPath)
{
	_OutputFolder = OutputFolderPath;
}

std::string CProvinceManager::PrepareOutputString()
{
    std::string outputString = "";

    std::string outputOwner = "";
    std::string outputReligion = "";
    std::string outputCulture = "";
    std::string outputDev = "";
    std::string outputTradeGoods = "";

    std::string outputDiscoveredBy = "discovered_by = chinese\ndiscovered_by = tech_gensokyan\ndiscovered_by = tech_lunarian\n";
    if (_discvoeredByList.size() > 0)
    {
        for (int i = 0; i < _discvoeredByList.size(); i++)
        {
            outputDiscoveredBy += "discovered_by = " + _discvoeredByList.at(i) + "\n";
        }
    }
    if (!_owner.empty())
       outputOwner = "add_core = " + _owner + "\nowner = " + _owner + "\ncontroller = " + _owner + "\n";
    if (!_religion.empty())
        outputReligion = "religion = " + _religion + "\n";
    if (!_culture.empty())
        outputCulture = "culture = " + _culture + "\n";
    if (_usesDevelopment)
        outputDev = "is_city = yes\nbase_tax = " + std::to_string(_baseTax) + "\nbase_production = " + std::to_string(_baseProduction) + "\nbase_manpower = " + std::to_string(_baseManpower) + "\n";
    if (!_tradeGoods.empty())
        outputTradeGoods = "trade_goods = " + _tradeGoods + "\n";

    outputString = outputDiscoveredBy + outputOwner + outputReligion + outputCulture + outputDev + outputTradeGoods;
    return outputString;
}

void CProvinceManager::PrintProvinces()
{
    std::string outputString = PrepareOutputString();
	int currentProvinceIndex = 0;
	std::string line;
	while (std::getline(_InputFile, line))
	{
		++currentProvinceIndex;
		std::string outputFileName = "";
		if (currentProvinceIndex > _startOfNewProvinces)
		{
			int counter = 0;
            std::string innertext = "";
            int argumentCounter = 0;
            while (counter < line.size())
            {
                char character = line.at(counter);
                if (character != _separatorChar)
                {
                    innertext = innertext + character;
                }
                else
                {
                    if (argumentCounter == 0)
                    {
                        outputFileName = innertext + " - ";
                    }
                    else if (argumentCounter == 4)
                    {
                        outputFileName = outputFileName + innertext;
                    }
                    else {
                        innertext = "";
                    }
                    ++argumentCounter;
                }
                ++counter;
            }
            std::cout << outputFileName << "\n";
            std::ofstream outfile(_OutputFolder + "\\" + outputFileName + ".txt");
            outfile << outputString;
            outfile.close();
		}
	}
}