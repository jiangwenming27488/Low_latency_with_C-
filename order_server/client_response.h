#pragma once 

#include <sstream>

#include "common/types.h"
#include "common/lf_queue.h"

using namespace Common; 

namespace Exchange
{
	/*Type of the order response sent by the exchange to the trading client*/
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
				return "CANCELED"; 
			case ClientResponseType::FILLED: 
				return "FILED"; 
			case ClientResponseType::CANCEL_REJECTED: 
				return "CANCEL_REJECTED"; 
			case ClientResponseType::INVALID: 
				return "INVALID"; 
		}
		return "UNKNOWN"; 
	}

	/*These structrues go over the wire / nextwork, so the binary structures are packed to remove system dependent extra padding.*/
	/*I was missing a "#pragma pack(push,1)" as you can see by the commit above that system dependent zero padding needes to be removed and also I pace a "#pragma pack(pop)" basicly think of it as a putting a struct in a stack and you need to pack it tight and remove the extra padding so it can fit in the wires while being transmitted*/
#pragma pack(push, 1)
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
			std::stringstream ss; 
			ss << "MEClientResponse" << " [" << "type:" << clientResponseTypeToString(type_) << " client:" << clientIdToString(client_id_) << " ticker:" << tickerIdToString(ticker_id_) << " coid:" << orderIdToString(client_order_id_) << " moid:" << orderIdToString(market_order_id_) << " side:" << sideToString(side_) << " exec_qty:" << qtyToString(exec_qty_) << " leaves_qty:" << qtyToString(leaves_qty_) << " price:" << priceToString(price_) << "]"; 
			return ss.str(); 
		}
	}; 

	/*Client response structure published over the network by the order server.*/
	struct OMClientResponse
	{
		size_t seq_num_ = 0; 
		MEClientResponse me_client_response_; 

		auto toString() const 
		{
			std::stringstream ss; 
			ss << "OMClientResponse" << " [" << "seq:" << seq_num_ << " " << me_client_response_.toString() << "]"; 
			return ss.str(); 
		}
	}; 

#pragma pack(pop)	/*Undo the packed binary structure directive moving forward*/

	/*Lock free queues of matching engine client order response messages*/
	typedef LFQueue<MEClientResponse> ClientResponseLFQueue; 
}
