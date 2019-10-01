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
const int MOD = 1000000007;

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int x, y;
  cin >> x >> y;
  vector<int> cnt(13);
  cnt[x]++;
  cnt[y]++;

  if (cnt[1] + cnt[3] + cnt[5] + cnt[7] + cnt[8] + cnt[10] + cnt[12] == 2)
    cout << "Yes" << endl;
  else if (cnt[4] + cnt[6] + cnt[9] + cnt[11] == 2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}