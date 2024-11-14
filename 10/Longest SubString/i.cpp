#include <bits/stdc++.h>
using namespace std;

int longestSubString(string str) // O(N^2)
{
    int cnt = 0, n = str.size();
    for (int i = 0; i < n; i++)
    {
        vector<bool> visited(256, false); // ASCII(Range[0-255])
        for (int j = i; j < n; j++)
        {
            if (visited[str[j]] == true)
                break;

            else
            {
                cnt = max(cnt, j - i + 1);
                visited[str[j]] = true;
            }
        }
    }

    return cnt;
}

int Longest_Sub_String(string str) // sliding window -O(N)
{
    int cnt = 0;
    if (str.length() == 0)
        return 0;
    if (str.length() == 1)
        return 1;
    vector<bool> visited(256, false);
    int left = 0, right = 0;
    while (right < str.length())
    {
        while (visited[str[right]] == true)
        {
            visited[str[left]] = false;
            left++;
        }
        visited[str[right]] = true;
        cnt = max(cnt, right - left + 1);
        right++;
    }

    return cnt;
}

int main()
{
    string str = "geeksforgeeks";
    cout << longestSubString(str) << endl;
    cout << Longest_Sub_String(str) << endl;

    return 0;
}