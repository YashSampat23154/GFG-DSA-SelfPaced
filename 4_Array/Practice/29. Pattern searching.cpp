/*
    Given a string str and a pattern pat. You need to check whether the pattern is present or not in the given string. 

    Example 1:-

    Input:
    2
    abcdefh
    bcd
    axzy
    xy

    Output:
    Present
    Not present

    Input Format: The input line contains T, denoting the number of test cases. Each test case contains two lines. First line contains string str. Second line contains pattern text.

    Output format: For each test case in a new line you have to print the "Present" if found otherwise "Not present".

    Your task: You need to complete the function searchPattern() containing string and text as an argument. You don't have to worry about input. 

    Constraints:
    1 <= T <= 100
    1 <= |str| <= 100
    1 <= |text| <= 100
*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

/*
str: string in which pattern we have to find pattern.
text: pattern needs to searched.
*/

bool searchPattern(string str, string pat)
{
    for(int i = 0; i<=str.length()-pat.length(); i++){
        if(str.substr(i, pat.length()) == pat) return true;
    }
    return false; 
}



//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}


// } Driver Code Ends