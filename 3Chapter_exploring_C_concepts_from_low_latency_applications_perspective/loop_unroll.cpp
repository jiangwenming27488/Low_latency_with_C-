/*compile-time branching using an "if consttexpr (condition-expression) {}" format can obviously help a lot by moving the overhead branching to compile time, but this requires that "condition-expression" be something that can be evaluated at compile time.*/
int main() 
{
	{	
		/*original code.*/
		int a[5]; 
		a[0] = 0; 
		for (int i = 1; i < 5; ++i)
			a[i] = a[i - 1] + 1; 
	}
	{
		/*loop unrolled code.*/
		int a[5]; 
		a[0] = 0; 
		a[1] = a[0] + 1; 
		a[2] = a[1] + 1; 
		a[3] = a[1] + 1; 
		a[4] = a[3] + 1; 
	}
}
