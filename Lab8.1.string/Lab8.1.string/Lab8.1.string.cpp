#include <iostream>
#include <string>
using namespace std;

bool Include(const string s)
{
    size_t pos = 0;
    while ((pos = s.find_first_of("abc", pos)) != -1)
    {
        if (pos + 1 < s.length() && s[pos] == s[pos + 1])
            return true;
        pos++;
    }
    return false;
}

string Change(string& s)
{
    size_t pos = 0;
    while ((pos = s.find_first_of("abc", pos)) != -1)
    {
        if (pos + 1 < s.length() && s[pos] == s[pos + 1])
        {
            s.replace(pos, 2, "***");
            pos += 3;
        }
        else
            pos++;
    }
    return s;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    if (Include(str))
        cout << "Found pairs: aa, bb or cc" << endl;
    else
        cout << "No such pairs found" << endl;

    string dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}