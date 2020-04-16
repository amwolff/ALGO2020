#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d\n", &n);

  size_t s = n;

  vector<int> dem(s), dis(s);
  for (size_t i = 0; i < s; i++) {
    scanf("%d %d\n", &dem[i], &dis[i]);
  }

  long long dem_l = 0;
  long long dis_l = 0;
  long long dem_r = 0;
  long long dis_r = 0;

  size_t l = 0;
  size_t r = 0;

  long long c = 0;

  for (size_t i = 1; i < s; i++) {
    if (dis_l + dis[(l + s - 1) % s] < dis_r + dis[r]) {
      dis_l += dis[(l + s - 1) % s];
      l = (l + s - 1) % s;
      c += dis_l * dem[l];
      dem_l += dem[l];
    } else {
      dis_r += dis[r];
      r = (r + 1) % s;
      c += dis_r * dem[r];
      dem_r += dem[r];
    }
  }

  long long minimum = c;

  for (size_t i = 1; i < s; i++) {
    dem_l += dem[i - 1];

    dis_l += dis[(i + s - 1) % s];
    dis_r -= dis[(i + s - 1) % s];

    c += dis[(i + s - 1) % s] * (dem_l - dem_r);

    dem_r -= dem[i];

    while (dis_l > dis_r + dis[r]) {
      dis_r += dis[r];

      r = (r + 1) % s;

      dem_l -= dem[r];
      dem_r += dem[r];

      c += dem[r] * (dis_r - dis_l);

      dis_l -= dis[r];
    }

    minimum = min(minimum, c);
  }

  printf("%lld\n", minimum);

  return 0;
}
