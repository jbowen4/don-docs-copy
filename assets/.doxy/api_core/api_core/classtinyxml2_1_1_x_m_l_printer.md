

# Class tinyxml2::XMLPrinter



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**XMLPrinter**](classtinyxml2_1_1_x_m_l_printer.md)



[More...](#detailed-description)

* `#include <tinyxml2.h>`



Inherits the following classes: [tinyxml2::XMLVisitor](classtinyxml2_1_1_x_m_l_visitor.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  const char \* | [**CStr**](#function-cstr) () const<br> |
|  int | [**CStrSize**](#function-cstrsize) () const<br> |
|  void | [**ClearBuffer**](#function-clearbuffer) (bool resetToFirstElement=true) <br> |
| virtual void | [**CloseElement**](#function-closeelement) (bool compactMode=false) <br>_If streaming, close the Element._  |
|  void | [**OpenElement**](#function-openelement) (const char \* name, bool compactMode=false) <br> |
|  void | [**PushAttribute**](#function-pushattribute-17) (const char \* name, const char \* value) <br>_If streaming, add an attribute to an open element._  |
|  void | [**PushAttribute**](#function-pushattribute-27) (const char \* name, int value) <br> |
|  void | [**PushAttribute**](#function-pushattribute-37) (const char \* name, unsigned value) <br> |
|  void | [**PushAttribute**](#function-pushattribute-47) (const char \* name, int64\_t value) <br> |
|  void | [**PushAttribute**](#function-pushattribute-57) (const char \* name, uint64\_t value) <br> |
|  void | [**PushAttribute**](#function-pushattribute-67) (const char \* name, bool value) <br> |
|  void | [**PushAttribute**](#function-pushattribute-77) (const char \* name, double value) <br> |
|  void | [**PushComment**](#function-pushcomment) (const char \* comment) <br>_Add a comment._  |
|  void | [**PushDeclaration**](#function-pushdeclaration) (const char \* value) <br> |
|  void | [**PushHeader**](#function-pushheader) (bool writeBOM, bool writeDeclaration) <br> |
|  void | [**PushText**](#function-pushtext-18) (const char \* text, bool cdata=false) <br>_Add a text node._  |
|  void | [**PushText**](#function-pushtext-28) (int value) <br>_Add a text node from an integer._  |
|  void | [**PushText**](#function-pushtext-38) (unsigned value) <br>_Add a text node from an unsigned._  |
|  void | [**PushText**](#function-pushtext-48) (int64\_t value) <br>_Add a text node from a signed 64bit integer._  |
|  void | [**PushText**](#function-pushtext-58) (uint64\_t value) <br>_Add a text node from an unsigned 64bit integer._  |
|  void | [**PushText**](#function-pushtext-68) (bool value) <br>_Add a text node from a bool._  |
|  void | [**PushText**](#function-pushtext-78) (float value) <br>_Add a text node from a float._  |
|  void | [**PushText**](#function-pushtext-88) (double value) <br>_Add a text node from a double._  |
|  void | [**PushUnknown**](#function-pushunknown) (const char \* value) <br> |
| virtual bool | [**Visit**](#function-visit-14) (const [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) &) override<br>_Visit a text node._  |
| virtual bool | [**Visit**](#function-visit-24) (const [**XMLComment**](classtinyxml2_1_1_x_m_l_comment.md) &) override<br>_Visit a comment node._  |
| virtual bool | [**Visit**](#function-visit-34) (const [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) &) override<br>_Visit a declaration._  |
| virtual bool | [**Visit**](#function-visit-44) (const [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) &) override<br>_Visit an unknown node._  |
| virtual bool | [**VisitEnter**](#function-visitenter-12) (const [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md) &) override<br>_Visit a document._  |
| virtual bool | [**VisitEnter**](#function-visitenter-22) (const [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) &, const [**XMLAttribute**](classtinyxml2_1_1_x_m_l_attribute.md) \*) override<br>_Visit an element._  |
| virtual bool | [**VisitExit**](#function-visitexit-12) (const [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md) &) override<br>_Visit a document._  |
| virtual bool | [**VisitExit**](#function-visitexit-22) (const [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) &) override<br>_Visit an element._  |
|   | [**XMLPrinter**](#function-xmlprinter-12) (FILE \* file=0, bool compact=false, int depth=0) <br> |
| virtual  | [**~XMLPrinter**](#function-xmlprinter) () <br> |


## Public Functions inherited from tinyxml2::XMLVisitor

See [tinyxml2::XMLVisitor](classtinyxml2_1_1_x_m_l_visitor.md)

| Type | Name |
| ---: | :--- |
| virtual bool | [**Visit**](classtinyxml2_1_1_x_m_l_visitor.md#function-visit-14) (const [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) &) <br>_Visit a declaration._  |
| virtual bool | [**Visit**](classtinyxml2_1_1_x_m_l_visitor.md#function-visit-24) (const [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) &) <br>_Visit a text node._  |
| virtual bool | [**Visit**](classtinyxml2_1_1_x_m_l_visitor.md#function-visit-34) (const [**XMLComment**](classtinyxml2_1_1_x_m_l_comment.md) &) <br>_Visit a comment node._  |
| virtual bool | [**Visit**](classtinyxml2_1_1_x_m_l_visitor.md#function-visit-44) (const [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) &) <br>_Visit an unknown node._  |
| virtual bool | [**VisitEnter**](classtinyxml2_1_1_x_m_l_visitor.md#function-visitenter-12) (const [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md) &) <br>_Visit a document._  |
| virtual bool | [**VisitEnter**](classtinyxml2_1_1_x_m_l_visitor.md#function-visitenter-22) (const [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) &, const [**XMLAttribute**](classtinyxml2_1_1_x_m_l_attribute.md) \*) <br>_Visit an element._  |
| virtual bool | [**VisitExit**](classtinyxml2_1_1_x_m_l_visitor.md#function-visitexit-12) (const [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md) &) <br>_Visit a document._  |
| virtual bool | [**VisitExit**](classtinyxml2_1_1_x_m_l_visitor.md#function-visitexit-22) (const [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) &) <br>_Visit an element._  |
| virtual  | [**~XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md#function-xmlvisitor) () <br> |














## Protected Attributes

| Type | Name |
| ---: | :--- |
|  bool | [**\_elementJustOpened**](#variable-_elementjustopened)  <br> |
|  [**DynArray**](classtinyxml2_1_1_dyn_array.md)&lt; const char \*, 10 &gt; | [**\_stack**](#variable-_stack)  <br> |
































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual bool | [**CompactMode**](#function-compactmode) (const [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) &) <br> |
| virtual void | [**Print**](#function-print) (const char \* format, ...) <br> |
| virtual void | [**PrintSpace**](#function-printspace) (int depth) <br> |
| virtual void | [**Putc**](#function-putc) (char ch) <br> |
|  void | [**SealElementIfJustOpened**](#function-sealelementifjustopened) () <br> |
| virtual void | [**Write**](#function-write-12) (const char \* data, size\_t size) <br> |
|  void | [**Write**](#function-write-22) (const char \* data) <br> |








## Detailed Description


Printing functionality. The [**XMLPrinter**](classtinyxml2_1_1_x_m_l_printer.md) gives you more options than the [**XMLDocument::Print()**](classtinyxml2_1_1_x_m_l_document.md#function-print) method.


It can:
* Print to memory.
* Print to a file you provide.
* Print XML without a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md).




Print to Memory





Print to a File


You provide the file pointer. 


Print without a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md)


When loading, an XML parser is very useful. However, sometimes when saving, it just gets in the way. The code is often set up for streaming, and constructing the DOM is just overhead.


The Printer supports the streaming case. The following code prints out a trivially simple XML file without ever creating an XML document.


 


    
## Public Functions Documentation




### function CStr 

```C++
inline const char * tinyxml2::XMLPrinter::CStr () const
```



If in print to memory mode, return a pointer to the XML file in memory. 


        

<hr>



### function CStrSize 

```C++
inline int tinyxml2::XMLPrinter::CStrSize () const
```



If in print to memory mode, return the size of the XML file in memory. (Note the size returned includes the terminating null.) 


        

<hr>



### function ClearBuffer 

```C++
inline void tinyxml2::XMLPrinter::ClearBuffer (
    bool resetToFirstElement=true
) 
```



If in print to memory mode, reset the buffer to the beginning. 


        

<hr>



### function CloseElement 

_If streaming, close the Element._ 
```C++
virtual void tinyxml2::XMLPrinter::CloseElement (
    bool compactMode=false
) 
```




<hr>



### function OpenElement 

```C++
void tinyxml2::XMLPrinter::OpenElement (
    const char * name,
    bool compactMode=false
) 
```



If streaming, start writing an element. The element must be closed with [**CloseElement()**](classtinyxml2_1_1_x_m_l_printer.md#function-closeelement) 


        

<hr>



### function PushAttribute [1/7]

_If streaming, add an attribute to an open element._ 
```C++
void tinyxml2::XMLPrinter::PushAttribute (
    const char * name,
    const char * value
) 
```




<hr>



### function PushAttribute [2/7]

```C++
void tinyxml2::XMLPrinter::PushAttribute (
    const char * name,
    int value
) 
```




<hr>



### function PushAttribute [3/7]

```C++
void tinyxml2::XMLPrinter::PushAttribute (
    const char * name,
    unsigned value
) 
```




<hr>



### function PushAttribute [4/7]

```C++
void tinyxml2::XMLPrinter::PushAttribute (
    const char * name,
    int64_t value
) 
```




<hr>



### function PushAttribute [5/7]

```C++
void tinyxml2::XMLPrinter::PushAttribute (
    const char * name,
    uint64_t value
) 
```




<hr>



### function PushAttribute [6/7]

```C++
void tinyxml2::XMLPrinter::PushAttribute (
    const char * name,
    bool value
) 
```




<hr>



### function PushAttribute [7/7]

```C++
void tinyxml2::XMLPrinter::PushAttribute (
    const char * name,
    double value
) 
```




<hr>



### function PushComment 

_Add a comment._ 
```C++
void tinyxml2::XMLPrinter::PushComment (
    const char * comment
) 
```




<hr>



### function PushDeclaration 

```C++
void tinyxml2::XMLPrinter::PushDeclaration (
    const char * value
) 
```




<hr>



### function PushHeader 

```C++
void tinyxml2::XMLPrinter::PushHeader (
    bool writeBOM,
    bool writeDeclaration
) 
```



If streaming, write the BOM and declaration. 


        

<hr>



### function PushText [1/8]

_Add a text node._ 
```C++
void tinyxml2::XMLPrinter::PushText (
    const char * text,
    bool cdata=false
) 
```




<hr>



### function PushText [2/8]

_Add a text node from an integer._ 
```C++
void tinyxml2::XMLPrinter::PushText (
    int value
) 
```




<hr>



### function PushText [3/8]

_Add a text node from an unsigned._ 
```C++
void tinyxml2::XMLPrinter::PushText (
    unsigned value
) 
```




<hr>



### function PushText [4/8]

_Add a text node from a signed 64bit integer._ 
```C++
void tinyxml2::XMLPrinter::PushText (
    int64_t value
) 
```




<hr>



### function PushText [5/8]

_Add a text node from an unsigned 64bit integer._ 
```C++
void tinyxml2::XMLPrinter::PushText (
    uint64_t value
) 
```




<hr>



### function PushText [6/8]

_Add a text node from a bool._ 
```C++
void tinyxml2::XMLPrinter::PushText (
    bool value
) 
```




<hr>



### function PushText [7/8]

_Add a text node from a float._ 
```C++
void tinyxml2::XMLPrinter::PushText (
    float value
) 
```




<hr>



### function PushText [8/8]

_Add a text node from a double._ 
```C++
void tinyxml2::XMLPrinter::PushText (
    double value
) 
```




<hr>



### function PushUnknown 

```C++
void tinyxml2::XMLPrinter::PushUnknown (
    const char * value
) 
```




<hr>



### function Visit [1/4]

_Visit a text node._ 
```C++
virtual bool tinyxml2::XMLPrinter::Visit (
    const XMLText &
) override
```



Implements [*tinyxml2::XMLVisitor::Visit*](classtinyxml2_1_1_x_m_l_visitor.md#function-visit-24)


<hr>



### function Visit [2/4]

_Visit a comment node._ 
```C++
virtual bool tinyxml2::XMLPrinter::Visit (
    const XMLComment &
) override
```



Implements [*tinyxml2::XMLVisitor::Visit*](classtinyxml2_1_1_x_m_l_visitor.md#function-visit-34)


<hr>



### function Visit [3/4]

_Visit a declaration._ 
```C++
virtual bool tinyxml2::XMLPrinter::Visit (
    const XMLDeclaration &
) override
```



Implements [*tinyxml2::XMLVisitor::Visit*](classtinyxml2_1_1_x_m_l_visitor.md#function-visit-14)


<hr>



### function Visit [4/4]

_Visit an unknown node._ 
```C++
virtual bool tinyxml2::XMLPrinter::Visit (
    const XMLUnknown &
) override
```



Implements [*tinyxml2::XMLVisitor::Visit*](classtinyxml2_1_1_x_m_l_visitor.md#function-visit-44)


<hr>



### function VisitEnter [1/2]

_Visit a document._ 
```C++
virtual bool tinyxml2::XMLPrinter::VisitEnter (
    const XMLDocument &
) override
```



Implements [*tinyxml2::XMLVisitor::VisitEnter*](classtinyxml2_1_1_x_m_l_visitor.md#function-visitenter-12)


<hr>



### function VisitEnter [2/2]

_Visit an element._ 
```C++
virtual bool tinyxml2::XMLPrinter::VisitEnter (
    const XMLElement &,
    const XMLAttribute *
) override
```



Implements [*tinyxml2::XMLVisitor::VisitEnter*](classtinyxml2_1_1_x_m_l_visitor.md#function-visitenter-22)


<hr>



### function VisitExit [1/2]

_Visit a document._ 
```C++
inline virtual bool tinyxml2::XMLPrinter::VisitExit (
    const XMLDocument &
) override
```



Implements [*tinyxml2::XMLVisitor::VisitExit*](classtinyxml2_1_1_x_m_l_visitor.md#function-visitexit-12)


<hr>



### function VisitExit [2/2]

_Visit an element._ 
```C++
virtual bool tinyxml2::XMLPrinter::VisitExit (
    const XMLElement &
) override
```



Implements [*tinyxml2::XMLVisitor::VisitExit*](classtinyxml2_1_1_x_m_l_visitor.md#function-visitexit-22)


<hr>



### function XMLPrinter [1/2]

```C++
tinyxml2::XMLPrinter::XMLPrinter (
    FILE * file=0,
    bool compact=false,
    int depth=0
) 
```



Construct the printer. If the FILE\* is specified, this will print to the FILE. Else it will print to memory, and the result is available in [**CStr()**](classtinyxml2_1_1_x_m_l_printer.md#function-cstr). If 'compact' is set to true, then output is created with only required whitespace and newlines. 


        

<hr>



### function ~XMLPrinter 

```C++
inline virtual tinyxml2::XMLPrinter::~XMLPrinter () 
```




<hr>
## Protected Attributes Documentation




### variable \_elementJustOpened 

```C++
bool tinyxml2::XMLPrinter::_elementJustOpened;
```




<hr>



### variable \_stack 

```C++
DynArray< const char*, 10 > tinyxml2::XMLPrinter::_stack;
```




<hr>
## Protected Functions Documentation




### function CompactMode 

```C++
inline virtual bool tinyxml2::XMLPrinter::CompactMode (
    const XMLElement &
) 
```




<hr>



### function Print 

```C++
virtual void tinyxml2::XMLPrinter::Print (
    const char * format,
    ...
) 
```




<hr>



### function PrintSpace 

```C++
virtual void tinyxml2::XMLPrinter::PrintSpace (
    int depth
) 
```



Prints out the space before an element. You may override to change the space and tabs used. A [**PrintSpace()**](classtinyxml2_1_1_x_m_l_printer.md#function-printspace) override should call Print(). 


        

<hr>



### function Putc 

```C++
virtual void tinyxml2::XMLPrinter::Putc (
    char ch
) 
```




<hr>



### function SealElementIfJustOpened 

```C++
void tinyxml2::XMLPrinter::SealElementIfJustOpened () 
```




<hr>



### function Write [1/2]

```C++
virtual void tinyxml2::XMLPrinter::Write (
    const char * data,
    size_t size
) 
```




<hr>



### function Write [2/2]

```C++
inline void tinyxml2::XMLPrinter::Write (
    const char * data
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

