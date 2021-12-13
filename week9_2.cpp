#include <bits/stdc++.h>

using namespace std;

int main()
{
	int temp = 0, n, k;
	float ans = 0;
	cin >> n;

	int w[n], va[n];

	vector < pair<float, pair<int, int>>> v(n);
	vector <pair<int, int>> vec;

	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> va[i];
	}
	cin >> k;

	for (int i = 0; i < n; i++) {
		v[i].first = float(va[i]) / w[i];
		v[i].second.first = w[i];
		v[i].second.second = va[i];
	}

	sort(v.begin(), v.end(), greater < pair<float, pair<int, int>>>());

	for (int i = 0; i < n; i++) {
		if (v[i].second.first < k) {
			k -= v[i].second.first;
			ans += v[i].second.second;
			vec.push_back({v[i].first, v[i].second.second});
		}
		else {
			ans += v[i].first * k;
			k = 0;
			break;
		}
	}
	cout << ans << endl;

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << " " << vec[i].second << endl;
	}
	cout << endl;

}