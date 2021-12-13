#include <bits/stdc++.h>

using namespace std;

void merge(int arr[], int l, int m, int r) {
	int l1 = (m - l) + 1;
	int l2 = r - m;

	int arr1[l1], arr2[l2];

	for (int i = 0; i < l1; i++) {
		arr1[i] = arr[i + l];
	}
	for (int i = 0; i < l2; i++) {
		arr2[i] = arr[m + i + 1];
	}

	int i = 0, j = 0, temp = l;

	while (i < l1 and j < l2) {
		if (arr1[i] < arr2[j]) {
			arr[temp++] = arr1[i++];
		}
		else {
			arr[temp++] = arr2[j++];
		}
	}

	while (i < l1) {
		arr[temp++] = arr1[i++];
	}
	while (j < l2) {
		arr[temp++] = arr2[j++];
	}

	return;
}
void merge_sort(int arr[], int l, int r) {
	if (l >= r) return;

	int m = l + (r - l) / 2;
	merge_sort(arr, l, m);
	merge_sort(arr, m + 1, r);

	merge(arr, l, m, r);
}


int main()
{
	int n;
	cin >> n;

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	merge_sort(arr, 0, n - 1);
	int ans = 0;

	for (int i = 1; i < n; i++) {
		arr[i] = arr[i] + arr[i - 1];
		ans += arr[i];
	}
	cout << ans << endl;
	return 0;
}