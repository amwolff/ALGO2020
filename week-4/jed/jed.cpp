#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);

  const size_t s = n;

  vector<int> a(s), b(s), c(s);
  for (size_t i = 0; i < s; i++) {
    scanf("%d", &a[i]);
  }
  for (size_t i = 0; i < s; i++) {
    scanf("%d", &b[i]);
  }
  for (size_t i = 0; i < s; i++) {
    scanf("%d", &c[i]);
  }

  int maximum = 0;
  for (size_t i = 0; i < s; i++) {
    for (size_t j = 0; j < s; j++) {
      for (size_t k = 0; k < s; k++) {
        int count = 0;
        for (size_t l = 0; l < s; l++) {
          if (a[l] == b[l] && a[l] == c[l]) {
            count++;
          }
        }
        maximum = max(maximum, count);
        rotate(c.begin(), ++c.begin(), c.end());
      }
      rotate(b.begin(), ++b.begin(), b.end());
    }
    rotate(a.begin(), ++a.begin(), a.end());
  }

  printf("%d\n", maximum);

  return 0;
}
