#include<iostream>

using namespace std;



int NumPaths(int row, int col, int n) {
	if ((row == n) || (col == n))
		return 1;
	else
		return NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
}

int mat[10000][10000] = {0,};

int NumPaths_C(int row, int col, int n) {
	if (mat[row][col] == 0) {
		if ((row == n) || (col == n))
			mat[row][col] = 1;
		else
			mat[row][col] = NumPaths(row + 1, col, n) + NumPaths(row, col + 1, n);
	}
	return mat[row][col];
}

int main() {
	int ans = NumPaths(1, 1, 6);
	cout << ans << endl;
	ans = NumPaths_C(1, 1, 6);
	cout << ans << endl;

	return 0;
}