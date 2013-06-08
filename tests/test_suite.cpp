#include <varchar/varchar.hpp>
#include <cassert>
#include <string>
#include <vector>

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

void test7()
{
	std::string text = "hello world";
	varchar<20> data;
	std::copy(text.begin(), text.end(), data.begin());
	assert(data == text.c_str());
}

void test8()
{
	varchar<20> data = "hello world";
	std::vector<char> output(21, '\0');
	std::copy(data.begin(), data.end(), output.begin());
	assert(std::string(output.data()) == "hello world");
}

void test9()
{
	varchar<20> data = "hello world";
	assert(data[0] == 'h');
	assert(data[1] == 'e');
	assert(data[2] == 'l');
	assert(data[3] == 'l');
	assert(data[4] == 'o');
	assert(data[5] == ' ');
	assert(data[6] == 'w');
	assert(data[7] == 'o');
	assert(data[8] == 'r');
	assert(data[9] == 'l');
	assert(data[10] == 'd');
}

void test10()
{
	varchar<20> data = "hello world";
	assert(data.at(0) == 'h');
	assert(data.at(1) == 'e');
	assert(data.at(2) == 'l');
	assert(data.at(3) == 'l');
	assert(data.at(4) == 'o');
	assert(data.at(5) == ' ');
	assert(data.at(6) == 'w');
	assert(data.at(7) == 'o');
	assert(data.at(8) == 'r');
	assert(data.at(9) == 'l');
	assert(data.at(10) == 'd');
}

void test11()
{
	varchar<5> data = "1234";
	bool got_exception;
	try
	{
		(void)data.at(1234);
		got_exception = false;
	} catch (std::out_of_range const &)
	{
		got_exception = true;
	}
	assert(got_exception);
}

void test12()
{
	varchar<5> data = "1234";
	bool got_exception;
	try
	{
		(void)data.at(5);
		got_exception = false;
	} catch (std::out_of_range const &)
	{
		got_exception = true;
	}
	assert(got_exception);
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
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
}