#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define rep(i,a,b) for(int i=a; i<b; i++)

//struct Values{
//int x;
//};

using namespace std;

/*
    Given a value 'n' we want to find all prime numbers <= n
    This problem can be solved using Sieve of Eratosthenes
*/

bool isPrime(ll n){
    if(n == 2 || n == 3) return 1;
    if(n==1 || n%2==0 || n%3==0) return 0;
    for(int i = 5; i*i<=n; i+=6){
        if(n%i==0 || n%(i+2)==0) return 0;
    }
    return 1;
}

// Time Complexity : O(n^1.5)
// Space Complexity : O(n)
void printPrime_Naive(ll n){
    for(int i = 2; i<=n; i++){ // O(n)
        if(isPrime(i))  cout<<i<<" "; // O(sqrt(n))
    }
    cout<<endl;
    return;
}

// Time Complexity : O(nloglogn)
// Space Complexity : O(n)
void Sieve_of_Eratosthenes_naive(ll n){
    vector<bool> prime(n+1, true);
    
    for(int i=2; i*i<=n; i++){ 
        if(prime[i]){
            for(int j = 2*i; j<=n; j+=i) 
                prime[j] = false;
        }
    }

    for(int i = 2; i<=n; i++){
        if(prime[i])   cout<<i<<" ";
    }
    cout<<endl;

    return;
}

// Sieving till root :
// Time Complexity : O(nloglog(sqrt(n))) = O(nloglogn)
// Space Complexity : O(n)
void Sieve_of_Eratosthenes_efficient(ll n){
    vector<bool> prime(n+1, true);
    
    for(int i=2; i*i<=n; i++){ 
        if(prime[i]){
            for(int j = i*i; j<=n; j+=i) 
                prime[j] = false;
        }
    }

    for(int i = 2; i<=n; i++){
        if(prime[i])   cout<<i<<" ";
    }
    cout<<endl;

    return;
}

// Time Complexity : O(nloglogn)
// Space Complexity : O(n)
void Sieve_of_Eratosthenes_efficient_but_cleaner(ll n){
    vector<bool> prime(n+1, true);
    
    for(int i=2; i<=n; i++){ 
        if(prime[i]){
            cout<<i<<" ";
            for(int j = i*i; j<=n; j+=i) 
                prime[j] = false;
        }
    }

    cout<<endl;

    return;
}



/*
    More information about sieve : 
    https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

    https://www.researchgate.net/publication/331967146_COMPARISON_AMONG_DIFFERENT_PRIME_GENERATOR_ALGORITHMS


    The biggest weakness of the algorithm is, that it "walks" along the memory multiple times, only manipulating single elements. This is not very cache friendly. And because of that, the constant which is concealed in  is comparably big.
    Besides, the consumed memory is a bottleneck for big n.

    One way to solve this problem is to use Segmented Sieve.


    We can also have a linear time complexity sieve. This approach is described in the article :
    https://cp-algorithms.com/algebra/prime-sieve-linear.html
    However, this algorithm also has its own weaknesses.


    To find primes in a range : 
    https://www.geeksforgeeks.org/segmented-sieve-print-primes-in-a-range/
*/


int main(){

    fastio;

    Sieve_of_Eratosthenes_naive(10);
    Sieve_of_Eratosthenes_efficient(23);
    Sieve_of_Eratosthenes_efficient_but_cleaner(50);

    return 0;
}
