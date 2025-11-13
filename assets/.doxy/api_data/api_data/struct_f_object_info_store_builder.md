

# Struct FObjectInfoStoreBuilder



[**ClassList**](annotated.md) **>** [**FObjectInfoStoreBuilder**](struct_f_object_info_store_builder.md)



[More...](#detailed-description)

* `#include <ObjectInfoStore.h>`





Inherited by the following classes: [FObjectInfoStoreCopyBuilder](struct_f_object_info_store_copy_builder.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddObject**](#function-addobject-12) (const FName & Name, const TOptional&lt; FName &gt; & ParentName, const FVector & Position, const FQuat & Orientation, const bool Visibility) <br> |
|  void | [**AddObject**](#function-addobject-22) (const [**FObjectInfo**](struct_f_object_info.md) & ToCopy) <br> |
|  void | [**Build**](#function-build-12) ([**FObjectInfoStore**](struct_f_object_info_store.md) & out) <br> |
|  FORCEINLINE [**FObjectInfoStore**](struct_f_object_info_store.md) | [**Build**](#function-build-22) () <br> |
|  bool | [**Contains**](#function-contains) (const FName & Name) const<br> |
|   | [**FObjectInfoStoreBuilder**](#function-fobjectinfostorebuilder) () <br> |
|  USE\_RET bool | [**SetOrigin**](#function-setorigin) (const [**FObjectInfo**](struct_f_object_info.md) & Origin) <br> |
|  int32 | [**Size**](#function-size) () const<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  TMap&lt; FName, [**FObjectInfoTmp**](struct_f_object_info_tmp.md) &gt; | [**toAdd**](#variable-toadd)  <br> |




















## Detailed Description


Used on the first sim-tick to establish all objects' initial states. Use to update the positions for later ticks. 


    
## Public Functions Documentation




### function AddObject [1/2]

```C++
void FObjectInfoStoreBuilder::AddObject (
    const FName & Name,
    const TOptional< FName > & ParentName,
    const FVector & Position,
    const FQuat & Orientation,
    const bool Visibility
) 
```



Add an object's information to this builder, to be added to the resulting store.




**Parameters:**


* `Name` The unique identifier of this object. Each object's name must be unique, and any successive calls with an already-given name will overwrite the previous. 
* `ParentName` The unique identifier of the parent to this object. If empty, will default to .  Position The position of this object relative to the parent.  Orientation The orientation of this object relative to the parent.  Visibility Whether or not this object should be visible. 




        

<hr>



### function AddObject [2/2]

```C++
void FObjectInfoStoreBuilder::AddObject (
    const FObjectInfo & ToCopy
) 
```



Add this existing object's information, to be copied to the resulting store. 


        

<hr>



### function Build [1/2]

```C++
void FObjectInfoStoreBuilder::Build (
    FObjectInfoStore & out
) 
```



Create the ObjectInfoStore with the provided data.


Generated instances will be owned by the provided struct, with pointers to their parents within this ObjectInfoStore. This method may only be called once per builder. What we do is we first just associate all of the FNames with completely empty FObjectInfos, so we get all of the hashing and reorganizing out of the way. Now that we have a map that will never change, we can save pointers within the map. However, even though we can get the pointers, we still need to add parents before children so the children can get the right NestIndex. 


        

<hr>



### function Build [2/2]

```C++
inline FORCEINLINE FObjectInfoStore FObjectInfoStoreBuilder::Build () 
```



Create the ObjectInfoStore with the provided data.


Generated instances will be owned by the returned struct, each with pointers to their parents that are also stored within this ObjectInfoStore. This method may only be called once per builder. 


        

<hr>



### function Contains 

```C++
bool FObjectInfoStoreBuilder::Contains (
    const FName & Name
) const
```



Returns true if Name is already defined in this builder, false otherwise. 


        

<hr>



### function FObjectInfoStoreBuilder 

```C++
FObjectInfoStoreBuilder::FObjectInfoStoreBuilder () 
```



Create a new builder to construct a new ObjectInfoStore from scratch.


To only update pre-existing data, see FObjectInfoStoreCopyBuilder@endlink


        

<hr>



### function SetOrigin 

```C++
USE_RET bool FObjectInfoStoreBuilder::SetOrigin (
    const FObjectInfo & Origin
) 
```



Set the position for the new coordinate system that all positions will be based on. Must not have a parent.


Defaults to .  False if Origin is not a valid origin. 


        

<hr>



### function Size 

```C++
int32 FObjectInfoStoreBuilder::Size () const
```



Get how many items are in this builder. 


        

<hr>
## Protected Attributes Documentation




### variable toAdd 

```C++
TMap<FName, FObjectInfoTmp> FObjectInfoStoreBuilder::toAdd;
```




<hr>## Friends Documentation





### friend FObjectInfoStore 

```C++
struct FObjectInfoStoreBuilder::FObjectInfoStore (
    FObjectInfoStore
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Data/ObjectInfoStore.h`

