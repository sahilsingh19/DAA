#include <bits/stdc++.h>

using namespace std;

int find(int x, vector <int> &p) {
	if (p[x] == -1) return x;
	return find(p[x], p);
}

int kruskals(vector <pair<int, pair<int, int>>> &v, int n) {
	sort(v.begin(), v.end());
	int mn = 0;
	int l = v.size();
	vector <int> parent(n, -1);

	for (int i = 0; i < l; i++) {
		int x = find(v[i].second.first, parent);
		int y = find(v[i].second.second, parent);
		// cout << v[i].second.first << " " << v[i].second.second << "   " << x << " " << y << endl;

		if (x == y) continue;

		mn += v[i].first;

		if (x < y) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
		}
	}
	return mn;
}

int main()
{
	int n, temp;
	cin >> n;

	vector <pair<int, pair<int, int>>> v;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;


			if (temp != 0) {
				v.push_back({temp, {i, j}});
				// cout << temp << " ";
			}
		}
	}

	cout << kruskals(v, n) << endl;

	return 0;
}