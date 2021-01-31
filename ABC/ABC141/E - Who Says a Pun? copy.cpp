#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
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

typedef unsigned long long ull;
const int MAX_LENGTH = 500000;
const ull MASK30 = (1ULL << 30) - 1;
const ull MASK31 = (1ULL << 31) - 1;
const ull MODrh = (1ULL << 61) - 1;
const ull POSITIVIZER = MODrh * ((1ULL << 3) - 1);
unsigned int Base;
vector<ull> powMemo(MAX_LENGTH + 1);

ull Mul(ull l, ull r) {
  ull lu = l >> 31;
  ull ld = l & MASK31;
  ull ru = r >> 31;
  ull rd = r & MASK31;
  ull middleBit = ld * ru + lu * rd;
  return ((lu * ru) << 1) + ld * rd + ((middleBit & MASK30) << 31) +
         (middleBit >> 30);
}

ull CalcMod(ull val) {
  val = (val & MODrh) + (val >> 61);
  if (val > MODrh)
    val -= MODrh;
  return val;
}

void init_RH() {
  srand(time(NULL));
  Base = rand() % RAND_MAX + 129;
  powMemo[0] = 1;
  repp(i, 1, sz(powMemo) - 1) {
    powMemo[i] = CalcMod(Mul(powMemo[i - 1], Base));
  }
}

struct RollingHash {
  vector<ull> hash;

  RollingHash(string s) {
    hash = vector<ull>(sz(s) + 1);
    rep(i, sz(s)) {
      hash[i + 1] = CalcMod(Mul(hash[i], Base) + s[i]);
    }
  }

  ull Slice(int begin, int length) {
    return CalcMod(hash[begin + length] + POSITIVIZER -
                   Mul(hash[begin], powMemo[length]));
  }
};



int main() {
  init_RH();
  int N;
  cin >> N;
  string S;
  cin >> S;

  RollingHash R(S);

  int ans = 0;
  rep(i, N) {
    repp(j, i, N - 1) {
      while ((ans < j - i) && (j + ans < N) &&
             R.Slice(i, ans + 1) == R.Slice(j, ans + 1))
        ans++;
    }
  }

  cout << ans << endl;
}