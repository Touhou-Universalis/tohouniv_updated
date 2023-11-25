#include <iostream>
#include <fstream>
#include <sstream>

int main()
{
    int _numOfProvinces = 0;
    char _separatorChar = ';';
    int _startOfNewProvinces = 5525;
    std::string _owner = "FOM";
    std::string _religion = "th_hakureishinto";
    std::string _culture = "Gensokyo_human";
    std::string _tradeGoods = "fish";

    std::string _outputDiscoveredBy = "discovered_by = chinese\ndiscovered_by = tech_gensokyan\n";
    std::string _outputOwner = "add_core = " + _owner + "\nowner = " + _owner + "\ncontroller = " + _owner + "\n";
    std::string _outputReligion = "religion = " + _religion + "\n";
    std::string _outputCulture = "culture = " + _culture + "\n";
    std::string _outputDev = "is_city = yes\nbase_tax = 1\nbase_production = 1\nbase_manpower = 1\n";
    std::string _outputTradeGoods = "trade_goods = " + _tradeGoods + "\n";
    std::string _outputString = _outputDiscoveredBy + _outputOwner + _outputReligion + _outputCulture + _outputDev + _outputTradeGoods;

    std::string outfileFolder = "C:\\Users\\<user>\\Documents\\Paradox Interactive\\Europa Universalis IV\\mod\\tohouniv_updated\\history\\provinces";
    std::ifstream infile("C:\\Users\\<user>\\Documents\\Paradox Interactive\\Europa Universalis IV\\mod\\tohouniv_updated\\map\\definition.csv");
    std::string line;
    while (std::getline(infile, line))
    {
        ++_numOfProvinces;
        std::string _fileName = "";
        if (_numOfProvinces > _startOfNewProvinces)
        {
            int counter = 0;
            std::string innertext = "";
            int argumentCounter = 0;
            while (counter < line.size())
            {
                char character = line.at(counter);
                if (character != ';')
                {
                    innertext = innertext + character;
                }
                else
                {
                    if (argumentCounter == 0)
                    {
                        _fileName = innertext + " - ";
                    }
                    else if (argumentCounter == 4)
                    {
                        _fileName = _fileName + innertext;
                    }
                    else {
                        innertext = "";
                    }
                    ++argumentCounter;
                }
                ++counter;
            }
            std::cout << _fileName << "\n";
            std::ofstream outfile(outfileFolder + "\\" + _fileName);
            outfile << _outputString;
            outfile.close();
        }
    }
}
