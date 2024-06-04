#pragma once
#include <iostream>
#include <vector>

class CProvinceManager
{
public:
	void SetStartOfNewProvinces(int provinceStart) { _startOfNewProvinces = provinceStart; }
	void SetOwner(std::string& owner) { _owner = owner; }
	void SetReligion(std::string& religion) { _religion = religion; }
	void SetCulture(std::string& culture) { _culture = culture; }
	void SetTradeGoods(std::string& tradeGoods) { _tradeGoods = tradeGoods; }
	void SetDiscoveredList(std::vector<std::string>& discoveredList) { _discvoeredByList = discoveredList; }

private:
	int _startOfNewProvinces = 7054;
	std::string _owner = NULL;
	std::string _religion = NULL;
	std::string _culture = NULL;
	std::string _tradeGoods = NULL;
	std::vector<std::string> _discvoeredByList;
};

