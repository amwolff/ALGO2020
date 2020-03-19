#include <iostream>

int main() {
  int n;
  scanf("%d", &n);

  int fib[60];
  int idx = (n + 1) % 60;

  fib[0] = 0;
  fib[1] = 1;
  for (int i = 2; i <= idx; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % 10;
  }

  printf("%d\n", fib[idx]);

  return 0;
}
