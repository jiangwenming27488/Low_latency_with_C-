#pragma once 

#include <sstream>

#include "common/types.h"

using namespace Common; 

namespace Exchange
{
	/*The "MEMarket" struct also needs to be a packed structure, since it will be part of the message that is sent and received over the network; hence, we use the "#pragma pack()" directive again. 
	 * Before we define the struct, we need to define the "MarketUpdateType" enumeration that represents the update action in the market update for an order. 
	 * In Addidtion to taking on order book, as well as trade events in the market.*/
#pragma pack(push, 1)
	enum class MarketUpdateType : int8_t
	{
		INVAID = 0, 
		ADD = 1, 
		MODIFY = 2, 
		CANCEL = 3, 
		TRADE = 4
	}; 

	inline std::string mareketUpdateTypeToString(MarketUpdateType type)
	{
		switch (type)
		{
			case MarketUpdateType::ADD: 
				return "ADD"; 
			case MarketUpdateType::MODIFY: 
				return "MODIFY"; 
			case MarketUpdateType::CANCEL: 
				return "CANCEL"; 
			case MarketUpdateType::TRADE: 
				return "TRADE"; 
			case MarketUpdateType::INVALID: 
				return "INVALID"; 
		}

		return "UNKNOWN"; 
	}

	/*The complete "MEMarketUpdate" struct is shown in the following code block, along with the "MEMarketUpdateLFQueu" typedef, which captures a lock-free queue of "MEMarketUpdate" struct message: */
	struct MEMarketUpdate 
	{
		MarketUpdateType type_ = MarketUpdateType::INVALID; 

		OrderId order_id_ = OrderId_INVALID; 
		TickerId ticker_id_ = TickerId_INVALID; 
		Side side_ = Side::INVALID; 
		Price price_ = Price_INVALID; 
		Qty qty_ = Qty_INVALID; 
		Proirity priority_ = Priority_INVALID; 

		auto toString() const 
		{
			std::stringstream ss; 
			ss << "MEMarketUpdate" << " [" << " type:"  << marketUpdateTypeToString(type_) << " ticker:" << tickerIdToString(ticker_id_) << " oid:" << orderIdToString(order_id_) << " side:" << sideToString(side_) << " qty:" << qtyToString(qty_) << " price:" << priceToString(price_) << " priority:" << priorityToString(priority_) << "]"; 
			return ss.str(); 
		}
	}; 

#pragma pack(pop)

	typedef Common::LFQueue<Exchange::MEMarketUpdate> MEMarketUpdateLFQueue;

}
