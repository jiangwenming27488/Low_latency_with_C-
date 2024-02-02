/*The compiler typically picks variables such as local var, loop counter and iterator var, function parameters, commonly used expressions, or induction var. 
 * There are some limitations to what the compiler can place in registers such as variables whose address needs to be taken via pointers or references that need to reside in main memory
 * This is a simple example of how a compiler will transform a loop expression using induction variables.*/
int main() 
{
	[[maybe_unused]] int a[100]; 

	/*original */
	for (auto i = 0; i < 100; ++i)
	{
		a[i] = i * 10 + 12; 

		/*optimized*/
		int temp = 12; 
		for (auto i = 0; i < 100; ++i)
		{
			a[i] = temp; 
			temp += 10; 
		}
	}
}
