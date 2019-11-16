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
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  string U = S;
  sort(all(U));

  repr(i, N, 0) {
    int diff = 0;
    rep(j, i) {
      if (U[j] != S[j])
        diff++;
    }
    map<char, int> mS;
    map<char, int> mU;
    repp(j, i, N - 1) {
      mS[S[j]]++;
      mU[U[j]]++;
    }

    int cnt = 0;
    for (char c = 'a'; c <= 'z'; c++) {
      cnt += abs(mS[c] - mU[c]);
    }
    cnt /= 2;

    if (diff + cnt <= K) {
    
        }
  }
}