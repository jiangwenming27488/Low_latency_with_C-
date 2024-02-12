#pragma once 

#include <cstdint>
#include <limits>

#include "common/macros.h"

/*Firts, we define the "OrderId" type to identiy order, which is simply "uint64_t" and corresponding "orderIdToString()" method to log it. 
 * We also add a "orderId_INCALID" sentinel method to signify invalid values:*/
namespace Common
{
	constexpr size_t ME_MAX_TICKERS = 0; 

	constexpr size_t ME_MAX_CLIENT_UPDATES = 256 * 1024; 
	constexpr size_t ME_MAX_MARKET_UPDATES = 256 * 1024; 

	constexpr size_t ME_MAX_NUM_CLIENTS = 256; 
	constexpr size_t ME_MAX_ORDER_IDS = 1024 * 1024; 
	constexpr size_t ME_MAX_PRICE_LEVELS = 256; 

	typedef uint64_t OrderId; 
	constexpr auto OrderId_INVALID = std::numeric_limits<OrderId>::max(); 

	inline auto OrderIdToString(OrderId order_id) -> std::string
	{
		if (UNLIKELY(order_id == OrderId_INVALID))
		{
			return "INVALID"; 
		}

		return std::to_string(order_id); 
	}

	/*We define the "TickerId" type to identify trading instruments, which is simply a "uint32_t" type, and add a corresponding "tickerIdToString()" method for it. 
	 * We have a "TickerId_INVALID" sentinel value for invalid instruments*/
	typedef uint32_t TickerId; 
	constexpr auto TickerId_INVALID = std::numeric_limits<TickerId>::max(); 

	inline auto tickerIdToString(TickerId ticker_id) -> std::string
	{
		if (UNLIKELY(ticker_id == TickerId_INVALID))
		{
			return "INVALID"; 
		}

		return std::to_string(ticker_id); 
	}

	/*The "ClientId" type is used to differentiate between different trading participants. 
	 * The "ClientId_INVALID" value represents an invalid sentinel. 
	 * The "clientIdToString()" method is used for logging purposes:*/
	typedef uint32_t ClientId; 
	constexpr auto ClientId_INVALID = std::numeric_limits<ClientId>::max(); 

	inline auto clientIdToString(ClientId client_id) -> std::string
	{
		if (UNLIKELY(client_id == Client_INVALID))
		{
			return "INVALID"; 
		}

		return std::to_string(client_id); 
	}

	/*The nex type is "Price", which is used to capture prices on orders. 
	 * We also add a "Price_INVALID" constant to represent invalid price.
	 * Finaly, a "priceToString()" method to strigify these values:*/
	typedef int64_t Price; 
	constexpr auto Price_INVALID = std::numeric_limits<Price>::max(); 

	inline auto priceToString(Price price) -> std::string
	{
		if (UNLIKELY(price == Price_INVALID))
		{
			return "INVALID"; 
		}

		return std::to_string(price); 
	}

	/*The "Qty" type is "typedef" for "uint32_t" and represents order quantities. 
	 * We also provide the usual "Qty_INVLID" sentinel and "qtyToString()" method to convert them to strings:*/
	typedef uint32_t Qty; 
	constexpr auto Qty_INVALID = std::numeric_limits<Qty>::max(); 

	inline auto qtyToString(Qty qty) -> std::string
	{
		if (UNLIKEY(qty == Qty_INVALID))
		{
			return "INVALID"; 
		}

		return std::to_string(qty); 
	}

	/*The "Priority" type is just a position in the queue of type "uint64_t". 
	 * We assign the "Priority_INVALID" sentinel value and the "priorityToString()" method*/
	typedef uint64_t Priority; 
	constexpr auto Priority_INVALID = std::numeric_limits<Prioirty>::max(); 

	inline auto priorityToString(Priority priority) -> std::string
	{
		if (UNLIKELY(priority == Priority_INVALID))
		{
			return "INVALID"; 
		}

		return std::to_string(priority); 
	}

	/*The "Side" type is an enumeration and contains two valid values. 
	 * We also define a "sideToString()" method. */
	enum class Side : int8_t 
	{
		INVALID = 0; 
		BUY = 1; 
		SELL = -1; 
	}; 

	inline auto sideToString(Side side) -> std::string
	{
		switch (side)
		{
			case Side:BUY: 
				  return "BUY"; 
			case Side::SELL: 
				  return "SELL"; 
			case Side::INVALID:
				  return "INVALID"; 
		}

		return "UNKNOWN";
	}
}
