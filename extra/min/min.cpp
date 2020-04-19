#include <cstdio>

int main() {
  int n;
  scanf("%d\n", &n);

  // Use a closure here to remember state.
  char prev = '\0';
  for (int i = 0; i < n - 1; i++) {
    char curr;
    scanf("%c\n", &curr);

    if (curr == '+' && prev == '\0') {
      printf("-(-");
    } else if (curr == '+' && prev == '-') {
      printf("(-");
    } else if (curr == '+' && prev == '+') {
      printf("-");
    } else if (curr == '-' && prev == '+') {
      printf(")-");
    } else {
      printf("-");
    }

    prev = curr;
  }

  if (prev == '+') {
    printf(")\n");
  } else {
    printf("\n");
  }

  return 0;
}
