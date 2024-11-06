#line 1 "A.cpp"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
template <class T>
using pq = priority_queue<T>;
template <class T>
using qp = priority_queue<T, vector<T>, greater<T>>;
#define vec(T, A, ...) vector<T> A(__VA_ARGS__);
#define vvec(T, A, h, ...) vector<vector<T>> A(h, vector<T>(__VA_ARGS__));
#define vvvec(T, A, h1, h2, ...) vector<vector<vector<T>>> A(h1, vector<vector<T>>(h2, vector<T>(__VA_ARGS__)));

#ifndef RIN__LOCAL
#define endl "\n"
#endif
#define spa ' '
#define len(A) A.size()
#define all(A) begin(A), end(A)

#define fori1(a) for(ll _ = 0; _ < (a); _++)
#define fori2(i, a) for(ll i = 0; i < (a); i++)
#define fori3(i, a, b) for(ll i = (a); i < (b); i++)
#define fori4(i, a, b, c) for(ll i = (a); ((c) > 0 || i > (b)) && ((c) < 0 || i < (b)); i += (c))
#define overload4(a, b, c, d, e, ...) e
#define fori(...) overload4(__VA_ARGS__, fori4, fori3, fori2, fori1)(__VA_ARGS__)

template <typename T>
vector<tuple<ll, T>> ENUMERATE(vector<T> &A, ll s = 0){
    vector<tuple<ll, T>> ret(A.size());
    for(int i = 0; i < A.size(); i++) ret[i] = {i + s, A[i]};
    return ret;
}

vector<tuple<ll, char>> ENUMERATE(string &A, ll s = 0){
    vector<tuple<ll, char>> ret(A.size());
    for(int i = 0; i < A.size(); i++) ret[i] = {i + s, A[i]};
    return ret;
}

#define enum1(A) fori(A.size())
#define enum2(a, A) for(auto a:A)
#define enum3(i, a, A) for(auto&& [i, a]: ENUMERATE(A))
#define enum4(i, a, A, s) for(auto&& [i, a]: ENUMERATE(A, s))
#define enum(...) overload4(__VA_ARGS__, enum4, enum3, enum2, enum1)(__VA_ARGS__)

template <typename T, typename S>
vector<tuple<T, S>> ZIP(vector<T> &A, vector<S> &B){
    int n = min(A.size(), B.size());
    vector<tuple<T, S>> ret(n);
    for(int i = 0; i < n; i++) ret[i] = {A[i], B[i]};
    return ret;
}

template <typename T, typename S>
vector<tuple<ll, T, S>> ENUMZIP(vector<T> &A, vector<S> &B, ll s = 0){
    int n = min(A.size(), B.size());
    vector<tuple<ll, T, S>> ret(n);
    for(int i = 0; i < n; i++) ret[i] = {i + s, A[i], B[i]};
    return ret;
}

#define zip4(a, b, A, B) for(auto&& [a, b]: ZIP(A, B))
#define enumzip5(i, a, b, A, B) for(auto&& [i, a, b]: ENUMZIP(A, B))
#define enumzip6(i, a, b, A, B, s) for(auto&& [i, a, b]: ENUMZIP(A, B, s))
#define overload6(a, b, c, d, e, f, g, ...) g
#define zip(...) overload6(__VA_ARGS__, enumzip6, enumzip5, zip4, _, _, _)(__VA_ARGS__)

vector<char> stoc(string &S){
    int n = S.size();
    vector<char> ret(n);
    for(int i = 0; i < n; i++) ret[i] = S[i];
    return ret;
}

#define INT(...) int __VA_ARGS__; inp(__VA_ARGS__);
#define LL(...) ll __VA_ARGS__; inp(__VA_ARGS__);
#define STRING(...) string __VA_ARGS__; inp(__VA_ARGS__);
#define CHAR(...) char __VA_ARGS__; inp(__VA_ARGS__);
#define VEC(T, A, n) vector<T> A(n); inp(A);
#define VVEC(T, A, n, m) vector<vector<T>> A(n, vector<T>(m)); inp(A);

