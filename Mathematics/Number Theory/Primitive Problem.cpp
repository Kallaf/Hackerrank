// C++ program to find primitive root of a 
// given number n 
#include<bits/stdc++.h>
#define ll long long int
using namespace std; 


/* Iterative Function to calculate (x^n)%p in 
O(logy) */
ll power(ll x, unsigned ll y, ll p) 
{ 
    ll res = 1;     // Initialize result 

    x = x % p; // Update x if it is more than or 
    // equal to p 

    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 

        // y must be even now 
        y = y >> 1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 

// Utility function to store prime factors of a number 
void findPrimefactors(unordered_set<ll> &s, ll n) 
{ 
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
        s.insert(2); 
        n = n/2; 
    } 

    // n must be odd at this point. So we can skip 
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            s.insert(i); 
            n = n/i; 
        } 
    } 

    // This condition is to handle the case when 
    // n is a prime number greater than 2 
    if (n > 2) 
        s.insert(n); 
} 

// Function to find smallest primitive root of n 
ll findPrimitive(ll n) 
{ 
    unordered_set<ll> s; 

    // Find value of Euler Totient function of n 
    // Since n is a prime number, the value of Euler 
    // Totient function is n-1 as there are n-1 
    // relatively prime numbers. 
    ll phi = n-1; 

    // Find prime factors of phi and store in a set 
    findPrimefactors(s, phi); 

    // Check for every number from 2 to phi 
    for (ll r=2; r<=phi; r++) 
    { 
        // Iterate through all prime factors of phi. 
        // and check if we found a power with value 1 
        bool flag = false; 
        for (auto it = s.begin(); it != s.end(); it++) 
        { 

            // Check if r^((phi)/primefactors) mod n 
            // is 1 or not 
            if (power(r, phi/(*it), n) == 1) 
            { 
                flag = true; 
                break; 
            } 
        } 

        // If there was no power with value 1. 
        if (flag == false) 
        return r; 
    } 

    // If no primitive root found 
    return -1; 
} 

  
// A simple method to evaluate Euler Totient Function 
ll phi(ll n) 
{ 
    ll result = n; // Initialize result as n 
  
    // Consider all prime factors of n and subtract their 
    // multiples from result 
    for (ll p = 2; p * p <= n; ++p) { 
          
        // Check if p is a prime factor. 
        if (n % p == 0) { 
              
            // If yes, then update n and result 
            while (n % p == 0) 
                n /= p; 
            result -= result / p; 
        } 
    } 
  
    // If n has a prime factor greater than sqrt(n) 
    // (There can be at-most one such prime factor) 
    if (n > 1) 
        result -= result / n; 
    return result; 
} 

// Driver code 
int main() 
{ 
    int n;
    cin >> n;
    cout << findPrimitive(n) <<  " " << phi(n-1) << endl; 
    return 0; 
} 
