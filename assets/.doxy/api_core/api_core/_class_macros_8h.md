

# File ClassMacros.h



[**FileList**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Public**](dir_c336ec6675be099178e02bcdcfb186ce.md) **>** [**Util**](dir_91e92cab0a0b5df2370f6d3ddd515cf6.md) **>** [**ClassMacros.h**](_class_macros_8h.md)

[Go to the source code of this file](_class_macros_8h_source.md)



































































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**GETTER**](_class_macros_8h.md#define-getter) (fieldType, fieldName) `USE\_RET FORCEINLINE const fieldType& Get##fieldName() const noexcept { return fieldName; }`<br> |
| define  | [**USE\_RET**](_class_macros_8h.md#define-use_ret)  `[[nodiscard]]`<br> |

## Macro Definition Documentation





### define GETTER 

```C++
#define GETTER (
    fieldType,
    fieldName
) `USE_RET FORCEINLINE const fieldType& Get##fieldName() const noexcept { return fieldName; }`
```



Create a getter for a field that passes by const reference with the name `Get<FieldName>()`.


Assumes no exceptions can be thrown by the method.


Example: `GETTER(int, Foo)` becomes `const int& GetFoo() const noexcept { return Foo; }` 


        

<hr>



### define USE\_RET 

```C++
#define USE_RET `[[nodiscard]]`
```



Marks that the return value of this function should always be used in some way, and it is an error to not use it.


It could be because this function's sole purpose is to return a value with no side effects, or because this function returns an error type that must be accounted for. 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Util/ClassMacros.h`

