varchar
===

Constant-size strings for humans.

# Abstract

I realized that I use too much of `strncmp`, `strncpy`, but I still need constant size strings. `std::string` was not an option for me mostly because the codebase was quite large, and tests showed that it would add too much overhead. I needed a way to simply replace `char string_data[11]` into a more clean solution in C++ and ofcourse drop all these `strncmp`, `strncpy` (and even few `memset`s, `memcpy`s... !).

Usage is simple and very idiomatic similiar to `std::string`. This library should not add more overhead to your output code more than using the `cstring` API directly.

When you switch over you will never overrun any buffer by mistake and the code will be way more readable. 

# Usage

## String comparision

Before
	
	char test[11] = {0};
	strncpy(test, "hello world", sizeof(test) - 1);
	if (strncmp(test, "Hello World", sizeof(test) - 1) == 0)
	{
		// Do something
	}

After

	varchar<10> str = "hello world";
	if (str == "Hello World")
	{
	}

## Length of a string

Before

	char test[11];
	std::memset(test, '\0', sizeof(test) - 1);
	std::strncpy(test, "test", sizeof(test) - 1);
	std::printf("%d\n", std::strlen(test));
	
After

	varchar<5> test = "test";
	std::printf("%d\n", test.length());
	
## Copy operations

Before

	char test1[32];
	char test2[64];
	std::memcpy(test1, test2, 64); // dont do this!
	test[32] = '\0'; // not again
	
After

	varchar<32> test1;
	varchar<64> test2 = "what";
	test1 = test2;

# TODO

* Memory alignment

# Building

	mkdir build && cd build && cmake .. && make
	
# Copyright

The same as Boost license.

# Authors

* Michał Papierski <michal@papierski.net>
