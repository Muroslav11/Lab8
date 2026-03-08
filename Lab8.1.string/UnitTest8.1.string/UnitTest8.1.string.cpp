#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8.1.string/Lab8.1.string.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81string
{
	TEST_CLASS(UnitTest81string)
	{
	public:

		TEST_METHOD(TestIncludeFound)
		{
			string s = "xxaayy";
			bool result = Include(s);
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestIncludeNotFound)
		{
			string s = "abc abc";
			bool result = Include(s);
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(TestChangePairs)
		{
			string s = "aa b bb cc";
			string expected = "*** b *** ***";
			string result = Change(s);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TestChangeNoPairs)
		{
			string s = "abc";
			string expected = "abc";
			string result = Change(s);
			Assert::AreEqual(expected, result);
		}
	};
}