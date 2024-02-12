/*The constructor itself is straightforward -- it initializes the internal data members and creates an "MEOrderBook" instance for each one of the supported trading instruments. */
#include "matching_engine.h"

namespace Exchange
{
	MatchingEngine::MatchingEngine(ClientRequestLFQueue *client_requests, ClientResponseLFQueue *client_responses, MEMarketUpdateLFQueue *market_updates) : incoming_requests_(client_requests), outgoing_ogw_responses_(client_responses), outgoing_md_updates_(market_updates), logger_("exchange_matching_engine.log")
	{
		for (size_t i = 0; i < ticker_order_book_.size(); ++i)
		{
			ticker_order_book_[i] = new MEOrderBook(i, &logger_, this); 
		}
	}

	/*The destructor does the opposite of the constructor and resets the internal data member variables. 
	 * It also deletes the "MEOrderBook" objects it created in the constructor.*/
	MatchingEngine::~MatchingEngine()
	{
		run_ = false; 

		using namespace std::literals::chrono_literals; 
		std::this_thread::sleep_for(1s);

		incoming_requests_ = nullptr; 
		outgoing_ogw_responses_ = nullptr; 
		outgoing_md_updates_ = nullptr; 

		for (auto& order_book : ticker_order_book_)
		{
			delete order_book; 
			order_book = nullptr; 
		}
	}

	/*The "start()" method creates andlaunches a new thread, assigning it the "MatchingEngine::run()" method. 
	 * Before it does that, it enables "run_ flag", since it controls the execution of the "run()" method.*/
	auto MatchingEngine::start() -> void
	{
		run_ = true;
		ASSERT(Common::createAndStartThread(-1, "Exchange/MatchingEngine", [this]() { run(); }) != nullptr, "Failed to start MatchingEngine thread."); 
	}

	/*The "stop()" method simply sets the "run_" flag to be "false", and that in turn causes the "run()" method to exit out of its main loop, */
	auto MatchingEngine::stop() ->void 
	{
		run_ = false; 
	}
}
