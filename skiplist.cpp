#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>

using namespace std;

#define UNSUCCESSFUL -1

template <typename KEY>
class SkipNode 
{
	private:
		SkipNode(KEY r, int level);
  		~SkipNode();
  		KEY 						value;
  		vector< SkipNode<KEY>* > 	forward;

	template <typename sKEY> friend class SkipList;
};

template <typename KEY>
SkipNode<KEY>::SkipNode(KEY r, int level) 
{
	value 	= r;
    forward.resize( level, NULL );
}

template <typename KEY>
SkipNode<KEY>::~SkipNode() 
{ 
}

template <typename KEY>
class SkipList 
{
	public:
		SkipList();
  		bool search(KEY);
  		void insert(KEY);
		void remove(KEY);
		void prt();
	private:
  		SkipNode<KEY>* head;

		vector< SkipNode<KEY>* > find(KEY);
  		void AdjustHead(int);
};

int randomLevel(void) 
{ 
	int level;
  	for (level = 1; rand() % 2 == 0; level++) /* NOOP */;			// Pick a level on exponential distribution
  	return level;
}

template <typename KEY>
SkipList<KEY>::SkipList()
{
	srand(time(0));													// seed the random number generator with time
	head = new SkipNode<KEY>( KEY(-1), 1 );
}

template <typename KEY>
void SkipList<KEY>::AdjustHead( int newLevel )
{
	SkipNode<KEY>* tmp = new SkipNode<KEY>( -1, newLevel );

	int i;
	for ( i = head->forward.size() - 1; i >= 0; i-- )
	{
		tmp->forward[i] = head->forward[i];
	}
	delete head;

	head 	= tmp;
}

template <typename KEY>
bool SkipList<KEY>::search(KEY searchKey) 
{ 
	vector< SkipNode<KEY>* > update = find(searchKey);

  	return (update[0]->forward[0] != NULL && update[0]->forward[0]->value == searchKey);				// Move to actual record, if it exists
}

template <typename KEY>
vector< SkipNode<KEY>* > SkipList<KEY>::find(KEY searchKey) 
{
  	vector< SkipNode<KEY>* > update( head->forward.size(), NULL );	// Update tracks end of each level
	
	SkipNode<KEY> *x = head;                  						// Dummy header node
  	for (int i = head->forward.size() - 1; i >= 0; i--) 			// Search for insert position
	{ 
    	while(	(x->forward[i] != NULL) && (x->forward[i]->value < searchKey))
		{
      		x = x->forward[i];
		}
		update[i] = x;												// Keep track of ith end 
	}
	return update;
}

template <typename KEY>
void SkipList<KEY>::insert(KEY newValue) 							// Insert into skiplist
{ 
  	SkipNode<KEY> *x;           									// Start at header node
  
	int newLevel = randomLevel(); 									// Select level for new node

  	if (newLevel > head->forward.size()) 							// New node will be deepest in list
	{       
    	AdjustHead(newLevel);       								// Add null pointers to header
  	}
	
	vector< SkipNode<KEY>* > update = find(newValue);				// find the insertion point

	x = new SkipNode<KEY>(newValue, newLevel ); 		// Create new SkipNode
  
	for (int i = 0; i < newLevel; i++) 								// Splice into list
	{ 						
    		x->forward[i] = update[i]->forward[i]; 					// Who x points to
    		update[i]->forward[i] = x;             					// Who y points to
  	}
}

template <typename KEY>
void SkipList<KEY>::remove( KEY doomedValue )
{
	vector< SkipNode<KEY>* > update = find(doomedValue);			// find item to remove

	if (update[0]->forward[0]->value == doomedValue) {
		SkipNode<KEY>* doomed = update[0]->forward[0];
		cout << "value " << doomed->value << endl;
		cout << "size " << doomed->forward.size() << endl;
		for (int i = 0; i < doomed->forward.size(); i++) 
		{ 						
				update[i]->forward[i] = doomed->forward[i]; 		// Bypass doomed
		}
		delete doomed;
	}
}

template <typename KEY>
void SkipList<KEY>::prt()
{
	int i;
	for ( i = head->forward.size() - 1; i >= 0; i-- )
	{
		cout << "Level " << i << ": ";

		SkipNode<KEY>* p;
		for ( p = head->forward[i]; p != NULL; p = p->forward[i] )
		{
			cout << p->value << " ";
		}
		cout << endl;
	}
}

int main() 
{
	SkipList<int> s;

	for ( int i = 10; i <= 60; i+=2 )
	{
		s.insert(i);
	}

	cout << "Skiplist Content" << endl;
	s.prt();
	
	// // test find
	// for ( int i = 10; i <= 40; i+=1 )
	// {
		// cout << "find " << i << " " << s.search(i) << endl;
	// }
	
	// cout << "Removing every 4th value" << endl;
	// for ( int i = 10; i <= 40; i+=4 )
	// {
		// s.remove(i);
		// cout << "After removing " << i << endl;
		// s.prt();	
	// }

}
