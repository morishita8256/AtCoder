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
  vector<string> temp(N);
  rep(i, N) {
    cin >> temp[i];
  }

  typedef pair<int, int> P;
  vector<P> SE(N);
  rep(i, N) {
    int Sh = stoi(temp[i].substr(0, 2));
    int Sm = stoi(temp[i].substr(2, 2));
    int Eh = stoi(temp[i].substr(5, 2));
    int Em = stoi(temp[i].substr(7, 2));

    SE[i] = P(Sh * 60 + Sm, Eh * 60 + Em);
  }


  rep(i, N) {
    SE[i].fi /= 5;
    SE[i].fi *= 5;
    SE[i].se = (SE[i].se + 4) / 5;
    SE[i].se *= 5;
  }

  sort(all(SE));


  rep(i, N - 1) {
    if (SE[i].se >= SE[i + 1].fi) {
      SE[i + 1].fi = SE[i].fi;

      int temp_E = max(SE[i].se, SE[i + 1].se);
      SE[i].se = temp_E, SE[i + 1].se = temp_E;
    }
  }


  SE.pb(P(INF, INF));
  rep(i, N) {
    if (SE[i].fi == SE[i + 1].fi)
      continue;
    int Sh = SE[i].fi / 60;
    int Sm = SE[i].fi % 60;
    int Eh = SE[i].se / 60;
    int Em = SE[i].se % 60;
    printf("%02d%02d-%02d%02d\n", Sh, Sm, Eh, Em);
  }
}