#include <limits.h>

#include <cstdio>
#include <vector>

using namespace std;

int t, a;
vector<int> t_list, a_list, w_list;

int f(size_t i, int t_i, int a_i) {
  if (t_i >= t && a_i >= a) {
    return 0;
  }

  int res = INT_MAX;

  for (; i < w_list.size(); i++) {
    const int sub = f(i + 1, t_i + t_list[i], a_i + a_list[i]);
    if (sub != INT_MAX && sub + w_list[i] < res) {
      res = sub + w_list[i];
    }
  }

  return res;
}

int main() {
  scanf("%d %d\n", &t, &a);
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++) {
    int t_i, a_i, w_i;
    scanf("%d %d %d\n", &t_i, &a_i, &w_i);
    t_list.push_back(t_i);
    a_list.push_back(a_i);
    w_list.push_back(w_i);
  }

  printf("%d\n", f(0, 0, 0));

  return 0;
}
