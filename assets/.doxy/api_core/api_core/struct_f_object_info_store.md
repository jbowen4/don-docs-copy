

# Struct FObjectInfoStore



[**ClassList**](annotated.md) **>** [**FObjectInfoStore**](struct_f_object_info_store.md)



[More...](#detailed-description)

* `#include <ObjectInfoStore.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**FObjectInfoStore**](#function-fobjectinfostore-14) () <br>_Default/empty constructor._  |
|   | [**FObjectInfoStore**](#function-fobjectinfostore-24) (const [**FObjectInfo**](struct_f_object_info.md) & Origin) <br> |
|   | [**FObjectInfoStore**](#function-fobjectinfostore-34) (const [**FObjectInfoStore**](struct_f_object_info_store.md) & copyFrom) <br>_Copy constructor._  |
|   | [**FObjectInfoStore**](#function-fobjectinfostore-44) ([**FObjectInfoStore**](struct_f_object_info_store.md) && other) noexcept<br> |
|   | [**GETTER**](#function-getter) ([**FObjectInfo**](struct_f_object_info.md), Origin) <br> |
|  [**TOptRef**](class_t_opt_ref.md)&lt; const [**FObjectInfo**](struct_f_object_info.md) &gt; | [**Get**](#function-get) (const FName & Name) const<br> |
|  void | [**Keys**](#function-keys-12) (TArray&lt; FName &gt; & Out) const<br> |
|  FORCEINLINE TArray&lt; FName &gt; | [**Keys**](#function-keys-22) () const<br> |
|  int32 | [**Size**](#function-size) () const<br> |
|  FString | [**ToString**](#function-tostring) () const<br> |
|  [**FObjectInfoStore**](struct_f_object_info_store.md) & | [**operator=**](#function-operator) (const [**FObjectInfoStore**](struct_f_object_info_store.md) & other) <br> |
|  [**FObjectInfoStore**](struct_f_object_info_store.md) & | [**operator=**](#function-operator_1) ([**FObjectInfoStore**](struct_f_object_info_store.md) && other) noexcept<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**FObjectInfoStoreBuilder**](struct_f_object_info_store_builder.md) | [**Builder**](#function-builder) () <br> |
|  [**FObjectInfoStoreCopyBuilder**](struct_f_object_info_store_copy_builder.md) | [**CopyBuilder**](#function-copybuilder) (const [**FObjectInfoStore**](struct_f_object_info_store.md) & CopyFrom) <br> |


























## Detailed Description


Stores the data (position, orientation, visibility, and parent) for every object in the simulation at a time step. 


    
## Public Functions Documentation




### function FObjectInfoStore [1/4]

_Default/empty constructor._ 
```C++
FObjectInfoStore::FObjectInfoStore () 
```




<hr>



### function FObjectInfoStore [2/4]

```C++
explicit FObjectInfoStore::FObjectInfoStore (
    const FObjectInfo & Origin
) 
```



Creates an ObjectInfoStore with the provided origin. 

**Parameters:**


* `Origin` The basis for this coordinate system, which all objects' positions will be relative to. 




        

<hr>



### function FObjectInfoStore [3/4]

_Copy constructor._ 
```C++
FObjectInfoStore::FObjectInfoStore (
    const FObjectInfoStore & copyFrom
) 
```




<hr>



### function FObjectInfoStore [4/4]

```C++
inline FObjectInfoStore::FObjectInfoStore (
    FObjectInfoStore && other
) noexcept
```




<hr>



### function GETTER 

```C++
FObjectInfoStore::GETTER (
    FObjectInfo,
    Origin
) 
```



Get the origin for this coordinate system that objects' positions are based on.


Current implementation is always . 


        

<hr>



### function Get 

```C++
TOptRef < const FObjectInfo > FObjectInfoStore::Get (
    const FName & Name
) const
```



Get the object info for the given name, or empty if that object does not exist in this store. 


        

<hr>



### function Keys [1/2]

```C++
void FObjectInfoStore::Keys (
    TArray< FName > & Out
) const
```



Get a list of all object names in this store.




**Parameters:**


* `Out` Upon return, contains the set of unique keys in this store. 




        

<hr>



### function Keys [2/2]

```C++
inline FORCEINLINE TArray< FName > FObjectInfoStore::Keys () const
```



Returns a list of all object names in this store. 


        

<hr>



### function Size 

```C++
int32 FObjectInfoStore::Size () const
```



How many objects are in this store. 


        

<hr>



### function ToString 

```C++
FString FObjectInfoStore::ToString () const
```



Returns a string representation of this object. 


        

<hr>



### function operator= 

```C++
inline FObjectInfoStore & FObjectInfoStore::operator= (
    const FObjectInfoStore & other
) 
```




<hr>



### function operator= 

```C++
inline FObjectInfoStore & FObjectInfoStore::operator= (
    FObjectInfoStore && other
) noexcept
```




<hr>
## Public Static Functions Documentation




### function Builder 

```C++
static FObjectInfoStoreBuilder FObjectInfoStore::Builder () 
```



Get a builder to create an [**FObjectInfoStore**](struct_f_object_info_store.md) from scratch. 


        

<hr>



### function CopyBuilder 

```C++
static FObjectInfoStoreCopyBuilder FObjectInfoStore::CopyBuilder (
    const FObjectInfoStore & CopyFrom
) 
```



Get a builder for a new [**FObjectInfoStore**](struct_f_object_info_store.md) populated with the values from another [**FObjectInfoStore**](struct_f_object_info_store.md). 


        

<hr>## Friends Documentation





### friend FObjectInfoStoreBuilder 

```C++
struct FObjectInfoStore::FObjectInfoStoreBuilder (
    FObjectInfoStoreBuilder
) 
```




<hr>



### friend FObjectInfoStoreCopyBuilder 

```C++
struct FObjectInfoStore::FObjectInfoStoreCopyBuilder (
    FObjectInfoStoreCopyBuilder
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Data/ObjectInfoStore.h`

