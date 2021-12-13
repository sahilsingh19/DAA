#include <bits/stdc++.h>

using namespace std;


int prims(vector <vector <int>> &v, int n) {
	priority_queue <pair<int, int>, vector <pair<int, int>>, greater <pair<int, int>> > pq;
	pq.push({0, 0});

	int mn = 0;
	vector <bool> visited(n, false);

	while (!pq.empty()) {
		pair<int, int> p;
		p = pq.top();
		pq.pop();

		if (visited[p.second] != false) continue;
		visited[p.second] = true;
		mn += p.first;

		int x = p.second;

		for (int i = 0; i < n; i++) {
			if (visited[i] == false and v[x][i] != 0) {
				pq.push({v[x][i], i});
			}
		}
	}
	return mn;
}

int main()
{
	int n, temp;
	cin >> n;

	vector <vector <int>> v(n, vector <int> (n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> temp;
			v[i][j] = temp;
		}
	}

	cout << prims(v, n) << endl;
	return 0;
}