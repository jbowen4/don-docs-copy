

# Class tinyxml2::XMLDocument



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md)



[More...](#detailed-description)

* `#include <tinyxml2.h>`



Inherits the following classes: [tinyxml2::XMLNode](classtinyxml2_1_1_x_m_l_node.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual bool | [**Accept**](#function-accept) ([**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) \* visitor) override const<br> |
|  void | [**Clear**](#function-clear) () <br>_Clear the document, resetting it to the initial state._  |
|  void | [**ClearError**](#function-clearerror) () <br>_Clears the error flags._  |
|  void | [**DeepCopy**](#function-deepcopy) ([**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md#function-xmldocument-12) \* target) const<br> |
|  void | [**DeleteNode**](#function-deletenode) (XMLNode \* node) <br> |
|  bool | [**Error**](#function-error) () const<br>_Return true if there was an error parsing the document._  |
|  XMLError | [**ErrorID**](#function-errorid) () const<br>_Return the errorID._  |
|  int | [**ErrorLineNum**](#function-errorlinenum) () const<br>_Return the line where the error occurred, or zero if unknown._  |
|  const char \* | [**ErrorName**](#function-errorname) () const<br> |
|  const char \* | [**ErrorStr**](#function-errorstr) () const<br> |
|  bool | [**HasBOM**](#function-hasbom) () const<br> |
|  char \* | [**Identify**](#function-identify) (char \* p, XMLNode \*\* node, bool first) <br> |
|  XMLError | [**LoadFile**](#function-loadfile-12) (const char \* filename) <br> |
|  XMLError | [**LoadFile**](#function-loadfile-22) (FILE \*) <br> |
|  void | [**MarkInUse**](#function-markinuse) (const XMLNode \* const) <br> |
|  XMLComment \* | [**NewComment**](#function-newcomment) (const char \* comment) <br> |
|  XMLDeclaration \* | [**NewDeclaration**](#function-newdeclaration) (const char \* text=0) <br> |
|  XMLElement \* | [**NewElement**](#function-newelement) (const char \* name) <br> |
|  XMLText \* | [**NewText**](#function-newtext) (const char \* text) <br> |
|  XMLUnknown \* | [**NewUnknown**](#function-newunknown) (const char \* text) <br> |
|  XMLError | [**Parse**](#function-parse-12) (const char \* xml, size\_t nBytes=static\_cast&lt; size\_t &gt;(-1)) <br> |
|  void | [**Print**](#function-print) ([**XMLPrinter**](classtinyxml2_1_1_x_m_l_printer.md) \* streamer=0) const<br> |
|  void | [**PrintError**](#function-printerror) () const<br>_A (trivial) utility function that prints the_ [_**ErrorStr()**_](classtinyxml2_1_1_x_m_l_document.md#function-errorstr) _to stdout._ |
|  bool | [**ProcessEntities**](#function-processentities) () const<br> |
|  XMLElement \* | [**RootElement**](#function-rootelement-12) () <br> |
|  const XMLElement \* | [**RootElement**](#function-rootelement-22) () const<br> |
|  XMLError | [**SaveFile**](#function-savefile-12) (const char \* filename, bool compact=false) <br> |
|  XMLError | [**SaveFile**](#function-savefile-22) (FILE \* fp, bool compact=false) <br> |
|  void | [**SetBOM**](#function-setbom) (bool useBOM) <br> |
| virtual XMLNode \* | [**ShallowClone**](#function-shallowclone) ([**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md#function-xmldocument-12) \* document) override const<br> |
| virtual bool | [**ShallowEqual**](#function-shallowequal) (const XMLNode \* compare) override const<br> |
| virtual [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md#function-xmldocument-12) \* | [**ToDocument**](#function-todocument-12) () override<br>_Safely cast to a Document, or null._  |
| virtual const [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md#function-xmldocument-12) \* | [**ToDocument**](#function-todocument-22) () override const<br> |
|  Whitespace | [**WhitespaceMode**](#function-whitespacemode) () const<br> |
|   | [**XMLDocument**](#function-xmldocument-12) (bool processEntities=true, Whitespace whitespaceMode=PRESERVE\_WHITESPACE) <br>_constructor_  |
|   | [**~XMLDocument**](#function-xmldocument) () <br> |


## Public Functions inherited from tinyxml2::XMLNode

See [tinyxml2::XMLNode](classtinyxml2_1_1_x_m_l_node.md)

| Type | Name |
| ---: | :--- |
| virtual bool | [**Accept**](classtinyxml2_1_1_x_m_l_node.md#function-accept) ([**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) \* visitor) const = 0<br> |
|  int | [**ChildElementCount**](classtinyxml2_1_1_x_m_l_node.md#function-childelementcount-12) (const char \* value) const<br> |
|  int | [**ChildElementCount**](classtinyxml2_1_1_x_m_l_node.md#function-childelementcount-22) () const<br> |
|  XMLNode \* | [**DeepClone**](classtinyxml2_1_1_x_m_l_node.md#function-deepclone) (XMLDocument \* target) const<br> |
|  void | [**DeleteChild**](classtinyxml2_1_1_x_m_l_node.md#function-deletechild) (XMLNode \* node) <br> |
|  void | [**DeleteChildren**](classtinyxml2_1_1_x_m_l_node.md#function-deletechildren) () <br> |
|  const XMLNode \* | [**FirstChild**](classtinyxml2_1_1_x_m_l_node.md#function-firstchild-12) () const<br>_Get the first child node, or null if none exists._  |
|  XMLNode \* | [**FirstChild**](classtinyxml2_1_1_x_m_l_node.md#function-firstchild-22) () <br> |
|  const XMLElement \* | [**FirstChildElement**](classtinyxml2_1_1_x_m_l_node.md#function-firstchildelement-12) (const char \* name=0) const<br> |
|  XMLElement \* | [**FirstChildElement**](classtinyxml2_1_1_x_m_l_node.md#function-firstchildelement-22) (const char \* name=0) <br> |
|  const XMLDocument \* | [**GetDocument**](classtinyxml2_1_1_x_m_l_node.md#function-getdocument-12) () const<br>_Get the_ [_**XMLDocument**_](classtinyxml2_1_1_x_m_l_document.md) _that owns this_[_**XMLNode**_](classtinyxml2_1_1_x_m_l_node.md) _._ |
|  XMLDocument \* | [**GetDocument**](classtinyxml2_1_1_x_m_l_node.md#function-getdocument-22) () <br>_Get the_ [_**XMLDocument**_](classtinyxml2_1_1_x_m_l_document.md) _that owns this_[_**XMLNode**_](classtinyxml2_1_1_x_m_l_node.md) _._ |
|  int | [**GetLineNum**](classtinyxml2_1_1_x_m_l_node.md#function-getlinenum) () const<br>_Gets the line number the node is in, if the document was parsed from a file._  |
|  void \* | [**GetUserData**](classtinyxml2_1_1_x_m_l_node.md#function-getuserdata) () const<br> |
|  XMLNode \* | [**InsertAfterChild**](classtinyxml2_1_1_x_m_l_node.md#function-insertafterchild) (XMLNode \* afterThis, XMLNode \* addThis) <br> |
|  XMLNode \* | [**InsertEndChild**](classtinyxml2_1_1_x_m_l_node.md#function-insertendchild) (XMLNode \* addThis) <br> |
|  XMLNode \* | [**InsertFirstChild**](classtinyxml2_1_1_x_m_l_node.md#function-insertfirstchild) (XMLNode \* addThis) <br> |
|  const XMLNode \* | [**LastChild**](classtinyxml2_1_1_x_m_l_node.md#function-lastchild-12) () const<br>_Get the last child node, or null if none exists._  |
|  XMLNode \* | [**LastChild**](classtinyxml2_1_1_x_m_l_node.md#function-lastchild-22) () <br> |
|  const XMLElement \* | [**LastChildElement**](classtinyxml2_1_1_x_m_l_node.md#function-lastchildelement-12) (const char \* name=0) const<br> |
|  XMLElement \* | [**LastChildElement**](classtinyxml2_1_1_x_m_l_node.md#function-lastchildelement-22) (const char \* name=0) <br> |
|  XMLNode \* | [**LinkEndChild**](classtinyxml2_1_1_x_m_l_node.md#function-linkendchild) (XMLNode \* addThis) <br> |
|  const XMLNode \* | [**NextSibling**](classtinyxml2_1_1_x_m_l_node.md#function-nextsibling-12) () const<br>_Get the next (right) sibling node of this node._  |
|  XMLNode \* | [**NextSibling**](classtinyxml2_1_1_x_m_l_node.md#function-nextsibling-22) () <br> |
|  const XMLElement \* | [**NextSiblingElement**](classtinyxml2_1_1_x_m_l_node.md#function-nextsiblingelement-12) (const char \* name=0) const<br>_Get the next (right) sibling element of this node, with an optionally supplied name._  |
|  XMLElement \* | [**NextSiblingElement**](classtinyxml2_1_1_x_m_l_node.md#function-nextsiblingelement-22) (const char \* name=0) <br> |
|  bool | [**NoChildren**](classtinyxml2_1_1_x_m_l_node.md#function-nochildren) () const<br>_Returns true if this node has no children._  |
|  const XMLNode \* | [**Parent**](classtinyxml2_1_1_x_m_l_node.md#function-parent-12) () const<br>_Get the parent of this node on the DOM._  |
|  XMLNode \* | [**Parent**](classtinyxml2_1_1_x_m_l_node.md#function-parent-22) () <br> |
|  const XMLNode \* | [**PreviousSibling**](classtinyxml2_1_1_x_m_l_node.md#function-previoussibling-12) () const<br>_Get the previous (left) sibling node of this node._  |
|  XMLNode \* | [**PreviousSibling**](classtinyxml2_1_1_x_m_l_node.md#function-previoussibling-22) () <br> |
|  const XMLElement \* | [**PreviousSiblingElement**](classtinyxml2_1_1_x_m_l_node.md#function-previoussiblingelement-12) (const char \* name=0) const<br>_Get the previous (left) sibling element of this node, with an optionally supplied name._  |
|  XMLElement \* | [**PreviousSiblingElement**](classtinyxml2_1_1_x_m_l_node.md#function-previoussiblingelement-22) (const char \* name=0) <br> |
|  void | [**SetUserData**](classtinyxml2_1_1_x_m_l_node.md#function-setuserdata) (void \* userData) <br> |
|  void | [**SetValue**](classtinyxml2_1_1_x_m_l_node.md#function-setvalue) (const char \* val, bool staticMem=false) <br> |
| virtual XMLNode \* | [**ShallowClone**](classtinyxml2_1_1_x_m_l_node.md#function-shallowclone) (XMLDocument \* document) const = 0<br> |
| virtual bool | [**ShallowEqual**](classtinyxml2_1_1_x_m_l_node.md#function-shallowequal) (const XMLNode \* compare) const = 0<br> |
| virtual [**XMLComment**](classtinyxml2_1_1_x_m_l_comment.md) \* | [**ToComment**](classtinyxml2_1_1_x_m_l_node.md#function-tocomment-12) () <br>_Safely cast to a Comment, or null._  |
| virtual const [**XMLComment**](classtinyxml2_1_1_x_m_l_comment.md) \* | [**ToComment**](classtinyxml2_1_1_x_m_l_node.md#function-tocomment-22) () const<br> |
| virtual [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) \* | [**ToDeclaration**](classtinyxml2_1_1_x_m_l_node.md#function-todeclaration-12) () <br>_Safely cast to a Declaration, or null._  |
| virtual const [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) \* | [**ToDeclaration**](classtinyxml2_1_1_x_m_l_node.md#function-todeclaration-22) () const<br> |
| virtual XMLDocument \* | [**ToDocument**](classtinyxml2_1_1_x_m_l_node.md#function-todocument-12) () <br>_Safely cast to a Document, or null._  |
| virtual const XMLDocument \* | [**ToDocument**](classtinyxml2_1_1_x_m_l_node.md#function-todocument-22) () const<br> |
| virtual XMLElement \* | [**ToElement**](classtinyxml2_1_1_x_m_l_node.md#function-toelement-12) () <br>_Safely cast to an Element, or null._  |
| virtual const XMLElement \* | [**ToElement**](classtinyxml2_1_1_x_m_l_node.md#function-toelement-22) () const<br> |
| virtual [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) \* | [**ToText**](classtinyxml2_1_1_x_m_l_node.md#function-totext-12) () <br>_Safely cast to Text, or null._  |
| virtual const [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) \* | [**ToText**](classtinyxml2_1_1_x_m_l_node.md#function-totext-22) () const<br> |
| virtual [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) \* | [**ToUnknown**](classtinyxml2_1_1_x_m_l_node.md#function-tounknown-12) () <br>_Safely cast to an Unknown, or null._  |
| virtual const [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) \* | [**ToUnknown**](classtinyxml2_1_1_x_m_l_node.md#function-tounknown-22) () const<br> |
|  const char \* | [**Value**](classtinyxml2_1_1_x_m_l_node.md#function-value) () const<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const char \* | [**ErrorIDToName**](#function-erroridtoname) (XMLError errorID) <br> |














## Protected Attributes inherited from tinyxml2::XMLNode

See [tinyxml2::XMLNode](classtinyxml2_1_1_x_m_l_node.md)

| Type | Name |
| ---: | :--- |
|  XMLDocument \* | [**\_document**](classtinyxml2_1_1_x_m_l_node.md#variable-_document)  <br> |
|  XMLNode \* | [**\_firstChild**](classtinyxml2_1_1_x_m_l_node.md#variable-_firstchild)  <br> |
|  XMLNode \* | [**\_lastChild**](classtinyxml2_1_1_x_m_l_node.md#variable-_lastchild)  <br> |
|  XMLNode \* | [**\_next**](classtinyxml2_1_1_x_m_l_node.md#variable-_next)  <br> |
|  XMLNode \* | [**\_parent**](classtinyxml2_1_1_x_m_l_node.md#variable-_parent)  <br> |
|  int | [**\_parseLineNum**](classtinyxml2_1_1_x_m_l_node.md#variable-_parselinenum)  <br> |
|  XMLNode \* | [**\_prev**](classtinyxml2_1_1_x_m_l_node.md#variable-_prev)  <br> |
|  void \* | [**\_userData**](classtinyxml2_1_1_x_m_l_node.md#variable-_userdata)  <br> |
|  [**StrPair**](classtinyxml2_1_1_str_pair.md) | [**\_value**](classtinyxml2_1_1_x_m_l_node.md#variable-_value)  <br> |
































## Protected Functions inherited from tinyxml2::XMLNode

See [tinyxml2::XMLNode](classtinyxml2_1_1_x_m_l_node.md)

| Type | Name |
| ---: | :--- |
| virtual char \* | [**ParseDeep**](classtinyxml2_1_1_x_m_l_node.md#function-parsedeep) (char \* p, [**StrPair**](classtinyxml2_1_1_str_pair.md) \* parentEndTag, int \* curLineNumPtr) <br> |
|   | [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md#function-xmlnode-12) (XMLDocument \*) <br> |
| virtual  | [**~XMLNode**](classtinyxml2_1_1_x_m_l_node.md#function-xmlnode) () <br> |






## Detailed Description


A Document binds together all the functionality. It can be saved, loaded, and printed to the screen. All Nodes are connected and allocated to a Document. If the Document is deleted, all its Nodes are also deleted. 


    
## Public Functions Documentation




### function Accept 

```C++
virtual bool tinyxml2::XMLDocument::Accept (
    XMLVisitor * visitor
) override const
```



Accept a hierarchical visit of the nodes in the TinyXML-2 DOM. Every node in the XML tree will be conditionally visited and the host will be called back via the [**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) interface.


This is essentially a SAX interface for TinyXML-2. (Note however it doesn't re-parse the XML for the callbacks, so the performance of TinyXML-2 is unchanged by using this interface versus any other.)


The interface has been based on ideas from:



* [http://www.saxproject.org/](http://www.saxproject.org/)
* [http://c2.com/cgi/wiki?HierarchicalVisitorPattern](http://c2.com/cgi/wiki?HierarchicalVisitorPattern)




Which are both good references for "visiting".


An example of using [**Accept()**](classtinyxml2_1_1_x_m_l_document.md#function-accept):  


        
Implements [*tinyxml2::XMLNode::Accept*](classtinyxml2_1_1_x_m_l_node.md#function-accept)


<hr>



### function Clear 

_Clear the document, resetting it to the initial state._ 
```C++
void tinyxml2::XMLDocument::Clear () 
```




<hr>



### function ClearError 

_Clears the error flags._ 
```C++
void tinyxml2::XMLDocument::ClearError () 
```




<hr>



### function DeepCopy 

```C++
void tinyxml2::XMLDocument::DeepCopy (
    XMLDocument * target
) const
```



Copies this document to a target document. The target will be completely cleared before the copy. If you want to copy a sub-tree, see [**XMLNode::DeepClone()**](classtinyxml2_1_1_x_m_l_node.md#function-deepclone).


NOTE: that the 'target' must be non-null. 


        

<hr>



### function DeleteNode 

```C++
void tinyxml2::XMLDocument::DeleteNode (
    XMLNode * node
) 
```



Delete a node associated with this document. It will be unlinked from the DOM. 


        

<hr>



### function Error 

_Return true if there was an error parsing the document._ 
```C++
inline bool tinyxml2::XMLDocument::Error () const
```




<hr>



### function ErrorID 

_Return the errorID._ 
```C++
inline XMLError tinyxml2::XMLDocument::ErrorID () const
```




<hr>



### function ErrorLineNum 

_Return the line where the error occurred, or zero if unknown._ 
```C++
inline int tinyxml2::XMLDocument::ErrorLineNum () const
```




<hr>



### function ErrorName 

```C++
const char * tinyxml2::XMLDocument::ErrorName () const
```




<hr>



### function ErrorStr 

```C++
const char * tinyxml2::XMLDocument::ErrorStr () const
```



Returns a "long form" error description. A hopefully helpful diagnostic with location, line number, and/or additional info. 


        

<hr>



### function HasBOM 

```C++
inline bool tinyxml2::XMLDocument::HasBOM () const
```



Returns true if this document has a leading Byte Order Mark of UTF8. 


        

<hr>



### function Identify 

```C++
char * tinyxml2::XMLDocument::Identify (
    char * p,
    XMLNode ** node,
    bool first
) 
```




<hr>



### function LoadFile [1/2]

```C++
XMLError tinyxml2::XMLDocument::LoadFile (
    const char * filename
) 
```



Load an XML file from disk. Returns XML\_SUCCESS (0) on success, or an errorID. 


        

<hr>



### function LoadFile [2/2]

```C++
XMLError tinyxml2::XMLDocument::LoadFile (
    FILE *
) 
```



Load an XML file from disk. You are responsible for providing and closing the FILE\*.


NOTE: The file should be opened as binary ("rb") not text in order for TinyXML-2 to correctly do newline normalization.


Returns XML\_SUCCESS (0) on success, or an errorID. 


        

<hr>



### function MarkInUse 

```C++
void tinyxml2::XMLDocument::MarkInUse (
    const XMLNode * const
) 
```




<hr>



### function NewComment 

```C++
XMLComment * tinyxml2::XMLDocument::NewComment (
    const char * comment
) 
```



Create a new Comment associated with this Document. The memory for the Comment is managed by the Document. 


        

<hr>



### function NewDeclaration 

```C++
XMLDeclaration * tinyxml2::XMLDocument::NewDeclaration (
    const char * text=0
) 
```



Create a new Declaration associated with this Document. The memory for the object is managed by the Document.


If the 'text' param is null, the standard declaration is used.:  


        

<hr>



### function NewElement 

```C++
XMLElement * tinyxml2::XMLDocument::NewElement (
    const char * name
) 
```



Create a new Element associated with this Document. The memory for the Element is managed by the Document. 


        

<hr>



### function NewText 

```C++
XMLText * tinyxml2::XMLDocument::NewText (
    const char * text
) 
```



Create a new Text associated with this Document. The memory for the Text is managed by the Document. 


        

<hr>



### function NewUnknown 

```C++
XMLUnknown * tinyxml2::XMLDocument::NewUnknown (
    const char * text
) 
```



Create a new Unknown associated with this Document. The memory for the object is managed by the Document. 


        

<hr>



### function Parse [1/2]

```C++
XMLError tinyxml2::XMLDocument::Parse (
    const char * xml,
    size_t nBytes=static_cast< size_t >(-1)
) 
```



Parse an XML file from a character string. Returns XML\_SUCCESS (0) on success, or an errorID.


You may optionally pass in the 'nBytes', which is the number of bytes which will be parsed. If not specified, TinyXML-2 will assume 'xml' points to a null terminated string. 


        

<hr>



### function Print 

```C++
void tinyxml2::XMLDocument::Print (
    XMLPrinter * streamer=0
) const
```



Print the Document. If the Printer is not provided, it will print to stdout. If you provide Printer, this can print to a file: 


Or you can use a printer to print to memory:  


        

<hr>



### function PrintError 

_A (trivial) utility function that prints the_ [_**ErrorStr()**_](classtinyxml2_1_1_x_m_l_document.md#function-errorstr) _to stdout._
```C++
void tinyxml2::XMLDocument::PrintError () const
```




<hr>



### function ProcessEntities 

```C++
inline bool tinyxml2::XMLDocument::ProcessEntities () const
```




<hr>



### function RootElement [1/2]

```C++
inline XMLElement * tinyxml2::XMLDocument::RootElement () 
```



Return the root element of DOM. Equivalent to [**FirstChildElement()**](classtinyxml2_1_1_x_m_l_node.md#function-firstchildelement-12). To get the first node, use [**FirstChild()**](classtinyxml2_1_1_x_m_l_node.md#function-firstchild-12). 


        

<hr>



### function RootElement [2/2]

```C++
inline const XMLElement * tinyxml2::XMLDocument::RootElement () const
```




<hr>



### function SaveFile [1/2]

```C++
XMLError tinyxml2::XMLDocument::SaveFile (
    const char * filename,
    bool compact=false
) 
```



Save the XML file to disk. Returns XML\_SUCCESS (0) on success, or an errorID. 


        

<hr>



### function SaveFile [2/2]

```C++
XMLError tinyxml2::XMLDocument::SaveFile (
    FILE * fp,
    bool compact=false
) 
```



Save the XML file to disk. You are responsible for providing and closing the FILE\*.


Returns XML\_SUCCESS (0) on success, or an errorID. 


        

<hr>



### function SetBOM 

```C++
inline void tinyxml2::XMLDocument::SetBOM (
    bool useBOM
) 
```



Sets whether to write the BOM when writing the file. 


        

<hr>



### function ShallowClone 

```C++
inline virtual XMLNode * tinyxml2::XMLDocument::ShallowClone (
    XMLDocument * document
) override const
```



Make a copy of this node, but not its children. You may pass in a Document pointer that will be the owner of the new Node. If the 'document' is null, then the node returned will be allocated from the current Document. (this-&gt;[**GetDocument()**](classtinyxml2_1_1_x_m_l_node.md#function-getdocument-22))


Note: if called on a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md), this will return null. 


        
Implements [*tinyxml2::XMLNode::ShallowClone*](classtinyxml2_1_1_x_m_l_node.md#function-shallowclone)


<hr>



### function ShallowEqual 

```C++
inline virtual bool tinyxml2::XMLDocument::ShallowEqual (
    const XMLNode * compare
) override const
```



Test if 2 nodes are the same, but don't test children. The 2 nodes do not need to be in the same Document.


Note: if called on a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md), this will return false. 


        
Implements [*tinyxml2::XMLNode::ShallowEqual*](classtinyxml2_1_1_x_m_l_node.md#function-shallowequal)


<hr>



### function ToDocument [1/2]

_Safely cast to a Document, or null._ 
```C++
inline virtual XMLDocument * tinyxml2::XMLDocument::ToDocument () override
```



Implements [*tinyxml2::XMLNode::ToDocument*](classtinyxml2_1_1_x_m_l_node.md#function-todocument-12)


<hr>



### function ToDocument [2/2]

```C++
inline virtual const XMLDocument * tinyxml2::XMLDocument::ToDocument () override const
```



Implements [*tinyxml2::XMLNode::ToDocument*](classtinyxml2_1_1_x_m_l_node.md#function-todocument-22)


<hr>



### function WhitespaceMode 

```C++
inline Whitespace tinyxml2::XMLDocument::WhitespaceMode () const
```




<hr>



### function XMLDocument [1/2]

_constructor_ 
```C++
tinyxml2::XMLDocument::XMLDocument (
    bool processEntities=true,
    Whitespace whitespaceMode=PRESERVE_WHITESPACE
) 
```




<hr>



### function ~XMLDocument 

```C++
tinyxml2::XMLDocument::~XMLDocument () 
```




<hr>
## Public Static Functions Documentation




### function ErrorIDToName 

```C++
static const char * tinyxml2::XMLDocument::ErrorIDToName (
    XMLError errorID
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

