#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);

  vector<pair<int, int>> intervals(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d\n", &intervals[i].first, &intervals[i].second);
  }

  sort(intervals.begin(), intervals.end());

  int locmin = intervals[0].first;
  int locmax = intervals[0].second;
  for (size_t i = 1; i < intervals.size(); i++) {
    if (locmax < intervals[i].first) {
      printf("%d %d\n", locmin, locmax);
      locmin = intervals[i].first;
      locmax = intervals[i].second;
    } else {
      locmax = max(locmax, intervals[i].second);
    }
    if (i == intervals.size() - 1) {
      printf("%d %d\n", locmin, locmax);
    }
  }

  return 0;
}
