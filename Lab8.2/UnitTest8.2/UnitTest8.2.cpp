#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8.2/Lab8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81
{
	TEST_CLASS(UnitTest81)
	{
	public:

		TEST_METHOD(TestHasWordTrue)
		{
			string s = "apple banana cherry";
			bool result = HasWordStartingWithA(s);
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestHasWordFalse)
		{
			string s = "orange banana cherry";
			bool result = HasWordStartingWithA(s);
			Assert::AreEqual(false, result);
		}

		TEST_METHOD(TestMultipleSpaces)
		{
			string s = "   orange      apple   ";
			bool result = HasWordStartingWithA(s);
			Assert::AreEqual(true, result);
		}

		TEST_METHOD(TestEmptyString)
		{
			string s = "";
			bool result = HasWordStartingWithA(s);
			Assert::AreEqual(false, result);
		}
	};
}
