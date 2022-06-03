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
    Given a string we want to generate all the subsets of that given string. 

    Eg : 
    I/P : S = "abc"
    O/P : "", "a", "b", "c", "ab", "ac", "bc", "abc"   

    I/P : S = "ab"
    O/P : "", "a", "b", "ab"
*/

/*
    We can use the length of the string to count the number of bits required and assign each character of the string a single bit.
    Now we iterate from 0 to 2^(length of string)-1 and add the corresponding characters into our final list.

    Time Complexity : O(2^n * n) where n = length of string
 */

vector<string> powerset(string S){
    int n = pow(2, S.length())-1;
    
    vector<string> s; 
    s.push_back(" ");
    
    for(int i = 1; i<=n; i++){
        int res = i, index = 0; 
        string temp = " ";
        while(res!=0){
            if(res&1) temp+=S[index];
            index++;
            res = res>>1;
        }
        s.push_back(temp);
    } 

    return s; 
}

int main(){

    fastio;

    vector<string> s = powerset("abc");

    for(int i=0; i<s.size(); i++)   cout<<s[i];
    cout<<endl;

    return 0;
}
