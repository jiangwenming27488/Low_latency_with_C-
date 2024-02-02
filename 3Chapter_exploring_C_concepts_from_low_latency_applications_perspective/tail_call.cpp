/*Tail call optimization refers to compiler optimization techniques in which revursive function calls are replaced by loops. 
 * This has obvious performance benefits such as eliminating function call overheads and stack operations and avoids possible stack overflow cases. 
 * Below simple example of a recursive factoral implementation.*/
auto __attribute__((noinline)) factorial(unsigned n) -> unsigned
{
	return (n ? n * factorial(n - 1) : 1); 
}

int main() 
{
	[[maybe_unused]] volatile auto res = factorial(100); 
}
