#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8.1.it/Lab8.1.it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81it
{
	TEST_CLASS(UnitTest81it)
	{
	public:

		TEST_METHOD(TestIncludeTrue)
		{
			// Перевірка, чи функція знаходить пари
			char str[] = "abc aa def";
			bool result = Include(str);
			Assert::IsTrue(result);
		}

		TEST_METHOD(TestIncludeFalse)
		{
			// Перевірка, коли пар немає
			char str[] = "abc ab cde";
			bool result = Include(str);
			Assert::IsFalse(result);
		}

		TEST_METHOD(TestChange)
		{
			// Перевірка коректності заміни
			char str[100] = "aabbcc";
			char* result_ptr = Change(str);

			// Очікуваний результат
			Assert::AreEqual("*********", str);

			// Звільняємо пам'ять, яку виділив Change всередині
			delete[] result_ptr;
		}
	};
}