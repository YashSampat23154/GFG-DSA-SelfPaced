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
    Problems with Simple Array : Fixed Size

    Advantages of Vectors : 
    1) Dynamic Size.
    2) Rich library functions.  
    3) Easy to know size.
    4) No need to pass size.
    5) Can be returned from a function. 
    6) By default initialized by default values. 
    7) We can copy a vector to other. 

*/

int main(){

    fastio;

    /*
        Vectors are the same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container. Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

        Certain functions associated with the vector are:

        1) Iterators

        begin() – Returns an iterator pointing to the first element in the vector.
        end() – Returns an iterator pointing to the theoretical element that follows the last element in the vector.      
        rbegin() – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element.
        rend() – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end).
        
        
        vector<int> g1; 
        for (int i = 1; i <= 5; i++) 
            g1.push_back(i); 
    
        cout << "Output of begin and end: "; 
        for (auto i = g1.begin(); i != g1.end(); ++i) 
            cout << *i << " "; 
    
        cout << "\nOutput of rbegin and rend: "; 
        for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir) 
            cout << *ir << " "; 
    
        Output:

        Output of begin and end: 1 2 3 4 5 
        Output of rbegin and rend: 5 4 3 2 1 



        2) Capacity

        size() – Returns the number of elements in the vector.
        capacity() – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
        max_size() – Returns the maximum number of elements that the vector can hold.
        resize(n) – Resizes the container so that it contains ‘n’ elements.
        empty() – Returns whether the container is empty.


        vector<int> g1; 
        for (int i = 1; i <= 5; i++) 
            g1.push_back(i); 
  
        cout << "Size : " << g1.size(); 
        cout << "\nCapacity : " << g1.capacity(); 
        cout << "\nMax_Size : " << g1.max_size(); 
        
        g1.resize(4); 
        cout << "\nSize : " << g1.size(); 
    
        // checks if the vector is empty or not 
        if (g1.empty() == false) 
            cout << "\nVector is not empty"; 
        else
            cout << "\nVector is empty"; 
  
        Output:
        Size : 5
        Capacity : 8
        Max_Size : 4611686018427387903
        Size : 4
        Vector is not empty
        Vector elements are: 1 2 3 4



        3) Element access:

        reference operator [g] – Returns a reference to the element at position ‘g’ in the vector
        at(g) – Returns a reference to the element at position ‘g’ in the vector
        front() – Returns a reference to the first element in the vector
        back() – Returns a reference to the last element in the vector
        data() – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

    
        vector<int> g1; 
        for (int i = 1; i <= 10; i++) 
            g1.push_back(i * 10); 
  
        cout << "\nReference operator [g] : g1[2] = " << g1[2]; 
        cout << "\nat : g1.at(4) = " << g1.at(4); 
        cout << "\nfront() : g1.front() = " << g1.front(); 
        cout << "\nback() : g1.back() = " << g1.back(); 
    
        // pointer to the first element 
        int* pos = g1.data(); 
        cout << "\nThe first element is " << *pos; 
    

        Output:
        Reference operator [g] : g1[2] = 30
        at : g1.at(4) = 50
        front() : g1.front() = 10
        back() : g1.back() = 100
        The first element is 10


        4) Modifiers:

        assign() – It assigns new value to the vector elements by replacing old ones.
        push_back() – It push the elements into a vector from the back.
        pop_back() – It is used to pop or remove elements from a vector from the back.
        insert() – It inserts new elements before the element at the specified position.
        erase() – It is used to remove elements from a container from the specified position or range.
        swap() – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
        clear() – It is used to remove all the elements of the vector container.
        emplace() – It extends the container by inserting new element at position.
        emplace_back() – It is used to insert a new element into the vector container, the new element is added to the end of the vector.
        .


        // Assign vector 
        vector<int> v; 
    
        // fill the array with 10 five times 
        v.assign(5, 10); 
    
        cout << "The vector elements are: "; 
        for (int i = 0; i < v.size(); i++) 
            cout << v[i] << " "; 
    
        // inserts 15 to the last position 
        v.push_back(15); 
        int n = v.size(); 
        cout << "\nThe last element is: " << v[n - 1]; 
    
        // removes last element 
        v.pop_back(); 
    
        // prints the vector 
        cout << "\nThe vector elements are: "; 
        for (int i = 0; i < v.size(); i++) 
            cout << v[i] << " "; 
    
        // inserts 5 at the beginning 
        v.insert(v.begin(), 5); 
    
        cout << "\nThe first element is: " << v[0]; 
    
        // removes the first element 
        v.erase(v.begin()); 
    
        cout << "\nThe first element is: " << v[0]; 
    
        // inserts at the beginning 
        v.emplace(v.begin(), 5); 
        cout << "\nThe first element is: " << v[0]; 
    
        // Inserts 20 at the end 
        v.emplace_back(20); 
        n = v.size(); 
        cout << "\nThe last element is: " << v[n - 1]; 
    
        // erases the vector 
        v.clear(); 
        cout << "\nVector size after erase(): " << v.size(); 
    
        // two vector to perform swap 
        vector<int> v1, v2; 
        v1.push_back(1); 
        v1.push_back(2); 
        v2.push_back(3); 
        v2.push_back(4); 
    
        cout << "\n\nVector 1: "; 
        for (int i = 0; i < v1.size(); i++) 
            cout << v1[i] << " "; 
    
        cout << "\nVector 2: "; 
        for (int i = 0; i < v2.size(); i++) 
            cout << v2[i] << " "; 
    
        // Swaps v1 and v2 
        v1.swap(v2); 
    
        cout << "\nAfter Swap \nVector 1: "; 
        for (int i = 0; i < v1.size(); i++) 
            cout << v1[i] << " "; 
    
        cout << "\nVector 2: "; 
        for (int i = 0; i < v2.size(); i++) 
            cout << v2[i] << " "; 
  


        Output:
        The vector elements are: 10 10 10 10 10 
        The last element is: 15
        The vector elements are: 10 10 10 10 10 
        The first element is: 5
        The first element is: 10
        The first element is: 5
        The last element is: 20
        Vector size after erase(): 0

        Vector 1: 1 2 
        Vector 2: 3 4 
        After Swap 
        Vector 1: 3 4 
        Vector 2: 1 2

    */

    return 0;
}