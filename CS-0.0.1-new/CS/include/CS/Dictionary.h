#ifndef DICTIONARY_H_
#define DICTIONARY_H_

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class Dictionary{
	private:
		typedef vector<T> vector_t;
	public:
		Dictionary(){}
		virtual ~Dictionary(){clear();}
	    void push_back(T value){m_dicVector.push_back(value);}
		void print()
		{
			uint64_t i = 0;
			for(typename vector_t::iterator itr = m_dicVector.begin(); itr != m_dicVector.end(); itr++)
			{
				cout << "Dictionary[" << i << "]: " << *itr << endl;
				i++;
			}
		}
		T get(uint64_t pos){return m_dicVector[pos];}
		uint64_t getRows(){return m_dicVector.size();}
		int64_t getSurePos(T value)
		{
			typename vector_t::iterator itr = find(m_dicVector.begin(), m_dicVector.end(), value);
            if( itr != m_dicVector.end() )
                return distance(m_dicVector.begin(), itr);
            else
                return -1;
		}
		bool ifExist(T value)
		{
			typename vector_t::iterator itr = find(m_dicVector.begin(), m_dicVector.end(), value);
			if(itr == m_dicVector.end())
				return false;
			else
				return true;
		}
		int64_t letGetPos(T floor)
		{
			if(floor < m_dicVector[0])
				return -1;
			typename vector_t::iterator itr = find(m_dicVector.begin(), m_dicVector.end(), floor);
			if(itr == m_dicVector.end())
			{
				itr = upper_bound(m_dicVector.begin(),m_dicVector.end(), floor);
				itr--;
			}
			return distance(m_dicVector.begin(), itr);
		}
		int64_t ltGetPos(T floor)
		{
			if(floor < m_dicVector[0])
				return -1;
			typename vector_t::iterator itr = lower_bound(m_dicVector.begin(), m_dicVector.end(), floor);
			itr--;
			return distance(m_dicVector.begin(), itr);
		}
		int64_t getGetPos(T ceiling)
		{
			if(ceiling > m_dicVector[m_dicVector.size() - 1])
				return -1;
			//typename vector_t::iterator itr = find(m_dicVector.begin(), m_dicVector.end(), ceiling);
			//if(itr == m_dicVector.end())
			//{
				//itr = upper_bound(m_dicVector.begin(), m_dicVector.end(), ceiling);
			//}
			typename vector_t::iterator itr = lower_bound(m_dicVector.begin(), m_dicVector.end(), ceiling);
			return distance(m_dicVector.begin(), itr);
		}
		int64_t gtGetPos(T ceiling)
		{
			if(ceiling > m_dicVector[m_dicVector.size() - 1])
				return -1;
			typename vector_t::iterator itr = upper_bound(m_dicVector.begin(), m_dicVector.end(), ceiling);
			return distance(m_dicVector.begin(), itr);
		}
		void dicShrink(size_t pos)
		{
			for(typename vector_t::iterator itr = m_dicVector.begin() + pos; itr != m_dicVector.end();)
			{
				itr = m_dicVector.erase(itr);
			}
		}

		void clear(){m_dicVector.clear();}
	private:
		vector_t m_dicVector;
};
#endif
