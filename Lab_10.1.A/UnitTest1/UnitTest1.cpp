#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.1.A/Student.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// тестові дані: 4 студенти, з них 1 відмінник
			Student p[4] = {
			   { "Ivanenko", 1, KN,  5, 5, 5 },   // відмінник
			   { "Petrenko", 2, INF, 5, 4, 5 },
			   { "Koval",    1, ME,  4, 5, 5 },
			   { "Shevchuk", 3, TN,  3, 3, 4 }
			};

			double t = PercentExcellent(p, 4);

			Assert::AreEqual(25.0, t, 0.001);   // очікуємо 25%
		}
	};
}
