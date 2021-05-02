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
#define len(x) ((ll)(x).size())
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

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

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

struct KMP {
  vector<ll> pattern;
  int plen;
  vector<int> table;

  KMP(const vector<ll>& s)
      : pattern(s), plen((int)pattern.size()), table(plen + 1) {
    table[0] = -1;
    int j = -1;
    for (int i = 0; i < plen; ++i) {
      while (j >= 0 && pattern[i] != pattern[j]) {
        j = table[j];
      }
      table[i + 1] = ++j;
    }
  }

  void search(const vector<ll>& text, vector<int>& res) {
    int head = 0, j = 0, tlen = (int)text.size();
    while (head + j < tlen) {
      if (pattern[j] == text[head + j]) {
        if (++j == plen) {
          res.push_back(head);
          head = head + j - table[j];
          j = table[j];
        }
      } else {
        head = head + j - table[j];
        if (j)
          j = table[j];
      }
    }
  }
};

signed main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  rep(i, N) {
    cin >> a[i];
  }
  vector<ll> b(N);
  rep(i, N) {
    cin >> b[i];
  }

  vector<ll> aa(N), bb(N);
  rep(i, N) {
    int j = (i + 1) % N;
    aa[i] = (a[i] ^ a[j]);
    bb[i] = (b[i] ^ b[j]);
  }

  vector<ll> aa2(2 * N);
  rep(i, N) {
    aa2[i] = aa[i];
    aa2[i + N] = aa[i];
  }

  KMP kmp(bb);  // 検索文字列
  vector<int> ans;
  kmp.search(aa2, ans);
  rep(i, len(ans)) {
    if (ans[i] >= N)
      break;
    int k = ans[i];
    ll x = (a[k] ^ b[0]);
    cout << k << ' ' << x << "\n";
  }
}