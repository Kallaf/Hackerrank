#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int SIZE = 100005;

int mul(ll x, ll y) {
  return x * y % mod;
}

ll _sieve_size;
bitset<SIZE> bs;
vector<int> primes;
vector<pair<int,int>> ps[SIZE];
void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < SIZE; i++)
        if (bs[i]) {
            for (ll j = i; j < SIZE; j += i)
            {
                if(j!=i)bs[j] = 0;

                int x = j;
                int a = 0;
                while (x % i == 0) {
                    x /= i;
                    ++a;
                }

                ps[j].emplace_back(i, a);
            }
            primes.push_back((int)i);
        }
}

int tc=1,n,arr[SIZE];

void preprocess(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //scanf("%d",&tc);
    sieve();
    fill(arr,arr+SIZE,-1);
}

void input()
{
    scanf("%d",&n);
}

void solve()
{
    bool good = true;
    for(int i=1;i<=n;i++)
    {
        int in;
        scanf("%d",&in);
        if(in == -1)continue;
        for (auto d : ps[i]) {
            int p = d.first;
            int pw = d.second;
            int cur = p;

            for (int j = 1; j <= pw; ++j) {
                int rem = in % cur;
                if (arr[cur] == -1)
                    arr[cur] = rem;

                if (arr[cur] != rem)
                    good = false;

                cur *= p;
            }
        }
    }

    if (!good) {
        printf("0\n");
        return;
    }

    int ans = 1;

    for (int p : primes) {
        int cur = 1, a = 0, b = 0;
        while (cur <= n / p) {
            cur *= p;
            a++;
            if (arr[cur] != -1)
                b = a;
        }

        for (int i = 0; i < a - b; ++i)
            ans = mul(ans, p);
    }
    printf("%d\n",ans);
}

int main()
{
    preprocess();
    while(tc--)
    {
        input();
        solve();
    }
    return 0;
}
