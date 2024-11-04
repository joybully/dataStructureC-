#include "Student.h"
#include <iostream>
#include "BubbleSort.h"

void BubbleUp(Student values[], int startIndex, int endIndex) {
	for (int index = endIndex; index > startIndex; index--)
		if (values[index] < values[index - 1])
			Swap(values[index], values[index-1]);
}

void BubbleSort(Student values[], int numValues) {
	int current = 0;

	while (current < numValues - 1) {
		BubbleUp(values, current, numValues - 1);
		current++;
	}
}

//int main() {
//	Student stu[100];
//	stu[0].InitValue(2003200111, "ÀÌ¿õÀç", 3.0);
//	stu[1].InitValue(2004200121, "±Ç¿ÀÁØ", 3.2);
//	stu[2].InitValue(2005200132, "±èÁøÀÏ", 2.7);
//
//	BubbleSort(stu, 3);
//	Print(cout, stu, 3);
//	return 0;
//}