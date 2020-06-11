#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);

  const size_t s = n;

  vector<int> v(s);
  for (size_t i = 0; i < s; i++) {
    scanf("%d\n", &v[i]);
  }

  vector<int> ans;

  size_t idx = 0;
  for (size_t j = idx; j < s; j++) {
    if (v[j] == 0) {
      idx = j;
      ans.push_back(0);
      break;
    }
  }
  for (size_t j = idx; j < s; j++) {
    if (v[j] == 1) {
      idx = j;
      ans.push_back(0);
      break;
    }
  }
  for (size_t j = idx; j < s; j++) {
    if (v[j] == 2) {
      ans.push_back(0);
      break;
    }
  }

  printf("%ld\n", ans.size());

  return 0;
}
