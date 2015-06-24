#include <iostream>

#include <CS/IndexOffset.h>

IndexOffset::IndexOffset()
{
}

IndexOffset::~IndexOffset()
{
	clear();
}

void IndexOffset::push_back(uint64_t index)
{
	m_offsetVector.push_back(index);
}

void IndexOffset::print()
{
	uint64_t i = 0;
	for(vector<uint64_t>::iterator itr = m_offsetVector.begin(); itr != m_offsetVector.end(); itr++)
	{
		cout << "IndexOffset[" << i << "]: " << *itr << endl;
		i++;
	}
}

uint64_t IndexOffset::get(uint64_t pos)
{
	return m_offsetVector[pos];
}

uint64_t IndexOffset::getRows()
{
	return m_offsetVector.size();
}

uint64_t IndexOffset::findBinarySplitPos(uint64_t positionIndex)
{
	uint64_t pos = 0;
	for(vector<uint64_t>::iterator itr = m_offsetVector.begin(); itr != m_offsetVector.end(); itr++)
	{
		if(*itr > positionIndex)
			return pos - 1;
		else
			pos++;
	}
}
void IndexOffset::offsetShrink(uint64_t pos, uint64_t count)
{
	for(vector<uint64_t>::iterator itr = m_offsetVector.begin() + pos; itr != m_offsetVector.end();)
	{
		itr = m_offsetVector.erase(itr);
	}
	push_back(count);
}

void IndexOffset::clear()
{
	m_offsetVector.clear();
	m_offsetVector.push_back(0);
}
