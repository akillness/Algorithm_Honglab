#include <iostream>
#include <string>
using namespace std;

int main()
{
    // 문제 1. 10진수 -> 2진수
    {
        int decimal = 105;
        string binary = "";

        //TODO:
        while(decimal != 0)
        {
            if ( decimal % 2 > 0 ){
                binary.insert(0,to_string(1));
            }else{
                binary.insert(0,to_string(0));
            }
            

            decimal /= 2;
        }

        cout << binary << endl; // 1101001
    }

    // 문제 2. 문자열 뒤집기
    {
        string input = "Hello, World!";

        // TODO:
        unsigned long right_idx = input.size()-1;
        unsigned long left_idx = 0;
        while(left_idx < right_idx)
        {
            
            swap(input[left_idx],input[right_idx]);
            
            left_idx++;
            right_idx--;
        }

        cout << input << endl; // !dlroW ,olleH
    }

    // 문제 3. 모든 자리 다 더하기
    {
        string n = "789789";

        // TODO:
        int sum = 0;
        while(n.size() >= 2)
        {
            for (char c : n)
            {
                sum += c-'0';
            }
            
            n = to_string(sum);
            sum = 0;
        }
        
        cout << n << endl;
    }

    return 0;
}
