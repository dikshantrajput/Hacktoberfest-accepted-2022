#include <iostream>
#include <vector>

using namespace std;

// Prime Sieve
vector<int> sieve(int *pr,int n) {
    pr[0] = pr[1] = 1;
    vector<int> primes;
    for(int i=2; i<=n; i++) {
        if(pr[i] == 0) {
            primes.push_back(i);
            for(int j=i*i; j<=n; j+=i) {
                pr[j] = 1;
            }
        }
     }
     return primes;
}

vector<int> factorize(vector<int> &primes, int N) {
    vector<int> factors;
    factors.clear();

    for(int i=0; i*i<=N; i++) {
        if(N%primes[i] ==0) {
            factors.push_back(primes[i]);
            while(N%primes[i] == 0) {
                N /= primes[i];
            }
        }
    }
    if(N>1) {
        factors.push_back(N);
    }
    return factors;
}


int main() {

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    const int N = 1000000;
    int pr[N] = {0};

    vector<int> primes = sieve(pr, 10000);

    int t;
    cin>>t;

    while(t--) {

        int n;
        cin>>n;

        vector<int> factors = factorize(primes, n);

        for(auto f: factors) {
            cout<<f<<" ";
        }

        cout<<endl;
    }
    return 0;
}
