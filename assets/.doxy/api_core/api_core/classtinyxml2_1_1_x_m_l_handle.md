

# Class tinyxml2::XMLHandle



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md)



[More...](#detailed-description)

* `#include <tinyxml2.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md#function-xmlhandle-13) | [**FirstChild**](#function-firstchild) () <br>_Get the first child of this handle._  |
|  [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md#function-xmlhandle-13) | [**FirstChildElement**](#function-firstchildelement) (const char \* name=0) <br>_Get the first child element of this handle._  |
|  [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md#function-xmlhandle-13) | [**LastChild**](#function-lastchild) () <br>_Get the last child of this handle._  |
|  [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md#function-xmlhandle-13) | [**LastChildElement**](#function-lastchildelement) (const char \* name=0) <br>_Get the last child element of this handle._  |
|  [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md#function-xmlhandle-13) | [**NextSibling**](#function-nextsibling) () <br>_Get the next sibling of this handle._  |
|  [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md#function-xmlhandle-13) | [**NextSiblingElement**](#function-nextsiblingelement) (const char \* name=0) <br>_Get the next sibling element of this handle._  |
|  [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md#function-xmlhandle-13) | [**PreviousSibling**](#function-previoussibling) () <br>_Get the previous sibling of this handle._  |
|  [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md#function-xmlhandle-13) | [**PreviousSiblingElement**](#function-previoussiblingelement) (const char \* name=0) <br>_Get the previous sibling element of this handle._  |
|  [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) \* | [**ToDeclaration**](#function-todeclaration) () <br>_Safe cast to_ [_**XMLDeclaration**_](classtinyxml2_1_1_x_m_l_declaration.md) _. This can return null._ |
|  [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) \* | [**ToElement**](#function-toelement) () <br>_Safe cast to_ [_**XMLElement**_](classtinyxml2_1_1_x_m_l_element.md) _. This can return null._ |
|  [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md) \* | [**ToNode**](#function-tonode) () <br>_Safe cast to_ [_**XMLNode**_](classtinyxml2_1_1_x_m_l_node.md) _. This can return null._ |
|  [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) \* | [**ToText**](#function-totext) () <br>_Safe cast to_ [_**XMLText**_](classtinyxml2_1_1_x_m_l_text.md) _. This can return null._ |
|  [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) \* | [**ToUnknown**](#function-tounknown) () <br>_Safe cast to_ [_**XMLUnknown**_](classtinyxml2_1_1_x_m_l_unknown.md) _. This can return null._ |
|   | [**XMLHandle**](#function-xmlhandle-13) ([**XMLNode**](classtinyxml2_1_1_x_m_l_node.md) \* node) <br>_Create a handle from any node (at any depth of the tree.) This can be a null pointer._  |
|   | [**XMLHandle**](#function-xmlhandle-23) ([**XMLNode**](classtinyxml2_1_1_x_m_l_node.md) & node) <br>_Create a handle from a node._  |
|   | [**XMLHandle**](#function-xmlhandle-33) (const XMLHandle & ref) <br>_Copy constructor._  |
|  [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md#function-xmlhandle-13) & | [**operator=**](#function-operator) (const [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md#function-xmlhandle-13) & ref) <br>_Assignment._  |




























## Detailed Description


A [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md) is a class that wraps a node pointer with null checks; this is an incredibly useful thing. Note that [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md) is not part of the TinyXML-2 DOM structure. It is a separate utility class.


Take an example: 


Assuming you want the value of "attributeB" in the 2nd "Child" element, it's very easy to write a _lot_ of code that looks like:





And that doesn't even cover "else" cases. [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md) addresses the verbosity of such code. A [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md) checks for null pointers so it is perfectly safe and correct to use:





Which is MUCH more concise and useful.


It is also safe to copy handles - internally they are nothing more than node pointers. 


See also [**XMLConstHandle**](classtinyxml2_1_1_x_m_l_const_handle.md), which is the same as [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md), but operates on const objects. 


    
## Public Functions Documentation




### function FirstChild 

_Get the first child of this handle._ 
```C++
inline XMLHandle tinyxml2::XMLHandle::FirstChild () 
```




<hr>



### function FirstChildElement 

_Get the first child element of this handle._ 
```C++
inline XMLHandle tinyxml2::XMLHandle::FirstChildElement (
    const char * name=0
) 
```




<hr>



### function LastChild 

_Get the last child of this handle._ 
```C++
inline XMLHandle tinyxml2::XMLHandle::LastChild () 
```




<hr>



### function LastChildElement 

_Get the last child element of this handle._ 
```C++
inline XMLHandle tinyxml2::XMLHandle::LastChildElement (
    const char * name=0
) 
```




<hr>



### function NextSibling 

_Get the next sibling of this handle._ 
```C++
inline XMLHandle tinyxml2::XMLHandle::NextSibling () 
```




<hr>



### function NextSiblingElement 

_Get the next sibling element of this handle._ 
```C++
inline XMLHandle tinyxml2::XMLHandle::NextSiblingElement (
    const char * name=0
) 
```




<hr>



### function PreviousSibling 

_Get the previous sibling of this handle._ 
```C++
inline XMLHandle tinyxml2::XMLHandle::PreviousSibling () 
```




<hr>



### function PreviousSiblingElement 

_Get the previous sibling element of this handle._ 
```C++
inline XMLHandle tinyxml2::XMLHandle::PreviousSiblingElement (
    const char * name=0
) 
```




<hr>



### function ToDeclaration 

_Safe cast to_ [_**XMLDeclaration**_](classtinyxml2_1_1_x_m_l_declaration.md) _. This can return null._
```C++
inline XMLDeclaration * tinyxml2::XMLHandle::ToDeclaration () 
```




<hr>



### function ToElement 

_Safe cast to_ [_**XMLElement**_](classtinyxml2_1_1_x_m_l_element.md) _. This can return null._
```C++
inline XMLElement * tinyxml2::XMLHandle::ToElement () 
```




<hr>



### function ToNode 

_Safe cast to_ [_**XMLNode**_](classtinyxml2_1_1_x_m_l_node.md) _. This can return null._
```C++
inline XMLNode * tinyxml2::XMLHandle::ToNode () 
```




<hr>



### function ToText 

_Safe cast to_ [_**XMLText**_](classtinyxml2_1_1_x_m_l_text.md) _. This can return null._
```C++
inline XMLText * tinyxml2::XMLHandle::ToText () 
```




<hr>



### function ToUnknown 

_Safe cast to_ [_**XMLUnknown**_](classtinyxml2_1_1_x_m_l_unknown.md) _. This can return null._
```C++
inline XMLUnknown * tinyxml2::XMLHandle::ToUnknown () 
```




<hr>



### function XMLHandle [1/3]

_Create a handle from any node (at any depth of the tree.) This can be a null pointer._ 
```C++
inline explicit tinyxml2::XMLHandle::XMLHandle (
    XMLNode * node
) 
```




<hr>



### function XMLHandle [2/3]

_Create a handle from a node._ 
```C++
inline explicit tinyxml2::XMLHandle::XMLHandle (
    XMLNode & node
) 
```




<hr>



### function XMLHandle [3/3]

_Copy constructor._ 
```C++
inline tinyxml2::XMLHandle::XMLHandle (
    const XMLHandle & ref
) 
```




<hr>



### function operator= 

_Assignment._ 
```C++
inline XMLHandle & tinyxml2::XMLHandle::operator= (
    const XMLHandle & ref
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

