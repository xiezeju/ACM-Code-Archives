#include <cstdio>
#include <cstring>
using namespace std;

char a[5] = {'a', 'e', 'i', 'o', 'u'};
int ans[256];

int main() {
  int n;
  scanf("%d", &n);

  getchar();

  while (n--) {
    memset(ans, 0, sizeof ans);
    char s[105];
    gets(s);

    for (int i = 0; i < strlen(s); i++) ans[s[i]]++;

    for (int i = 0; i < 5; i++) printf("%c:%d\n", a[i], ans[a[i]]);

    if (n) puts("");
  }

  return 0;
}