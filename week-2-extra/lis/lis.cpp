#include <cstdio>

int main() {
  long long n, k, i, j;
  scanf("%lld %lld %lld %lld", &n, &k, &i, &j);

  if (j >= k) {
    if (i < k) {
      printf("%lld\n", n * (-i + k + 1) - (i - j - 1) * (i + j - 2 * k) / 2);
      return 0;
    } else if (i == k) {
      printf("%lld\n", (j - k) * (j - k + 1) / 2 + n);
      return 0;
    } else if (i > k) {
      printf("%lld\n", (i - j - 1) * (i + j - 2 * k) / -2);
      return 0;
    }
  }

  return 0;
}
