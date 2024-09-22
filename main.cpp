#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

long long mod_inverse(long long x, long long mod) {
    return mod_pow(x, mod - 2, mod);
}

long long binomial_coefficient(int n, int k, const vector<long long>& fact, const vector<long long>& inv_fact) {
    if (k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<long long> fact(n + 1), inv_fact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    inv_fact[n] = mod_inverse(fact[n], MOD);
    for (int i = n - 1; i >= 0; --i) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
    }

    cout << binomial_coefficient(n, k, fact, inv_fact) << endl;

    return 0;
}
