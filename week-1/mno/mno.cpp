#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  vector<int> t(n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &t[i]);
  }

  int asc_count = 0;
  int dsc_count = 0;
  for (size_t i = 0, s = t.size(); i < s; i++) {
    if (t[i] > t[(i + 1) % s]) {
      asc_count++;
    }
    if (t[i] < t[(i + 1) % s]) {
      dsc_count++;
    }
    if (asc_count > 1 && dsc_count > 1) {
      printf("NIE\n");
      return 0;
    }
  }

  printf("TAK\n");

  return 0;
}
