#include <math.h>
#include <iostream>

int main() {
  int n;
  scanf("%d", &n);

  int ans = (n - 1) + sqrt(n);

  int i = 2;
  int j = n / 2;
  while (i < j) {
    if (i * j <= n) {
      ans += j - i;
      i++;
    } else {
      j--;
    }
  }

  printf("%d\n", ans);

  return 0;
}
