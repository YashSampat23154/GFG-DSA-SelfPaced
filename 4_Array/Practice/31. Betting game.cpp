/*
    You are involved in a betting game whose rules are as follows :
    a) If you win a round, the bet amount will be added to your current sum and next bet amount will become $1;
    b) If you lose a round, the bet amount will be reduced from your current sum and next bet will become twice the previous.
    c) game ends either when all the rounds are complete or when you don't have sufficient sum.

    Initially, you are given with a string result consisiting of characters from the set {'W', 'L'}, where 'W' indicates a win and 'L' indicates a loss, and initial sum is 4. Initial bet amount for the 1st round will be $1.

    You need to find and print the amount at the end of the game (final sum) and in case you do not have enough money in between the game to play the next round, then return -1.

    Example 1:

    Input: 
    result = WL 

    Output: 4 

    Explaination: At first you win the game so currently have 4+1 = $5 and the bet is $1. Now you loss this bet and the final balance is $4.
    
    Example 2:
    
    Input: 
    result = WLWLLLWWLW 
    
    Output: -1
    
    Explaination: When you reach the starting of the three consecutive losing streak you have balance $6 and bet is $1. After first loss in this streak you have balance $5 and bet $2. After second loss in this streak you have balance $3 and bet is $4. Now see that your balance is lesser than the next bet. So you cannot continue playing. So the answer is -1.

    Your Task: 
    You don't need to read input or print anything. Your task is to complete the function betBalance() which takes the string result as input parameter and returns the balance after the sequence of win or lose. If you cannot carry betting in between then return -1 

    Expected Time Complexity: O(|result|)
    Expected Auxiliary Space: O(1)

    Constraints:

    1 ≤ |result| ≤ 10000
*/

//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
        int betBalance(string result)
        {
            int currBet = 1; 
            int currAmt = 4; 
            
            for(int i=0; i<result.length(); i++){
                if(currAmt < currBet) return -1; 
                
                if(result[i] == 'W'){
                    currAmt += currBet; 
                    currBet = 1; 
                }
                else{
                    currAmt -= currBet; 
                    currBet *= 2; 
                }
            }
            
            return currAmt; 
        }
    
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string result;
        cin>>result;
        
        Solution ob;
        cout<<ob.betBalance(result)<<endl;
    }
    return 0;
}
// } Driver Code Ends