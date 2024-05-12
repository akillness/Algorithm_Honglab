#include <iostream>
#include <vector>
#include <string>

using namespace std;


string Add(string str1, string str2)
{
    // TO DO

    // parameter string의 길이 중 큰 길이 만큼 반복 횟수 설정
    string long_len = "";
    string short_len = "";
    if (str1.size() >= str2.size())
    {
        long_len = str1;
        short_len = str2;
    }else{
        long_len = str2;
        short_len = str1;
    }
     
    string result = "";
    int carry = 0;
    int totalSum = 0;

    int long_len_size = long_len.size();
    int short_len_size = short_len.size();
    
    for (; long_len_size > 0; )
    {
        int lVal = long_len[long_len_size-1] - '0';
        int sVal = 0;

        if (short_len_size > 0)
        {
            sVal = short_len[short_len_size-1] - '0';
        }

        // 같은 자리수의 합 및 이전 초과 자리수 합
        totalSum = carry+lVal+sVal;
        carry = totalSum/10;
        int remain = totalSum%10;

        if (carry >0){
            totalSum = remain;
        }
        
        result.insert(0,to_string(totalSum));
        long_len_size--;
        short_len_size--;
    }
    
    // 두 자리수의 합을 초과했는지 확인
    if (carry > 0)
    {
        result.insert(0,to_string(carry));
    }

    return result;
}


int main()
{
    vector<vector<string>> tests = {
        {"12", "34", to_string(12 + 34)}
		, {"123", "45", to_string(123 + 45)}
		, {"54544", "44545", to_string(54544 + 44545)}
		, {"5555", "55", to_string(5555 + 55)}
		, {"5555", "5555", to_string(5555 + 5555)}
		, {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "11538017781967960909090003089999089"}
    };

    for (const auto& t : tests)
    {
        const string str1 = t[0];       // 12
        const string str2 = t[1];       // 34
        const string expected = t[2];   // 46

        cout << str1 << " + " << str2 << " = " << expected << endl;

        const string result = Add(str1, str2);

        cout << result << " " << expected << " ";

        if (result == expected)
        {
            cout << "OK" << endl;
        }else{
            cout << "Not OK" << endl;
            exit(-1);
        }

        cout << endl << endl;
    }

    cout << "Congratulations. All OK!" << endl; 

    return 0;
}