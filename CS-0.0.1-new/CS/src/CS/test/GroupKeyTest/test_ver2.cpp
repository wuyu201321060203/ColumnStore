#include <iostream>
#include <string>
#include <fstream>

#include "DRowTable.h"
#include "DGroupKey.h"

using namespace std;

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
	multimap<string, uint64_t> myMap;
	vector<string> cityVector;
	while(inputFile >> word)
	{
		myMap.insert(make_pair(word, i));
		cityVector.push_back(word);
		i++;
	}

	//ifstream inputFile2(argv[2]);
	//uint64_t j = 0;
	//multimap<string, uint64_t> myMap2;
	//vector<string> nameVector;
	//while(inputFile2 >> word)
	//{
		//myMap2.insert(make_pair(word, j));
		//nameVector.push_back(word);
		//j++;
	//}

	DGroupKey<string> cityDGroup("city", i, 0, 0);
	cityDGroup.constructThreeVector(myMap);
	Dictionary<string> a = cityDGroup.getDictionary();
	
	vector<uint64_t> cityCompVector;
	for(int i = 0; i < cityVector.size(); i++)
	{
		cityCompVector.push_back(a.getPos(cityVector[i]));
	}

	//myDGroup.print();
	//cout << endl;
	//cout << endl;
	//cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	//cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	//cout << endl;
	//cout << endl;
	//DGroupKey<string> nameDGroup("name", j, 0, 0);
	//nameDGroup.constructThreeVector(myMap2);
	//Dictionary<string> b = nameDGroup.getDictionary();

	//vector<uint64_t> nameCompVector;
	//for(int i = 0; i < nameVector.size(); i++)
	//{
		//nameCompVector.push_back(b.getPos(nameVector[i]));
	//}

	//cityDGroup.print();
	//nameDGroup.print();

	DRowTable table(1, "people", 0);
	table.fillOneColumn("city", i, cityCompVector);
	//table.fillOneColumn("name", j, nameCompVector);
	table.print();
	//table.print();
	//cout << endl;
	//cout << endl;
	//cout << endl;
	//cout << endl;
	//cout << endl;
	//cout << endl;
	//cout << endl;
	//cout << endl;
	//cout << endl;
	//
	//
	ifstream inputFile3(argv[2]);
	i = 0;
	multimap<string, uint64_t> updateMap;
	vector<string> cityUpVector;
	while(inputFile3 >> word)
	{
		updateMap.insert(make_pair(word, i));
		cityUpVector.push_back(word);
		i++;
	}

	DGroupKey<string> updateDGroup("city", i, 0, 0);
	updateDGroup.constructThreeVector(updateMap);
	Dictionary<string> a1 = updateDGroup.getDictionary();
	IndexOffset b1 = updateDGroup.getOffset();
	BitCompressedVector c1 = updateDGroup.getPosition();

	//a.print();
	//b.print();
	//c.print();
	//c.print();
	
	vector<uint64_t> xVector = cityDGroup.insertUpdatedData(a1, b1, c1);
	//for(int i = 0; i < xVector.size(); i++)
	//{
		//cout << xVector[i] << endl;
	//}

	Dictionary<string> e = cityDGroup.getDictionary(); // new dictionary
	
	vector<uint64_t> cityUpCompVector;
	for(int i = 0; i < cityUpVector.size(); i++)
	{
		int64_t pos = e.getPos(cityUpVector[i]);
		cityUpCompVector.push_back(pos);
	}

	table.refresh("city", xVector);
	table.updateOneColumn("city", i, cityUpCompVector);
	//myDGroup.print();
	table.print();

	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	//vector<uint64_t> xVector = myDGroup.insertUpdatedData()
	//cityDGroup.print();
	return 0;
}
