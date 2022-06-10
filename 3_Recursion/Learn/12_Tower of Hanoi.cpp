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
    Tower of Hanoi is a mathematical puzzle where we have three rods and n disks. The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules: 

    1) Only one disk can be moved at a time.
    
    2) Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
    
    3) No disk may be placed on top of a smaller disk.


    Approach : 

    Let rod 1 = 'A', rod 2 = 'B', rod 3 = 'C'.
    An example with 2 disks :
    Step 1 : Shift first disk from 'A' to 'B'.

    Step 2 : Shift second disk from 'A' to 'C'.

    Step 3 : Shift first disk from 'B' to 'C'.


    An example with 3 disks :
    Step 1 : Shift first disk from 'A' to 'C'.
    Step 2 : Shift second disk from 'A' to 'B'.
    Step 3 : Shift first disk from 'C' to 'B'.

    Step 4 : Shift third disk from 'A' to 'C'.

    Step 5 : Shift first disk from 'B' to 'A'.
    Step 6 : Shift second disk from 'B' to 'C'.
    Step 7 : Shift first disk from 'A' to 'C'.
    (Notice the gaps)


    The pattern here is :
    - Shift 'n-1' disks from 'A' to 'B', using C.
    - Shift last disk from 'A' to 'C'.
    - Shift 'n-1' disks from 'B' to 'C', using A.


    Recurrrence Relation : 
    T(n) = 2T(n-1) + 1
    
    Number of steps : 2^n - 1
*/
void Tower_of_Hanoi(char A, char B, char C, int i){
    if(i == 0)  return;
    Tower_of_Hanoi(A,C,B,i-1);
    cout<<"Move disk "<<i<<" from "<<A<<" to "<<C<<endl;
    Tower_of_Hanoi(B,A,C,i-1);
    return;
}

int main(){

    fastio;

    Tower_of_Hanoi('A', 'B', 'C', 3);

    return 0;
}