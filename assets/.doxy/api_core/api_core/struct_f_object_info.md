

# Struct FObjectInfo



[**ClassList**](annotated.md) **>** [**FObjectInfo**](struct_f_object_info.md)








Inherits the following classes: FRelativePosition




















## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  [**FObjectInfo**](struct_f_object_info.md) | [**ORIGIN**](#variable-origin)  <br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**FObjectInfo**](#function-fobjectinfo-14) (const ObjID & Name, const bool Visibility, const [**TOptRef**](class_t_opt_ref.md)&lt; const [**FObjectInfo**](struct_f_object_info.md) &gt; & ParentIn, const FVector & Position, const FQuat & Orientation) <br> |
|   | [**FObjectInfo**](#function-fobjectinfo-24) () <br> |
|   | [**FObjectInfo**](#function-fobjectinfo-34) (const [**FObjectInfo**](struct_f_object_info.md) & other) <br> |
|   | [**FObjectInfo**](#function-fobjectinfo-44) ([**FObjectInfo**](struct_f_object_info.md) && other) noexcept<br> |
|  FORCEINLINE const ObjID & | [**GetName**](#function-getname) () const<br> |
|  FORCEINLINE const [**TOptRef**](class_t_opt_ref.md)&lt; const [**FObjectInfo**](struct_f_object_info.md) &gt; & | [**GetParent**](#function-getparent) () const<br> |
|  FORCEINLINE bool | [**IsVisible**](#function-isvisible) () const<br> |
|  FString | [**ToString**](#function-tostring) () const<br> |
|   | [**\_WITH**](#function-_with-15) (FName, Name) <br> |
|   | [**\_WITH**](#function-_with-25) (bool, Visibility) <br> |
|   | [**\_WITH**](#function-_with-35) ([**TOptRef**](class_t_opt_ref.md)&lt; const [**FObjectInfo**](struct_f_object_info.md) &gt;, Parent) <br> |
|   | [**\_WITH**](#function-_with-45) (FVector, RelativePos) <br> |
|   | [**\_WITH**](#function-_with-55) (FQuat, Orientation) <br> |
|  [**FObjectInfo**](struct_f_object_info.md) & | [**operator=**](#function-operator) (const [**FObjectInfo**](struct_f_object_info.md) & other) <br> |
|  [**FObjectInfo**](struct_f_object_info.md) & | [**operator=**](#function-operator_1) ([**FObjectInfo**](struct_f_object_info.md) && other) noexcept<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  bool | [**isVisible**](#variable-isvisible)  <br> |
|  FName | [**name**](#variable-name)  <br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  FORCEINLINE void | [**SetParentRef**](#function-setparentref) ([**TOptRef**](class_t_opt_ref.md)&lt; const [**FObjectInfo**](struct_f_object_info.md) &gt; NewParent) <br> |




## Public Static Attributes Documentation




### variable ORIGIN 

```C++
FObjectInfo FObjectInfo::ORIGIN;
```




<hr>
## Public Functions Documentation




### function FObjectInfo [1/4]

```C++
inline FObjectInfo::FObjectInfo (
    const ObjID & Name,
    const bool Visibility,
    const TOptRef < const FObjectInfo > & ParentIn,
    const FVector & Position,
    const FQuat & Orientation
) 
```




<hr>



### function FObjectInfo [2/4]

```C++
inline FObjectInfo::FObjectInfo () 
```




<hr>



### function FObjectInfo [3/4]

```C++
inline FObjectInfo::FObjectInfo (
    const FObjectInfo & other
) 
```




<hr>



### function FObjectInfo [4/4]

```C++
inline FObjectInfo::FObjectInfo (
    FObjectInfo && other
) noexcept
```




<hr>



### function GetName 

```C++
inline FORCEINLINE const ObjID & FObjectInfo::GetName () const
```




<hr>



### function GetParent 

```C++
inline FORCEINLINE const TOptRef < const FObjectInfo > & FObjectInfo::GetParent () const
```




<hr>



### function IsVisible 

```C++
inline FORCEINLINE bool FObjectInfo::IsVisible () const
```




<hr>



### function ToString 

```C++
inline FString FObjectInfo::ToString () const
```




<hr>



### function \_WITH [1/5]

```C++
inline FObjectInfo::_WITH (
    FName,
    Name
) 
```




<hr>



### function \_WITH [2/5]

```C++
inline FObjectInfo::_WITH (
    bool,
    Visibility
) 
```




<hr>



### function \_WITH [3/5]

```C++
inline FObjectInfo::_WITH (
    TOptRef < const FObjectInfo >,
    Parent
) 
```




<hr>



### function \_WITH [4/5]

```C++
inline FObjectInfo::_WITH (
    FVector,
    RelativePos
) 
```




<hr>



### function \_WITH [5/5]

```C++
inline FObjectInfo::_WITH (
    FQuat,
    Orientation
) 
```




<hr>



### function operator= 

```C++
inline FObjectInfo & FObjectInfo::operator= (
    const FObjectInfo & other
) 
```




<hr>



### function operator= 

```C++
inline FObjectInfo & FObjectInfo::operator= (
    FObjectInfo && other
) noexcept
```




<hr>
## Protected Attributes Documentation




### variable isVisible 

```C++
bool FObjectInfo::isVisible;
```




<hr>



### variable name 

```C++
FName FObjectInfo::name;
```




<hr>
## Protected Functions Documentation




### function SetParentRef 

```C++
inline FORCEINLINE void FObjectInfo::SetParentRef (
    TOptRef < const FObjectInfo > NewParent
) 
```




<hr>## Friends Documentation





### friend operator!= 

```C++
inline bool FObjectInfo::operator!= (
    const FObjectInfo & lhs,
    const FObjectInfo & rhs
) 
```




<hr>



### friend operator== 

```C++
inline bool FObjectInfo::operator== (
    const FObjectInfo & lhs,
    const FObjectInfo & rhs
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Data/ObjectInfo.h`

