#include <iostream>

using namespace std;

int main() {
	long long n;
	scanf("%lld", &n);
	while (n > 1) {
		if (n % 2 == 0) {
			n /= 2;
		} else {
			cout << "NIE\n";
			return 0;
		}
	}
	cout << "TAK\n";
	return 0;
}
