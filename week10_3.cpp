#include <bits/stdc++.h>
using namespace std;
string majorityElement(int *arr, int n) {
	int count = 1, temp = arr[0], ele, f = 0;

	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1]) {
			count++;
		}
		else {
			if (count > (n / 2)) {
				f = 1;
			}
			count = 1;
		}
	}
	return (f == 1 ? "yes" : "no");
}
int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	cout << majorityElement(arr, n) << endl;

	if (n % 2 == 0)
		cout << (arr[n / 2 - 1] + arr[n / 2]) / 2;
	else
		cout << arr[n / 2];

	cout << endl;
	return 0;
}
