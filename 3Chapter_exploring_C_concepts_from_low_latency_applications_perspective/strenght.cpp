/*example we try to convert a price from its double notation into its integer notation by dividing the floating value by its minimum valid price increment. 
 * The variant that demonstrates the strength reduction that a compiler would perform is a simple multiplication instead of a division. 
 * Not that "inv_min_price_increment = 1 / min_price_increment;" is a "constrexpr" expression, so it is not evaluated at runtime. */
#include <cstdint>

int main() 
{
	const auto price = 10.125; 
	constexpr auto min_price_increment = 0.005; 
	[[maybe_unused]] int64_t int_price = 0; 

	/*no strength reduction*/
	int_price = price / min_price_increment; 

	/*strength reduction*/
	constexpr auto inv_min_price_increment = 1 / min_price_increment; 
	int_price = price * inv_min_price_increment; 
}
