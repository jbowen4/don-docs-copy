

# Class tinyxml2::XMLVisitor



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md)



[More...](#detailed-description)

* `#include <tinyxml2.h>`





Inherited by the following classes: [tinyxml2::XMLPrinter](classtinyxml2_1_1_x_m_l_printer.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual bool | [**Visit**](#function-visit-14) (const [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) &) <br>_Visit a declaration._  |
| virtual bool | [**Visit**](#function-visit-24) (const [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) &) <br>_Visit a text node._  |
| virtual bool | [**Visit**](#function-visit-34) (const [**XMLComment**](classtinyxml2_1_1_x_m_l_comment.md) &) <br>_Visit a comment node._  |
| virtual bool | [**Visit**](#function-visit-44) (const [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) &) <br>_Visit an unknown node._  |
| virtual bool | [**VisitEnter**](#function-visitenter-12) (const [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md) &) <br>_Visit a document._  |
| virtual bool | [**VisitEnter**](#function-visitenter-22) (const [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) &, const [**XMLAttribute**](classtinyxml2_1_1_x_m_l_attribute.md) \*) <br>_Visit an element._  |
| virtual bool | [**VisitExit**](#function-visitexit-12) (const [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md) &) <br>_Visit a document._  |
| virtual bool | [**VisitExit**](#function-visitexit-22) (const [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) &) <br>_Visit an element._  |
| virtual  | [**~XMLVisitor**](#function-xmlvisitor) () <br> |




























## Detailed Description


Implements the interface to the "Visitor pattern" (see the Accept() method.) If you call the Accept() method, it requires being passed a [**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) class to handle callbacks. For nodes that contain other nodes (Document, Element) you will get called with a VisitEnter/VisitExit pair. Nodes that are always leafs are simply called with [**Visit()**](classtinyxml2_1_1_x_m_l_visitor.md#function-visit-14).


If you return 'true' from a Visit method, recursive parsing will continue. If you return false, **no children of this node or its siblings** will be visited.


All flavors of Visit methods have a default implementation that returns 'true' (continue visiting). You need to only override methods that are interesting to you.


Generally Accept() is called on the [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md), although all nodes support visiting.


You should never change the document from a callback.




**See also:** [**XMLNode::Accept()**](classtinyxml2_1_1_x_m_l_node.md#function-accept) 



    
## Public Functions Documentation




### function Visit [1/4]

_Visit a declaration._ 
```C++
inline virtual bool tinyxml2::XMLVisitor::Visit (
    const XMLDeclaration &
) 
```




<hr>



### function Visit [2/4]

_Visit a text node._ 
```C++
inline virtual bool tinyxml2::XMLVisitor::Visit (
    const XMLText &
) 
```




<hr>



### function Visit [3/4]

_Visit a comment node._ 
```C++
inline virtual bool tinyxml2::XMLVisitor::Visit (
    const XMLComment &
) 
```




<hr>



### function Visit [4/4]

_Visit an unknown node._ 
```C++
inline virtual bool tinyxml2::XMLVisitor::Visit (
    const XMLUnknown &
) 
```




<hr>



### function VisitEnter [1/2]

_Visit a document._ 
```C++
inline virtual bool tinyxml2::XMLVisitor::VisitEnter (
    const XMLDocument &
) 
```




<hr>



### function VisitEnter [2/2]

_Visit an element._ 
```C++
inline virtual bool tinyxml2::XMLVisitor::VisitEnter (
    const XMLElement &,
    const XMLAttribute *
) 
```




<hr>



### function VisitExit [1/2]

_Visit a document._ 
```C++
inline virtual bool tinyxml2::XMLVisitor::VisitExit (
    const XMLDocument &
) 
```




<hr>



### function VisitExit [2/2]

_Visit an element._ 
```C++
inline virtual bool tinyxml2::XMLVisitor::VisitExit (
    const XMLElement &
) 
```




<hr>



### function ~XMLVisitor 

```C++
inline virtual tinyxml2::XMLVisitor::~XMLVisitor () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

