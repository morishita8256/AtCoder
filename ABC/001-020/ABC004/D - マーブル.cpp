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
  int R, G, B;
  cin >> R >> G >> B;

  int ans = INF;
  repp(Gl, -1000, 1000) {
    int Gr = Gl + G - 1;

    int Rr = -100 + (R - 1) / 2;
    if (Rr >= Gl)
      Rr = Gl - 1;
    int Rl = Rr - R + 1;

    int Bl = 100 - (B - 1) / 2;
    if (Bl <= Gr)
      Bl = Gr + 1;
    int Br = Bl + B - 1;

    int temp = 0;
    repp(i, Rl, Rr) {
      temp += abs(i - (-100));
    }
    repp(i, Gl, Gr) {
      temp += abs(i);
    }
    repp(i, Bl, Br) {
      temp += abs(i - 100);
    }
    chmin(ans, temp);

  }
  cout << ans << endl;
}