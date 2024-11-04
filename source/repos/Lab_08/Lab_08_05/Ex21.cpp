#include <iostream>
#include "UnsortedType.h"

using namespace std;

int main() {
	UnsortedType<int> l1;
	l1.InsertItem(4);
	l1.InsertItem(5);
	l1.InsertItem(9);
	l1.InsertItem(2);
	l1.InsertItem(3);
	l1.Print();
	NodeType<int>* loc;
	l1.GetlistData(loc);
	l1.Sort(loc);
	l1.Print();
	return 0;
}