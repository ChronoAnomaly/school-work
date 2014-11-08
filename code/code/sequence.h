#ifndef _SEQUENCE_

#define _SEQUENCE_

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> 
class Sequence
{
	public:
		Sequence()
		{
			m_length = 0;
			m_items = NULL;
		}
		
		Sequence(int size)
		{
			m_length = size;
			m_items = new T[m_length];
		}	
		
		Sequence(Sequence& cs)
		{
			m_length = cs.m_length;
			m_items = new T[m_length];
			
			for (int i = 0; i < m_length; i++)
			{
				m_items[i] = cs.m_items[i];
			}
		
		}
		
		~Sequence()
		{
			delete [] m_items;
		}
		
		T& operator[]( int pos )
		{
			return m_items[pos];
		}
		
		friend ostream& operator<<( ostream& os, Sequence& s )
		{
			os << "[ ";
			
			for ( int pos = 0; pos < s.m_length; pos++ )
			{
				os << s.m_items[pos] << (pos < s.m_length-1 ? ", " : " ");
			}
			os << "]";
			
			return os;
		}
	
	
	private:
		int m_length;
		T* m_items;
		//T other[5];
	
};

#endif
