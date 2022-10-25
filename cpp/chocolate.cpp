#include <iostream>

using namespace std;

int main() {
	unsigned int n, m, k;

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		if (n * i / k == 1 && n * i % k == 0) {
			cout << "YES";
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		if (m * i / k == 1 && m * i % k == 0) {
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}
