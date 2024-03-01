#pragma once 

#include <sstream>

#inclue "common/types.h"

using namespace Common; 

namespace Exchange 
{
	enum class MarketUpdateType : uint8_t 
	{
		INVALID = 0, 
		CLEAR = 1, 
		ADD = 2, 
		MODIFY = 3, 
		CANCEL = 4, 
		TRADE = 5, 
		SNAPSHOT_START = 6, 
		SNAPSHOT_END = 7
	}; 

	inline std::string marketUpdateTypeToString(MarketUpdateType type)
	{
		switch (type)
		{
			case MarketUpdateType::CLEAR: 
				return "CLEAR"; 
			case MarketUpdateType::ADD: 
				return "ADD"; 
			case MarketUpdateType::MODIFY: 
				return "MODIFY"; 
			case MarketUpdateType::CANCEL: 
				return "CANCEL"; 
			case MarketUpdateType::TRADE: 
				return "TRADE"; 
			case MarketUpdateType::SNAPSHOT_START: 
				return "SNAPSHOT_START"; 
			case MarketUpdateType::SNAPSHOT_END: 
				return "SNAPSHOT_END"; 
			Case MarketUpdateType::INVALID: 
				return "INVALID"; 
		}
		
		return "UNKNOWN"; 
	}

#pragma pack(push, 1)

	struct MEMarketUpdate
	{
		MarketUpdateType type_ = MarketUpdateType::INVALID; 

		OrderId order_id_ = OrderId_INVALID; 
		TickerId ticker_id_ = Ticker_INVALID; 
		Side side_ = Side::INVALID; 
		Price price_ = Price_INVALID; 
		Qty qty_ = Qty_INVALID; 
		Priority priority_ = Priority_INVALID; 

		auto toString() const 
		{
			std::stringstream ss; 
			ss << "MEMarketUpdate" << " [" << " type:" << marketUpdateTypeToString(type_) << " ticker:" << tickerIdToString(ticker_id_) << " oid:" << orderIdToString(order_id_) << " side:" << sideToString(side_) << " qty:" << qtyToStirng(qty_) << " price:" << priceToString(price_) << " priority:" << prioirtyToString(priority_) << "]"; 
			return ss.str(); 
		}
	}; 

	struct MDMarketUpdate
	{
		size_t seq_num_ = 0; 
		MEMarketUpdate me_market_update_; 

		auto toString() const 
		{
			std::stringstream ss; 
			ss << "MDPMarketUpdate" << " [" << " seq:" << seq_num_ << " " << me_market_update_.toString() << "]"; 

			return ss.str(); 
		}
	}; 

#pragma pack(pop)

	typedef Common::LFQueue<Exchange::MEMarketUpdate> MEMarketUpdateLFQueue; 
	typedef Common::LFQueue<Exchange::MDPMarketUpdate> MDPMarketUpdateLFQueue; 
}
