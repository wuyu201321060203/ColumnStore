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
	int word;
	uint64_t i = 0;
	multimap<int, uint64_t> ageMap;
	vector<int> ageVector;
	while(inputFile >> word)
	{
		ageMap.insert(make_pair(word, i));
		ageVector.push_back(word);
		i++;
	}

	ifstream inputFile2(argv[2]);
	uint64_t j = 0;
	multimap<int, uint64_t> upAgeMap;
	vector<int> upAgeVector;
	while(inputFile2 >> word)
	{
		upAgeMap.insert(make_pair(word, j));
		upAgeVector.push_back(word);
		j++;
	}

	ifstream inputFile3(argv[3]);
	double salary;
	uint64_t m = 0;
	multimap<double, uint64_t> salaryMap;
	vector<double> salaryVector;
	while(inputFile3 >> salary)
	{
		salaryMap.insert(make_pair(salary, m));
		salaryVector.push_back(salary);
		m++;
	}

	ifstream inputFile4(argv[4]);
	uint64_t n = 0;
	multimap<double, uint64_t> upSalaryMap;
	vector<double> upSalaryVector;
	while(inputFile4 >> salary)
	{
		upSalaryMap.insert(make_pair(salary, n));
		upSalaryVector.push_back(salary);
		n++;
	}

	ColumnTable* table = new ColumnTable("people");
	DGroupKey<int>* firstColumn = constructDGroupKey("age", i, 0, 1, ageMap);
	DGroupKey<double>* secondColumn = constructDGroupKey("salary", m, 0, 2, salaryMap);
	table->insertOneDGroupKey((void*)firstColumn, firstColumn->getName(), 1);
	table->insertOneDGroupKey((void*)secondColumn, secondColumn->getName(), 2);

	DRowTable* rtable = constructDRowTable(2, "people", 0);
	vector<uint64_t> ageCompVector = generateCompVector(firstColumn->getDictionary(), ageVector);
	vector<uint64_t> salaryCompVector = generateCompVector(secondColumn->getDictionary(), salaryVector);
	rtable->fillOneColumn("age", i, ageCompVector);
	rtable->fillOneColumn("salary", m, salaryCompVector);
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

	DGroupKey<int>* firstUpColumn = constructDGroupKey("age", j, 0, 1, upAgeMap);
	DGroupKey<double>* secondUpColumn = constructDGroupKey("salary", n, 0, 2, upSalaryMap);
	vector<uint64_t> xAgeVector = table->updateOneDGroupKey((void*)firstUpColumn, "age", 1);
	vector<uint64_t> xSalaryVector = table->updateOneDGroupKey((void*)secondUpColumn, "salary", 2);
	vector<uint64_t> upAgeCompVector = generateCompVector(firstColumn->getDictionary(), upAgeVector);
	vector<uint64_t> upSalaryCompVector = generateCompVector(secondColumn->getDictionary(), upSalaryVector);
	rtable->refresh("age", xAgeVector);
	rtable->refresh("salary", xSalaryVector);
	rtable->updateOneColumn("age", j, upAgeCompVector);
	rtable->updateOneColumn("salary", n, upSalaryCompVector);

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