const ll MOD1 = 1000000007;
const ll MOD9 = 998244353;

template<class T> auto min(const T& a){
    return *min_element(all(a));
}
template<class T> auto max(const T& a){
    return *max_element(all(a));
}
template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

void FLUSH(){cout << flush;}
void print(){cout << endl;}
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
    cout << head;
    if (sizeof...(Tail)) cout << spa;
    print(forward<Tail>(tail)...);
}
template<typename T>
void print(vector<T> &A){
    int n = A.size();
    for(int i = 0; i < n; i++){
        cout << A[i];
        if(i == n - 1) cout << endl;
        else cout << spa;
    }
}
template<typename T>
void print(vector<vector<T>> &A){
    for(auto &row: A) print(row);
}
template<typename T, typename S>
void print(pair<T, S> &A){
    cout << A.first << spa << A.second << endl;
}
template<typename T, typename S>
void print(vector<pair<T, S>> &A){
    for(auto &row: A) print(row);
}
template<typename T, typename S>
void prisep(vector<T> &A, S sep){
    int n = A.size();
    for(int i = 0; i < n; i++){
        cout << A[i];
        if(i == n - 1) cout << endl;
        else cout << sep;
    }
}
template<typename T, typename S>
void priend(T A, S end){
    cout << A << end;
}
template<typename T>
void priend(T A){
    priend(A, spa);
}
template<class... T>
void inp(T&... a){
    (cin >> ... >> a);
}
template<typename T>
void inp(vector<T> &A){
    for(auto &a:A) cin >> a;
}
template<typename T>
void inp(vector<vector<T>> &A){
    for(auto &row:A) inp(row);
}
template<typename T, typename S>
void inp(pair<T, S> &A){
    inp(A.first, A.second);
}
template<typename T, typename S>
void inp(vector<pair<T, S>> &A){
    for(auto &row: A) inp(row.first, row.second);
}

template<typename T>
T sum(vector<T> &A){
    T tot = 0;
    for(auto a:A) tot += a;
    return tot;
}

template<typename T>
pair<vector<T>, map<T, int>> compression(vector<T> X){
    sort(all(X));
    X.erase(unique(all(X)), X.end());
    map<T, int> mp;
    for(int i = 0; i < X.size(); i++) mp[X[i]] = i;
    return {X, mp};
}

#line 2 "Library/C++/math/modpow.hpp"

