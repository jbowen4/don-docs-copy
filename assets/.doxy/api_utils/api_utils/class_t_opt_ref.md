

# Class TOptRef

**template &lt;typename T&gt;**



[**ClassList**](annotated.md) **>** [**TOptRef**](class_t_opt_ref.md)



[More...](#detailed-description)

* `#include <TOptRef.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  FORCEINLINE [**TOptRef**](class_t_opt_ref.md) | [**Filter**](#function-filter) (Predicate shouldKeepValue) const<br> |
|  FORCEINLINE TOptional&lt; R &gt; | [**FlatMapOwned**](#function-flatmapowned) (\_Mapper transformer) const<br> |
|  FORCEINLINE [**TOptRef**](class_t_opt_ref.md)&lt; R &gt; | [**FlatMapRef**](#function-flatmapref) (\_Mapper transformer) const<br> |
|  FORCEINLINE T & | [**GetOrCompute**](#function-getorcompute) (\_Computer computer) <br> |
|  FORCEINLINE T & | [**GetOrDefault**](#function-getordefault) (T & Default) noexcept const<br> |
|  FORCEINLINE T & | [**GetOrThrow**](#function-getorthrow-13) () const<br> |
|  FORCEINLINE T & | [**GetOrThrow**](#function-getorthrow-23) (const std::string errorMessage) const<br> |
|  FORCEINLINE T & | [**GetOrThrow**](#function-getorthrow-33) (const \_ExceptionFactory exceptionFactory) const<br> |
|  FORCEINLINE T \* | [**GetPtrOrNull**](#function-getptrornull) () noexcept const<br> |
|  FORCEINLINE T & | [**GetUnchecked**](#function-getunchecked) () noexcept const<br> |
|  FORCEINLINE [**TOptRef**](class_t_opt_ref.md) | [**IfAbsent**](#function-ifabsent) (\_Action action) const<br> |
|  FORCEINLINE [**TOptRef**](class_t_opt_ref.md) | [**IfPresent**](#function-ifpresent) (\_Action action) const<br> |
|  FORCEINLINE bool | [**IsAbsent**](#function-isabsent) () noexcept const<br> |
|  FORCEINLINE bool | [**IsPresent**](#function-ispresent) () noexcept const<br> |
|  FORCEINLINE TOptional&lt; R &gt; | [**MapOwned**](#function-mapowned) (\_Mapper transformer) const<br> |
|  FORCEINLINE [**TOptRef**](class_t_opt_ref.md)&lt; R &gt; | [**MapRef**](#function-mapref) (\_Mapper transformer) const<br> |
|  FORCEINLINE | [**TOptRef**](#function-toptref-16) () <br> |
|  FORCEINLINE | [**TOptRef**](#function-toptref-26) (T & ref) <br> |
|  FORCEINLINE | [**TOptRef**](#function-toptref-36) (T \* ptr) <br> |
|  FORCEINLINE | [**TOptRef**](#function-toptref-46) (T && rvalRef) <br> |
|   | [**TOptRef**](#function-toptref-56) (const [**TOptRef**](class_t_opt_ref.md) & other) <br> |
|   | [**TOptRef**](#function-toptref-66) ([**TOptRef**](class_t_opt_ref.md) && other) noexcept<br> |
|  FORCEINLINE TOptional&lt; T &gt; | [**ToOwned**](#function-toowned-12) () noexcept const<br> |
|  FORCEINLINE void | [**ToOwned**](#function-toowned-22) (TOptional&lt; T &gt; & Out) noexcept const<br> |
|  FORCEINLINE T | [**ToOwnedOrCompute**](#function-toownedorcompute) (\_Computer computer) <br> |
|  FORCEINLINE | [**operator bool**](#function-operator-bool) () noexcept const<br> |
|  bool | [**operator!=**](#function-operator) ([**TOptRef**](class_t_opt_ref.md)&lt; \_Other &gt; other) noexcept const<br> |
|  bool | [**operator!=**](#function-operator_1) (const T & other) noexcept const<br> |
|  bool | [**operator!=**](#function-operator_2) (T && other) noexcept const<br> |
|  FORCEINLINE T & | [**operator\***](#function-operator_3) () <br> |
|  FORCEINLINE T \* | [**operator-&gt;**](#function-operator-) () <br> |
|  [**TOptRef**](class_t_opt_ref.md) & | [**operator=**](#function-operator_4) (const [**TOptRef**](class_t_opt_ref.md) & other) <br> |
|  [**TOptRef**](class_t_opt_ref.md) & | [**operator=**](#function-operator_5) ([**TOptRef**](class_t_opt_ref.md) && other) noexcept<br> |
|  bool | [**operator==**](#function-operator_6) ([**TOptRef**](class_t_opt_ref.md)&lt; \_Other &gt; other) noexcept const<br> |
|  bool | [**operator==**](#function-operator_6) ([**TOptRef**](class_t_opt_ref.md)&lt; \_Other &gt; other) noexcept const<br> |
|  bool | [**operator==**](#function-operator_8) (const T & other) noexcept const<br> |
|  bool | [**operator==**](#function-operator_9) (T && other) noexcept const<br> |




























## Detailed Description


A nullable reference, but explicitly stated.


Contains functions to act on the resulting value.




**Template parameters:**


* `T` The type this reference points to. May be const. Untested when T is a reference itself. 




    
## Public Functions Documentation




### function Filter 

```C++
template<typename Predicate, std::enable_if_t< std::is_invocable_r_v< bool, Predicate, const T & >, bool >>
inline FORCEINLINE TOptRef TOptRef::Filter (
    Predicate shouldKeepValue
) const
```



If this value is absent or the predicate returns false, return an empty optional. 

**Template parameters:**


* `Predicate` A function or lambda that accepts `const T&` and returns either `true` to return the current instance or `false` to return an empty [**TOptRef**](class_t_opt_ref.md). 



**Returns:**

This instance if `shouldKeepValue` returns true or an empty [**TOptRef**](class_t_opt_ref.md) if `shouldKeepValue` returns false. 





        

<hr>



### function FlatMapOwned 

```C++
template<typename R, typename _Mapper, std::enable_if_t< std::is_invocable_r_v< TOptional< R >, _Mapper, const T & >, bool >>
inline FORCEINLINE TOptional< R > TOptRef::FlatMapOwned (
    _Mapper transformer
) const
```



Maps this reference to a new OWNED VALUE, which is STORED in the returned TOptional. Used to connect another function that returns an optional with this one so you don't get `TOptional<TOptional<Foo>>` Cannot return a reference. To return a reference, use .  R The new type.  transformer The function or lambda to generate the new value. Signature = 


        

<hr>



### function FlatMapRef 

```C++
template<typename R, typename _Mapper, std::enable_if_t< std::is_invocable_r_v< TOptRef < R >, _Mapper, const T & >, bool >>
inline FORCEINLINE TOptRef < R > TOptRef::FlatMapRef (
    _Mapper transformer
) const
```



Map the value to the value of another optional reference if this value is present. Returns empty if absent.


Used to connect another function that returns an optional with this one, so you don't get `TOptRef < TOptRef <Foo>>`. For example: 
```C++
class Foo {
  TOptRef<int> GetNumber();
}

Foo foo;
TOptRef<Foo> bar = TOptRef(foo);
TOptRef<int> baz = bar.FlatMapRef<int>([](const Foo& it) -> TOptRef<int> { return it.GetNumber(); });
assert(baz.IsPresent() == bar.IsPresent() && foo.GetNumber().IsPresent());
assert(baz.GetOrThrow() == bar.GetOrThrow().GetNumber().GetOrThrow();
```



Should _not_ be used with a newly generated value, only to map this reference to one stored somewhere else. To contain a value, see .  R The new type.  transformer The transformation function or lambda. Signature = 


        

<hr>



### function GetOrCompute 

```C++
template<typename _Computer, std::enable_if_t< std::is_invocable_r_v< T &, _Computer >, int >>
inline FORCEINLINE T & TOptRef::GetOrCompute (
    _Computer computer
) 
```



Returns the stored reference if present, else executes the provided function and returns it. 

**Parameters:**


* `computer` A `T& (void)` function or lambda 




        

<hr>



### function GetOrDefault 

```C++
inline FORCEINLINE T & TOptRef::GetOrDefault (
    T & Default
) noexcept const
```



Returns the stored reference if present, else returns Default. 


        

<hr>



### function GetOrThrow [1/3]

```C++
inline FORCEINLINE T & TOptRef::GetOrThrow () const
```



Get the contained reference if present.


If absent, throws a `std::runtime_error` describing the error.




**Exception:**


* `std::runtime_error` If the value is absent. 




        

<hr>



### function GetOrThrow [2/3]

```C++
inline FORCEINLINE T & TOptRef::GetOrThrow (
    const std::string errorMessage
) const
```



Get the contained reference if present.


If absent, throws a `std::runtime_error` with the provided error message.




**Exception:**


* `std::runtime_error` If the value is absent. 




        

<hr>



### function GetOrThrow [3/3]

```C++
template<typename _ExceptionFactory, std::enable_if_t< std::is_invocable_r_v< std::exception, _ExceptionFactory >, bool >>
inline FORCEINLINE T & TOptRef::GetOrThrow (
    const _ExceptionFactory exceptionFactory
) const
```



If the contained reference is present, returns it.


If absent, throws the exception created by the provided factory method.




**Exception:**


* `std::exception` If the value is absent. 




        

<hr>



### function GetPtrOrNull 

```C++
inline FORCEINLINE T * TOptRef::GetPtrOrNull () noexcept const
```



Get the stored reference as a pointer if present, else nullptr. 


        

<hr>



### function GetUnchecked 

```C++
inline FORCEINLINE T & TOptRef::GetUnchecked () noexcept const
```




<hr>



### function IfAbsent 

```C++
template<typename _Action, std::enable_if_t< std::is_invocable_v< _Action >, bool >>
inline FORCEINLINE TOptRef TOptRef::IfAbsent (
    _Action action
) const
```



Executes the given action if the value is absent. Does nothing if the value is present. 

**Parameters:**


* `action` The action function/lambda to be performed. Signature = `void()` 



**Returns:**

This object. 





        

<hr>



### function IfPresent 

```C++
template<typename _Action, std::enable_if_t< std::is_invocable_v< _Action, const T & >, bool >>
inline FORCEINLINE TOptRef TOptRef::IfPresent (
    _Action action
) const
```



Execute the given lambda on the value if it is present, or does nothing if absent. 

**Parameters:**


* `action` The action to be performed in the form of a `void(const T&)` function or lambda. 



**Returns:**

This object. 





        

<hr>



### function IsAbsent 

```C++
inline FORCEINLINE bool TOptRef::IsAbsent () noexcept const
```




<hr>



### function IsPresent 

```C++
inline FORCEINLINE bool TOptRef::IsPresent () noexcept const
```




<hr>



### function MapOwned 

```C++
template<typename R, typename _Mapper, std::enable_if_t< std::is_invocable_r_v< R, _Mapper, const T & >, bool >>
inline FORCEINLINE TOptional< R > TOptRef::MapOwned (
    _Mapper transformer
) const
```



Maps this reference to a new OWNED VALUE, which is STORED in the returned TOptional. Cannot return a reference. To return a reference, use .  R The new type.  transformer The function or lambda to generate the new value. Signature = 


        

<hr>



### function MapRef 

```C++
template<typename R, typename _Mapper, std::enable_if_t< std::is_invocable_r_v< TRetainedRef< R >, _Mapper, const T & >, bool >>
inline FORCEINLINE TOptRef < R > TOptRef::MapRef (
    _Mapper transformer
) const
```



Map the value to a new reference if present. Returns empty if absent.


Should _not_ be used with a newly generated value, only to map this reference to one stored somewhere else. To contain a value, see .  R The new type.  transformer The transformation function or lambda. Signature = 


        

<hr>



### function TOptRef [1/6]

```C++
inline explicit FORCEINLINE TOptRef::TOptRef () 
```




<hr>



### function TOptRef [2/6]

```C++
inline FORCEINLINE TOptRef::TOptRef (
    T & ref
) 
```




<hr>



### function TOptRef [3/6]

```C++
inline FORCEINLINE TOptRef::TOptRef (
    T * ptr
) 
```




<hr>



### function TOptRef [4/6]

```C++
inline FORCEINLINE TOptRef::TOptRef (
    T && rvalRef
) 
```




<hr>



### function TOptRef [5/6]

```C++
inline TOptRef::TOptRef (
    const TOptRef & other
) 
```




<hr>



### function TOptRef [6/6]

```C++
inline TOptRef::TOptRef (
    TOptRef && other
) noexcept
```




<hr>



### function ToOwned [1/2]

```C++
inline FORCEINLINE TOptional< T > TOptRef::ToOwned () noexcept const
```



Copy the value stored in this reference into one stored in the returned struct. 


        

<hr>



### function ToOwned [2/2]

```C++
inline FORCEINLINE void TOptRef::ToOwned (
    TOptional< T > & Out
) noexcept const
```




<hr>



### function ToOwnedOrCompute 

```C++
template<typename _Computer, std::enable_if_t< std::is_invocable_r_v< T, _Computer >, int >>
inline FORCEINLINE T TOptRef::ToOwnedOrCompute (
    _Computer computer
) 
```



Returns a copy of the stored reference if it is present, or else executes the provided function if the reference is absent.




**Parameters:**


* `computer` A function/lambda that accepts no arguments and returns an owned T instance. 




        

<hr>



### function operator bool 

```C++
inline FORCEINLINE TOptRef::operator bool () noexcept const
```




<hr>



### function operator!= 

```C++
template<typename _Other, std::enable_if_t< std::is_assignable_v< T, _Other >, bool >>
inline bool TOptRef::operator!= (
    TOptRef < _Other > other
) noexcept const
```




<hr>



### function operator!= 

```C++
inline bool TOptRef::operator!= (
    const T & other
) noexcept const
```




<hr>



### function operator!= 

```C++
inline bool TOptRef::operator!= (
    T && other
) noexcept const
```




<hr>



### function operator\* 

```C++
inline FORCEINLINE T & TOptRef::operator* () 
```




<hr>



### function operator-&gt; 

```C++
inline FORCEINLINE T * TOptRef::operator-> () 
```




<hr>



### function operator= 

```C++
inline TOptRef & TOptRef::operator= (
    const TOptRef & other
) 
```




<hr>



### function operator= 

```C++
inline TOptRef & TOptRef::operator= (
    TOptRef && other
) noexcept
```




<hr>



### function operator== 

```C++
template<typename _Other, std::enable_if_t< std::is_convertible_v< T, _Other >, bool >>
inline bool TOptRef::operator== (
    TOptRef < _Other > other
) noexcept const
```



Checks object equality instead of pointer equality to keep the same contract as a standard reference. 


        

<hr>



### function operator== 

```C++
template<typename _Other, std::enable_if_t<!std::is_convertible_v< T, _Other >, int >>
inline bool TOptRef::operator== (
    TOptRef < _Other > other
) noexcept const
```



If they hold non-convertible types, it's false. 


        

<hr>



### function operator== 

```C++
inline bool TOptRef::operator== (
    const T & other
) noexcept const
```




<hr>



### function operator== 

```C++
inline bool TOptRef::operator== (
    T && other
) noexcept const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Util/Types/TOptRef.h`

