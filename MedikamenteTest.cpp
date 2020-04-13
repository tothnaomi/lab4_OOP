#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "../lab4_OOP/Repository.h"
using namespace lab4_OOPTest::lab4_OOPTest;

#define T
/*TEST_CLASS(MedikamenteTest::lab4_OOPTest::lab4_OOPTest::MedikamenteTest) {
class MedikameteTest : public::Microsoft::VisualStudio::CppUnitTestFramework::TestClass<MedikamenteTest>*/

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace lab4_OOPTest
{
	void TEST_CLASS(lab4_OOPTest::MedikamenteTest)
	{
	public:

		TEST_METHOD(ConstructorTest)
		{
			auto Medikament* MPtr = new Medikament("Nurofen", 100, 0, 123.45);
			Assert::AreEqual(100.0, MPtr->get_konzentration());
			Assert::AreEqual(0, MPtr->get_menge());
			Assert::AreEqual(123.45, MPtr->get_preis());
			Assert::AreEqual(std::string("Nurofen"), MPtr->get_name());

		}

		TEST_METHOD(SubstractQuantityTest)
		{
			auto medik = Medikament("Nurofen", 100, 2, 123.45);

				
				try {
					medik -= 10;
				}
				catch (std::exception ex) {
					Assert::AreEqual(std::string("Invalid Menge to substract"), std::string(ex.what()));
				}
}