template<typename T>
T modpow(T a, long long b, T MOD){
    T ret = 1;
    while(b > 0){
        if(b & 1){
            ret *= a;
            ret %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return ret;
}
#line 3 "Library/C++/convolution/convolution.hpp"

namespace FFT{
    using ll = long long;
    
    const ll MOD = 998244353;
    const int g = 3;
 
    template<typename T>
    void butterfly(vector<T> &a) {
        int n = a.size();
        int h = 0;
        while((1 << h) < n) h++;
        static bool first = true;
        static T sum_e[30];
        if(first) {
            first = false;
            T es[30], ies[30];
            int cnt2 = __builtin_ctz(MOD - 1);
            T e = modpow<T>(g, (MOD - 1) >> cnt2, MOD);
            T ie = modpow<T>(e, MOD - 2, MOD);
 
            for(int i = cnt2; i >= 2; i--){
                es[i - 2] = e;
                ies[i - 2] = ie;
                e *= e;
                e %= MOD;
                ie *= ie;
                ie %= MOD;
            }
 
            T now = 1;
            for(int i = 0; i < cnt2 - 2; i++){
                sum_e[i] = es[i] * now % MOD;
                now *= ies[i];
                now %= MOD;
            }
        }
 
        for(int ph = 1; ph <= h; ph++){
            int w = 1 << (ph - 1);
            int p = 1 << (h - ph);
            T now = 1;
            for(int s = 0; s < w; s++){
                int offset = s << (h - ph + 1);
                for(int i = 0; i < p; i++){
                    auto l = a[i + offset];
                    auto r = a[i + offset + p] * now % MOD;
                    a[i + offset] = (l + r) % MOD;
                    a[i + offset + p] = (l - r) % MOD;
                }
                now *= sum_e[__builtin_ctz(~(unsigned int)(s))];
                now %= MOD;
            }
        }
    }
 
    template<typename T>
    void butterfly_inv(vector<T> &a) {
        int n = a.size();
        int h = 1;
        while((1 << h) < n) h++;
        static bool first = true;
        static T sum_ie[30];
        if(first) {
            first = false;
            T es[30], ies[30];
            int cnt2 = __builtin_ctz(MOD - 1);
            T e = modpow<T>(g, (MOD - 1) >> cnt2, MOD);
            T ie = modpow<T>(e, MOD - 2, MOD);
 
            for(int i = cnt2; i >= 2; i--){
                es[i - 2] = e;
                ies[i - 2] = ie;
                e *= e;
                e %= MOD;
                ie *= ie;
                ie %= MOD;
            }
 
            T now = 1;
            for(int i = 0; i < cnt2 - 2; i++){
                sum_ie[i] = ies[i] * now % MOD;
                now *= es[i];
                now %= MOD;
            }
        }
 
        for(int ph = h; ph > 0; ph--){
            int w = 1 << (ph - 1);
            int p = 1 << (h - ph);
            T inow = 1;
            for(int s = 0; s < w; s++){
                int offset = s << (h - ph + 1);
                for(int i = 0; i < p; i++){
                    auto l = a[i + offset];
                    auto r = a[i + offset + p];
                    a[i + offset] = (l + r) % MOD;
                    a[i + offset + p] = (l - r) * inow % MOD;
                }
                inow *= sum_ie[ __builtin_ctz(~(unsigned int)(s))];
                inow %= MOD;
            }
        }
    }
 
    template<typename T>
    vector<T> convolution(vector<T> a, vector<T> b){
        int n = a.size();
        int m = b.size();
        if(min(n, m) <= 60){
            if(n < m){
                swap(n, m);
                swap(a, b);
            }
            vector<T> ans(n + m - 1);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    ans[i + j] += a[i] * b[j];
                    ans[i + j] %= MOD;
                }
            }
            for(int i = 0; i < n + m - 1; i++){
                if(ans[i] < 0) ans [i] += MOD;
            }
            return ans;
        }
 
        int z = 1;
        while(z < n + m - 1) z *= 2;
        a.resize(z);
        butterfly(a);
        b.resize(z);
        butterfly(b);
        for(int i = 0; i < z; i++){
            a[i] *= b[i];
            a[i] %= MOD;
        }
        butterfly_inv(a);
        a.resize(n + m - 1);
        T iz = modpow<T>(z, MOD - 2, MOD);
        for(int i = 0; i < n + m - 1; i++){
            a[i] *= iz;
            a[i] = (a[i] % MOD + MOD) % MOD;
        }
        return a;
    }
};
#line 188 "A.cpp"

void solve(){
    INT(n, k);
    vec(ll, A, 1001, 0);
    fori(n){
        INT(a);
        A[a] = 1;
    }
    while(A.back() == 0) A.pop_back();
    vec(ll, dp, 1, 1);
    while(k > 0){
        if(k & 1){
            dp = FFT::convolution(dp, A);
            fori(i, len(dp)){
                if(dp[i] > 1) dp[i] = 1;
            }
        }
        A = FFT::convolution(A, A);
        k >>= 1;
    }
    vec(int, ans, 0);
    fori(i, len(dp)){
        if(dp[i]) ans.push_back(i);
    }
    assert(len(ans) > 0);
    print(ans);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    // cout << fixed << setprecision(12);
    int t;
    t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}
