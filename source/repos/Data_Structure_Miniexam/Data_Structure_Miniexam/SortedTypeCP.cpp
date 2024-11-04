#include <iostream>
#include "SortedType_Win.h"
using namespace std;
//4template <class ItemType>
int main()
{
	SortedType<int> myList;
	myList.InsertItem(1);
	myList.InsertItem(2);
	myList.InsertItem(3);
	myList.InsertItem(4);
	myList.DeleteItem(2);
	myList.DeleteItem(2);
	int item1;
	int leng = myList.LengthIs();
	while (leng >0) {
		leng--;
		myList.GetNextItem(item1);
		std::cout << item1<<'\n';
	}

	return 0;
}
