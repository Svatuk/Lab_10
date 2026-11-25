#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.2.A/Student.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// масив уже впорядкований: Інформатика -> Комп. науки -> Мат. та екон.
			Student p[3] = {
				{ "Boiko",   1, INF, 5, 5, 4 },
				{ "Oliinyk", 2, KN,  5, 3, 3 },
				{ "Koval",   1, ME,  4, 3, 5 }
			};

			int t = BinSearch(p, 3, "Koval", ME, 3);

			Assert::AreEqual(2, t);     // Koval має бути знайдений в позиції з індексом 2
		}
	};
}
