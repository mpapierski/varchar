#if !defined(VARCHAR_INCLUDED_HPP_)
#define VARCHAR_INCLUDED_HPP_

#include <cstring>
#include <cassert>

template <std::size_t N>
struct varchar
{
	char data_[N + 1];
	varchar()
	{
		std::memset(data_, '\0', sizeof(data_));
	}
	varchar(const char * data)
	{
		std::strncpy(data_, data, N);
	}
	template <std::size_t M>
	varchar(varchar<M> const & x)
	{
		std::strncpy(data_, x.data(), N);
	}
	bool operator==(const char * rhs)
	{
		return std::strncmp(data_, rhs, N) == 0;
	}
	template <std::size_t M>
	bool operator==(varchar<M> const & rhs)
	{
		return std::strncmp(data_, rhs.data(), N) == 0;
	}
	bool operator!=(const char * rhs)
	{
		return std::strncmp(data_, rhs, N) != 0;
	}
	template <std::size_t M>
	bool operator!=(varchar<M> const & rhs)
	{
		return std::strncmp(data_, rhs.data(), N) != 0;
	}
	char * data()
	{
		return data_;
	}
	const char * data() const
	{
		return data_;
	}
	operator bool()
	{
		assert(N >= 1);
		return data_[0];
	}
	std::size_t length()
	{
		return std::strlen(data_);
	}
};

#endif