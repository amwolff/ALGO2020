#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);

  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    scanf("%d\n", &a[i]);
  }

  sort(a.begin(), a.end());

  size_t i = 0;
  size_t j = a.size() - 1;
  int ans = 0;
  while (i <= j) {
    if (i == j) {
      ans += a[i];
      break;
    }
    ans += 2 * a[j];
    i++;
    j--;
  }

  printf("%d\n", ans);

  return 0;
}
