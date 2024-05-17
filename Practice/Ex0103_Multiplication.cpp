#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Multiply(string str1, string str2)
{
    // TODO:
    if (str1.size() < 1 || str2.size() < 1)
    {
        return "0";
    }
    
    int N = max(str1.size(), str2.size());
    
    str1 = string(N - str1.size(),'0') + str1;
    str2 = string(N - str2.size(),'0') + str2;
    
    string result(N*2,'0');
    int k = result.size() - 1;
 
    for (int i = N-1; i >= 0; i--){
        
        int fVal = str2[i] - '0';
        int carry = 0;
        
        for (int j = N-1; j >=0; j--)
        {
            int lVal = str1[j] - '0';
            int resVal = result[k] - '0';
            int tmpMultiply = fVal*lVal+carry+resVal;
            carry = tmpMultiply/10;
            tmpMultiply = tmpMultiply%10;
            
            result[k] = tmpMultiply + '0';
            k--;
        }
        if (carry > 0){
            result[k] = carry + '0';
        }

        k = (result.size() - 1) - ( N - i )  ;
    }
    
    int rIdx = 0;
    while(result[rIdx] == '0'){
        rIdx++;
    }
    
    result = result.substr(rIdx,result.size());
    return result;
}

int main()
{
    vector<vector<string>> tests = {
        {"12", "34", std::to_string(12 * 34)},
        {"123", "45", std::to_string(123 * 45)},
        {"5555", "55", std::to_string(5555 * 55)},
        {"5555", "5555", std::to_string(5555 * 5555)},
        {"98234712354214154", "171454654654655", "16842798681791158832220782986870"}
        //  , {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "16842798681791114273590624445460185389471221520083884298838480662480"}
    };

    for (const auto& t : tests)
    {
        const string str1 = t[0];
        const string str2 = t[1];
        const string expected = t[2];

        cout << str1 << " * " << str2 << " = " << expected << endl;

        const string result = Multiply(str1, str2);

        cout << result << " " << expected << " ";

        if (result == expected)
            cout << "OK";
        else {
            cout << "Not OK";
            exit(-1);
        }
        cout << endl << endl;
    }

    cout << "Congratulations. All OK!" << endl;

    return 0;
}
