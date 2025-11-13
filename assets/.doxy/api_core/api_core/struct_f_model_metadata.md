

# Struct FModelMetadata



[**ClassList**](annotated.md) **>** [**FModelMetadata**](struct_f_model_metadata.md)


























## Public Attributes

| Type | Name |
| ---: | :--- |
|  TArray&lt; [**FModelComponentData**](struct_f_model_component_data.md) &gt; | [**Components**](#variable-components)  <br> |
|  FString | [**DynamicParent**](#variable-dynamicparent)  <br> |
|  FString | [**Id**](#variable-id)  <br> |
|  FQuat | [**StaticOrientation**](#variable-staticorientation)  <br> |
|  FString | [**StaticParent**](#variable-staticparent)  <br> |
|  FVector | [**StaticPosition**](#variable-staticposition)  <br> |
|  FVector | [**StaticScale**](#variable-staticscale)  <br> |
|  bool | [**bStatic**](#variable-bstatic)   = `false`<br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  FQuat | [**ConvertOrientationToUnreal**](#function-convertorientationtounreal) () const<br> |
|  FVector | [**ConvertPositionToUnreal**](#function-convertpositiontounreal) () const<br> |
|  FVector | [**ConvertScaleToUnreal**](#function-convertscaletounreal) () const<br> |




























## Public Attributes Documentation




### variable Components 

```C++
TArray<FModelComponentData> FModelMetadata::Components;
```




<hr>



### variable DynamicParent 

```C++
FString FModelMetadata::DynamicParent;
```




<hr>



### variable Id 

```C++
FString FModelMetadata::Id;
```




<hr>



### variable StaticOrientation 

```C++
FQuat FModelMetadata::StaticOrientation;
```




<hr>



### variable StaticParent 

```C++
FString FModelMetadata::StaticParent;
```




<hr>



### variable StaticPosition 

```C++
FVector FModelMetadata::StaticPosition;
```




<hr>



### variable StaticScale 

```C++
FVector FModelMetadata::StaticScale;
```




<hr>



### variable bStatic 

```C++
bool FModelMetadata::bStatic;
```




<hr>
## Public Functions Documentation




### function ConvertOrientationToUnreal 

```C++
FQuat FModelMetadata::ConvertOrientationToUnreal () const
```




<hr>



### function ConvertPositionToUnreal 

```C++
FVector FModelMetadata::ConvertPositionToUnreal () const
```




<hr>



### function ConvertScaleToUnreal 

```C++
FVector FModelMetadata::ConvertScaleToUnreal () const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/DataTypes.h`

