#include "pch.h"
#include "CppUnitTest.h"
#include "../person_lab/person_lab.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Test_getCross)
		{
			Line l1(0, 0, 1, 1);
			Line l2(0, 1, 1, 0);
			Point p;
			Point q(0.5, 0.5);
			getCross(l1, l2, &p);
			Assert::IsTrue(q == p);


		}

		TEST_METHOD(Test_getInterSect) {
			Line l1(0 ,0 ,1, 1);
			Line l2(1, 0, 0 ,1);
			Line l3(1, 2, 2 ,0);
			Line l4();
			std::vector<Line> a;
			a.push_back(l1);
			a.push_back(l2);
			a.push_back(l3);
			Assert::AreEqual(3, (int) getAllIntersrc(a));
		}
	};
}
