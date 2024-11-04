#include <iostream>
#include "Student.h"

using namespace std;

void Merge(Student* values[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
	int arySize = rightLast - leftFirst + 1;
	Student* tempArray = new Student[arySize];
	int index = leftFirst;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
		if (*values[leftFirst] < *values[rightFirst]) {
			tempArray[index] = *values[leftFirst];
			leftFirst++;
		}
		else {
			tempArray[index] = *values[rightFirst];
			rightFirst++;
		}
		index++;
	}
	while (leftFirst <= leftLast) {
		tempArray[index] = *values[leftFirst];
		leftFirst++;
		index++;
	}
	while (rightFirst <= rightLast) {
		tempArray[index] = *values[rightFirst];
		rightFirst++;
		index++;
	}
	for (index = saveFirst; index <= rightLast; index++)
		*values[index] = tempArray[index];
	delete[] tempArray;
}

void MergeSortpointer(Student* values[], int first, int last) {
	if (first < last) {
		int middle = (first + last) / 2;
		MergeSortpointer(values, first, middle);
		MergeSortpointer(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
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

	MergeSortpointer(stuPtrs, 0, 2);
	PrintByPointer(cout, stuPtrs, 3);
	return 0;
}