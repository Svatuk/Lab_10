#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_10.2.B/Student.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// масив уже впорядкований: Інформатика -> Комп. науки -> Мат. та екон.
			Student p[3];
			p[0].prizv = "Boiko";   p[0].kurs = 1; p[0].spec = INF;
			p[0].fizyka = 5; p[0].matematyka = 5; p[0].chyselni_metody = 4;

			p[1].prizv = "Oliinyk"; p[1].kurs = 2; p[1].spec = KN;
			p[1].fizyka = 5; p[1].matematyka = 3; p[1].programuvannia = 3;

			p[2].prizv = "Koval";   p[2].kurs = 1; p[2].spec = ME;
			p[2].fizyka = 4; p[2].matematyka = 3; p[2].pedagogika = 5;

			int t = BinSearch(p, 3, "Koval", ME, 3);

			Assert::AreEqual(2, t);     // Koval - в позиції з індексом 2
		}
	};
}
