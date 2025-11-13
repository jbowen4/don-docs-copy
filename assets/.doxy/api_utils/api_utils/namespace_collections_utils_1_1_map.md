

# Namespace CollectionsUtils::Map



[**Namespace List**](namespaces.md) **>** [**CollectionsUtils**](namespace_collections_utils.md) **>** [**Map**](namespace_collections_utils_1_1_map.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|  FORCEINLINE V & | [**computeIfAbsent**](#function-computeifabsent) (TMap&lt; K, V &gt; & map, const K & key, const \_Factory computer) <br> |




























## Public Functions Documentation




### function computeIfAbsent 

```C++
template<typename K, typename V, typename _Factory, std::enable_if_t< std::is_invocable_r_v< V, _Factory >, int >>
FORCEINLINE V & CollectionsUtils::Map::computeIfAbsent (
    TMap< K, V > & map,
    const K & key,
    const _Factory computer
) 
```



If the value is present, returns a reference to it. If the value is absent, calls the provided function with signature `V()` to generate the value.




**Template parameters:**


* `_Factory` Creater of the new value. Returns V and accepts no params. 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Private/Util/CollectionsUtils.h`

