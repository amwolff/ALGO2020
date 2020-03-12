#include <iostream>

using namespace std;

int main() {
	int a, b, k;
	scanf("%d %d %d", &a, &b, &k);

	if (a < k || b < k) {
		cout << 0 << endl;
		return 0;
	}

	if (b > a) {
		int t = a;
		a = b;
		b = t;
	}

	int ans = 0;
	if (b >= 2 * k) {
		ans += 2 * (a / k);
		b -= 2 * k;
		if (b > k) {
			ans += 2 * (b / k);
		}
	} else {
		ans += a / k;
	}

	cout << ans << endl;

	return 0;
}
