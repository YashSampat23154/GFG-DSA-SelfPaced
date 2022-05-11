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
    Prime No : A number that is only divisible by 1 and itself.

    Every prime number can be representated in the form of 6n+1 or 6n-1 except 2 and 3, where n is a natural number.

    Two and Three are the only two consecutive natural numbers which are prime too.

    One is neither prime nor composite.
*/

// Time Complexity : O(n)
bool isPrime_naive(ll n){
    if(n == 1) return false;
    for(int i = 2; i<n; i++)
        if(n%i == 0) return false;
    return true;
}

/*
    If (x,y) is a pair, then 
    x*y = n

    And if x<=y, then
    x*x <= n
    x <= sqrt(n)

    Time Complexity : O(sqrt(n))
*/
bool isPrime_efficient_1(ll n){
    if(n == 1) return false;
    for(int i = 2; i*i<n; i++)
        if(n%i == 0) return false;
    return true;
}

/*
    Idea is to check for divisibility by 2 and 3 to futher reduce the computation.
    We also use the fact that all prime no can be written as 6n-1 or 6n+1

    Time Complexity : O(sqrt(n)/3)
    This method is almost 3 times faster than 1st efficient soln. 
    Here although we increment by 6 we are performing 2 checks so 3 times faster.
*/
bool isPrime_efficient_2(ll n){
    if(n == 2 || n == 3) return true;
    if(n == 1 || n%2 == 0 || n%3 == 0) return false;    
    for(int i = 5; i*i<=n; i+=6)
        if(n%i == 0 || n%(i+2) == 0) return false;
    return true;
}



// Time Complexity : O((n^1.5)logn)
void primefactors_naive(ll n){
    for(int i = 2; i<n; i++){ // O(n)
        if(isPrime_efficient_2(i)){ // O(sqrt(n))
            int x = i;
            while(n%x == 0){ // O(log n)
                cout<<i<<" ";
                x = x*i;
            } 
        }
    }
    cout<<endl;
}


/*
    Efficient Solution : 
    1) Divisors always appera in pairs
    Eg : 30 = (1,30), (2,15), (3,10), (5,6)

    2) A number n can be written as mulitplications of powers of prime factors
    Eg : 12 = 2^2 * 3^1
    450 = 2^1 * 3^2 * 5^2
    13 = 13^1 
*/
void primefactors_efficient_1(ll n){
    if(n<=1) return;

    for(int i = 2; i*i<=n; i++){
        while(n%i == 0){
            cout<<i<<" ";
            n/=i;
        }
    }
    if(n>1) cout<<n;

    cout<<endl;
    return;
}

// Similar logic to finding whether no is prime or not
// Time Complexity : O(sqrt(n)/6)
void primefactors_efficient_2(ll n){
    if(n <= 1) return;

    while(n%2 == 0){
        cout<<"2 ";
        n/=2;
    }
    while(n%3 == 0){
        cout<<"3 ";
        n/=3;
    } 

    for(int i=5; i*i<=n; i+=6){
        while(n%i == 0){
            cout<<i<<" ";
            n/=i;
        
        }
        while(n%(i+2) == 0){
            cout<<i+2<<" ";
            n/=(i+2);
        }
         
    }
    if(n>3) cout<<n<<" ";

    cout<<endl;
    return;
}


int main(){

    fastio;

    cout<<isPrime_naive(7)<<endl;
    cout<<isPrime_efficient_1(7)<<endl;
    cout<<isPrime_efficient_2(7)<<endl;

    primefactors_naive(12);
    primefactors_efficient_1(13);
    primefactors_efficient_2(315);

    return 0;
}