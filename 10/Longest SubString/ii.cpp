// Maximum consecutive repeating character in string

#include <bits/stdc++.h>
using namespace std;

char maxRepeating(string str)
{
    int n = str.length();
    int cnt = 0;
    char res = str[0];
    for (int i = 0; i < n; i++)
    {
        int curr = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] != str[j])
                break;
            curr++;
        }

        if (curr > cnt)
        {
            cnt = curr;
            res = str[i];
        }
    }
    return res;
}

int main()
{
    string str = "geeekk";
    cout << maxRepeating(str);
    return 0;
}