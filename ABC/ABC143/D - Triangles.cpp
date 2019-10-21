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

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  rep(i, N) cin >> L[i];
  sort(all(L));

  int ans = 0;
  rep(ia, N - 2) {
    repp(ib, ia + 1, N - 2) {
      int a = L[ia], b = L[ib];
      int wa = a + b, sa = b - a;
      auto iterR = lower_bound(all(L), wa);
      int posR = distance(L.begin(), iterR);
      auto iterL = upper_bound(all(L), sa);
      int posL = distance(L.begin(), iterL);
      chmax(posL, ib + 1);
      ans += posR - posL;
    }
  }
  cout << ans << endl;
  // rep(ia, N) {
  //   rep(ib, N) {
  //     if (ia == ib)
  //       continue;
  //     int a = L[ia], b = L[ib];
  //     int wa = a + b, sa = abs(a - b);

  //     auto iterR = lower_bound(all(L), wa);
  //     int posR = distance(L.begin(), iterR);
  //     auto iterL = upper_bound(all(L), sa);
  //     int posL = distance(L.begin(), iterL);

  //     int temp = posR - posL;
  //     if (posL <= ia && ia < posR)
  //       temp--;
  //     if (posL <= ib && ib < posR)
  //       temp--;
  //     ans += temp;
  //   }
  // }
  // ans /= 6;

  // cout << ans << endl;
}