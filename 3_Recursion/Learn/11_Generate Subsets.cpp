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
    Top Down Approach : 
    We can generate subsets of a string using the following concept : 
    The last character may or may not be present in the subsets of the string of lenght n-1

    Example : Substring of "ABC" can be calculated as : 

    " " : " " and "C"
    "A" : "A" and "AC"
    "B" : "B" and "BC"
    "AB" : "AB" and "ABC"
*/

/*
    Top Down Approach : 


    Time Complexity : O(2^n)
    Space Complexity : O(2^n)
    Auxillary Space : O(2^n)
*/
vector<string> Generate_subset(string s, int end){
    if(end == -1){
        vector<string> str; 
        str.push_back(" ");
        return str;
    }
    vector<string> str;
    for(auto p : Generate_subset(s, end-1)){
        str.push_back(p);
        str.push_back(p + s[end]);
    }
    return str;
}

/*
    Bottom Up Approach:
    Here we start with an empty string. We again have two choices to keep the string as it is or add the next element. 

    Time Complexity : O(2^n)
    Space Complexity : O(1)
    Auxillary Space : O(2^n)
*/
void generate_subset(string s, string current = " ", int i = 0){
    if(i == s.length()){
        cout<<current<<" ";
        return ;
    }
    generate_subset(s, current, i+1);
    generate_subset(s, current+s[i], i+1);
}

int main(){

    fastio;

    string s = "ABC";
    vector<string> str = Generate_subset(s, 2);

    for(auto p : str){
        cout<<p<<" ";
    }
    cout<<endl;

    generate_subset("ABC");

    return 0;
}