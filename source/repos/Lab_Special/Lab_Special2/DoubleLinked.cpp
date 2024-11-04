#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "Iterator.h"

int main() {
	List<int> list1;
	ListIterator<int> it1(list1);
	List<int> list2;
	ListIterator<int> it3(list2);
	int item1;
	for (int i = 1; i < 10; i=i+2) {
		item1 = i;
		list1.InsertItem(item1);
	}
	for (int i = 0; i < 10; i=i+2) {
		item1 = i;
		list2.InsertItem(item1);
	}
	int k = 0;
	int leng1 = list1.LengthIs();
	int leng2 = list2.LengthIs();
	while (k < leng1) {
		k++;
		it1.GetCurrentItem(item1);
		std::cout << item1 << '\n';
	}
	k = 0;
	while (k < leng2) {
		k++;
		it3.GetCurrentItem(item1);
		std::cout << item1 << '\n';
	}



	list1.ResetList();
	list2.ResetList();
	it1.ResetList();
	it3.ResetList();
	int j = 0;
	k = 0;
	int item2;
	it1.GetCurrentItem(item1);
	it3.GetCurrentItem(item2);
	while (k < leng1 && j < leng2) {
		if (item1 < item2) {
			list1.InsertItem(item1);
			k++;
			it1.GetCurrentItem(item1);
		}
		else {
			list1.InsertItem(item2);
			j++;
			it3.GetCurrentItem(item2);
		}
	}
	while (k < leng1) {
		list1.InsertItem(item1);
		k++;
		it1.GetCurrentItem(item1);
	}
	while (j < leng2) {
		list1.InsertItem(item2);
		j++;
		it3.GetCurrentItem(item2);
	}

	for (int i = 0; i < 3; i++) {
		std::cout << '\n';
	}

	k = 0;
	it1.ResetList();
	leng1 = list1.LengthIs();
	while (k < leng1) {
		k++;
		it1.GetCurrentItem(item1);
		std::cout << item1 << '\n';
	}
	return 0;
}
