/*
    Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ], the task is to list all words which are possible by pressing these numbers.

    Diagram at : https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/0/?track=DSASP-Recursion&batchId=154

    Example 1:

    Input: N = 3, a[] = {2, 3, 4}
    Output:
    adg adh adi aeg aeh aei afg afh afi 
    bdg bdh bdi beg beh bei bfg bfh bfi 
    cdg cdh cdi ceg ceh cei cfg cfh cfi 
    Explanation: When we press 2,3,4 then 
    adg, adh, adi, ... cfi are the list of 
    possible words.
    Example 2:

    Input: N = 3, a[] = {3, 4, 5}
    Output:
    dgj dgk dgl dhj dhk dhl dij dik dil 
    egj egk egl ehj ehk ehl eij eik eil 
    fgj fgk fgl fhj fhk fhl fij fik fil
    Explanation: When we press 3,4,5 then 
    dgj, dgk, dgl, ... fil are the list of 
    possible words.
    Your Task:
    You don't need to read input or print anything. You just need to complete the function possibleWords() that takes an array a[ ] and N as input parameters and returns an array of all the possible words in lexicographical increasing order. 

    Expected Time Complexity: O(4N * N).
    Expected Auxiliary Space: O(N).

    Constraints:
    1 ≤ N ≤ 10
    2 ≤ a[i] ≤ 9
*/

// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    
    vector<string> alphabets(int n){
        vector<string> v;
        if(n == 2){
            v.push_back("a");
            v.push_back("b");
            v.push_back("c");
        }
        else if(n == 3){
            v.push_back("d");
            v.push_back("e");
            v.push_back("f");
        }
        else if(n == 4){
            v.push_back("g");
            v.push_back("h");
            v.push_back("i");
        }
        else if(n == 5){
            v.push_back("j");
            v.push_back("k");
            v.push_back("l");
        }
        else if(n == 6){
            v.push_back("m");
            v.push_back("n");
            v.push_back("o");
        }
        else if(n == 7){
            v.push_back("p");
            v.push_back("q");
            v.push_back("r");
            v.push_back("s");
        }
        else if(n == 8){
            v.push_back("t");
            v.push_back("u");
            v.push_back("v");
        }
        else if(n == 9){
            v.push_back("w");
            v.push_back("x");
            v.push_back("y");
            v.push_back("z");
        }
        
        return v;
    }
    
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N, int i = 0)
    {
        if(N == 1){
            vector<string> v = alphabets(a[i]);
            return v;
        }
        
        vector<string> s;
        
        for(auto s1 : alphabets(a[i])){
            for(auto s2 : possibleWords(a, N-1, i+1)){
                s.push_back(s1+s2);
            }    
        }

        return s;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends