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
	//비재귀는 배열에 저장하고 사용하면 simple하다.
	//하지만 재귀는 중복계산의 양이 2의 제곱으로 늘어난다.
	//따라서 성능이 재귀버전으로 한다고 향상되지 않는다.
	int ans = Fibonacci_recursive(10);
	cout << ans << endl;
	ans = FIbonacci_non_recursive(11);
	cout << ans << endl;
	return 0;
}