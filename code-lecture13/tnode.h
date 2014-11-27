#ifndef _BTREE

#include <iostream>

using namespace std;

class BTNode
{
	public:
		BTNode(int data, BTNode* L = NULL, BTNode* R = NULL)
		{
			m_data = data;
			m_left = L;
			m_right= R;
		}
		
		/*
		~BTNode()
		{
			if (t->m_left) delete t->m_left;
			if (t->m_right) delete t->m_right;
		}
		*/
		
		friend ostream& operator<< (ostream& os, BTNode& tn)
		{
			os << tn.m_data << " ";
		}
		
	private:
		int 	m_data;
		BTNode*	m_left;
		BTNode*	m_right;
		
	friend class BTree;
};

class BTree
{
	public:
		BTree()
		{
			m_root = NULL;
		}
		
		BTree(int data)
		{
			m_root = new BTNode(data);
		}
		
		BTree(int data, BTree tLeft, BTree tRight)
		{
			m_root = new BTNode(data, 
								tLeft.copy(),
								tRight.copy()
								);
		}
		
		BTree(Btree& t)
		{
			m_root = t.copy();
		}
		
		~BTree()
		{
			kill(m_root);	// delete m_root;
		}
		
		friend ostream& operator<< (ostream& os, BTree& t)
		{
			return t.postorder(os);
		}
		
		ostream& postorder(ostream& os = cout)
		{
			postorder(m_root, os);
			return os;
		}
		
	private:
		BTNode* m_root;
		
		void postorder( BTNode* t, ostream& os = cout )
		{
			if (t != NULL )
			{
				postorder(t->m_left, os);
				postorder(t->m_right, os);
				os << *t << " ";
			}
		}
		
		BTNode* copy()
		{
			return copy(m_root);
		}
		
		BTNode* copy( BTNode* t )
		{
			if ( t == NULL )
			{
				return NULL;
			}
			else
			{
				BTNode* L = copy(t->m_left);
				BTNode* R = copy(t->m_right);
				return new BTNode(t->m_data, L, R);
			}
		}
		
		kill(BTNode* t)
		{
			if ( t != NULL )
			{
				kill(t->m_left);
				kill(t->m_right);
				delete t;
			}			
		}
};
		
#endif
