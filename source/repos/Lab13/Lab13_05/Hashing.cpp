#include <iostream>
#include "Student.h"
#include "Hashing.h"


using namespace std;

template <class ItemType>
HashTable<ItemType>::HashTable() {
	emptyItem.EmptyKey();
	for (int i = 0; i < MAX_ITEMS; i++) {
		info[i].EmptyKey();
	}
	length = 0;
}

template<class ItemType>
HashTable<ItemType>::~HashTable() {
	delete[] info;
}

int getIntFromString(char* key);

template <class ItemType>
int HashTable<ItemType>::Hash(char* key) const {
	return (getIntFromString(key) % MAX_ITEMS);
}

int getIntFromString(char* key) {
	int sum = 0;
	int len = strlen(key);
	if (len % 2 == 1) len++;
	for (int j = 0; j < len; j += 2)
		sum = (sum + 100 * key[j] + key[j + 1]) % 19937;
	return sum;
}

template<class ItemType>
void HashTable<ItemType>::InsertItem(ItemType item) {
	int location;
	location = Hash(item.Key());
	while (info[location] != emptyItem)
		location = (location + 1) % MAX_ITEMS;
	info[location] = item;
	length++;
}

template<class ItemType>
void HashTable<ItemType>::RetrieveItem(ItemType& item, bool& found) {
	int location;
	int startLoc;
	bool moreToSearch = true;
	startLoc = Hash(item.Key());
	location = startLoc;
	do {
		if (info[location] == item || info[location] == emptyItem)
			moreToSearch = false;
		else
			location = location + 1%MAX_ITEMS;
	} while (location != startLoc && moreToSearch);
	found = (info[location] == item);
	if (found)
		item = info[location];
}

template<class ItemType>
void HashTable<ItemType>::RetrieveItem2(ItemType& item, bool& found) {
	int location;
	int startLoc;
	bool moreToSearch = true;

	startLoc = Hash(item.Key());
	location = startLoc;
	do {
		if ((strcmp(info[location]->Key(), item->Key()) == 0) || (info[location] == "»´±Êµø"))
			moreToSearch = false;
		else
			location = location + 1;
	} while (location != startLoc && moreToSearch);
	found = (info[location]->Key() == item);
	if (found)
		item = info[location]->Key();
}

int main() {

	Student stu[100];
	stu[0].InitValue(2003200111, "¿Ãøı¿Á", 3.0);
	stu[1].InitValue(2004200121, "±«ø¿¡ÿ", 3.2);
	stu[2].InitValue(2005200132, "±Ë¡¯¿œ", 2.7);
	for (int i = 3; i < 5; i++)
		stu[i].InitValue(2018102188, "±Ë»÷ø¨", 2.8);
	HashTable<Student> ht;
	ht.InsertItem(stu[0]);
	ht.InsertItem(stu[1]);
	ht.InsertItem(stu[2]);

	char name[30];
	cin >> name;
	
	bool found;
	ht.RetrieveItem(stu[0], found);
	cout << name;
	return 0;
}