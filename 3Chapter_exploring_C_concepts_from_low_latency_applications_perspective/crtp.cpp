/*Runtime polymorphism using virtual functions
 * Here we have an example of implementing runtime polymorphism where "SpecificRuntimeExample" derives "RuntimeExample" and overrides the "placeOrder()" method:*/
#include <cstdio>

class RuntimeExample
{
	public:
		virtual void placeOrder()
		{
			printf("RuntimeExample::placeOrder()\n"); 
		}
}; 

classSpecificRunTimeExample : public RuntimeExample
{
	public: 
		void placeOrder() override
		{
			printf("SpecificRuntimeExample::placeOrder()\n"); 
		}
}; 

/*Compile-time polymorphism using the CRTP
 * Now we implement similar functionality as discussed inj the previous section, but instead of using runtime polymorphism, we use compile-time polymorphism. 
 * Here, we use the CRTP paten and "SpecificCRTPExample" specializes/implements the "CRTPExample" interface and has a different implementation of "placeOrder()" via "actualPlaceOrder()": */
template<typename actual_type>
class CRTPExample
{
	public: 
		void placeOrder()
		{
			static_cast<actual_type *>(this)->actualPlaceOrder(); 
		}

		void actualPlaceOrder()
		{
			printf("CRTPExample::actualPlaceOrder()\n"); 
		}
}; 

class SpecificCRTPExample : public CRTPExample<SpecificCRTPExample>
{
	public: 
		void actualPlaceOrder()
		{
			printf("SpecificCRTPExample::actualPlaceOrder()\n"); 
		}
}; 

int main(int, char **)
{
	RuntimeExample *runtime_example = new SpecificRuntimeExample(); 
	runtime_example->placeOrder(); 

	CRTPExample <SpecificCRTPExample> crtp_example; 
	crtp_example.placeOrder(); 

	return 0; 
}
