#include <iostream>
#include "Student.h"

using namespace std;

void Split(Student* values[], int first, int last, int& splitPoint) {
	Student splitVal = *values[first];
	int saveFirst = first;
	bool onCorrectSide;

	first++;
	do {
		onCorrectSide = true;
		while (onCorrectSide) {
			if (splitVal <= *values[first])
				onCorrectSide = false;
			else {
				first++;
				onCorrectSide = (first <= last);
			}
		}
		onCorrectSide = (first <= last);
		while (onCorrectSide) {
			if (*values[last] <= *values[splitPoint])
				onCorrectSide = false;
			else {
				last--;
				onCorrectSide = (first <= last);
			}
		}
		if (first < last) {
			Swap(values[first], values[last]);
			first++;
			last--;
		}
	} while (first <= last);
	splitPoint = last;
	Swap(values[saveFirst], values[splitPoint]);
}

void QuickSortPointer(Student* values[], int first, int last) {
	if (first < last) {
		int splitPoint;

		Split(values, first, last, splitPoint);

		QuickSortPointer(values, first, splitPoint - 1);
		QuickSortPointer(values, splitPoint + 1, last);
	}
}

int main() {
	Student stu[100];
	stu[0].InitValue(2003200111, "ÀÌ¿õÀç", 3.0);
	stu[1].InitValue(2004200121, "±Ç¿ÀÁØ", 3.2);
	stu[2].InitValue(2005200132, "±èÁøÀÏ", 2.7);
	Student* stuPtrs[3];

	for (int k = 0; k < 3; k++)
		stuPtrs[k] = &stu[k];
	QuickSortPointer(stuPtrs, 0, 2);
	PrintByPointer(cout, stuPtrs, 3);
	return 0;
}