

# Class tinyxml2::XMLNode



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md)



[More...](#detailed-description)

* `#include <tinyxml2.h>`





Inherited by the following classes: [tinyxml2::XMLComment](classtinyxml2_1_1_x_m_l_comment.md),  [tinyxml2::XMLDeclaration](classtinyxml2_1_1_x_m_l_declaration.md),  [tinyxml2::XMLDocument](classtinyxml2_1_1_x_m_l_document.md),  [tinyxml2::XMLElement](classtinyxml2_1_1_x_m_l_element.md),  [tinyxml2::XMLText](classtinyxml2_1_1_x_m_l_text.md),  [tinyxml2::XMLUnknown](classtinyxml2_1_1_x_m_l_unknown.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual bool | [**Accept**](#function-accept) ([**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) \* visitor) const = 0<br> |
|  int | [**ChildElementCount**](#function-childelementcount-12) (const char \* value) const<br> |
|  int | [**ChildElementCount**](#function-childelementcount-22) () const<br> |
|  XMLNode \* | [**DeepClone**](#function-deepclone) (XMLDocument \* target) const<br> |
|  void | [**DeleteChild**](#function-deletechild) (XMLNode \* node) <br> |
|  void | [**DeleteChildren**](#function-deletechildren) () <br> |
|  const XMLNode \* | [**FirstChild**](#function-firstchild-12) () const<br>_Get the first child node, or null if none exists._  |
|  XMLNode \* | [**FirstChild**](#function-firstchild-22) () <br> |
|  const XMLElement \* | [**FirstChildElement**](#function-firstchildelement-12) (const char \* name=0) const<br> |
|  XMLElement \* | [**FirstChildElement**](#function-firstchildelement-22) (const char \* name=0) <br> |
|  const XMLDocument \* | [**GetDocument**](#function-getdocument-12) () const<br>_Get the_ [_**XMLDocument**_](classtinyxml2_1_1_x_m_l_document.md) _that owns this_[_**XMLNode**_](classtinyxml2_1_1_x_m_l_node.md) _._ |
|  XMLDocument \* | [**GetDocument**](#function-getdocument-22) () <br>_Get the_ [_**XMLDocument**_](classtinyxml2_1_1_x_m_l_document.md) _that owns this_[_**XMLNode**_](classtinyxml2_1_1_x_m_l_node.md) _._ |
|  int | [**GetLineNum**](#function-getlinenum) () const<br>_Gets the line number the node is in, if the document was parsed from a file._  |
|  void \* | [**GetUserData**](#function-getuserdata) () const<br> |
|  XMLNode \* | [**InsertAfterChild**](#function-insertafterchild) (XMLNode \* afterThis, XMLNode \* addThis) <br> |
|  XMLNode \* | [**InsertEndChild**](#function-insertendchild) (XMLNode \* addThis) <br> |
|  XMLNode \* | [**InsertFirstChild**](#function-insertfirstchild) (XMLNode \* addThis) <br> |
|  const XMLNode \* | [**LastChild**](#function-lastchild-12) () const<br>_Get the last child node, or null if none exists._  |
|  XMLNode \* | [**LastChild**](#function-lastchild-22) () <br> |
|  const XMLElement \* | [**LastChildElement**](#function-lastchildelement-12) (const char \* name=0) const<br> |
|  XMLElement \* | [**LastChildElement**](#function-lastchildelement-22) (const char \* name=0) <br> |
|  XMLNode \* | [**LinkEndChild**](#function-linkendchild) (XMLNode \* addThis) <br> |
|  const XMLNode \* | [**NextSibling**](#function-nextsibling-12) () const<br>_Get the next (right) sibling node of this node._  |
|  XMLNode \* | [**NextSibling**](#function-nextsibling-22) () <br> |
|  const XMLElement \* | [**NextSiblingElement**](#function-nextsiblingelement-12) (const char \* name=0) const<br>_Get the next (right) sibling element of this node, with an optionally supplied name._  |
|  XMLElement \* | [**NextSiblingElement**](#function-nextsiblingelement-22) (const char \* name=0) <br> |
|  bool | [**NoChildren**](#function-nochildren) () const<br>_Returns true if this node has no children._  |
|  const XMLNode \* | [**Parent**](#function-parent-12) () const<br>_Get the parent of this node on the DOM._  |
|  XMLNode \* | [**Parent**](#function-parent-22) () <br> |
|  const XMLNode \* | [**PreviousSibling**](#function-previoussibling-12) () const<br>_Get the previous (left) sibling node of this node._  |
|  XMLNode \* | [**PreviousSibling**](#function-previoussibling-22) () <br> |
|  const XMLElement \* | [**PreviousSiblingElement**](#function-previoussiblingelement-12) (const char \* name=0) const<br>_Get the previous (left) sibling element of this node, with an optionally supplied name._  |
|  XMLElement \* | [**PreviousSiblingElement**](#function-previoussiblingelement-22) (const char \* name=0) <br> |
|  void | [**SetUserData**](#function-setuserdata) (void \* userData) <br> |
|  void | [**SetValue**](#function-setvalue) (const char \* val, bool staticMem=false) <br> |
| virtual XMLNode \* | [**ShallowClone**](#function-shallowclone) (XMLDocument \* document) const = 0<br> |
| virtual bool | [**ShallowEqual**](#function-shallowequal) (const XMLNode \* compare) const = 0<br> |
| virtual [**XMLComment**](classtinyxml2_1_1_x_m_l_comment.md) \* | [**ToComment**](#function-tocomment-12) () <br>_Safely cast to a Comment, or null._  |
| virtual const [**XMLComment**](classtinyxml2_1_1_x_m_l_comment.md) \* | [**ToComment**](#function-tocomment-22) () const<br> |
| virtual [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) \* | [**ToDeclaration**](#function-todeclaration-12) () <br>_Safely cast to a Declaration, or null._  |
| virtual const [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) \* | [**ToDeclaration**](#function-todeclaration-22) () const<br> |
| virtual XMLDocument \* | [**ToDocument**](#function-todocument-12) () <br>_Safely cast to a Document, or null._  |
| virtual const XMLDocument \* | [**ToDocument**](#function-todocument-22) () const<br> |
| virtual XMLElement \* | [**ToElement**](#function-toelement-12) () <br>_Safely cast to an Element, or null._  |
| virtual const XMLElement \* | [**ToElement**](#function-toelement-22) () const<br> |
| virtual [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) \* | [**ToText**](#function-totext-12) () <br>_Safely cast to Text, or null._  |
| virtual const [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) \* | [**ToText**](#function-totext-22) () const<br> |
| virtual [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) \* | [**ToUnknown**](#function-tounknown-12) () <br>_Safely cast to an Unknown, or null._  |
| virtual const [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) \* | [**ToUnknown**](#function-tounknown-22) () const<br> |
|  const char \* | [**Value**](#function-value) () const<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  XMLDocument \* | [**\_document**](#variable-_document)  <br> |
|  XMLNode \* | [**\_firstChild**](#variable-_firstchild)  <br> |
|  XMLNode \* | [**\_lastChild**](#variable-_lastchild)  <br> |
|  XMLNode \* | [**\_next**](#variable-_next)  <br> |
|  XMLNode \* | [**\_parent**](#variable-_parent)  <br> |
|  int | [**\_parseLineNum**](#variable-_parselinenum)  <br> |
|  XMLNode \* | [**\_prev**](#variable-_prev)  <br> |
|  void \* | [**\_userData**](#variable-_userdata)  <br> |
|  [**StrPair**](classtinyxml2_1_1_str_pair.md) | [**\_value**](#variable-_value)  <br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual char \* | [**ParseDeep**](#function-parsedeep) (char \* p, [**StrPair**](classtinyxml2_1_1_str_pair.md) \* parentEndTag, int \* curLineNumPtr) <br> |
|   | [**XMLNode**](#function-xmlnode-12) (XMLDocument \*) <br> |
| virtual  | [**~XMLNode**](#function-xmlnode) () <br> |




## Detailed Description


[**XMLNode**](classtinyxml2_1_1_x_m_l_node.md) is a base class for every object that is in the XML Document Object Model (DOM), except XMLAttributes. Nodes have siblings, a parent, and children which can be navigated. A node is always in a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md). The type of a [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md) can be queried, and it can be cast to its more defined type.


A [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md) allocates memory for all its Nodes. When the [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md) gets deleted, all its Nodes will also be deleted.


 


    
## Public Functions Documentation




### function Accept 

```C++
virtual bool tinyxml2::XMLNode::Accept (
    XMLVisitor * visitor
) const = 0
```



Accept a hierarchical visit of the nodes in the TinyXML-2 DOM. Every node in the XML tree will be conditionally visited and the host will be called back via the [**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) interface.


This is essentially a SAX interface for TinyXML-2. (Note however it doesn't re-parse the XML for the callbacks, so the performance of TinyXML-2 is unchanged by using this interface versus any other.)


The interface has been based on ideas from:



* [http://www.saxproject.org/](http://www.saxproject.org/)
* [http://c2.com/cgi/wiki?HierarchicalVisitorPattern](http://c2.com/cgi/wiki?HierarchicalVisitorPattern)




Which are both good references for "visiting".


An example of using [**Accept()**](classtinyxml2_1_1_x_m_l_node.md#function-accept):  


        

<hr>



### function ChildElementCount [1/2]

```C++
int tinyxml2::XMLNode::ChildElementCount (
    const char * value
) const
```




<hr>



### function ChildElementCount [2/2]

```C++
int tinyxml2::XMLNode::ChildElementCount () const
```




<hr>



### function DeepClone 

```C++
XMLNode * tinyxml2::XMLNode::DeepClone (
    XMLDocument * target
) const
```



Make a copy of this node and all its children.


If the 'target' is null, then the nodes will be allocated in the current document. If 'target' is specified, the memory will be allocated is the specified [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md).


NOTE: This is probably not the correct tool to copy a document, since XMLDocuments can have multiple top level XMLNodes. You probably want to use [**XMLDocument::DeepCopy()**](classtinyxml2_1_1_x_m_l_document.md#function-deepcopy) 


        

<hr>



### function DeleteChild 

```C++
void tinyxml2::XMLNode::DeleteChild (
    XMLNode * node
) 
```



Delete a child of this node. 


        

<hr>



### function DeleteChildren 

```C++
void tinyxml2::XMLNode::DeleteChildren () 
```



Delete all the children of this node. 


        

<hr>



### function FirstChild [1/2]

_Get the first child node, or null if none exists._ 
```C++
inline const XMLNode * tinyxml2::XMLNode::FirstChild () const
```




<hr>



### function FirstChild [2/2]

```C++
inline XMLNode * tinyxml2::XMLNode::FirstChild () 
```




<hr>



### function FirstChildElement [1/2]

```C++
const XMLElement * tinyxml2::XMLNode::FirstChildElement (
    const char * name=0
) const
```



Get the first child element, or optionally the first child element with the specified name. 


        

<hr>



### function FirstChildElement [2/2]

```C++
inline XMLElement * tinyxml2::XMLNode::FirstChildElement (
    const char * name=0
) 
```




<hr>



### function GetDocument [1/2]

_Get the_ [_**XMLDocument**_](classtinyxml2_1_1_x_m_l_document.md) _that owns this_[_**XMLNode**_](classtinyxml2_1_1_x_m_l_node.md) _._
```C++
inline const XMLDocument * tinyxml2::XMLNode::GetDocument () const
```




<hr>



### function GetDocument [2/2]

_Get the_ [_**XMLDocument**_](classtinyxml2_1_1_x_m_l_document.md) _that owns this_[_**XMLNode**_](classtinyxml2_1_1_x_m_l_node.md) _._
```C++
inline XMLDocument * tinyxml2::XMLNode::GetDocument () 
```




<hr>



### function GetLineNum 

_Gets the line number the node is in, if the document was parsed from a file._ 
```C++
inline int tinyxml2::XMLNode::GetLineNum () const
```




<hr>



### function GetUserData 

```C++
inline void * tinyxml2::XMLNode::GetUserData () const
```



Get user data set into the [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md). TinyXML-2 in no way processes or interprets user data. It is initially 0. 


        

<hr>



### function InsertAfterChild 

```C++
XMLNode * tinyxml2::XMLNode::InsertAfterChild (
    XMLNode * afterThis,
    XMLNode * addThis
) 
```



Add a node after the specified child node. If the child node is already part of the document, it is moved from its old location to the new location. Returns the addThis argument or 0 if the afterThis node is not a child of this node, or if the node does not belong to the same document. 


        

<hr>



### function InsertEndChild 

```C++
XMLNode * tinyxml2::XMLNode::InsertEndChild (
    XMLNode * addThis
) 
```



Add a child node as the last (right) child. If the child node is already part of the document, it is moved from its old location to the new location. Returns the addThis argument or 0 if the node does not belong to the same document. 


        

<hr>



### function InsertFirstChild 

```C++
XMLNode * tinyxml2::XMLNode::InsertFirstChild (
    XMLNode * addThis
) 
```



Add a child node as the first (left) child. If the child node is already part of the document, it is moved from its old location to the new location. Returns the addThis argument or 0 if the node does not belong to the same document. 


        

<hr>



### function LastChild [1/2]

_Get the last child node, or null if none exists._ 
```C++
inline const XMLNode * tinyxml2::XMLNode::LastChild () const
```




<hr>



### function LastChild [2/2]

```C++
inline XMLNode * tinyxml2::XMLNode::LastChild () 
```




<hr>



### function LastChildElement [1/2]

```C++
const XMLElement * tinyxml2::XMLNode::LastChildElement (
    const char * name=0
) const
```



Get the last child element or optionally the last child element with the specified name. 


        

<hr>



### function LastChildElement [2/2]

```C++
inline XMLElement * tinyxml2::XMLNode::LastChildElement (
    const char * name=0
) 
```




<hr>



### function LinkEndChild 

```C++
inline XMLNode * tinyxml2::XMLNode::LinkEndChild (
    XMLNode * addThis
) 
```




<hr>



### function NextSibling [1/2]

_Get the next (right) sibling node of this node._ 
```C++
inline const XMLNode * tinyxml2::XMLNode::NextSibling () const
```




<hr>



### function NextSibling [2/2]

```C++
inline XMLNode * tinyxml2::XMLNode::NextSibling () 
```




<hr>



### function NextSiblingElement [1/2]

_Get the next (right) sibling element of this node, with an optionally supplied name._ 
```C++
const XMLElement * tinyxml2::XMLNode::NextSiblingElement (
    const char * name=0
) const
```




<hr>



### function NextSiblingElement [2/2]

```C++
inline XMLElement * tinyxml2::XMLNode::NextSiblingElement (
    const char * name=0
) 
```




<hr>



### function NoChildren 

_Returns true if this node has no children._ 
```C++
inline bool tinyxml2::XMLNode::NoChildren () const
```




<hr>



### function Parent [1/2]

_Get the parent of this node on the DOM._ 
```C++
inline const XMLNode * tinyxml2::XMLNode::Parent () const
```




<hr>



### function Parent [2/2]

```C++
inline XMLNode * tinyxml2::XMLNode::Parent () 
```




<hr>



### function PreviousSibling [1/2]

_Get the previous (left) sibling node of this node._ 
```C++
inline const XMLNode * tinyxml2::XMLNode::PreviousSibling () const
```




<hr>



### function PreviousSibling [2/2]

```C++
inline XMLNode * tinyxml2::XMLNode::PreviousSibling () 
```




<hr>



### function PreviousSiblingElement [1/2]

_Get the previous (left) sibling element of this node, with an optionally supplied name._ 
```C++
const XMLElement * tinyxml2::XMLNode::PreviousSiblingElement (
    const char * name=0
) const
```




<hr>



### function PreviousSiblingElement [2/2]

```C++
inline XMLElement * tinyxml2::XMLNode::PreviousSiblingElement (
    const char * name=0
) 
```




<hr>



### function SetUserData 

```C++
inline void tinyxml2::XMLNode::SetUserData (
    void * userData
) 
```



Set user data into the [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md). TinyXML-2 in no way processes or interprets user data. It is initially 0. 


        

<hr>



### function SetValue 

```C++
void tinyxml2::XMLNode::SetValue (
    const char * val,
    bool staticMem=false
) 
```



Set the Value of an XML node. 

**See also:** [**Value()**](classtinyxml2_1_1_x_m_l_node.md#function-value) 



        

<hr>



### function ShallowClone 

```C++
virtual XMLNode * tinyxml2::XMLNode::ShallowClone (
    XMLDocument * document
) const = 0
```



Make a copy of this node, but not its children. You may pass in a Document pointer that will be the owner of the new Node. If the 'document' is null, then the node returned will be allocated from the current Document. (this-&gt;[**GetDocument()**](classtinyxml2_1_1_x_m_l_node.md#function-getdocument-22))


Note: if called on a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md), this will return null. 


        

<hr>



### function ShallowEqual 

```C++
virtual bool tinyxml2::XMLNode::ShallowEqual (
    const XMLNode * compare
) const = 0
```



Test if 2 nodes are the same, but don't test children. The 2 nodes do not need to be in the same Document.


Note: if called on a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md), this will return false. 


        

<hr>



### function ToComment [1/2]

_Safely cast to a Comment, or null._ 
```C++
inline virtual XMLComment * tinyxml2::XMLNode::ToComment () 
```




<hr>



### function ToComment [2/2]

```C++
inline virtual const XMLComment * tinyxml2::XMLNode::ToComment () const
```




<hr>



### function ToDeclaration [1/2]

_Safely cast to a Declaration, or null._ 
```C++
inline virtual XMLDeclaration * tinyxml2::XMLNode::ToDeclaration () 
```




<hr>



### function ToDeclaration [2/2]

```C++
inline virtual const XMLDeclaration * tinyxml2::XMLNode::ToDeclaration () const
```




<hr>



### function ToDocument [1/2]

_Safely cast to a Document, or null._ 
```C++
inline virtual XMLDocument * tinyxml2::XMLNode::ToDocument () 
```




<hr>



### function ToDocument [2/2]

```C++
inline virtual const XMLDocument * tinyxml2::XMLNode::ToDocument () const
```




<hr>



### function ToElement [1/2]

_Safely cast to an Element, or null._ 
```C++
inline virtual XMLElement * tinyxml2::XMLNode::ToElement () 
```




<hr>



### function ToElement [2/2]

```C++
inline virtual const XMLElement * tinyxml2::XMLNode::ToElement () const
```




<hr>



### function ToText [1/2]

_Safely cast to Text, or null._ 
```C++
inline virtual XMLText * tinyxml2::XMLNode::ToText () 
```




<hr>



### function ToText [2/2]

```C++
inline virtual const XMLText * tinyxml2::XMLNode::ToText () const
```




<hr>



### function ToUnknown [1/2]

_Safely cast to an Unknown, or null._ 
```C++
inline virtual XMLUnknown * tinyxml2::XMLNode::ToUnknown () 
```




<hr>



### function ToUnknown [2/2]

```C++
inline virtual const XMLUnknown * tinyxml2::XMLNode::ToUnknown () const
```




<hr>



### function Value 

```C++
const char * tinyxml2::XMLNode::Value () const
```



The meaning of 'value' changes for the specific type.  


        

<hr>
## Protected Attributes Documentation




### variable \_document 

```C++
XMLDocument* tinyxml2::XMLNode::_document;
```




<hr>



### variable \_firstChild 

```C++
XMLNode* tinyxml2::XMLNode::_firstChild;
```




<hr>



### variable \_lastChild 

```C++
XMLNode* tinyxml2::XMLNode::_lastChild;
```




<hr>



### variable \_next 

```C++
XMLNode* tinyxml2::XMLNode::_next;
```




<hr>



### variable \_parent 

```C++
XMLNode* tinyxml2::XMLNode::_parent;
```




<hr>



### variable \_parseLineNum 

```C++
int tinyxml2::XMLNode::_parseLineNum;
```




<hr>



### variable \_prev 

```C++
XMLNode* tinyxml2::XMLNode::_prev;
```




<hr>



### variable \_userData 

```C++
void* tinyxml2::XMLNode::_userData;
```




<hr>



### variable \_value 

```C++
StrPair tinyxml2::XMLNode::_value;
```




<hr>
## Protected Functions Documentation




### function ParseDeep 

```C++
virtual char * tinyxml2::XMLNode::ParseDeep (
    char * p,
    StrPair * parentEndTag,
    int * curLineNumPtr
) 
```




<hr>



### function XMLNode [1/2]

```C++
explicit tinyxml2::XMLNode::XMLNode (
    XMLDocument *
) 
```




<hr>



### function ~XMLNode 

```C++
virtual tinyxml2::XMLNode::~XMLNode () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

