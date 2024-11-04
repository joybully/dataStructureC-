#include "Student.h"
#include <iostream>
#include "InsertionSort.h"

void InsertItem(Student values[], int startIndex, int endIndex) {
	bool finished = false;
	int current = endIndex;
	bool moreToSearch = (current != startIndex);
	
	while (moreToSearch && !finished) {
		if (values[current] < values[current - 1]) {
			Swap(values[current], values[current - 1]);
			current--;
			moreToSearch = (current != startIndex);
		}
		else
			finished = true;
	}
}	

void InsertionSort(Student values[], int numValues) {
	for (int count = 0; count < numValues; count++) {
		InsertItem(values, 0, count);
	}
}

int main() {
	Student stu[100];
	stu[0].InitValue(2003200111, "ÀÌ¿õÀç", 3.0);
	stu[1].InitValue(2004200121, "±Ç¿ÀÁØ", 3.2);
	stu[2].InitValue(2005200132, "±èÁøÀÏ", 2.7);

	InsertionSort(stu, 3);
	Print(cout, stu, 3);
	return 0;
}