#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
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

template <typename T>
size_t lis(const vector<T>& a, bool strict) {
  vector<T> lis;
  for (auto& p : a) {
    typename vector<T>::iterator it;
    if (strict)
      it = lower_bound(begin(lis), end(lis), p);
    else
      it = upper_bound(begin(lis), end(lis), p);
    if (end(lis) == it)
      lis.emplace_back(p);
    else
      *it = p;
  }
  return lis.size();
}

int main() {
  int N;
  cin >> N;
  typedef pair<int, int> P;
  vector<P> wh(N);
  rep(i, N) {
    cin >> wh[i].fi >> wh[i].se;
    wh[i].se *= -1;
  }

  sort(all(wh));

  vector<int> H(N);
  rep(i, N) {
    H[i] = wh[i].se * -1;
  }

  int ans = lis(H, true);
  cout << ans << endl;
}