/*If there are expressions within the loop that conditionally yield one value or the other depending on branching conditions, those can also be moved out the loop. 
 * Also if there are expressions executed on each branch within a loop, these can be moved out of the branches and possibly the loop. 
 * There are many such optimization possibilies, but the fundamental idea is that code that does not need to be executed on each loop iteration or can be evaluated once before the loop falls under the umbrella of lopp invariant code refactoring. 
 * Here is a hypothetical example of how loop invariant code movement implemnted by the compiler would work. 
 * The firs block is what the developer originally wrote, but the compiler can understand that the call to "doSomething()" and the expression involving the 'b' variable are loop invariants and only need to be computed once. */

#include <cstdlib>

int main()
{
	auto doSomething = [](double r) noexcept {return 3.14 * r * r; };
	[[maybe_unsued]] int a[100], b = rand(); 

	/*original*/
	for (auto i = 0; i < 100; ++i)
	{
		a[i] = (doSomething(50) + b * 2) + 1; 
	}
	/* loop invariant*/
	auto temp = (doSomething(50) + b * 2) + 1; 
	for (auto i = 0; i < 100; ++i)
	{
		a[i] = temp; 
	}
	
}
