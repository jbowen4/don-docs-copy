

# File CollectionsUtils.h

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Private**](dir_2c3ab2caebe6f83b4fac8c870e601c85.md) **>** [**Util**](dir_3a690fa77d5963354acc6a5ac4ebb1d1.md) **>** [**CollectionsUtils.h**](_collections_utils_8h.md)

[Go to the documentation of this file](_collections_utils_8h.md)


```C++
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <stack>

#include "CoreMinimal.h"

namespace CollectionsUtils
{
    namespace List
    {
        template<typename T>
        inline TOptional<T> PopHeadAndGet(std::list<T>& stack)
        {
            if (stack.empty())
                return TOptional<T>();

            auto head = TOptional<T>(MoveTempIfPossible(stack.front()));
            stack.pop_front();
            return head;
        }

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
```


