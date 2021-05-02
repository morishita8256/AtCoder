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
  int N, M, D;
  cin >> N >> M >> D;
  vector<int> A(M);
  rep(i, M) {
    cin >> A[i];
    A[i]--;
  }

  vector<int> B(N);
  rep(i, N) {
    B[i] = i;
  }

  reverse(all(A));
  rep(i, M) {
    swap(B[A[i]], B[A[i] + 1]);
  }

  vector<int> ans(N, -1);
  rep(i, N) {
    if (ans[i] != -1)
      continue;

    vector<int> loop;
    loop.pb(i);
    int temp = B[i];
    while (temp != i) {
      loop.pb(temp);
      temp = B[temp];
    }

    int num = sz(loop);
    int md = D % num;
    rep(j, num) {
      ans[loop[j]] = loop[(j + md) % num];
    }
  }

  rep(i, N) {
    cout << ans[i] + 1 << endl;
  }
}