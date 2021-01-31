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
  int N, K;
  cin >> N >> K;

  string S;
  cin >> S;

  vector<int> A(0);

  char now = '1';
  int cnt = 0;
  rep(i, S.size()) {
    if (now == S[i])
      cnt++;
    else {
      A.pb(cnt);
      now = S[i];
      cnt = 1;
    }
  }
  if (cnt != 0) A.pb(cnt);
  if (S[S.size() - 1] == '0') A.pb(0);
  // rep(i, A.size()) { cout << A[i] << endl; }

  vector<int> sum(N + 1);
  rep(i, A.size()) { sum[i + 1] = sum[i] + A[i]; }

  int w = 2 * K + 1;
  int temp = 0;
  int ans = 0;

  for (int i = 0; i < A.size(); i += 2) {
    int l = i;
    int r = min(i + w, (int)A.size());

    temp = sum[r] - sum[l];

    chmax(ans, temp);
  }

  cout << ans << endl;
}