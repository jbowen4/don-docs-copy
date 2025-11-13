

# Class tinyxml2::XMLAttribute



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**XMLAttribute**](classtinyxml2_1_1_x_m_l_attribute.md)



[More...](#detailed-description)

* `#include <tinyxml2.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**BoolValue**](#function-boolvalue) () const<br>_Query as a boolean. See_ [_**IntValue()**_](classtinyxml2_1_1_x_m_l_attribute.md#function-intvalue) _._ |
|  double | [**DoubleValue**](#function-doublevalue) () const<br>_Query as a double. See_ [_**IntValue()**_](classtinyxml2_1_1_x_m_l_attribute.md#function-intvalue) _._ |
|  float | [**FloatValue**](#function-floatvalue) () const<br>_Query as a float. See_ [_**IntValue()**_](classtinyxml2_1_1_x_m_l_attribute.md#function-intvalue) _._ |
|  int | [**GetLineNum**](#function-getlinenum) () const<br>_Gets the line number the attribute is in, if the document was parsed from a file._  |
|  int64\_t | [**Int64Value**](#function-int64value) () const<br> |
|  int | [**IntValue**](#function-intvalue) () const<br> |
|  const char \* | [**Name**](#function-name) () const<br>_The name of the attribute._  |
|  const XMLAttribute \* | [**Next**](#function-next) () const<br>_The next attribute in the list._  |
|  XMLError | [**QueryBoolValue**](#function-queryboolvalue) (bool \* value) const<br>_See QueryIntValue._  |
|  XMLError | [**QueryDoubleValue**](#function-querydoublevalue) (double \* value) const<br>_See QueryIntValue._  |
|  XMLError | [**QueryFloatValue**](#function-queryfloatvalue) (float \* value) const<br>_See QueryIntValue._  |
|  XMLError | [**QueryInt64Value**](#function-queryint64value) (int64\_t \* value) const<br>_See QueryIntValue._  |
|  XMLError | [**QueryIntValue**](#function-queryintvalue) (int \* value) const<br> |
|  XMLError | [**QueryUnsigned64Value**](#function-queryunsigned64value) (uint64\_t \* value) const<br>_See QueryIntValue._  |
|  XMLError | [**QueryUnsignedValue**](#function-queryunsignedvalue) (unsigned int \* value) const<br>_See QueryIntValue._  |
|  void | [**SetAttribute**](#function-setattribute-18) (const char \* value) <br>_Set the attribute to a string value._  |
|  void | [**SetAttribute**](#function-setattribute-28) (int value) <br>_Set the attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-38) (unsigned value) <br>_Set the attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-48) (int64\_t value) <br>_Set the attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-58) (uint64\_t value) <br>_Set the attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-68) (bool value) <br>_Set the attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-78) (double value) <br>_Set the attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-88) (float value) <br>_Set the attribute to value._  |
|  uint64\_t | [**Unsigned64Value**](#function-unsigned64value) () const<br> |
|  unsigned | [**UnsignedValue**](#function-unsignedvalue) () const<br>_Query as an unsigned integer. See_ [_**IntValue()**_](classtinyxml2_1_1_x_m_l_attribute.md#function-intvalue) _._ |
|  const char \* | [**Value**](#function-value) () const<br>_The value of the attribute._  |




























## Detailed Description


An attribute is a name-value pair. Elements have an arbitrary number of attributes, each with a unique name.




**Note:**

The attributes are not XMLNodes. You may only query the [**Next()**](classtinyxml2_1_1_x_m_l_attribute.md#function-next) attribute in a list. 





    
## Public Functions Documentation




### function BoolValue 

_Query as a boolean. See_ [_**IntValue()**_](classtinyxml2_1_1_x_m_l_attribute.md#function-intvalue) _._
```C++
inline bool tinyxml2::XMLAttribute::BoolValue () const
```




<hr>



### function DoubleValue 

_Query as a double. See_ [_**IntValue()**_](classtinyxml2_1_1_x_m_l_attribute.md#function-intvalue) _._
```C++
inline double tinyxml2::XMLAttribute::DoubleValue () const
```




<hr>



### function FloatValue 

_Query as a float. See_ [_**IntValue()**_](classtinyxml2_1_1_x_m_l_attribute.md#function-intvalue) _._
```C++
inline float tinyxml2::XMLAttribute::FloatValue () const
```




<hr>



### function GetLineNum 

_Gets the line number the attribute is in, if the document was parsed from a file._ 
```C++
inline int tinyxml2::XMLAttribute::GetLineNum () const
```




<hr>



### function Int64Value 

```C++
inline int64_t tinyxml2::XMLAttribute::Int64Value () const
```




<hr>



### function IntValue 

```C++
inline int tinyxml2::XMLAttribute::IntValue () const
```



IntValue interprets the attribute as an integer, and returns the value. If the value isn't an integer, 0 will be returned. There is no error checking; use [**QueryIntValue()**](classtinyxml2_1_1_x_m_l_attribute.md#function-queryintvalue) if you need error checking. 


        

<hr>



### function Name 

_The name of the attribute._ 
```C++
const char * tinyxml2::XMLAttribute::Name () const
```




<hr>



### function Next 

_The next attribute in the list._ 
```C++
inline const XMLAttribute * tinyxml2::XMLAttribute::Next () const
```




<hr>



### function QueryBoolValue 

_See QueryIntValue._ 
```C++
XMLError tinyxml2::XMLAttribute::QueryBoolValue (
    bool * value
) const
```




<hr>



### function QueryDoubleValue 

_See QueryIntValue._ 
```C++
XMLError tinyxml2::XMLAttribute::QueryDoubleValue (
    double * value
) const
```




<hr>



### function QueryFloatValue 

_See QueryIntValue._ 
```C++
XMLError tinyxml2::XMLAttribute::QueryFloatValue (
    float * value
) const
```




<hr>



### function QueryInt64Value 

_See QueryIntValue._ 
```C++
XMLError tinyxml2::XMLAttribute::QueryInt64Value (
    int64_t * value
) const
```




<hr>



### function QueryIntValue 

```C++
XMLError tinyxml2::XMLAttribute::QueryIntValue (
    int * value
) const
```



QueryIntValue interprets the attribute as an integer, and returns the value in the provided parameter. The function will return XML\_SUCCESS on success, and XML\_WRONG\_ATTRIBUTE\_TYPE if the conversion is not successful. 


        

<hr>



### function QueryUnsigned64Value 

_See QueryIntValue._ 
```C++
XMLError tinyxml2::XMLAttribute::QueryUnsigned64Value (
    uint64_t * value
) const
```




<hr>



### function QueryUnsignedValue 

_See QueryIntValue._ 
```C++
XMLError tinyxml2::XMLAttribute::QueryUnsignedValue (
    unsigned int * value
) const
```




<hr>



### function SetAttribute [1/8]

_Set the attribute to a string value._ 
```C++
void tinyxml2::XMLAttribute::SetAttribute (
    const char * value
) 
```




<hr>



### function SetAttribute [2/8]

_Set the attribute to value._ 
```C++
void tinyxml2::XMLAttribute::SetAttribute (
    int value
) 
```




<hr>



### function SetAttribute [3/8]

_Set the attribute to value._ 
```C++
void tinyxml2::XMLAttribute::SetAttribute (
    unsigned value
) 
```




<hr>



### function SetAttribute [4/8]

_Set the attribute to value._ 
```C++
void tinyxml2::XMLAttribute::SetAttribute (
    int64_t value
) 
```




<hr>



### function SetAttribute [5/8]

_Set the attribute to value._ 
```C++
void tinyxml2::XMLAttribute::SetAttribute (
    uint64_t value
) 
```




<hr>



### function SetAttribute [6/8]

_Set the attribute to value._ 
```C++
void tinyxml2::XMLAttribute::SetAttribute (
    bool value
) 
```




<hr>



### function SetAttribute [7/8]

_Set the attribute to value._ 
```C++
void tinyxml2::XMLAttribute::SetAttribute (
    double value
) 
```




<hr>



### function SetAttribute [8/8]

_Set the attribute to value._ 
```C++
void tinyxml2::XMLAttribute::SetAttribute (
    float value
) 
```




<hr>



### function Unsigned64Value 

```C++
inline uint64_t tinyxml2::XMLAttribute::Unsigned64Value () const
```




<hr>



### function UnsignedValue 

_Query as an unsigned integer. See_ [_**IntValue()**_](classtinyxml2_1_1_x_m_l_attribute.md#function-intvalue) _._
```C++
inline unsigned tinyxml2::XMLAttribute::UnsignedValue () const
```




<hr>



### function Value 

_The value of the attribute._ 
```C++
const char * tinyxml2::XMLAttribute::Value () const
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

