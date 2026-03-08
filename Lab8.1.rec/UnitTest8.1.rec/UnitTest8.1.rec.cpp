#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8.1.rec/Lab8.1.rec.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rec
{
    TEST_CLASS(UnitTest81rec)
    {
    public:
        TEST_METHOD(TestIncludeWithPairs)
        {
            char str[] = "abc aa def";
            bool result = Include(str, 0);
            Assert::IsTrue(result);
        }

        TEST_METHOD(TestIncludeWithoutPairs)
        {
            char str[] = "abc ab cde";
            bool result = Include(str, 0);
            Assert::IsFalse(result);
        }

        TEST_METHOD(TestChangePairs)
        {
            char str[100] = "aabbcc";
            char* dest1 = new char[151];
            dest1[0] = '\0';

            char* result_ptr = Change(dest1, str, dest1, 0);

            Assert::AreEqual("*********", result_ptr);

            delete[] dest1;
        }
    };
}
