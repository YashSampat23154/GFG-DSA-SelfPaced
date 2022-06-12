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
    Given a string we want to print all the permutations of that string.
    A string of length N contains N! permutations 

    Eg : 
    I/P : "ABC"
    O/P : "ABC", "ACB", "BAC", "BCA", "CAB", "CBA"

    I/P : "AB"
    O/P : "AB", "BA"
    
    I/P : ""
    O/P : 

*/

/*
    Approach : 
    Idea: We iterate from first to last index. For every index i, we swap the i-th character with the first index. This is how we fix characters at the current first index, then we recursively generate all permutations beginning with fixed characters (by parent recursive calls). After we have recursively generated all permutations with the first character fixed, then we move the first character back to its original position so that we can get the original string back and fix the next character at first position.

    Read the theory section of recusive track to get a better idea.

    Time Complexity : O(n!)

    ProTip : 
    How do we get permutations in lexicographically sorted order? 
    
    We can put all permutations in an array instead of printing them immediately. Then we can sort the array and print the array.
*/
void permute(string s, int i = 0){
    if(i == s.length()-1){
        cout<<s<<" ";
        return;
    }

    for(int j = i ; j<s.length(); j++){
        swap(s[i], s[j]);
        permute(s, i+1);
        swap(s[i], s[j]);
    }
}

int main(){

    fastio;

    permute("ABCD");

    return 0;
}