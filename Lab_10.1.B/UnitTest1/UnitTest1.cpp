#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.1.B/Student.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student p[3];

			p[0].prizv = "Ivanenko"; p[0].kurs = 1; p[0].spec = KN;   // відмінник
			p[0].fizyka = 5; p[0].matematyka = 5; p[0].programuvannia = 5;

			p[1].prizv = "Petrenko"; p[1].kurs = 2; p[1].spec = INF;  // не відмінник
			p[1].fizyka = 5; p[1].matematyka = 5; p[1].chyselni_metody = 4;

			p[2].prizv = "Koval";    p[2].kurs = 3; p[2].spec = TN;   // відмінник
			p[2].fizyka = 5; p[2].matematyka = 5; p[2].pedagogika = 5;

			double t = PercentExcellent(p, 3);

			Assert::AreEqual(66.67, t, 0.01);   // 2 з 3 = 66.67%
		}
	};
}
