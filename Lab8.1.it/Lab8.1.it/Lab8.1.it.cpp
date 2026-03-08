#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool Include(const char* str)
{
    for (int i = 0; str[i] != '\0' && str[i + 1] != '\0'; i++)
        if ((str[i] == 'a' && str[i + 1] == 'a') ||
            (str[i] == 'b' && str[i + 1] == 'b') ||
            (str[i] == 'c' && str[i + 1] == 'c'))
            return true;

    return false;
}

// Функція заміни кожної пари "aa", "bb", "cc" на "***"
char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 2)
        return str;

    char* tmp = new char[len * 3 / 2 + 1]; 
    char* t = tmp;
    tmp[0] = '\0';

    size_t i = 0;
    while (i < len && str[i + 1] != 0)
    {
        if ((str[i] == 'a' && str[i + 1] == 'a') ||
            (str[i] == 'b' && str[i + 1] == 'b') ||
            (str[i] == 'c' && str[i + 1] == 'c'))
        {
            strcat(t, "***");
            t += 3;
            i += 2;
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }


    if (i < len)
        *t++ = str[i];

    *t = '\0';
    strcpy(str, tmp);
    return tmp;
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
