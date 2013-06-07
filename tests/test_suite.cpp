#include <varchar/varchar.hpp>
#include <cassert>

void test1()
{
	varchar<10> data;
}

void test2()
{
	// Standard constructors
	varchar<10> data1 = "Hello world";
	varchar<10> data2("Hello world");
}


void test3()
{
	varchar<10> lhs = "test";
	assert(lhs == "test");
	assert(lhs != "hello");
}

void test4()
{
	varchar<10> lhs = "test";
	varchar<11> rhs = "hello";
	assert(lhs != rhs);
	assert(rhs != lhs);
	assert(!(lhs == rhs));
	assert(!(rhs == lhs));
}

void test5()
{
	varchar<10> lhs = "a";
	assert(lhs.length() == 1);
}

void test6()
{
	varchar<10> lhs = "12345678901234567890";
	assert(lhs.length() == 10);
}

int
main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
}