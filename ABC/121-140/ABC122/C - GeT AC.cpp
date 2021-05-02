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
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  vector<int> l(Q), r(Q);
  rep(i, Q) {
    cin >> l[i] >> r[i];
    l[i]--;
    r[i]--;
  }

  vector<int> L(N);
  L[0] = 0;
  repp(i, 1, N - 1) {
    L[i] = L[i - 1];
    if (S[i - 1] == 'A' && S[i] == 'C') L[i]++;
  }

  rep(i, Q) { cout << L[r[i]] - L[l[i]] << endl; }
}