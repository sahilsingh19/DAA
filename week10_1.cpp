#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int s[n], f[n];

	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> f[i];
	}

	int cnt = 0, end = 0;
	vector <int> ans;

	for (int i = 0; i < n; i++) {
		if (s[i] >= end) {
			ans.push_back(i + 1);
			end = f[i];
			cnt++;
		}
	}

	cout << "No. of non-conflicting activities: " << cnt << endl;
	cout << "List of selected activities: ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}