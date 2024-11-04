#include "PQType.h"
#include <iostream>

using namespace std;

int main() {
	PQType<int> pq1(8);
	pq1.Enqueue(6);
	pq1.Enqueue(8);
	pq1.Enqueue(3);
	pq1.Enqueue(5);
	pq1.Enqueue(2);
	pq1.Enqueue(7);
	pq1.Enqueue(9);
	while (!pq1.IsEmpty()) {
		int a;
		pq1.Dequeue(a);
		cout << a << endl;
	}
	return 0;
}