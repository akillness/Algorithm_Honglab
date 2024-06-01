#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>
using namespace std;

void Print(vector<int>& arr)
{
    for (auto& a : arr)
        cout << a << " ";
    cout << endl;
}

// 편의상 결과가 arr에 저장되도록 바꿨습니다.
void CountingSort(vector<int>& arr, int k, int exp)
{
    vector<int> temp = arr; // 복사

    vector<int> count(k + 1, 0);
    // TODO:
    for (int i = 0; i<arr.size();i++){
        count[temp[i]/exp%10]++;
    }
//    Print(count);
    for (int i=1;i<count.size();i++)
        count[i] += count[i-1];
//    Print(count);
    
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        // TODO:
//        cout<< count[temp[i]] <<", " << i <<" // " << arr[count[temp[i]]] << "," << arr[i] <<endl;
        count[(temp[i]/exp)%10]--;
        arr[count[(temp[i]/exp)%10]] = temp[i];
        
        
    }
//    Print(arr);
}

void RadixSort(vector<int>& arr)
{
    int k = 10; // 여기서는 10으로 고정
    int m = *max_element(arr.begin(), arr.end());
    
//    CountingSort(arr, k, 1);
    for (int exp = 1 ;m >= exp; exp *=10 )
    {
        cout << "exp = " << exp << endl;
    //    TODO:
        CountingSort(arr, k, exp);
        Print(arr);
    }
}

int main()
{
    vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
//    vector<int> arr = {329,457,657,839,436,720,355};
//    vector<int> arr = { 2, 5, 3, 0, 2, 3, 0, 3 };

    Print(arr);

    RadixSort(arr);

    return 0;
}
