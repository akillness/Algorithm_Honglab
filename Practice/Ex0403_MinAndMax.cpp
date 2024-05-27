#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = { 8, 2, 3, 5, 9, 1, 9, 4, 3, 7, 6, 7 };
    
    // TODO:
    for(int i=0 ; i < arr.size() ; i+=2){
        if(arr[1]<arr[0])
            swap(arr[0], arr[1]);
        
        if(arr[i+1]<arr[i])
            swap(arr[i],arr[i+1]);
        
        arr[0]= std::min(arr[i],arr[0]);
        arr[1] = std::max(arr[i+1],arr[1]);
        
    }

    cout << "Min value = " << arr[0] << ", Max value = " << arr[1] << endl; // Min value = 1, Max value = 9
}
