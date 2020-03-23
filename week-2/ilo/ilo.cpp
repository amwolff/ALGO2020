#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> fib(int n_i) {
  vector ret{0, 1};
  for (size_t i = 2; ret.back() < n_i; i++) {
    ret.push_back(ret[i - 1] + ret[i - 2]);
  }
  return ret;
}

int main() {
  int t;
  scanf("%d\n", &t);

  vector<int> n(t);
  for (int i = 0; i < t; i++) {
    scanf("%d", &n[i]);
  }

  vector fibs = fib(*max_element(n.begin(), n.end()));
  unordered_set<int> fibs_set(fibs.begin(), fibs.end());

  for (int n_i : n) {
    int limit = n_i / 2;
    if (limit == 0) {
      limit = 1;
    }
    for (size_t i = 1; fibs[i] <= limit; i++) {
      if (n_i % fibs[i] == 0 &&
          fibs_set.find(n_i / fibs[i]) != fibs_set.end()) {
        printf("TAK\n");
        goto cnt;
      }
    }
    printf("NIE\n");
  cnt:;
  }

  return 0;
}
