#include<iostream>

using namespace std;

int Fibonacci_recursive(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci_recursive(n - 2) + Fibonacci_recursive(n - 1);
};

int FIbonacci_non_recursive(int n) {
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else {
		int k = 2;
		int ans[10000];
		ans[0] = 0;
		ans[1] = 1;
		while (k < n+1) {
			ans[k] = ans[k - 1] + ans[k - 2];
			k++;
		}
		return ans[n];
	}
		
};

int main() {
	//����ʹ� �迭�� �����ϰ� ����ϸ� simple�ϴ�.
	//������ ��ʹ� �ߺ������ ���� 2�� �������� �þ��.
	//���� ������ ��͹������� �Ѵٰ� ������ �ʴ´�.
	int ans = Fibonacci_recursive(10);
	cout << ans << endl;
	ans = FIbonacci_non_recursive(11);
	cout << ans << endl;
	return 0;
}