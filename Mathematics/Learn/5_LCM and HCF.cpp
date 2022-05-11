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
    Factors : All the numbers that divide a number completely i.e., without leaving any remainder, are called factors of that number.

    Eg : Factors(24) = 1,2,3,4,6,8,12,24

    LCM : The least common multiple, or LCM, of two or more numbers is the smallest number other than zero that's a multiple of each number.

    Eg : LCM(4,6) = 12

    HCF or GCD : HCF/GCD of two or more given numbers is the highest number which exactly divides all the numbers.

    Eg : HCF(12,16) = 4

    If two no do not have any common divisors except 1, then these two numbers need not to be prime. 
    Eg : GCD(9,10) = 1 but neither 9 nor 10 is prime.
*/

/*
    One application of gcd of two numbers is the styling problem.
    
    Styling Problem : 
    Suppose you have two numbers A & B and you make a rectangle using these two numbers i.e. of size AxB. What will be the sides of the largest square using which we can tile the whole rectangle such that there is no wastage. And how many such tiles will you require.

    Side of largest tile : GCD(A,B)
    No of tiles required : LCM(A,B)
*/

// Time Complexity : O(min(a,b))
int gcd_naive(ll a, ll b){
    int res = min(a, b);
    while(res>0){
        if(a%res == 0 && b%res == 0) break;
        res--;
    }
    return res;
}

/*
This algorithm is called as Euclidean Algorithm. 

Basic Idea : 
Let 'b' be smaller than 'a', then 
gcd(a, b) = gcd(a-b, b);

Why is this true?
Let 'g' be GCD of 'a' and 'b'
a = gx & b = gy and GCD (x,y) = 1   
(a-b) = g(x-y)


Time Complexity : O(log(max(a,b)))
*/
ll gcd_euclideanalgo(ll a, ll b){
    while(a!=b){
        if(a>b)
            a = a-b; 
        else
            b = b-a;
    }
    return a; 
}

// Time Complexity : O(log(min(a, b))
ll gcd_optimised_euclideanalgo(ll a, ll b){
    if(b == 0)  return a;
    else return gcd_optimised_euclideanalgo(b, a%b);
}

/*
    The Extended euclidian algorithm can be used to write the gcd as a linear combination of the original two numbers.
    That is, 
    Extended Euclidean algorithm finds integer coefficients x and y such that:  
    ax + by = gcd(a, b) 

    https://www.youtube.com/watch?v=hB34-GSDT3k

    Extended euclidian algorithm is used to find Multiplicative inverser mod n
    https://www.youtube.com/watch?v=_bRVA5b4sb4


    How does Extended Algorithm Work? 

    As seen above, x and y are results for inputs a and b,
    a.x + b.y = gcd                      ----(1)  

    And x1 and y1 are results for inputs b and a%b
    b.x1 + (a%b).y1 = gcd   
                        
    When we put a%b = (a - (⌊a/b⌋).b) in above, we get following. 
    Note that ⌊b/a⌋ is floor(b/a)

    b.x1 + (a - (⌊a/b⌋).b).y1  = gcd

    Above equation can also be written as below
    a.y1 + b.(x1 - (⌊a/b⌋).y1) = gcd      ---(2)

    After comparing coefficients of 'a' and 'b' in (1) and 
    (2), we get following
    x = y1
    y = x1 - ⌊a/b⌋ * y1
*/
ll gcd_extended_euclideanalgo(ll a, ll b, ll *x, ll *y){
    if(b == 0){
        *x = 1;
        *y = 0;
        return a; 
    }
    else{
        ll x1, y1; 
        ll gcd = gcd_extended_euclideanalgo(b, a%b, &x1, &y1);

        *x = y1;
        *y = x1 - (a/b)*y1;

        return gcd;
    }
}


// More on Euclidean algorithms : https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/

// Time Complexity : O(a*b - max(a,b))
ll lcm_naive(ll a, ll b){
    ll res = max(a, b);
    while(1){
        if(res%a == 0 && res%b == 0) return res;
        res++;
    }
}

// Concept : a*b = lcm(a,b) * gcd(a,b)
// Time Complexity : O(log(min(a, b))
ll lcm_efficient(ll a, ll b){
    return a/__gcd(a,b)*b;
}

int main(){

    fastio;

    cout<<gcd_naive(4, 6)<<endl;
    cout<<gcd_optimised_euclideanalgo(100, 200)<<endl;
    
    ll x, y; 
    cout<<gcd_extended_euclideanalgo(7, 13, &x, &y)<<endl;
    cout<<"x : "<<x<<" y : "<<y<<endl;

    cout<<lcm_naive(4, 5)<<endl;
    cout<<lcm_efficient(4, 5)<<endl;

    return 0;
}