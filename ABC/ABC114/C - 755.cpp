#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

ll N;
int keta;

int dfs(int now, int sum) {
  int ans = 0;

  int cnt[10];
  rep(i, 10) { cnt[i] = 0; }
  int sum_cp = sum;
  while (sum_cp) {
    cnt[sum_cp % 10]++;
    sum_cp /= 10;
  }
  bool is_753 =
      cnt[3] > 0 && cnt[5] > 0 && cnt[7] > 0 &&
      cnt[0] + cnt[1] + cnt[2] + cnt[4] + cnt[6] + cnt[8] + cnt[9] == 0;

  if (now == keta) {
    if (sum <= N && is_753) ans++;
  } else {
    if (is_753) ans++;
    for (int i = 3; i < 8; i += 2) {
      ans += dfs(now + 1, sum * 10 + i);
    }
  }
  return ans;
}

int main() {
  cin >> N;
  keta = log10(N) + 1;

  cout << dfs(0, 0) << endl;
}