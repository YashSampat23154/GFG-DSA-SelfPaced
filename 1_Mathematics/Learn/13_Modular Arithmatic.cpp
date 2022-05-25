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
    The remainder obtained after the division operation on two operands is known as modulo operation.

    Operator for doing modulus operation is '%'.

    The reason of taking mod is to prevent integer overflows. 
    The largest datatype in C or C++ is unsigned long long int which is of 64 bit and can handle integers from 0 to 2^64-1. 
    But in some problems where the growth of the output is very high, this range of unsigned long long may be insufficient. That is where we use modular arithmetic. 
*/

/*
    Modular Arithmetics : 

    Let us take a look at some of the basic rules and properties that can be applied in Modular Arithmetic (Addition, Subtraction, Multiplication etc.). Consider numbers a and b operated under modulo M.

    (a + b) mod M = ((a mod M) + (b mod M)) mod M.

    (a - b) mod M = ((a mod M) - (b mod M)) mod M = ((a mod M) - (b mod M) + M) mod M. 
    Adding + M makes sure that the result after mod operation is never negative
    
    (a * b) mod M = ((a mod M) * (b mod M)) mod M.

    The above three expressions are valid and can be performed as stated. But when it comes to modular division, there are some limitations.

    There isn't any formula to calculate:
    (a / b) mod M

    For this we have to learn modular inverse.
*/

/*
    Modular Inverse :

    The modular inverse is an integer 'x' such that.
    a x ≡ 1 (mod M) 

    The value of x should be in {0, 1, 2, ... M-1}, i.e., in the ring of integer modulo M.

    The multiplicative inverse of "a modulo M" exists if and only if a and M are relatively prime (i.e., if gcd(a, M) = 1).

    Examples:
    Input:  a = 3, M = 11
    Output: 4
    Since (4*3) mod 11 = 1, 4 is modulo inverse of 3
    One might think, 15 also as a valid output as "(15*3) mod 11" 
    is also 1, but 15 is not in ring {0, 1, 2, ... 10}, so not 
    valid.

    Input:  a = 10, M = 17
    Output: 12
    Since (10*12) mod 17 = 1, 12 is modulo inverse of 3

    Methods of finding Modular Inverse: There are two very popular methods of finding modular inverse of any number a under modulo M.
    Extended Euclidean Algorithm: This method can be used when a and M are co-prime.
    Fermat Little Theorem: This method can be used when M is prime.


    Let us look at each of the above two methods in details:

    Extended Euclidean algorithm that takes two integers 'a' and 'b', finds their gcd and also find 'x' and 'y' such that,
    ax + by = gcd(a, b)

    To find the modulo inverse of 'a' under 'M', we put b = M in the above formula. Since we know that a and M are relatively prime, we can put value of gcd as 1.

    So, the formula becomes:
    ax + My = 1 

    If we take modulo M on both sides, we get:
    ax + My ≡ 1 (mod M)

    We can remove the second term on the left side, as 'My (mod M)' would always be 0 for an integer y.

    Therefore,
    ax  ≡ 1 (mod M) 

    So the 'x' that we can find using Extended Euclid Algorithm is modulo inverse of 'a'.



    Fermat Little Theorem: The Fermat’s little theorem states that if M is a prime number, then for any integer a, the number a^M – a is an integer multiple of M.

    a^M – a = kM

    So, 
    a^M - kM = a

    That is,
    a^M ≡ a (mod M).


    Since, a and M are co-prime to each other then aM-1 is an integral multiple of M.
    That is,
    a^(M-1) ≡ 1 (mod M)
    If we multiply both sides by a-1, we get:
    a^(-1) ≡ a(M-2) mod M

    Therefore, if M is a prime number to find modulo inverse of a under M, find modular exponentiation of aM-2 under modulo M.

*/
ll EEA_M(ll a, ll b, ll *x, ll *y, ll M){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a; 
    }
    else{
        ll x1, y1; 
        ll gcd = EEA_M(b, a%b, &x1, &y1, M);

        *x = y1%M;
        *y = (x1%M - ((a/b)*y1)%M + M)%M;

        return gcd;
    }
}

// This fails to work for relatively large values of a or b
ll BE_M(ll a, ll b, ll M){
    ll ans = 1, temp = a;

    while(b!=0){
        if(b&1) ans=(ans*temp)%M;
        temp=(temp*temp)%M;
        b = b>>1;
    }

    return ans;
}


int main(){

    fastio;
    int a = 3, m = 11;

    ll x, y;
    ll gcd = EEA_M(a, m, &x, &y, m);
    if(gcd != 1 || m==1)    cout<<"Inverse does not exist";
    else    cout<<x<<endl;
    cout<<BE_M(a, m-2, m)<<endl;

    return 0;
}
