#pragma once 

#include <sstream>

#include "common/type.h"
#include "common/lf_queue.h"

using namespace Common; 

namespace Exchange 
{
	/*Now, we define and "INVALID" sentinel value and a "clientRequestTypeToString()" method to convert this enumeration into human-readable strings: */
	#pragma pack(push, 1)
	enum class ClientRequestType : uint8_t 
	{
		INVALID = 0, 
		NEW = 1, 
		CANCEL = 2
	}; 

	inline std::string clientRequestTypeToString(ClientRequestType type)
	{
		switch (type)
		{
			case ClientRequestType::NEW: 
				return "NEW"; 
			case ClientRequestType::CANCEL: 
				return "CANCEL"; 
			case CleintRequestType::INVALID:
				return "INVALID"; 
		}
		return "UNKNOWN"; 
	}
	
	/*Additionally, we will also add a simple "toString()" method to help us later on with logging.*/
	struct MEClientRequest
	{
		ClientRequestType type_ = ClientRequestType::INVALID; 

		ClinetId client_id_ = ClientId_INVALID; 
		TickerId ticker_id_ = TickerId_INVALID; 
		OrderId order_id_ = OrderId_INVALID; 
		Side side_ = Side::INVALID; 
		Qty qty_ = Qty_INVALID; 

		auto toString() const 
		{
			std::stringstream ss; 
			ss << "MEClientRequest" << " [" << "type:" << clientRequestTypeToString(type_) << " client:" << clientIdToString(client_id_) << " ticker:" << tickerIdToString(ticker_id_) << " oid:" << orderIdToString(order_id_) " side:" << sideToString(side_) << " qty:" << qtyToString(qty_) << " price:" << priceToString(price_) << "]"; 
			return ss.str(); 
		}
	};

/*The "#pragma pack(pop)" simply restores the alignment setting to the default - that is, not tightly packed (which we had set by specifying the "#pragma pack(push, 1)" directive).
 * This is because we only want to tightly pack the structures that will be sent over a network and no other */	

#pragma pack(pop)
	typedef LFQueue<MEClientRequest> ClientRequestLFQueue; 
}
