#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8.1.char/Lab8.1.char.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:

		TEST_METHOD(TestIncludeTrue)
		{
			char str[] = "abc aa def";
			bool result = Include(str);
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestIncludeFalse)
		{
			char str[] = "abc a b c def";
			bool result = Include(str);
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(TestChange)
		{
			char str[100] = "aa b bb cc";
			char* result_ptr = Change(str);

			Assert::AreEqual("*** b *** ***", result_ptr);

			delete[] result_ptr;
		}

		TEST_METHOD(TestChangeNoPairs)
		{
			char str[100] = "abc";
			char* result_ptr = Change(str);

			Assert::AreEqual("abc", result_ptr);

			delete[] result_ptr;
		}
	};
}