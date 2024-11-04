#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "Sumlist.h" 

int main()
{
	int item1 = 1;
	int item2 = 3;
	int item3 = 2;
	int item4 = 5;

	UnsortedType<int> list,* result;
	result = new UnsortedType<int>;
	list.InsertItem(item1);
	list.InsertItem(item2);
	list.InsertItem(item3);
	list.InsertItem(item4);

	list.SumList(result);
	result->printList();
	return 0;
}
