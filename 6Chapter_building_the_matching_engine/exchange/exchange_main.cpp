/*First, we add some variables that will be pointers for the "Logger" object and the "MatchingEngine" object. 
 * We will also add a "signal_handler()" method to be invoked when killing the exchange application. 
 * The signal handler simply deletes these objects and exits:*/
#include <csignal>

#include "matcher/matching_engine.h"

Common::Logger* logger = nullptr; 
Exchange::MatchingEngine* matching_engine = nullptr; 

void signal_handler(int)
{
	using namespace std::literals::chrono_literals; 
	std::this_thread::sleep_for(10s); 
	
	delete logger; logger = nullptr; 
	delete matching_engine; matching_engine = nullptr; 

	std::this_thread::sleep_for(10s); 

	exit(EXIT_SUCCESS); 
}

/*The "main()" method is pretty simple for now, It installs the "signal_handler()" method using the "std::signal()" routine to trap external "SIGINT" signals.
 * It then initializes the "ClientRequestLFQueue" variable, "client_requests", and the "ClientResponseLFQueue"variable, "client_responses", to be of the "ME_MAX_CLIENT_UPDATES" size. 
 * We also initialize the lock-free queue variable, "market_updates", of type "MEMarketUpdateLFQueue" to be of "ME_MAX_MARKET_UPDATES" capacity. 
 * The "main()" mehtod also initializes the "logger" variable with an instances of the "Logger" class*/
int main(int, char **)
{
	logger = new Common::Logger("exchange_main.log"); 

	std::signal(SIGINT, signal_handler); 

	const int sleep_time = 100 * 1000; 

	Exchange::ClientRequestLFQueue client_requests(ME_MAX_CLIENT_UPDATES); 
	Exchange::ClientResponseLFQueue client_responses(ME_MAX_CLIENT_UPDATES); 
	Exchange::MEMarketUpdateLFQueue market_updates(ME_MAX_MARKET_UPDATES); 

	/*Finally, the "main()" method initializes the "matching_engine" variable with an instance of the "MatchingEngine" class we created and passes it the three lock-free queue it needs from the preceding code block .
	 * it then calls the "start()" method so that the main matching engine thread can start executing. 
	 * At this point, the "main()" method is done, so it enters into an ifintie loop, where it sleeps most of the i'm and waits for external signal that will kill this process: */
	std::string time_str; 

	logger->log("%:% %() Starting Matching Engine...\n", __FILE__, __LINE__, __FUNCTION__, Common::getCurrentTimeStr(&time_str)); 
	matching_engine = new Exchange::MatchingEngine(&client_requests, &client_responses, &market_updates); 
	matching_engine->start(); 

	while (true)
	{
		logger->log("%:% %() % Sleeping for a few milliseconds..\n", __FILE__, __LINE__, __FUNCTION__, Common::getCurrentTimeStr(&time_str)); 
		usleep(sleep_time * 1000); 
	}
}
