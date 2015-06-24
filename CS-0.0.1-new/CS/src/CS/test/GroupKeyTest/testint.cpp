#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	ifstream inputFile(argv[1]);
	double i;
	while(inputFile >> i)
		cout << i << endl;
	return 0;
}
