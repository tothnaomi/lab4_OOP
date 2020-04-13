#include "pch.h"
#include <iostream>
#include "CppUnitTest.h"
#include "../lab4_OOP/Repository.h"
#include "../lab4_OOP/Repository.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace lab4_OOPTest
{
	TEST_CLASS(lab4_OOPTest::RepositoryTest)
	{
	public:

		TEST_METHOD(Medikamente_die_eine_zeichenkette_enthaltenTest)
		{
			auto Medikament* MPtr = new Medikament("Nurofen", 100, 0, 123.45);
			assert::Medikamente_die_eine_zeichenkette_enthaltenTestz(fen);
		}

		TEST_METHOD()
	};
}
