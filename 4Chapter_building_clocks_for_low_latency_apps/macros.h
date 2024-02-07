#pragma once 

#include <cstring>
#include <iostream>

/*The "LIKELY(x)" macro specifies that the condition specified by 'x' is likely to be true, and the "UNLIKELY(x)" macro does the opposite.*/
#define LIKELY(x) __biltin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)

/*Next, define two additional function next. 
 * "Assert" logs a message and exits if the condition it is provided evaluates to "false". 
 * "FATAL" simply logs a message and exits. 
 * Note "UNLIKELY" here to specifiy that we do not expect the "!cond" condition to evaluate to "true". 
 * Also not that using the "ASSERT" method on critical code paths is not free mostly because of the if check.*/
inline auto ASSERT(bool cond, const std::string &msg) noexcept
{
	if (UNLIKELY(!cond))
	{
		std::cerr << "ASSERT : " << msg << std::endl; 

		exit(EXIT_FAILURE); 
	}
}

inline auto FATAL(const std::string &msg) noexcept 
{
	std::cerr << "FATAL : " << msg << std::endl; 

	exit(EXIT_FAILURE); 
}
