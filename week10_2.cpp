#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, temp;
	cin >> n;

	vector <vector <int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v[i].push_back(0);
		v[i].push_back(temp);
		v[i].push_back(i + 1);
	}

	for (int i = 0; i < n; i++) {
		cin >> temp;
		v[i][0] = temp;
	}

	sort(v.begin(), v.end());
	vector <int> ans;

	int cnt = 0, start = 0;

	for (int i = 0; i < n; i++) {
		if (v[i][1] + start <= v[i][0]) {
			start = v[i][1] + start;
			cnt++;
			ans.push_back(v[i][2]);
		}
	}
	cout << "Max number of tasks: " << cnt << endl;
	cout << "Selected task numbers: ";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}