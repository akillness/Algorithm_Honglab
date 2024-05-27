#include <iostream>
#include <vector>
#include <random>
#include <numeric>
#include <iostream>

using namespace std;

void Print(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// 가장 작은 값이 arr[lo]에 오도록
void SelectionSortPass(vector<int>& arr, int lo, int hi)
{
    // TODO:
    int min = 99999;
    int search_idx = -1;
    for (int i = lo ; i< hi-1; i++)
    {
        if(arr[i] < min){
            min = arr[i];
            search_idx = i;
        }
    }
    
    swap(arr[lo], arr[search_idx]);
    
}

void PartialSelectionSort(vector<int>& arr, int k)
{
    Print(arr);

    for (int i = 0; i < k; i++)
    {
        SelectionSortPass( arr, i, arr.size());

        Print(arr);
    }
}

int main()
{
    vector<int> my_vector = { 7, 10, 4, 3, 20, 15 };

    int k = 3;

    PartialSelectionSort(my_vector, k);

    cout << my_vector[k - 1] << endl;
}
