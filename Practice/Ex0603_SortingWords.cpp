#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <string>
using namespace std;

template<typename T>
void Print(vector<T>& arr)
{
    for (auto& a : arr)
        cout << a << " ";
    cout << endl;
}

void CountingSort(vector<string>& arr, int k, int d)
{
     vector<string> temp = arr; // 복사
//     std::fill(arr.begin(), arr.end(), "   "); // 디버깅 편의
    
    // TODO:
    vector<int> count(k+1,0);
    for (int i=0;i<arr.size();i++){
//        cout << temp[i][d]-'0' << endl;
        count[temp[i][d]-'A']++;
    }
//    Print(count);
    
    for (int i=1; i<count.size();i++)
        count[i] += count[i-1];
    
    Print(count);
    
    for (int i=arr.size()-1;i>=0;i--){
        count[temp[i][d]-'A']--;
        arr[count[temp[i][d]-'A']] = temp[i];
    }
//    Print(arr);
}

void RadixSort(vector<string>& arr)
{
    // TODO:
    int k = 'Z'-'A'+1;
    int max_size = 3;
        
    for(int d=max_size-1;d>=0;d--)
    {
        CountingSort(arr, k, d);
        Print(arr);
    }

}

int main()
{
    // CLRS 8.3-1
    vector<string> arr = { "COW", "DOG", "SEA", "RUG",
        "ROW", "MOB", "BOX", "TAB", "BAR", "EAR", "TAR",
        "DIG", "BIG", "TEA", "NOW", "FOX" };

    Print(arr);

    RadixSort(arr);

    Print(arr);

    return 0;
}
