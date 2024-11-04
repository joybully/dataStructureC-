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



	cout << endl;
	cout << endl;

	PQType<int> pq(50);
	pq.Enqueue(56);
	pq.Enqueue(27);
	pq.Enqueue(42);
	pq.Enqueue(26);
	pq.Enqueue(15);
	pq.Enqueue(3);
	pq.Enqueue(19);
	pq.Enqueue(25);
	pq.Enqueue(24);
	pq.Enqueue(5);
	pq.Enqueue(28);
	pq.Enqueue(2);
	pq.Enqueue(40);
	int x, y, z;
	pq.Dequeue(x);
	pq.Dequeue(y);
	pq.Dequeue(z);

	cout << x << " " << y << " " << z << endl;
	return 0;
}