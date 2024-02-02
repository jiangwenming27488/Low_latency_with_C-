/*The following code would prevent the compiler from applying loop-invariant code motion. 
 * This is despite there being no overlap between pointers "a[0]" to "a[n - 1]" and 'b'. 
 * That means that this optimization is valid because "*b" is constant for the entire loop  and can be computed once:*/
void func(int* a, int* b, int n)
{
	for (int i = 0; i < n; ++i)
	{
		a[i] = *b; 
	}
}

/*There are realy two options for instructing the compiler to assume no pointer aliasing in cases where the developer is confident that there is no behavior that is dependent on the side effects of pointer aliasing. 
 * Use "__restrict__", or "__restrict", a similar specifier keyword, for your compiler on the function arguments or functions to specify no aliasing on the pointers. 
 * This a hint, and the compiler does not guarantee that this will make a difference. 
 * The other option is to specify the "-fstrict-aliasing" compiler option to assume no pointer aliasing globally. 
 * Below code block demonstrates the use of the "trstrict" specifier for the preceding "func()" function */

void func(int *__restrict a, int *__restrict b, int n)
{
	for (int i = 0; i < n: ++i)
	{
		a[i] = *b; 
	}
}


