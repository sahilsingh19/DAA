#include <bits/stdc++.h>

using namespace std;

int find(int x, vector <int> &p) {
	if (p[x] == -1) return x;
	return find(p[x], p);
}

int kruskals(priority_queue<pair<int, pair<int, int>>> pq, int n) {
	int mx = 0;
	vector <int> parent(n, -1);

	while (!pq.empty()) {
		pair<int, pair<int, int>> p = pq.top();
		pq.pop();

		int x = find(p.second.first, parent);
		int y = find(p.second.second, parent);

		if (x == y) continue;

		mx += p.first;

		if (x < y) parent[y] = x;
		else parent[x] = y;
	}

	return mx;
}

int main()
{
	int n, temp;
	cin >> n;

	priority_queue <pair<int, pair<int, int>>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			pq.push({temp, {i, j}});
		}
	}

	cout << kruskals(pq, n) << endl;

	return 0;
}