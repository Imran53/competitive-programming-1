#include <bits/stdc++.h>

#define MAX 65536

#define bb(n) (buf[(n) % MAX])
#define cc(n) (cbuf[(n) % MAX])

int buf[MAX];
int cbuf[MAX];
int b, i, j, k, besti = -1, bestj;

int cnt[MAX];

int main() {
  for (i = 0; 1 == scanf("%d", &bb(i)) && bb(i); i++) {
    cnt[bb(i)]++;
    while (cnt[bb(i)] > 1)
      cnt[bb(j++)]--;
    if (i - j > besti - bestj) {
      if (j > besti) {
        for (k = j; k <= i; k++)
          cc(k) = bb(k);
      } else {
        for (k = besti + 1; k <= i; k++)
          cc(k) = bb(k);
      }
      besti = i;
      bestj = j;
    }
  }
  for (k = bestj; k <= besti; k++) {
    printf("%d\n", cc(k));
  }
}
