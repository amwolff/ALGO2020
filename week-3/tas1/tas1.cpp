#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, t;
  scanf("%d %d\n", &n, &t);

  vector<int> a(1 << n);
  for (size_t i = 0; i < a.size(); i++) {
    scanf("%d", &a[i]);
  }

  if (t % 2 == 1) {
    reverse(a.begin(), a.end());
  }

  for (size_t i = 0, s = a.size(); i < s; i++) {
    if (i == s - 1) {
      printf("%d\n", a[i]);
      return 0;
    }
    printf("%d ", a[i]);
  }

  return 0;
}
