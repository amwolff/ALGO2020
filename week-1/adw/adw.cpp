#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct meeting {
  int a;
  int b;
  int d;
  int idx;
};

bool compareMeetings(meeting m1, meeting m2) {
  if (m1.d == m2.d) {
    return m1.b < m2.b;
  }
  return m1.d < m2.d;
}

int main() {
  int n, m;
  scanf("%d %d\n", &n, &m);

  vector<vector<meeting> > meetings(m);
  for (int i = 0; i < n; i++) {
    meeting x;
    scanf("%d %d %d\n", &x.a, &x.b, &x.d);
    x.idx = i + 1;
    meetings[x.d - 1].push_back(x);
  }

  for (size_t i = 0; i < meetings.size(); i++) {
    sort(meetings[i].begin(), meetings[i].end(), compareMeetings);

    meeting x;
    if (meetings[i].size() > 0) {
      x = meetings[i][0];
    }

    for (size_t j = 1; j < meetings[i].size(); j++) {
      if (meetings[i][j].a > x.b) {
        printf("TAK %d %d\n", x.idx, meetings[i][j].idx);
        goto cnt;
      }
    }

    printf("NIE\n");

  cnt:;
  }

  return 0;
}
