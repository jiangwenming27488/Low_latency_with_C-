/*The following example builds "OrderBook", which basically holds a vector of "Order" objects, in two different ways. 
 * The benefit of the inheritance model is that it now inherits all the methods that "std::vector" provides while the composition model would need to implement them. 
 * In this example, we demonstrate this by implementing a "size()" method in "CompositionOrderBook", which calls the "size()" method on the "std::vector" object, while "InheritanceOrderBook" inherits it directly from "std::vector"*/

#include <cstdio>
#include <vector>

struct Order
{
	int id; 
	double price; 
}; 

class InheritanceOrderBook : public std::vector<Order>
{
	
};

class CompositionOrderBook
{
	std::vector<Order> orders_; 

	public: 
	auto size() const noexcept
	{
		return orders_.size(); 
	}
}; 

int main() 
{
	InheritanceOrderBook i_book; 
	CompositionOrderBook c_book; 

	printf("InheritanceOrderBook::size():%lu CompositionOrderBook:%lu\n", i_book.size(), c_book.size()); 
}
