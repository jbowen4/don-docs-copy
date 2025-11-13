

# File ObjectInfo.h



[**FileList**](files.md) **>** [**Data**](dir_436819c72972a51f013170f2c377a0ea.md) **>** [**ObjectInfo.h**](_object_info_8h.md)

[Go to the source code of this file](_object_info_8h_source.md)



* `#include "CoreMinimal.h"`
* `#include "RelativePosition.h"`
* `#include "Util/Types/TOptRef.h"`
* `#include "ObjectInfo.generated.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**FObjectInfo**](struct_f_object_info.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef FName | [**ObjID**](#typedef-objid)  <br> |















































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**\_WITH**](_object_info_8h.md#define-_with) (\_varType, \_varName) `[**FObjectInfo**](struct_f_object_info.md) With##\_varName(TCallTraits&lt;\_varType&gt;::ParamType New##\_varName)`<br> |

## Public Types Documentation




### typedef ObjID 

```C++
using ObjID =  FName;
```




<hr>
## Macro Definition Documentation





### define \_WITH 

```C++
#define _WITH (
    _varType,
    _varName
) `FObjectInfo With##_varName(TCallTraits<_varType>::ParamType New##_varName)`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Data/ObjectInfo.h`

