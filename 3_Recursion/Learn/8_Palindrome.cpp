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
    Check whether the given string is palindrome.
*/
bool palindrome1(string s, ll i){
    if(i>=s.length()/2) return 1;
    if(s[i] == s[s.length() - i -1]) return palindrome1(s, i+1);
    else return 0;
}

// OR

/*
    Time Complexity : O(n)
    T(n) = T(n-2) + O(n)

    Auxillary Space : O(n)
*/
bool palindrome2(string str, int start, int end){
    if(start>=end) return true; 
    return (str[start]==str[end]) && palindrome2(str, start+1, end-1); 
}

int main(){

    fastio;

    cout<<palindrome1("aba", 0)<<endl;
    cout<<palindrome1("ab", 0)<<endl;
    cout<<palindrome2("abba", 0, 3)<<endl;
    cout<<palindrome2("a", 0, 0)<<endl;
    cout<<palindrome2("ba", 0, 1)<<endl;

    return 0;
}