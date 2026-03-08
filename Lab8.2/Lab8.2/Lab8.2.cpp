#include <iostream>
#include <string>

using namespace std;

bool HasWordStartingWithA(const string s)
{
    size_t start = 0; 
    size_t finish;
    const string spaces = " \t\n\r";

    while ((start = s.find_first_not_of(spaces, start)) != -1)
    {
        finish = s.find_first_of(spaces, start + 1);

        if (finish == -1)
            finish = s.length();

        if (s[start] == 'a')
            return true;

        start = finish;
    }

    return false;
}

int main()
{
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    if (HasWordStartingWithA(str))
        cout << "The string contains a word starting with 'a'" << endl;
    else
        cout << "No words starting with 'a' found" << endl;

    return 0;
}