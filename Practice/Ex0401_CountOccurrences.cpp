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

int Count1(const vector<int>& arr, int x)
{
    //TODO: O(n)
    int result = 0;
    
    for (int a :arr){
        if ( a == x ) result++;
    }
    return result;
}

int Count2(const vector<int>& arr, int x)
{

    //TODO: O(log(n) + count)
    int result = 0;
    
    int left = 0;
    int right = arr.size()-1;
    int pivot = -1;
    while(left<=right){
        pivot = (left+right)/2;
        if(arr[pivot] == x){
            result++;
            break;
        }else if(arr[pivot] < x){
            left = pivot+1;
        }else{
            right = pivot-1;
        }
    }
    
    if (result < 1)
        return 0;
    
    bool isReverse = true;
    int idxDir = pivot-1;
    while(1){
        if (isReverse == true){
            if(arr[idxDir]==x){
                result++;
                idxDir--;
            }else {
                isReverse = false;
                idxDir = pivot+1;
            }
        }else{
            if(arr[idxDir]==x){
                result++;
                idxDir++;
            }else break;
        }
    }
    

    return result;
}

int Count3(const vector<int>& arr, int x)
{
    int left = 0;
    int right = arr.size();
    
    //TODO: O(log(n))
    // 고민중
    return -1;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());

    const int n = 20;
    vector<int> my_vector(n);

    int x = 6; // target to find

    for (int r = 0; r < 100; r++)
    {
        uniform_int_distribution<int> value_distribution(1, 10);
        generate(my_vector.begin(), my_vector.end(), [&]() { return value_distribution(gen); });
        sort(my_vector.begin(), my_vector.end());

        Print(my_vector);

        const int expected_count = std::count(my_vector.begin(), my_vector.end(), x);

        cout << "Expected count = " << expected_count << endl;

        // 1. O(n) brute force
        if (Count1(my_vector, x) != expected_count)
        {
            cout << "Wrong count1: " << Count1(my_vector, x) << endl;
            exit(-1);
        }

        // 2. O(log(n) + count)
        if (Count2(my_vector, x) != expected_count)
        {
            cout << "Wrong count2: " << Count2(my_vector, x) << endl;
            exit(-1);
        }

        // 3. O(log(n))
        if (Count3(my_vector, x) != expected_count)
        {
            cout << "Wrong count3: " << Count3(my_vector, x) << endl;
            exit(-1);
        }
    }

    cout << "Good!" << endl;

    return 0;
}
