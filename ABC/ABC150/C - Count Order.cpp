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
#define sz(x) ((ll)(x).size())
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
  int N;
  cin >> N;
  vector<int> P(N);
  rep(i, N) {
    cin >> P[i];
  }
  vector<int> Q(N);
  rep(i, N) {
    cin >> Q[i];
  }

  int p;
  int q;

  int i = 1;
  vector<int> v(N);
  iota(v.begin(), v.end(), 1);
  do {
    bool match = true;
    rep(j, N) {
      if (P[j] != v[j])
        match = false;
    }
    if (match)
      p = i;

    match = true;
    rep(j, N) {
      if (Q[j] != v[j])
        match = false;
    }
    if (match)
      q = i;

    i++;
  } while (next_permutation(v.begin(), v.end()));

  cout << abs(p-q) << endl;
}