#include <iostream>

int pow(int d, int exp) {
  int ret = d;
  for (int i = 0; i < exp - 1; i++) {
    ret *= d;
  }
  return ret;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  int d = a % 10;
  if (d == 0) {
    printf("0\n");
    return 0;
  }

  int exp = b % 4;
  if (exp == 0) {
    exp = 4;
  }

  printf("%d\n", pow(d, exp) % 10);

  return 0;
}
