

# Class tinyxml2::XMLComment



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**XMLComment**](classtinyxml2_1_1_x_m_l_comment.md)



[More...](#detailed-description)

* `#include <tinyxml2.h>`



Inherits the following classes: [tinyxml2::XMLNode](classtinyxml2_1_1_x_m_l_node.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual bool | [**Accept**](#function-accept) ([**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) \* visitor) override const<br> |
| virtual XMLNode \* | [**ShallowClone**](#function-shallowclone) (XMLDocument \* document) override const<br> |
| virtual bool | [**ShallowEqual**](#function-shallowequal) (const XMLNode \* compare) override const<br> |
| virtual XMLComment \* | [**ToComment**](#function-tocomment-12) () override<br>_Safely cast to a Comment, or null._  |
| virtual const XMLComment \* | [**ToComment**](#function-tocomment-22) () override const<br> |


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






























## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual char \* | [**ParseDeep**](#function-parsedeep) (char \* p, [**StrPair**](classtinyxml2_1_1_str_pair.md) \* parentEndTag, int \* curLineNumPtr) override<br> |
|   | [**XMLComment**](#function-xmlcomment-12) (XMLDocument \* doc) <br> |
| virtual  | [**~XMLComment**](#function-xmlcomment) () <br> |


## Protected Functions inherited from tinyxml2::XMLNode

See [tinyxml2::XMLNode](classtinyxml2_1_1_x_m_l_node.md)

| Type | Name |
| ---: | :--- |
| virtual char \* | [**ParseDeep**](classtinyxml2_1_1_x_m_l_node.md#function-parsedeep) (char \* p, [**StrPair**](classtinyxml2_1_1_str_pair.md) \* parentEndTag, int \* curLineNumPtr) <br> |
|   | [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md#function-xmlnode-12) (XMLDocument \*) <br> |
| virtual  | [**~XMLNode**](classtinyxml2_1_1_x_m_l_node.md#function-xmlnode) () <br> |






## Detailed Description


An XML Comment. 


    
## Public Functions Documentation




### function Accept 

```C++
virtual bool tinyxml2::XMLComment::Accept (
    XMLVisitor * visitor
) override const
```



Accept a hierarchical visit of the nodes in the TinyXML-2 DOM. Every node in the XML tree will be conditionally visited and the host will be called back via the [**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) interface.


This is essentially a SAX interface for TinyXML-2. (Note however it doesn't re-parse the XML for the callbacks, so the performance of TinyXML-2 is unchanged by using this interface versus any other.)


The interface has been based on ideas from:



* [http://www.saxproject.org/](http://www.saxproject.org/)
* [http://c2.com/cgi/wiki?HierarchicalVisitorPattern](http://c2.com/cgi/wiki?HierarchicalVisitorPattern)




Which are both good references for "visiting".


An example of using [**Accept()**](classtinyxml2_1_1_x_m_l_comment.md#function-accept):  


        
Implements [*tinyxml2::XMLNode::Accept*](classtinyxml2_1_1_x_m_l_node.md#function-accept)


<hr>



### function ShallowClone 

```C++
virtual XMLNode * tinyxml2::XMLComment::ShallowClone (
    XMLDocument * document
) override const
```



Make a copy of this node, but not its children. You may pass in a Document pointer that will be the owner of the new Node. If the 'document' is null, then the node returned will be allocated from the current Document. (this-&gt;[**GetDocument()**](classtinyxml2_1_1_x_m_l_node.md#function-getdocument-22))


Note: if called on a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md), this will return null. 


        
Implements [*tinyxml2::XMLNode::ShallowClone*](classtinyxml2_1_1_x_m_l_node.md#function-shallowclone)


<hr>



### function ShallowEqual 

```C++
virtual bool tinyxml2::XMLComment::ShallowEqual (
    const XMLNode * compare
) override const
```



Test if 2 nodes are the same, but don't test children. The 2 nodes do not need to be in the same Document.


Note: if called on a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md), this will return false. 


        
Implements [*tinyxml2::XMLNode::ShallowEqual*](classtinyxml2_1_1_x_m_l_node.md#function-shallowequal)


<hr>



### function ToComment [1/2]

_Safely cast to a Comment, or null._ 
```C++
inline virtual XMLComment * tinyxml2::XMLComment::ToComment () override
```



Implements [*tinyxml2::XMLNode::ToComment*](classtinyxml2_1_1_x_m_l_node.md#function-tocomment-12)


<hr>



### function ToComment [2/2]

```C++
inline virtual const XMLComment * tinyxml2::XMLComment::ToComment () override const
```



Implements [*tinyxml2::XMLNode::ToComment*](classtinyxml2_1_1_x_m_l_node.md#function-tocomment-22)


<hr>
## Protected Functions Documentation




### function ParseDeep 

```C++
virtual char * tinyxml2::XMLComment::ParseDeep (
    char * p,
    StrPair * parentEndTag,
    int * curLineNumPtr
) override
```



Implements [*tinyxml2::XMLNode::ParseDeep*](classtinyxml2_1_1_x_m_l_node.md#function-parsedeep)


<hr>



### function XMLComment [1/2]

```C++
explicit tinyxml2::XMLComment::XMLComment (
    XMLDocument * doc
) 
```




<hr>



### function ~XMLComment 

```C++
virtual tinyxml2::XMLComment::~XMLComment () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

