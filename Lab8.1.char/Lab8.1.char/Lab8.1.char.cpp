#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool Include(char* s)
{
    char* t;
    size_t pos = 0; 
    char cs[] = "abc";

    while (t = strpbrk(s + pos, cs))
    {
        pos = t - s + 1;
        if (s[pos] == s[pos - 1])
            return true;
    }
    return false;
}

char* Change(char* s)
{
    char* t = new char[strlen(s) * 3 / 2 + 1];
    char* p;
    size_t pos1 = 0, pos2 = 0; 
    *t = 0;
    char cs[] = "abc";

    while (p = strpbrk(s + pos1, cs))
    {
        if (s[p - s + 1] == *p)
        {
            pos2 = p - s + 2;
            strncat(t, s + pos1, p - s - pos1);
            strcat(t, "***");
            pos1 = pos2;
        }
        else
        {
            pos2 = p - s + 1;
            strncat(t, s + pos1, pos2 - pos1);
            pos1 = pos2;
        }
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Include(str))
        cout << "Found pairs: aa, bb or cc" << endl;
    else
        cout << "No such pairs found" << endl;

    char* dest = new char[151];
    dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest;
    return 0;
}