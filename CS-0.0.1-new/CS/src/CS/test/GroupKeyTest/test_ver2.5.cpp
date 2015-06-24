#include <iostream>
#include <string>
#include <fstream>

#include "DRowTable.h"
#include "ColumnTable.h"

using namespace std;

DGroupKey<string>* constructDGroupKey(string columnName, uint64_t itemCount, uint64_t base, uint64_t type, multimap<string, uint64_t> initMap);
DGroupKey<int>* constructDGroupKey(string columnName, uint64_t itemCount, uint64_t base, uint64_t type, multimap<int, uint64_t> initMap);
DGroupKey<double>* constructDGroupKey(string columnName, uint64_t itemCount, uint64_t base, uint64_t type, multimap<double, uint64_t> initMap);

template <class T>
vector<uint64_t> generateCompVector(Dictionary<T>* dic, const vector<T>& initVector);

DRowTable* constructDRowTable(size_t attributeCount, string tableName, uint64_t base);

int main(int argc, char** argv)
{
    if(argc < 5)
    {
        cout <<" arg erorr" << endl;
        return -1;
    }
    
	ifstream inputFile(argv[1]);
	string word;
	uint64_t i = 0;
	multimap<string, uint64_t> cityMap;
	vector<string> cityVector;
	while(inputFile >> word)
	{
		cityMap.insert(make_pair(word, i));
		cityVector.push_back(word);
		i++;
	}

	ifstream inputFile2(argv[2]);
	uint64_t j = 0;
	multimap<string, uint64_t> upCityMap;
	vector<string> upCityVector;
	while(inputFile2 >> word)
	{
		upCityMap.insert(make_pair(word, j));
		upCityVector.push_back(word);
		j++;
	}

	ifstream inputFile3(argv[3]);
	uint64_t m = 0;
	multimap<string, uint64_t> nameMap;
	vector<string> nameVector;
	while(inputFile3 >> word)
	{
		nameMap.insert(make_pair(word, m));
		nameVector.push_back(word);
		m++;
	}

	ifstream inputFile4(argv[4]);
	uint64_t n = 0;
	multimap<string, uint64_t> upNameMap;
	vector<string> upNameVector;
	while(inputFile4 >> word)
	{
		upNameMap.insert(make_pair(word, n));
		upNameVector.push_back(word);
		n++;
	}

	ColumnTable* table = new ColumnTable("people");
	DGroupKey<string>* firstColumn = constructDGroupKey("city", i, 0, 0, cityMap);
	DGroupKey<string>* secondColumn = constructDGroupKey("name", m, 0, 0, nameMap);
	table->insertOneDGroupKey((void*)firstColumn, firstColumn->getName(), 0);
	table->insertOneDGroupKey((void*)secondColumn, secondColumn->getName(), 0);

	DRowTable* rtable = constructDRowTable(2, "people", 0);
	vector<uint64_t> cityCompVector = generateCompVector(firstColumn->getDictionary(), cityVector);
	vector<uint64_t> nameCompVector = generateCompVector(secondColumn->getDictionary(), nameVector);
	rtable->fillOneColumn("city", i, cityCompVector);
	rtable->fillOneColumn("name", m, nameCompVector);
	table->print();
	rtable->print();

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	DGroupKey<string>* firstUpColumn = constructDGroupKey("city", j, 0, 0, upCityMap);
	DGroupKey<string>* secondUpColumn = constructDGroupKey("name", n, 0, 0, upNameMap);
	vector<uint64_t> xCityVector = table->updateOneDGroupKey((void*)firstUpColumn, "city", 0);
	vector<uint64_t> xNameVector = table->updateOneDGroupKey((void*)secondUpColumn, "name", 0);
	vector<uint64_t> upCityCompVector = generateCompVector(firstColumn->getDictionary(), upCityVector);
	vector<uint64_t> upNameCompVector = generateCompVector(secondColumn->getDictionary(), upNameVector);
	rtable->refresh("city", xCityVector);
	rtable->refresh("name", xNameVector);
	rtable->updateOneColumn("city", j, upCityCompVector);
	rtable->updateOneColumn("name", n, upNameCompVector);

	table->print();
	rtable->print();

	return 0;
}

DGroupKey<string>* constructDGroupKey(string columnName, uint64_t itemCount, uint64_t base, uint64_t type, multimap<string, uint64_t> initMap)
{
	DGroupKey<string>* string_ptr = new DGroupKey<string>(columnName, itemCount, base, type);
	string_ptr->constructThreeVector(initMap);
	return string_ptr;
}

DGroupKey<int>* constructDGroupKey(string columnName, uint64_t itemCount, uint64_t base, uint64_t type, multimap<int, uint64_t> initMap)
{
	DGroupKey<int>* int_ptr = new DGroupKey<int>(columnName, itemCount, base, type);
	int_ptr->constructThreeVector(initMap);
	return int_ptr;
}

DGroupKey<double>* constructDGroupKey(string columnName, uint64_t itemCount, uint64_t base, uint64_t type, multimap<double, uint64_t> initMap)
{
	DGroupKey<double>* double_ptr = new DGroupKey<double>(columnName, itemCount, base, type);
	double_ptr->constructThreeVector(initMap);
	return double_ptr;
}

template <class T>
vector<uint64_t> generateCompVector(Dictionary<T>* dic, const vector<T>& initVector)
{
	vector<uint64_t> result;
	for(uint64_t i = 0; i < initVector.size(); i++)
	{
		result.push_back(dic->getPos(initVector[i]));
	}
	return result;
}

DRowTable* constructDRowTable(size_t attributeCount, string tableName, uint64_t base)
{
	return new DRowTable(attributeCount, tableName, base);
}
