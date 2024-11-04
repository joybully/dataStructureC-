#include <iostream>
#include "Student.h"
#include "HeapSort.h"

using namespace std;

template <class ItemType>
void HeapSort(ItemType values[], int numValues) {
	int index;

	for (int i = 0; i < numValues; i++)
	{
		cout << values[i] << '\t';
	}
	cout << endl;
	for (index = numValues / 2; index >= 0; index--)
		ReheapDown(values, index, numValues - 1);

	for (int i = 0; i < numValues; i++)
	{
		cout << values[i] << '\t';
	}
	cout << endl;

	for (index = numValues - 1; index >= 1; index--) {
		Swap(values[0], values[index]);
		ReheapDown(values, 0, index - 1);
	}

	for (int i = 0; i < numValues; i++)
	{
		cout << values[i] << '\t';
	}
	cout << endl;
}

template<class ItemType>
int GetHeight(ItemType values[], int start, int numValues);

template<class ItemType>
void GetHeightSum(ItemType values[], int numValues) {
	int index, sum = 0;
	for (index = 0; index < numValues; index++)
		sum += GetHeight(values, index, numValues - 1);
	cout << "sum of heights = " << sum << endl;
}

template<class ItemType>
int GetHeight(ItemType values[], int start, int numValues) {
	if (start > (numValues-1) / 2) return 0;
	int l_height = GetHeight(values, start * 2 + 1, numValues);
	int r_height = GetHeight(values, start * 2 + 1, numValues);
	return (l_height > r_height) ? l_height + 1 : r_height + 1;
}

int main() {
	//Ex4
	/*Student stu[100];
	stu[0].InitValue(2003200111, "¿Ãøı¿Á", 3.0);
	stu[1].InitValue(2004200121, "±«ø¿¡ÿ", 3.2);
	stu[2].InitValue(2005200132, "±Ë¡¯¿œ", 2.7);

	HeapSort(stu, 3);
	Print(cout, stu, 3);*/

	//Ex5
	int a1[9];
	a1[0] = 25;
	a1[1] = 17;
	a1[2] = 36;
	a1[3] = 2;
	a1[4] = 3;
	a1[5] = 100;
	a1[6] = 1;
	a1[7] = 19;
	a1[8] = 7;
	//HeapSort(a1, 9);
	
	//Ex6
	GetHeightSum(a1, 9);
	
	return 0;
}