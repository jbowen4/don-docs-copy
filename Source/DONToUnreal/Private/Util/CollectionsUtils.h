// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <stack>

#include "CoreMinimal.h"

/**
 * Miscellaneous functions for working with collections.
 */
namespace CollectionsUtils
{
	namespace List
	{
		/**
		 * Pops and returns the first element of the linkedlist in a single operation.
		 *
		 * Returns empty if the list is empty.
		 */
		template<typename T>
		inline TOptional<T> PopHeadAndGet(std::list<T>& stack)
		{
			if (stack.empty())
				return TOptional<T>();

			auto head = TOptional<T>(MoveTempIfPossible(stack.front()));
			stack.pop_front();
			return head;
		}

		/**
		 * Searches the list sequentially, removing the first item found that matches the predicate and returning it.
		 *
		 * Returns empty if no matching item was found.
		 */
		template<typename T>
		FORCEINLINE static TOptional<T> RemoveFirstMatchingAndGet(std::list<T>& list, std::function<bool(const T&)> predicate)
		{
			for (auto iter = list.begin(), end = list.end(); iter != end; ++iter)
			{
				if (auto& current = *iter; predicate(current))
				{
					TOptional<T> owned = TOptional<T>(MoveTempIfPossible(current));
					list.erase(iter);
					return owned;
				}
			}
			return TOptional<T>();
		}
	}

	namespace Stack
	{
		/**
		 * Pops and returns the top element of a stack in a single operation. Returns empty if the stack is empty.
		 */
		template<typename T>
		TOptional<T> PopHeadAndGet(std::stack<T>& stack)
		{
			if (stack.empty())
				return TOptional<T>();

			auto head = TOptional(MoveTempIfPossible(stack.top()));
			stack.pop();
			return head;
		}
	}

	namespace Map
	{
		/**
		 * If the value is present, returns a reference to it.
		 * If the value is absent, calls the provided function with signature `V()` to generate the value.
		 *
		 * @tparam _Factory Creater of the new value.  Returns V and accepts no params.
		 */
		template<typename K, typename V, typename _Factory, std::enable_if_t<std::is_invocable_r_v<V, _Factory>, int> = 0>
		FORCEINLINE V& computeIfAbsent(TMap<K, V>& map, const K& key, const _Factory computer)
		{
			if (V* fromMap = map.Find(key); fromMap != nullptr)
			{
				return *fromMap;
			}
			else
			{
				return map.Add(key, computer());
			}
		}
	}
};
