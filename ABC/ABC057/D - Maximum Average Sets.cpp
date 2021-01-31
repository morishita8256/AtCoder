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
  ll N, A, B;
  cin >> N >> A >> B;
  vector<ll> v(N);
  rep(i, N) cin >> v[i];
  sort(all(v), greater<ll>());

  ll sum = 0;
  rep(i, A) {
    sum += v[i];
  }

  printf("%.6f\n", (double)sum / A);

  ll k = 0;
  rep(i, A) {
    if (v[i] == v[A - 1])
      k++;
  }

  ll n = 0;
  rep(i, N) {
    if (v[i] == v[A - 1])
      n++;
  }

  ll COM[51][51];

  repp(i, 0, N) {
    repp(j, 0, i) {
      if (j == 0 || j == i)
        COM[i][j] = 1;
      else {
        COM[i][j] = COM[i - 1][j - 1] + COM[i - 1][j];
      }
    }
  }

  ll ans = 0;
  if (k == A) {
    repp(i, A, B) {
      ans += COM[n][i];
    }
  } else {
    ans = COM[n][k];
  }
  cout << ans << endl;
}