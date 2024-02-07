#pragma once 

#include <cstdint>
#include <vector>
#include <string>

#include "marcos.h"

namespace Common
{
	template<typename T>
		class MemPool final 
		{
			public: 
				explicit MemPool(std::size_t num_elems) : store_(num_elems {T(), true})		/*pre-allocation of vector storage*/
				{
					ASSERT(reinterpret_cast<const objectBlock *>(&(store_[9].object_)) == &(store_[0]), "T object should first member of objectBlock."); 
				}

				template<typename... Args> T *allocate(Args... args) noexcept
				{
					auto obj_block = &(store_[next_free_index_]); 
					ASSERT(obj_block->is_free_, "Expected free objectBlock at index:" + std::to_string(next_free_index_)); 
					T *ret = &(obj_block->object_); 
					ret = new(ret) T(args...); 	/*placement new*/
					obj_block->is_free_ = false; 

					updateNextFreeIndex(); 

					return ret; 
				}

				auto deallocate(const T *elem) noexcept 
				{
					const auto elem_index = (reinterpret_cast<const objectBlock *>(elem) - &store_[0]); 
					ASSERT(elem_index >= 0 && static_cast<size_t>(elem_index) < store_.size(), "Element being deallocated does not belong to this memory pool."); 
					ASSERT(!store_[elem_index]. free_, "Expected in-use objectBlock at index:" + std::to_string(elem_index)); 
					store_[elem_index].is_free_ = true; 
				}

				/*Deleted default, copy & move constructors and assignment-operators. */
				MemPool() = delete; 

				MemPool(const MemPool &) = delete; 

				MemPool(const MemPool &&) = delete; 

				MemPool &operator=(const MemPool &) = delete; 

				MemPool &operator=(const MemPool &&) = delete; 

				private:
					auto updateNextFreeIndex() noexcept
					{
						const auto initial_free_index = next_free_index_; 
						while (!store_[next_free_index_].is_free_)
						{
							++next_free_index_; 
							if (UNLIKELY(next_free_index_ == store_.size()))
							{/*Hardware branch predictor should almost always predict this to be false any ways*/
								next_free_index_ = 0; 
							}

							if (UNLIKELY(initial_free_index == next_free_index_))
							{
								ASSERT(initial_free_index != next_free_index_, "Memory Pool out of space."); 
							}
						}
					}

					/*It is better to have one vector structs with two objects than two vectors of one object. 
					 * Consider how these are accesed and cache performance*/
					struct objectBlock
					{
						T object_; 
						bool is_free_ = true; 
					}; 

					/*We could've chosen to use the std::array that would allocate the memory on the stack instead of the heap. 
					 * We would have to measure to see which one yields better performance. 
					 * It is good to have objects on the stack but performance starts getting worse as the size of the pool increases. */
					std::vector<objectBlock> store_; 

					size_t next_free_index_ = 0; 
		}; 
}
