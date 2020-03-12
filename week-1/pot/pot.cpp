#include <iostream>

using namespace std;

int main() {
	long long a;
	int b;
	scanf("%lld %d", &a, &b);

	long long ans = 1;
	while (b > 0) {
		if (b & 1) {
			ans *= a;
		}
		a *= a;
		b >>= 1;
	}

	cout << ans % 10 << endl;
	return 0;
}
