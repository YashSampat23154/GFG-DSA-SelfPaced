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
    To check if a no is palindrome
    
    Palindrome Number : Basically a number whose reverse gives the same number.
*/

// Time Complexity : O(d) where d is the number of digits in our number.
void PalindromeNumber(int n){
    int temp = n;
    int rev = 0;
    while(temp!=0){
        rev = rev*10+temp%10;
        temp/=10;
    }
    if(rev == n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main(){

    fastio;

    PalindromeNumber(78987);
    PalindromeNumber(8668);
    PalindromeNumber(8);
    PalindromeNumber(21);
    PalindromeNumber(367);

    return 0;
}
