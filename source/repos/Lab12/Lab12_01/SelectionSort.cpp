#include "SelectionSort.h"
#include "Student.h"
#include <iostream>

int MinIndex(Student values[], int startIndex, int endIndex) {
	int indexOfMin = startIndex;
	for (int index = startIndex + 1; index <= endIndex; index++) {
		if (values[index] < values[indexOfMin])
			indexOfMin = index;
	}
	return indexOfMin;
}

void SelectionSort(Student values[], int numValues) {
	int endIndex = numValues - 1;
	for (int current = 0; current < endIndex; current++)
		Swap(values[current], values[MinIndex(values, current, endIndex)]);
}

//int main() {
//	Student stu[100];
//	stu[0].InitValue(2003200111, "ÀÌ¿õÀç", 3.0);
//	stu[1].InitValue(2004200121, "±Ç¿ÀÁØ", 3.2);
//	stu[2].InitValue(2005200132, "±èÁøÀÏ", 2.7);
//
//	SelectionSort(stu, 3);
//	Print(cout, stu, 3);
//	return 0;
//}