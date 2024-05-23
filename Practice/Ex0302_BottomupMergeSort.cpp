#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric> // std::iota

using namespace std;

void Print(vector<int>& arr, int lo, int hi)
{
    // setfill(), setw()는 줄맞춤에 사용

    for (int i = 0; i < lo; i++)
        cout << "   ";
    for (int i = lo; i <= hi; i++)
        cout << setfill(' ') << setw(3) << arr[i];
    cout << endl;
}

bool CheckSorted(vector<int>& a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i] > a[i + 1])
            return false;
    }

    return true;
}

// Sedgewick p. 278
class BottomupMerge
{
public:
    void Sort(vector<int>& a)
    {
        aux.resize(a.size());

        int N = a.size();
        // TODO: 재귀호출 사용하지 않습니다.
        // 분할하기 위한 Depth(Level) 탐색
        int searchDepth = N/2;
        int depth = 0;
        while(1){
            searchDepth /= 2;
            depth++;
            if (searchDepth <= 1)
                break;
            
        }
        
        // Depth 만큼 점진적으로 Sorting 하기 위한 이중 for문
        for (int d=1; d <= depth+1; d++){
            int addVal = pow(2,d);
            for (int i=0; i< N-1; i+=addVal )
            {
                int lo = i;
                int hi = i+addVal-1;
                int mid = (lo + hi)/2;
                Merge(a, lo, mid, hi);
            }
        }
        
    }

private:
    void Merge(vector<int>& a, int lo, int mid, int hi)
    {
        // TODO: Top-down과 동일
        cout<< "Before : ";
        Print(a,lo,hi);
        
        int i=lo, j=mid+1;
        
        if (a[mid] <= a[j]) // 이미 정렬이 되어있다면 아래의 과정을 반복하지않겠다
            return;

        for (int k = lo; k <= hi; k++)
            aux[k] = a[k];
        
        
        for (int k = lo; k < hi+1; k++ ){
            if(i > mid) 
                a[k] = aux[j++];
            else if(j > hi) 
                a[k] = aux[i++];
            else if(aux[j] < aux[i]) 
                a[k] = aux[j++];
            else 
                a[k] = a[i++];
        }
        
        
        cout<< "After : ";
        Print(a,lo,hi);
    }

    vector<int> aux; // 추가 메모리
};

int main()
{
    vector<int> my_vector(16);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    std::reverse(my_vector.begin(), my_vector.end());

    cout << "        ";
    Print(my_vector, 0, my_vector.size() - 1);

    BottomupMerge merge;
    merge.Sort(my_vector);

    cout << "        ";
    Print(my_vector, 0, my_vector.size() - 1);
}
