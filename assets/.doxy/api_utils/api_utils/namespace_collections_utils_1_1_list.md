

# Namespace CollectionsUtils::List



[**Namespace List**](namespaces.md) **>** [**CollectionsUtils**](namespace_collections_utils.md) **>** [**List**](namespace_collections_utils_1_1_list.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|  TOptional&lt; T &gt; | [**PopHeadAndGet**](#function-popheadandget) (std::list&lt; T &gt; & stack) <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  FORCEINLINE TOptional&lt; T &gt; | [**RemoveFirstMatchingAndGet**](#function-removefirstmatchingandget) (std::list&lt; T &gt; & list, std::function&lt; bool(const T &)&gt; predicate) <br> |


























## Public Functions Documentation




### function PopHeadAndGet 

```C++
template<typename T>
inline TOptional< T > CollectionsUtils::List::PopHeadAndGet (
    std::list< T > & stack
) 
```



Pops and returns the first element of the linkedlist in a single operation.


Returns empty if the list is empty. 


        

<hr>
## Public Static Functions Documentation




### function RemoveFirstMatchingAndGet 

```C++
template<typename T>
static FORCEINLINE TOptional< T > CollectionsUtils::List::RemoveFirstMatchingAndGet (
    std::list< T > & list,
    std::function< bool(const T &)> predicate
) 
```



Searches the list sequentially, removing the first item found that matches the predicate and returning it.


Returns empty if no matching item was found. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Private/Util/CollectionsUtils.h`

