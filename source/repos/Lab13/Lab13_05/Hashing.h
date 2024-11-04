#include <iostream>

using namespace std;

int MAX_ITEMS = 100;

template <class ItemType>
class HashTable {
public:
	HashTable();

	~HashTable();

	int Hash(char* key)const;
	
	void InsertItem(ItemType item);

	void RetrieveItem(ItemType& item, bool& found);

	void RetrieveItem2(ItemType& item, bool& found);

private:
	ItemType info[100];
	int length;
	ItemType emptyItem;
};