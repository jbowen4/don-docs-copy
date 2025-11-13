

# Struct FObjectInfoStoreCopyBuilder



[**ClassList**](annotated.md) **>** [**FObjectInfoStoreCopyBuilder**](struct_f_object_info_store_copy_builder.md)



[More...](#detailed-description)

* `#include <ObjectInfoStore.h>`



Inherits the following classes: [FObjectInfoStoreBuilder](struct_f_object_info_store_builder.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**FObjectInfoStoreCopyBuilder**](#function-fobjectinfostorecopybuilder-12) () <br> |
|   | [**FObjectInfoStoreCopyBuilder**](#function-fobjectinfostorecopybuilder-22) (const [**FObjectInfoStore**](struct_f_object_info_store.md) & CopyFrom) <br> |
|  bool | [**UpdateInfo**](#function-updateinfo) (const FName & Name, TOptRef&lt; TOptional&lt; FName &gt; &gt; ParentName, TOptRef&lt; const FVector &gt; Position, TOptRef&lt; const FQuat &gt; Orientation, TOptional&lt; bool &gt; Visibility) <br> |


## Public Functions inherited from FObjectInfoStoreBuilder

See [FObjectInfoStoreBuilder](struct_f_object_info_store_builder.md)

| Type | Name |
| ---: | :--- |
|  void | [**AddObject**](struct_f_object_info_store_builder.md#function-addobject-12) (const FName & Name, const TOptional&lt; FName &gt; & ParentName, const FVector & Position, const FQuat & Orientation, const bool Visibility) <br> |
|  void | [**AddObject**](struct_f_object_info_store_builder.md#function-addobject-22) (const [**FObjectInfo**](struct_f_object_info.md) & ToCopy) <br> |
|  void | [**Build**](struct_f_object_info_store_builder.md#function-build-12) ([**FObjectInfoStore**](struct_f_object_info_store.md) & out) <br> |
|  FORCEINLINE [**FObjectInfoStore**](struct_f_object_info_store.md) | [**Build**](struct_f_object_info_store_builder.md#function-build-22) () <br> |
|  bool | [**Contains**](struct_f_object_info_store_builder.md#function-contains) (const FName & Name) const<br> |
|   | [**FObjectInfoStoreBuilder**](struct_f_object_info_store_builder.md#function-fobjectinfostorebuilder) () <br> |
|  USE\_RET bool | [**SetOrigin**](struct_f_object_info_store_builder.md#function-setorigin) (const [**FObjectInfo**](struct_f_object_info.md) & Origin) <br> |
|  int32 | [**Size**](struct_f_object_info_store_builder.md#function-size) () const<br> |
















## Protected Attributes inherited from FObjectInfoStoreBuilder

See [FObjectInfoStoreBuilder](struct_f_object_info_store_builder.md)

| Type | Name |
| ---: | :--- |
|  TMap&lt; FName, [**FObjectInfoTmp**](struct_f_object_info_tmp.md) &gt; | [**toAdd**](struct_f_object_info_store_builder.md#variable-toadd)  <br> |






































## Detailed Description


Creates an ObjectInfoStore based on the values from a previously-defined ObjectInfoStore. 


    
## Public Functions Documentation




### function FObjectInfoStoreCopyBuilder [1/2]

```C++
inline FObjectInfoStoreCopyBuilder::FObjectInfoStoreCopyBuilder () 
```




<hr>



### function FObjectInfoStoreCopyBuilder [2/2]

```C++
explicit FObjectInfoStoreCopyBuilder::FObjectInfoStoreCopyBuilder (
    const FObjectInfoStore & CopyFrom
) 
```



Create a new ObjectInfoStore builder with the initial values from the provided store.


Add everything from the original store to this builder, to potentially be overwritten by calls to later. 


        

<hr>



### function UpdateInfo 

```C++
bool FObjectInfoStoreCopyBuilder::UpdateInfo (
    const FName & Name,
    TOptRef< TOptional< FName > > ParentName,
    TOptRef< const FVector > Position,
    TOptRef< const FQuat > Orientation,
    TOptional< bool > Visibility
) 
```



Add information to an object by name. The object may or may not already have data from the copy constructor, hence why every parameter is optional. This is why C++ needs optional arguments...


If the object has not already been added to this builder, a new object will be queued. Else the information provided will be overlaid over the EXISTING entry with this name.


For example, `Builder(storeWithEarth). AddObject (Earth, TOptRef(), FVector(0,1,2), TOptRef(), TOptional())` will keep all information from "storeWithEarth &gt; Earth", but replace its position with FVector(0,1,2).




**Parameters:**


* `Name` 
* `ParentName` If the Reference is empty, that means you don't wish to overwrite the existing data. If the internal Optional is empty, that means the parent is the ORIGIN. 
* `Position` 
* `Orientation` 
* `Visibility` 



**Returns:**

True if data was set successfully. False when Name does not exist in this builder (and by extension the copied-from ObjectInfoStore). 





        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Data/ObjectInfoStore.h`

