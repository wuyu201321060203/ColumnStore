#include <iostream>
#include <string>
#include <fstream>

#include "TableManager.h"

using namespace std;

DGroupKey<string>* constructDGroupKey(string columnName, uint64_t itemCount, uint64_t base, uint64_t type, multimap<string, uint64_t> initMap);
DGroupKey<int>* constructDGroupKey(string columnName, uint64_t itemCount, uint64_t base, uint64_t type, multimap<int, uint64_t> initMap);
DGroupKey<double>* constructDGroupKey(string columnName, uint64_t itemCount, uint64_t base, uint64_t type, multimap<double, uint64_t> initMap);

template <class T>
vector<uint64_t> generateCompVector(Dictionary<T>* dic, const vector<T>& initVector);

int main(int argc, char** argv)
{
    if(argc < 3)
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
	uint64_t age;
	uint64_t j = 0;
	multimap<int, uint64_t> ageMap;
	vector<int> ageVector;
	while(inputFile2 >> age)
	{
		ageMap.insert(make_pair(age, j));
		ageVector.push_back(age);
		j++;
	}

	(Singleton<TableManager>::getInstance())->createColumnTable("people");
	DGroupKey<string>* firstColumn = constructDGroupKey("city", i, 0, 0, cityMap);
	DGroupKey<int>* secondColumn = constructDGroupKey("age", j, 0, 1, ageMap);
	ColumnTable* cTable = (Singleton<TableManager>::getInstance())->getColumnTable("people");
	cTable->insertOneDGroupKey((void*)firstColumn, firstColumn->getName(), 0);
	cTable->insertOneDGroupKey((void*)secondColumn, secondColumn->getName(), 1);

	(Singleton<TableManager>::getInstance())->createDRowTable(1, "people", 0);//ÎªÊ²Ã´1²»ÊÇ2Ê??
	vector<uint64_t> cityCompVector = generateCompVector(firstColumn->getDictionary(), cityVector);
	vector<uint64_t> ageCompVector = generateCompVector(secondColumn->getDictionary(), ageVector);
	DRowTable* rTable = (Singleton<TableManager>::getInstance())->getDRowTable("people");
	rTable->fillOneColumn("city", i, cityCompVector);
	rTable->fillOneColumn("age", j, ageCompVector);
	
	cTable->print();
	rTable->print();
	
	DGroupKey<string>* string_ptr = (DGroupKey<string>*)(cTable->getOneDGroupKey("city").first);
	
	cout << string_ptr->getPosition()->getRows() << endl;
	cout << rTable->getColumnRows("city") << endl;

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;

	//select city from people where 10 <= age <= 20;
	DGroupKey<int>* int_ptr = (DGroupKey<int>*)cTable->getOneDGroupKey("age").first;
	uint64_t ceiling = int_ptr->getDictionary()->ltGetPos(55);
	uint64_t floor = int_ptr->getDictionary()->gtGetPos(12);

	cout << floor << " " << ceiling << endl;
	vector<uint64_t> rowKey = int_ptr->getRangeRowKeyByPos(floor, ceiling);
	for(int i = 0; i < rowKey.size(); i++)
		cout << rowKey[i] << endl;
	vector<uint64_t> dicValue = rTable->getValue("city", rowKey);
	cout << "sssssssssssss" << endl;
	for(int i = 0; i < dicValue.size(); i++)
		cout << dicValue[i] << endl;

	DGroupKey<string>* result_ptr = (DGroupKey<string>*)cTable->getOneDGroupKey("city").first;
	vector<string> result = result_ptr->getDicValue(dicValue);
	cout << "sssssssssssss" << endl;
	for(vector<string>::iterator itr = result.begin(); itr != result.end(); itr++)
		cout << *itr << endl;
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
		result.push_back(dic->getSurePos(initVector[i]));
	}
	return result;
}

DRowTable* constructDRowTable(size_t attributeCount, string tableName, uint64_t base)
{
	return new DRowTable(attributeCount, tableName, base);
}
