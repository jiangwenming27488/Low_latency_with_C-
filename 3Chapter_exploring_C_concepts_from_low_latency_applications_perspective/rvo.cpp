/*with "Return Value Optimization (RVO)" instead of creating a temporary "LargeClass" object inside "rvoExample()" and then copying it into the "LargeClass lc_obj" object in "main()", the "rvoExample()" function can directly update "lc_obj" and avoid the temporary object and copy.*/
#include <iostream>

struct LargeClass
{
	int i; 
	char c; 
	double d; 
}; 

auto rvoExample(int i, char c, double d)
{
	return LargeClass{i, c, d}; 
}

int main()
{
	LargeClass lc_obj = rvoExample(10, 'c', 3.14); 
}
