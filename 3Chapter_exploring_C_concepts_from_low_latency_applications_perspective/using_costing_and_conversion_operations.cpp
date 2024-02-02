/*This example uses a converion from "double * " into "uint64_t * " and modifies the sign bit using the "uint64_t" pointer. 
 * This is nothing more thatn a convoluted and more efficient method of achieving "x = -std::abs(x) " but demonstrates how this violates the strict aliasing rule:*/
#include <cstdio>
#include <cstdint>
int main()
{
	double x = 100; 
	const auto orig_x = x; 
	auto x_as_ui = (uint64_t *) (&x);
	*x_as_ui |= 0x80000000000000000; 
	printf("orig_x:%0.2f x:%0.2f &x:%p &x_as_ui:%p\n", orig_x, x, &x, x_as_ui); 
}

/*Using modern C++ casting operations, "const_cast", "static_cast", and "reinterpret_cast" do not incur any additional overhead when used. 
 * However, when it comes to "dynamic_cast", which coverts an object of certain class into an object of different class, this can be expensive at runtime. 
 * "dynamic_cast" checks whether the conversion is valid using Run-Time Type Information (RTTI), which is slow and possibly throws an exception if the conversion is invalid - this makes it safer but increases latency.*/
