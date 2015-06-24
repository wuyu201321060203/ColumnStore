#include <iostream>
#include <string>
#include <fstream>

#include "DGroupKey.h"

using namespace std;

int main(int argc, char** argv)
{
	BitCompressedVector a(1000);
	a.push_back(10);
	cout << a.get(0) << endl;
	return 0;
}
