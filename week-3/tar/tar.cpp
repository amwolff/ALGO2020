#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n, k;
  scanf("%d %d\n", &n, &k);

  vector<int> h(n);
  for (size_t i = 0; i < h.size(); i++) {
    scanf("%d\n", &h[i]);
  }

  vector<int> costs_right(n);
  costs_right[0] = 0;
  for (size_t i = 0; i < h.size() - 1; i++) {
    costs_right[i + 1] = max(h[i + 1] - h[i], 0);
  }

  vector<int> costs_left(n);
  costs_left[0] = 0;
  for (size_t i = h.size() - 1, j = 1; i > 0; i--, j++) {
    costs_left[j] = max(h[i - 1] - h[i], 0);
  }

  int max_r = 0;
  int max_l = 0;

  {
    int sum = 0;
    for (size_t i = 0, j = 0; i < costs_right.size(); i++) {
      while (sum + costs_right[i] > k && j < i) {
        sum -= costs_right[j];
        j++;
      }

      sum += costs_right[i];

      if (sum <= k) {
        max_r = max(max_r, int(i - j + 1));
      }
    }
  }

  {
    int sum = 0;
    for (size_t i = 0, j = 0; i < costs_left.size(); i++) {
      while (sum + costs_left[i] > k && j < i) {
        sum -= costs_left[j];
        j++;
      }

      sum += costs_left[i];

      if (sum <= k) {
        max_l = max(max_l, int(i - j + 1));
      }
    }
  }

  printf("%d\n", max(max_r, max_l));

  return 0;
}
