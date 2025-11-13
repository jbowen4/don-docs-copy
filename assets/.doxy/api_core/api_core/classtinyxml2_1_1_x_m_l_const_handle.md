

# Class tinyxml2::XMLConstHandle



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**XMLConstHandle**](classtinyxml2_1_1_x_m_l_const_handle.md)



[More...](#detailed-description)

* `#include <tinyxml2.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  const XMLConstHandle | [**FirstChild**](#function-firstchild) () const<br> |
|  const XMLConstHandle | [**FirstChildElement**](#function-firstchildelement) (const char \* name=0) const<br> |
|  const XMLConstHandle | [**LastChild**](#function-lastchild) () const<br> |
|  const XMLConstHandle | [**LastChildElement**](#function-lastchildelement) (const char \* name=0) const<br> |
|  const XMLConstHandle | [**NextSibling**](#function-nextsibling) () const<br> |
|  const XMLConstHandle | [**NextSiblingElement**](#function-nextsiblingelement) (const char \* name=0) const<br> |
|  const XMLConstHandle | [**PreviousSibling**](#function-previoussibling) () const<br> |
|  const XMLConstHandle | [**PreviousSiblingElement**](#function-previoussiblingelement) (const char \* name=0) const<br> |
|  const [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) \* | [**ToDeclaration**](#function-todeclaration) () const<br> |
|  const [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) \* | [**ToElement**](#function-toelement) () const<br> |
|  const [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md) \* | [**ToNode**](#function-tonode) () const<br> |
|  const [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) \* | [**ToText**](#function-totext) () const<br> |
|  const [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) \* | [**ToUnknown**](#function-tounknown) () const<br> |
|   | [**XMLConstHandle**](#function-xmlconsthandle-13) (const [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md) \* node) <br> |
|   | [**XMLConstHandle**](#function-xmlconsthandle-23) (const [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md) & node) <br> |
|   | [**XMLConstHandle**](#function-xmlconsthandle-33) (const XMLConstHandle & ref) <br> |
|  XMLConstHandle & | [**operator=**](#function-operator) (const XMLConstHandle & ref) <br> |




























## Detailed Description


A variant of the [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md) class for working with const XMLNodes and Documents. It is the same in all regards, except for the 'const' qualifiers. See [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md) for API. 


    
## Public Functions Documentation




### function FirstChild 

```C++
inline const XMLConstHandle tinyxml2::XMLConstHandle::FirstChild () const
```




<hr>



### function FirstChildElement 

```C++
inline const XMLConstHandle tinyxml2::XMLConstHandle::FirstChildElement (
    const char * name=0
) const
```




<hr>



### function LastChild 

```C++
inline const XMLConstHandle tinyxml2::XMLConstHandle::LastChild () const
```




<hr>



### function LastChildElement 

```C++
inline const XMLConstHandle tinyxml2::XMLConstHandle::LastChildElement (
    const char * name=0
) const
```




<hr>



### function NextSibling 

```C++
inline const XMLConstHandle tinyxml2::XMLConstHandle::NextSibling () const
```




<hr>



### function NextSiblingElement 

```C++
inline const XMLConstHandle tinyxml2::XMLConstHandle::NextSiblingElement (
    const char * name=0
) const
```




<hr>



### function PreviousSibling 

```C++
inline const XMLConstHandle tinyxml2::XMLConstHandle::PreviousSibling () const
```




<hr>



### function PreviousSiblingElement 

```C++
inline const XMLConstHandle tinyxml2::XMLConstHandle::PreviousSiblingElement (
    const char * name=0
) const
```




<hr>



### function ToDeclaration 

```C++
inline const XMLDeclaration * tinyxml2::XMLConstHandle::ToDeclaration () const
```




<hr>



### function ToElement 

```C++
inline const XMLElement * tinyxml2::XMLConstHandle::ToElement () const
```




<hr>



### function ToNode 

```C++
inline const XMLNode * tinyxml2::XMLConstHandle::ToNode () const
```




<hr>



### function ToText 

```C++
inline const XMLText * tinyxml2::XMLConstHandle::ToText () const
```




<hr>



### function ToUnknown 

```C++
inline const XMLUnknown * tinyxml2::XMLConstHandle::ToUnknown () const
```




<hr>



### function XMLConstHandle [1/3]

```C++
inline explicit tinyxml2::XMLConstHandle::XMLConstHandle (
    const XMLNode * node
) 
```




<hr>



### function XMLConstHandle [2/3]

```C++
inline explicit tinyxml2::XMLConstHandle::XMLConstHandle (
    const XMLNode & node
) 
```




<hr>



### function XMLConstHandle [3/3]

```C++
inline tinyxml2::XMLConstHandle::XMLConstHandle (
    const XMLConstHandle & ref
) 
```




<hr>



### function operator= 

```C++
inline XMLConstHandle & tinyxml2::XMLConstHandle::operator= (
    const XMLConstHandle & ref
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

