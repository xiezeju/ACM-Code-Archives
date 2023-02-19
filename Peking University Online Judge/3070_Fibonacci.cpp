
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
typedef long long ll;
const int mod = 10000;
const int N = 110;

int n, m;  // n×m的矩阵, 具体含义视题目而定

// 传统快速幂(a为底数, k为指数)
ll fastpow(int a, int k) {
  ll ans = 1;
  while (k) {
    if (k & 1) ans = (ans * a) % mod;  // 当前二进制数第一位有1说明需要乘a
    a = (a * a) % mod;                 // a变为自身的平方
    k >>= 1;  // 每次执行完一次判断, 二进制数左移一位
  }
  return ans;
}

// 矩阵快速幂(构造、运算一体化)
struct Matrix {
  ll a[N][N];  // 一定要开long long

  Matrix() { memset(a, 0, sizeof a); }  // 构造函数, 默认初始化

  Matrix operator*(
      const Matrix &b) const {  // 重载*运算符, 使得*可以直接表示矩阵相乘
    Matrix ans;
    // 这里假设两相乘的矩阵一个是n×m另一个是m×n的, 根据实际需求修改n和m的值
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= m; k++)
          // 这里用到了模运算的性质(a×b) mod m = ((a mod m) × (b mod m)) mod m
          ans.a[i][j] =
              (ans.a[i][j] + (a[i][k] % mod) * (b.a[k][j] % mod)) % mod;
    return ans;
  }

  Matrix fastpow(int k) {
    Matrix ans;
    Matrix p = (*this);  // 用一个this指针指向当前结构体的矩阵a[N][N]

    // 转移矩阵ans要根据题意自己构造, 这里举个简单的例子,
    // 构造成单位矩阵(假设n与m相等)
    for (int i = 1; i <= n; i++) ans.a[i][i] = 1;

    // 重载了*运算符以后这部分写法就和普通的快速幂没什么区别了
    while (k) {
      if (k & 1) ans = ans * p;
      p = p * p;
      k >>= 1;
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int g;
  while (cin >> g) {
    if (g == -1) break;
    n = m = 2;
    Matrix q;
    q.a[1][1] = q.a[1][2] = q.a[2][1] = 1;
    q = q.fastpow(g);
    cout << q.a[1][2] << endl;
    ;
  }
  return 0;
}