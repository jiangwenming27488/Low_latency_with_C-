#pragma once 

#include "common/types.h"
#include "common/lf_queue.h"

using namespace Common; 

namespace Exchange
{
	/*First, we will define a "ClientReponseType" enumeration to represent the type of response for client orders. 
	 * In addition to the "INVALID" sentinel value, it contains values that represent when a request for a new order is accepted, an order is canceled, and order is executed, or a cancel request is rejected by the matching engine
	 * We also add the "clientResponseTypeToString()" method to convert the "ClientResponseType" values to strings:*/
#pragma(push, 1)
	enum class ClientResponseType : uint8_t
	{
		INVALID = 0, 
		ACCEPTED = 1, 
		CANCELED = 2, 
		FILLED = 3, 
		CANCEL_REJECTED = 4
	}; 

	inline std::string clientResponseTypeToString(ClientResponseType type)
	{
		switch (type)
		{
			case ClientResponseType::ACCEPTED: 
				return "ACCEPTED"; 
			case ClientResponseType::CANCELED: 
				return "CANCELTED"; 
			case ClientResponseType::FILLED: 
				return "FILLED"; 
			case ClientResponseType::CANCEL_REJECTED: 
				return "CANCEL_REJECTED"; 
			case ClientResponseType::INVALID: 
				return "INVALID"; 
		}
		return "UNKNOWN"; 
	}
	
	struct MEClientResponse
	{
		ClientResponseType type_ = ClientResponseType::INVALID; 
		ClientId client_id_ = ClientId_INVALID; 
		TickerId ticker_id_ = TickerId_INVALID; 
		OrderId client_order_id_ = OrderId_INVALID; 
		OrderId market_order_id_ = OrderId_INVALID; 
		Side side_ = Side::INVALID; 
		Price price_ = Price_INVALID; 
		Qty exec_qty_ = Qty_INVALID; 
		Qty leaves_qty_ = Qty_INVALID; 

		auto toString() const 
		{
			ss << "MEClientResponse" << " [" << "type:" << clientResponseTypeToString(type_) << " client:" << clientIdToString(client_id_) << " ticker:" << tickerIdToString(ticker_id_) << " coid:" << orderIdToString(client_order_id_) << " moid:" << orderIdToString(market_order_id_) << " side:" << sideToString(side_) << " exec_qty:" << qtyToString(exec_qty_) << " leaves_qty:" << qtyToString(leaves_qty_) << " price:" << priceToString(price_) << "]"; 
			return ss.str(); 
		}
	}; 
#pragma pack(pop)

typedef LFQueue<MEClientResponse> ClinetResponseLFQueue; 
}
