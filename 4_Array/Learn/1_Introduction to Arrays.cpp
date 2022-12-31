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
    An array is a collection of items of the same data type stored at contiguous memory locations. This makes it easier to calculate the position of each element by simply adding an offset to a base value, i.e., the memory location of the first element of the array (generally denoted by the name of the array).

    For simplicity, we can think of an array as a fleet of stairs where on each step a value is placed (let’s say one of your friends). Here, you can identify the location of any of your friends by simply knowing the count of the step that they are on.

    Remember: “Location of the next index depends on the data type that we use”.




    Defining an Array: Array definition is similar to defining any other variable. There are two things that are needed to be kept in mind, the data type of the array elements and the size of the array. The size of the array is fixed and the memory for an array needs to be allocated before use, the size of an array cannot be increased or decreased dynamically.

    Generally, arrays are declared as:
    dataType arrayName[arraySize];

    An array is distinguished from a normal variable by brackets [ and ].

    Accessing array elements: Arrays allows to access elements randomly. Elements in an array can be accessed using indexes. Suppose an array named arr stores N elements. 
    
    Indexes in an array are in the range of 0 to N-1, where the first element is present at 0-th index and consecutive elements are placed at consecutive indexes. Element present at ith index in the array arr[] can be accessed as arr[i].




    Advantages of using arrays:
    1) Arrays allow random access of elements. This makes accessing elements by their position faster.
    2) Arrays have better cache locality that can make a pretty big difference in performance.

    Cache Locality : https://en.wikipedia.org/wiki/Locality_of_reference




    

*/

int main(){

    fastio;

    /*
        We can have fixed sized arrays or dynamic sized arrays.

        Fixed Sized Arrays cannot resize themself.
        Dynamic Sized Arrays resize themself automatically.
    */

    // Fixed Sized Array : C/C++
    int arr1[100]; 

    int n = 100;
    int arr2[n];

    int *arr3 = new int[n]; // In C we would use malloc

    int arr[] = {10, 15, 30, 40};

    /*
        In C and C++, the fixed size arrays are allocated memory in two ways. 
        One is area in the stack segment (where local vairables are stored) and the other is area in the heap segment (where we store dynamically allocated memory).
    */

    int arr1[100]; 

    int n = 100;
    int arr2[n];

    int arr[] = {10, 15, 30, 40};

    // Above 3 are stack allocated

    int *arr3 = new int[n]; // Heap allocated

    // Dynamic Sized Arrays 
    /*
        C++ : Vector
        Java : ArrayList
        Python : List
    */

    return 0;
}
