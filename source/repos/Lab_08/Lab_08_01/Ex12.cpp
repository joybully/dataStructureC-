#include<iostream>
#include "SumSquares.h"

template <class ItemType>
ItemType SumSquares_a(NodeType<ItemType>* list) {
//base case에 대한 조건문을 쓰지 않음
	if (list == NULL)
		return 0;
	else if (list != NULL)
		return(list->info * list->info) + SumSquares_a(list->next);
}

template<class ItemType>
ItemType SumSquares_b(NodeType<ItemType>* list){
	//제곱을 하지 않고 더함
	int sum = 0;
	while (list != NULL) {
		sum = ((list->info)*(list->info)) + sum;
		list = list->next;
	}
	return sum;
}

template<class ItemType>
ItemType SumSquares_c(NodeType<ItemType>* list) {
	//문제없음
	if (list == NULL)
		return 0;
	else
		return list->info * list->info + SumSquares_c(list->next);
}

template<class ItemType>
ItemType SumSquares_d(NodeType<ItemType>* list) {
	//문제없음
	if (list->next == NULL)
		return list->info * list->info;
	else
		return list->info * list->info + SumSquares_d(list->next);
}

template<class ItemType>
ItemType SumSquares_e(NodeType<ItemType>* list) {
	//recursion하는 함수를 잘못 설정함
	if (list == NULL)
		return 0;
	else
		return list->info * list->info + SumSquares_c(list->next);
}

int main() {
	UnsortedType<int> list1;
	for (int i = 0; i < 5; i++) {
		list1.InsertItem(i);
	}
	list1.PrintSumSquares();

	return 0;
}