#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool Include(const char* str, int i)
{
    if (str[i] == '\0' || str[i + 1] == '\0')
        return false;

    if ((str[i] == 'a' && str[i + 1] == 'a') ||
        (str[i] == 'b' && str[i + 1] == 'b') ||
        (str[i] == 'c' && str[i + 1] == 'c'))
        return true;

    return Include(str, i + 1);
}

char* Change(char* dest, const char* str, char* t, int i)
{
    if (str[i] != '\0' && str[i + 1] != '\0')
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||
            (str[i] == 'b' && str[i + 1] == 'b') ||
            (str[i] == 'c' && str[i + 1] == 'c'))
        {
            strcat(t, "***");
            return Change(dest, str, t + 3, i + 2);
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
            return Change(dest, str, t, i);
        }
    }
    else
    {
        if (str[i] != '\0')
            *t++ = str[i++];

        *t = '\0';
        return dest;
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (Include(str, 0))
        cout << "Found pairs: aa, bb or cc" << endl;
    else
        cout << "No such pairs found" << endl;

    char* dest1 = new char[151];
    dest1[0] = '\0';
    char* dest2;
  
    dest2 = Change(dest1, str, dest1, 0);

    strcpy(str, dest1);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;

    return 0;
}