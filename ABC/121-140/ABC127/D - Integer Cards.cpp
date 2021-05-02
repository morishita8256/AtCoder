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

int main() {
  int N, M;
  cin >> N >> M;

  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  typedef pair<ll, ll> P;
  vector<P> CB(M);
  rep(i, M) { cin >> CB[i].second >> CB[i].first; }
  sort(all(CB), greater<P>());

  int cnt = 0;
  vector<ll> C;

  rep(i, M) {
    rep(j, CB[i].se) {
      C.pb(CB[i].fi);
      cnt++;
      if (cnt > N) break;
    }
    if (cnt > N) break;
  }
  rep(i, N - cnt) C.pb(0);

  sort(all(A));

  ll sum = 0;
  rep(i, N) { sum += max(A[i], C[i]); }
  cout << sum << endl;
}