#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int t;
    cin >> t;
    int a[t] = {};
    int k = 0;
    cin.ignore(1);
    while (t--)
    {   
        stack<int> sum;
        string s;

        getline(cin, s);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'C')
            {
                sum.push(12);
            }
            else if (s[i] == 'O')
            {
                sum.push(16);
            }
            else if (s[i] == 'H')
            {
                sum.push(1);
            }
            else if (s[i] == '(')
            {
                sum.push(0);
            }
            else if (s[i] == ')')
            {
                int tong = 0;
                while (!sum.empty() && sum.top()!=0)
                {
                    tong += sum.top();
                    sum.pop();
                }
                sum.pop();
                sum.push(tong);
            }
            else // 0 <= s[i] <= 9
            {

                int temp = (sum.top())*((int)(s[i]-'0'));
                sum.pop();
                sum.push(temp);
            }
        }
        while (!sum.empty())
        {
            a[k] += sum.top();
            sum.pop();
        }
        k++;
    }
    for (int i = 0; i < k; i++)
    {
        cout << a[i] << endl;
    }
}

