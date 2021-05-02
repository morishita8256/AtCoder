#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define sz(x) ((int)(x).size())
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

int bit3(int n) {
  int temp = 1;
  rep(i, n) {
    temp *= 3;
  }
  return temp;
}

int shift(int b, int n) {
  rep(i, n) {
    b /= 3;
  }
  return b;
}

int ope_and(int b) {
  return b % 3;
}

int main() {
  int K, N;
  cin >> K >> N;
  vector<string> v(N), w(N);
  rep(i, N) cin >> v[i] >> w[i];

  rep(b, bit3(K)) {  // 20000
    vector<int> mojisu(K);
    rep(k, K) {  // 9
      mojisu[k] = ope_and(shift(b, k)) + 1;
    }

    bool mojisu_ok = true;
    rep(n, N) {  // 50
      int cnt = 0;
      rep(j, sz(v[n])) {  // 9
        int num = v[n][j] - '1';
        cnt += mojisu[num];
      }
      if (sz(w[n]) != cnt) {
        mojisu_ok = false;
        break;
      }
    }
    if (!mojisu_ok)
      continue;

    vector<string> ans(K, "hoge");
    bool ok = true;
    rep(n, N) {
      int it = 0;
      rep(j, sz(v[n])) {
        int num = v[n][j] - '1';
        int moji = mojisu[num];
        string sub = w[n].substr(it, moji);
        it += moji;

        if (ans[num] == "hoge") {
          ans[num] = sub;
        } else {
          if (sub != ans[num]) {
            ok = false;
            break;
          }
        }
        if (!ok)
          break;
      }
      if (!ok)
        break;
    }
    if (!ok)
      continue;

    rep(k, K) {
      cout << ans[k] << endl;
    }
    return 0;
  }
}