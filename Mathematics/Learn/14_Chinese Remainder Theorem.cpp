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
    We are given two arrays num[0..k-1] and rem[0..k-1]. In num[0..k-1], every pair is coprime (gcd for every pair is 1). We need to find minimum positive number x such that: 

        x % num[0]    =  rem[0], 
        x % num[1]    =  rem[1], 
        .......................
        x % num[k-1]  =  rem[k-1] 

    Basically, we are given k numbers which are pairwise coprime, and given remainders of these numbers when an unknown number x is divided by them. We need to find the minimum possible value of x that produces given remainders.

    Examples : 
    

    Input:  num[] = {5, 7}, rem[] = {1, 3}
    Output: 31
    Explanation: 
    31 is the smallest number such that:
    (1) When we divide it by 5, we get remainder 1. 
    (2) When we divide it by 7, we get remainder 3.

    Input:  num[] = {3, 4, 5}, rem[] = {2, 3, 1}
    Output: 11
    Explanation: 
    11 is the smallest number such that:
    (1) When we divide it by 3, we get remainder 2. 
    (2) When we divide it by 4, we get remainder 3.
    (3) When we divide it by 5, we get remainder 1.

    Chinese Remainder Theorem states that there always exists an x that satisfies given congruences.

    Chinese Remainder Theorem Statement: 
    Let num[0], num[1], …num[k-1] be positive integers that are pairwise coprime. Then, for any given sequence of integers rem[0], rem[1], … rem[k-1], there exists an integer x solving the following system of simultaneous congruences.
    Futhermore, all solutions x of this system are congruent modulo the product, prod = num[0] * num[1] * ...* num[n-1]. Hence,

    x = y (mod num[i]), 0<=i<=k-1 == x = y (mod prod)


    The first part is clear that there exists an x. 
    The second part basically states that all solutions (including the minimum one) produce the same remainder when divided by-product of n[0], num[1], .. num[k-1]. 

    In the above example, the product is 3*4*5 = 60. And 11 is one solution, other solutions are 71, 131, .. etc. All these solutions produce the same remainder when divided by 60, i.e., they are of form 11 + m*60 where m >= 0.
*/

/*
    A Naive Approach to find x is to start with 1 and one by one increment it and check if dividing it with given elements in num[] produces corresponding remainders in rem[]. Once we find such an x, we return it.

    Time Complexity : O(M), M is the product of all elements of num[] array. 
    Space Complexity : O(1)
*/
ll chinese_remainder_theorem_naive(ll num[], ll rem[], ll n){
    ll check = 1;
    while(true){
        int i = 0;
        for(; i<n; i++){
            if(check%num[i] != rem[i])  break;
        }
        if(i == n)  return check;
        check++;
    }
    return check;
}

/*
    The efficient solution is based on the formula : 
    x =  ( ∑ (rem[i]*pp[i]*inv[i]) ) % prod; Where 0 <= i <= n-1

    rem[i] is given array of remainders

    prod is product of all given numbers
    prod = num[0] * num[1] * ... * num[k-1]

    pp[i] is product of all divided by num[i]
    pp[i] = prod / num[i]

    inv[i] = Modular Multiplicative Inverse of pp[i] with respect to num[i]

    Time Complexity : O(N*LogN)
    Auxiliary Space : O(1)
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

ll chinese_remainder_theorem_efficient(ll num[], ll rem[], ll k)
{
    ll prod = 1;
    for (int i = 0; i < k; i++){
        prod *= num[i];
    }
      
    ll result = 0, pp, x, y, gcd;
    for (int i = 0; i < k; i++) {
        pp = prod / num[i];
        gcd = EEA_M(pp, num[i], &x, &y, prod);
        result = (result + (rem[i]%prod * x%prod * pp%prod)%prod)%prod;
    }
 
    return result;
}



int main(){

    fastio;

    ll num[] = {11, 14, 65};   
    ll rem[] = {2, 3, 1};
    cout<<chinese_remainder_theorem_efficient(num, rem, 3)<<endl;
    

    return 0;
}