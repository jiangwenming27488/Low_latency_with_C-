/*"&&", is the first operand is false, then the second one is not evaluated, and for "||" if the first ont is true, then the second one is not evaluated. 
 *
 * A simple optimization technique is to order the operands of "&&" in order from lowest to highest probability of being evaluated to true. 
 * Similarly, for "||", ordering the operands from highest to lowest probability of being true is best. 
 * This technique is referred to as short-circuiting the boolean operations and it not only reduces the number of times these operands are evaluated but also improves brach prediction. 
 * Another aspect of using boolean variaables is understanding the way they are stored. 
 * Boolean variables are stored as 8 bits and not a single bit, as might match our intuition from the way they are used. */
if (a != 0)
{
	if (b != 0)
	{
		c = true; 
	} else 
	{
		c = false; 
	}
} else 
{
	c = false; 
}

/*If there was a guarantee that 'a' and 'b' could not have values other than 0 or 1 then "c = a && b;" would simply be "c = a & b; ", which is super-fast and avoids branching and branching-related overheads. */

/*Bitwise operations can also help speed up other cases of boolean expressions by treating each bit of an integer as a single boolean variable and then rewriting expressions involving comparisons of multiple booleans with bit-masking operations. 
 * For instance, take an expression such as this, where "market_state" is "uint64_t" and "PreOpen", "Opening", and "Trading" are enum values that reflect different market states:*/
if (market_state == PreOpen || market_state == Opening || market_state == Trading)
{
	/*do something...*/
}

/*i can be rewritten as follows: */
if (market_state & (PreOpen | Opening |Trading))
{
	/*do something...*/
}

/*If the enum values are chosen such that each bit in the "market_state" variable represents a state of true or false, one choice would be for the "PreOpen", "Opening", and "Trading" enums to be set to 0x001, 0x010, and 0x100*/
