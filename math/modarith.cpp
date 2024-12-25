// definition of P required
namespace modarith {
class mint {
 private:
  int x;
 public:
  mint() : x(0) {}
  template <typename T> mint(T val) : x(val >= P ? val % P : val) {}
  int toint() {
    return x;
  }
  friend istream& operator >> (istream& ist, mint& rhs) {
    ist >> rhs.x;
    return ist;
  }
  friend ostream& operator << (ostream& ost, const mint& rhs) {
    ost << rhs.x;
    return ost;
  }
  mint& operator = (const mint& rhs) {
    x = rhs.x;
    return *this;
  }
  mint operator + (const mint& rhs) {
    mint res = x + rhs.x;
    if (res.x >= P) res.x -= P;
    return res;
  }
  mint operator - (const mint& rhs) {
    mint res = x - rhs.x;
    if (res.x < 0) res.x += P;
    return res;
  }
  mint operator * (const mint& rhs) {
    long long res = 1ll * x * rhs.x;
    if (res >= P) res %= P;
    return res;
  }
  mint& operator += (const mint& rhs) {
    return *this = *this + rhs;
  }
  mint& operator -= (const mint& rhs) {
    return *this = *this - rhs;
  }
  mint& operator *= (const mint& rhs) {
    return *this = *this * rhs;
  }
};
mint fastpow(mint x, int y) {
  mint res = 1;
  for (; y; y >>= 1) {
    if (y & 1) res *= x;
    x *= x;
  }
  return res;
}
vector<mint> fac, ifac;
void getfac(int n) {
  fac.resize(n + 1);
  n = min(n, P - 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i;
  }
}
void getifac(int n) {
  ifac.resize(n + 1);
  n = min(n, P - 1);
  ifac[n] = fastpow(fac[n], P - 2);
  for (int i = n - 1; i >= 0; i--) {
    ifac[i] = ifac[i + 1] * (i + 1);
  }
}
mint binom(int x, int y) {
  if (x < y) return 0;
  return fac[x] * ifac[y] * ifac[x - y];
}
} // namespace modarith
