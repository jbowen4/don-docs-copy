

# Struct FObjectInfoTmp



[**ClassList**](annotated.md) **>** [**FObjectInfoTmp**](struct_f_object_info_tmp.md)


























## Public Attributes

| Type | Name |
| ---: | :--- |
|  FName | [**Name**](#variable-name)  <br> |
|  FQuat | [**Orientation**](#variable-orientation)  <br> |
|  TOptional&lt; FName &gt; | [**ParentName**](#variable-parentname)  <br> |
|  FVector | [**Position**](#variable-position)  <br> |
|  bool | [**Visibility**](#variable-visibility)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**FObjectInfoTmp**](#function-fobjectinfotmp-12) (const FName & name, const TOptional&lt; FName &gt; & parent\_name, const FVector & position, const FQuat & orientation, const bool visibility) <br> |
|   | [**FObjectInfoTmp**](#function-fobjectinfotmp-22) () <br> |
|  FString | [**ToString**](#function-tostring) () const<br> |
|   | [**~FObjectInfoTmp**](#function-fobjectinfotmp) () <br> |




























## Public Attributes Documentation




### variable Name 

```C++
FName FObjectInfoTmp::Name;
```




<hr>



### variable Orientation 

```C++
FQuat FObjectInfoTmp::Orientation;
```




<hr>



### variable ParentName 

```C++
TOptional<FName> FObjectInfoTmp::ParentName;
```




<hr>



### variable Position 

```C++
FVector FObjectInfoTmp::Position;
```




<hr>



### variable Visibility 

```C++
bool FObjectInfoTmp::Visibility;
```




<hr>
## Public Functions Documentation




### function FObjectInfoTmp [1/2]

```C++
inline FObjectInfoTmp::FObjectInfoTmp (
    const FName & name,
    const TOptional< FName > & parent_name,
    const FVector & position,
    const FQuat & orientation,
    const bool visibility
) 
```




<hr>



### function FObjectInfoTmp [2/2]

```C++
inline FObjectInfoTmp::FObjectInfoTmp () 
```




<hr>



### function ToString 

```C++
FString FObjectInfoTmp::ToString () const
```




<hr>



### function ~FObjectInfoTmp 

```C++
inline FObjectInfoTmp::~FObjectInfoTmp () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Data/ObjectInfoStore.h`

