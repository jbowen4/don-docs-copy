

# Class tinyxml2::XMLElement



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md)



[More...](#detailed-description)

* `#include <tinyxml2.h>`



Inherits the following classes: [tinyxml2::XMLNode](classtinyxml2_1_1_x_m_l_node.md)














## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**ElementClosingType**](#enum-elementclosingtype)  <br> |








































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual bool | [**Accept**](#function-accept) ([**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) \* visitor) override const<br> |
|  const char \* | [**Attribute**](#function-attribute) (const char \* name, const char \* value=0) const<br> |
|  bool | [**BoolAttribute**](#function-boolattribute) (const char \* name, bool defaultValue=false) const<br>_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._ |
|  bool | [**BoolText**](#function-booltext) (bool defaultValue=false) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  ElementClosingType | [**ClosingType**](#function-closingtype) () const<br> |
|  void | [**DeleteAttribute**](#function-deleteattribute-12) (const char \* name) <br> |
|  double | [**DoubleAttribute**](#function-doubleattribute) (const char \* name, double defaultValue=0) const<br>_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._ |
|  double | [**DoubleText**](#function-doubletext) (double defaultValue=0) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  const [**XMLAttribute**](classtinyxml2_1_1_x_m_l_attribute.md) \* | [**FindAttribute**](#function-findattribute) (const char \* name) const<br>_Query a specific attribute in the list._  |
|  const [**XMLAttribute**](classtinyxml2_1_1_x_m_l_attribute.md) \* | [**FirstAttribute**](#function-firstattribute) () const<br>_Return the first attribute in the list._  |
|  float | [**FloatAttribute**](#function-floatattribute) (const char \* name, float defaultValue=0) const<br>_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._ |
|  float | [**FloatText**](#function-floattext) (float defaultValue=0) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  const char \* | [**GetText**](#function-gettext) () const<br> |
|  XMLElement \* | [**InsertNewChildElement**](#function-insertnewchildelement) (const char \* name) <br> |
|  [**XMLComment**](classtinyxml2_1_1_x_m_l_comment.md) \* | [**InsertNewComment**](#function-insertnewcomment) (const char \* comment) <br>_See_ [_**InsertNewChildElement()**_](classtinyxml2_1_1_x_m_l_element.md#function-insertnewchildelement) _._ |
|  [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) \* | [**InsertNewDeclaration**](#function-insertnewdeclaration) (const char \* text) <br>_See_ [_**InsertNewChildElement()**_](classtinyxml2_1_1_x_m_l_element.md#function-insertnewchildelement) _._ |
|  [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) \* | [**InsertNewText**](#function-insertnewtext) (const char \* text) <br>_See_ [_**InsertNewChildElement()**_](classtinyxml2_1_1_x_m_l_element.md#function-insertnewchildelement) _._ |
|  [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) \* | [**InsertNewUnknown**](#function-insertnewunknown) (const char \* text) <br>_See_ [_**InsertNewChildElement()**_](classtinyxml2_1_1_x_m_l_element.md#function-insertnewchildelement) _._ |
|  int64\_t | [**Int64Attribute**](#function-int64attribute) (const char \* name, int64\_t defaultValue=0) const<br>_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._ |
|  int64\_t | [**Int64Text**](#function-int64text) (int64\_t defaultValue=0) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  int | [**IntAttribute**](#function-intattribute) (const char \* name, int defaultValue=0) const<br> |
|  int | [**IntText**](#function-inttext) (int defaultValue=0) const<br> |
|  const char \* | [**Name**](#function-name) () const<br>_Get the name of an element (which is the_ [_**Value()**_](classtinyxml2_1_1_x_m_l_node.md#function-value) _of the node.)._ |
|  XMLError | [**QueryAttribute**](#function-queryattribute-18) (const char \* name, int \* value) const<br> |
|  XMLError | [**QueryAttribute**](#function-queryattribute-28) (const char \* name, unsigned int \* value) const<br> |
|  XMLError | [**QueryAttribute**](#function-queryattribute-38) (const char \* name, int64\_t \* value) const<br> |
|  XMLError | [**QueryAttribute**](#function-queryattribute-48) (const char \* name, uint64\_t \* value) const<br> |
|  XMLError | [**QueryAttribute**](#function-queryattribute-58) (const char \* name, bool \* value) const<br> |
|  XMLError | [**QueryAttribute**](#function-queryattribute-68) (const char \* name, double \* value) const<br> |
|  XMLError | [**QueryAttribute**](#function-queryattribute-78) (const char \* name, float \* value) const<br> |
|  XMLError | [**QueryAttribute**](#function-queryattribute-88) (const char \* name, const char \*\* value) const<br> |
|  XMLError | [**QueryBoolAttribute**](#function-queryboolattribute) (const char \* name, bool \* value) const<br>_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._ |
|  XMLError | [**QueryBoolText**](#function-querybooltext) (bool \* bval) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  XMLError | [**QueryDoubleAttribute**](#function-querydoubleattribute) (const char \* name, double \* value) const<br>_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._ |
|  XMLError | [**QueryDoubleText**](#function-querydoubletext) (double \* dval) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  XMLError | [**QueryFloatAttribute**](#function-queryfloatattribute) (const char \* name, float \* value) const<br>_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._ |
|  XMLError | [**QueryFloatText**](#function-queryfloattext) (float \* fval) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  XMLError | [**QueryInt64Attribute**](#function-queryint64attribute) (const char \* name, int64\_t \* value) const<br>_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._ |
|  XMLError | [**QueryInt64Text**](#function-queryint64text) (int64\_t \* uval) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  XMLError | [**QueryIntAttribute**](#function-queryintattribute) (const char \* name, int \* value) const<br> |
|  XMLError | [**QueryIntText**](#function-queryinttext) (int \* ival) const<br> |
|  XMLError | [**QueryStringAttribute**](#function-querystringattribute) (const char \* name, const char \*\* value) const<br>_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._ |
|  XMLError | [**QueryUnsigned64Attribute**](#function-queryunsigned64attribute) (const char \* name, uint64\_t \* value) const<br>_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._ |
|  XMLError | [**QueryUnsigned64Text**](#function-queryunsigned64text) (uint64\_t \* uval) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  XMLError | [**QueryUnsignedAttribute**](#function-queryunsignedattribute) (const char \* name, unsigned int \* value) const<br>_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._ |
|  XMLError | [**QueryUnsignedText**](#function-queryunsignedtext) (unsigned \* uval) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  void | [**SetAttribute**](#function-setattribute-18) (const char \* name, const char \* value) <br>_Sets the named attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-28) (const char \* name, int value) <br>_Sets the named attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-38) (const char \* name, unsigned value) <br>_Sets the named attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-48) (const char \* name, int64\_t value) <br>_Sets the named attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-58) (const char \* name, uint64\_t value) <br>_Sets the named attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-68) (const char \* name, bool value) <br>_Sets the named attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-78) (const char \* name, double value) <br>_Sets the named attribute to value._  |
|  void | [**SetAttribute**](#function-setattribute-88) (const char \* name, float value) <br>_Sets the named attribute to value._  |
|  void | [**SetName**](#function-setname) (const char \* str, bool staticMem=false) <br>_Set the name of the element._  |
|  void | [**SetText**](#function-settext-18) (const char \* inText) <br> |
|  void | [**SetText**](#function-settext-28) (int value) <br>_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._ |
|  void | [**SetText**](#function-settext-38) (unsigned value) <br>_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._ |
|  void | [**SetText**](#function-settext-48) (int64\_t value) <br>_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._ |
|  void | [**SetText**](#function-settext-58) (uint64\_t value) <br>_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._ |
|  void | [**SetText**](#function-settext-68) (bool value) <br>_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._ |
|  void | [**SetText**](#function-settext-78) (double value) <br>_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._ |
|  void | [**SetText**](#function-settext-88) (float value) <br>_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._ |
| virtual XMLNode \* | [**ShallowClone**](#function-shallowclone) (XMLDocument \* document) override const<br> |
| virtual bool | [**ShallowEqual**](#function-shallowequal) (const XMLNode \* compare) override const<br> |
| virtual XMLElement \* | [**ToElement**](#function-toelement-12) () override<br>_Safely cast to an Element, or null._  |
| virtual const XMLElement \* | [**ToElement**](#function-toelement-22) () override const<br> |
|  uint64\_t | [**Unsigned64Attribute**](#function-unsigned64attribute) (const char \* name, uint64\_t defaultValue=0) const<br>_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._ |
|  uint64\_t | [**Unsigned64Text**](#function-unsigned64text) (uint64\_t defaultValue=0) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |
|  unsigned | [**UnsignedAttribute**](#function-unsignedattribute) (const char \* name, unsigned defaultValue=0) const<br>_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._ |
|  unsigned | [**UnsignedText**](#function-unsignedtext) (unsigned defaultValue=0) const<br>_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._ |


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


## Protected Functions inherited from tinyxml2::XMLNode

See [tinyxml2::XMLNode](classtinyxml2_1_1_x_m_l_node.md)

| Type | Name |
| ---: | :--- |
| virtual char \* | [**ParseDeep**](classtinyxml2_1_1_x_m_l_node.md#function-parsedeep) (char \* p, [**StrPair**](classtinyxml2_1_1_str_pair.md) \* parentEndTag, int \* curLineNumPtr) <br> |
|   | [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md#function-xmlnode-12) (XMLDocument \*) <br> |
| virtual  | [**~XMLNode**](classtinyxml2_1_1_x_m_l_node.md#function-xmlnode) () <br> |






## Detailed Description


The element is a container class. It has a value, the element name, and can contain other elements, text, comments, and unknowns. Elements also contain an arbitrary number of attributes. 


    
## Public Types Documentation




### enum ElementClosingType 

```C++
enum tinyxml2::XMLElement::ElementClosingType {
    OPEN,
    CLOSED,
    CLOSING
};
```




<hr>
## Public Functions Documentation




### function Accept 

```C++
virtual bool tinyxml2::XMLElement::Accept (
    XMLVisitor * visitor
) override const
```



Accept a hierarchical visit of the nodes in the TinyXML-2 DOM. Every node in the XML tree will be conditionally visited and the host will be called back via the [**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) interface.


This is essentially a SAX interface for TinyXML-2. (Note however it doesn't re-parse the XML for the callbacks, so the performance of TinyXML-2 is unchanged by using this interface versus any other.)


The interface has been based on ideas from:



* [http://www.saxproject.org/](http://www.saxproject.org/)
* [http://c2.com/cgi/wiki?HierarchicalVisitorPattern](http://c2.com/cgi/wiki?HierarchicalVisitorPattern)




Which are both good references for "visiting".


An example of using [**Accept()**](classtinyxml2_1_1_x_m_l_element.md#function-accept):  


        
Implements [*tinyxml2::XMLNode::Accept*](classtinyxml2_1_1_x_m_l_node.md#function-accept)


<hr>



### function Attribute 

```C++
const char * tinyxml2::XMLElement::Attribute (
    const char * name,
    const char * value=0
) const
```



Given an attribute name, [**Attribute()**](classtinyxml2_1_1_x_m_l_element.md#function-attribute) returns the value for the attribute of that name, or null if none exists. For example:





The 'value' parameter is normally null. However, if specified, the attribute will only be returned if the 'name' and 'value' match. This allow you to write code:





rather than:  


        

<hr>



### function BoolAttribute 

_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._
```C++
bool tinyxml2::XMLElement::BoolAttribute (
    const char * name,
    bool defaultValue=false
) const
```




<hr>



### function BoolText 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
bool tinyxml2::XMLElement::BoolText (
    bool defaultValue=false
) const
```




<hr>



### function ClosingType 

```C++
inline ElementClosingType tinyxml2::XMLElement::ClosingType () const
```




<hr>



### function DeleteAttribute [1/2]

```C++
void tinyxml2::XMLElement::DeleteAttribute (
    const char * name
) 
```



Delete an attribute. 


        

<hr>



### function DoubleAttribute 

_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._
```C++
double tinyxml2::XMLElement::DoubleAttribute (
    const char * name,
    double defaultValue=0
) const
```




<hr>



### function DoubleText 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
double tinyxml2::XMLElement::DoubleText (
    double defaultValue=0
) const
```




<hr>



### function FindAttribute 

_Query a specific attribute in the list._ 
```C++
const XMLAttribute * tinyxml2::XMLElement::FindAttribute (
    const char * name
) const
```




<hr>



### function FirstAttribute 

_Return the first attribute in the list._ 
```C++
inline const XMLAttribute * tinyxml2::XMLElement::FirstAttribute () const
```




<hr>



### function FloatAttribute 

_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._
```C++
float tinyxml2::XMLElement::FloatAttribute (
    const char * name,
    float defaultValue=0
) const
```




<hr>



### function FloatText 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
float tinyxml2::XMLElement::FloatText (
    float defaultValue=0
) const
```




<hr>



### function GetText 

```C++
const char * tinyxml2::XMLElement::GetText () const
```



Convenience function for easy access to the text inside an element. Although easy and concise, [**GetText()**](classtinyxml2_1_1_x_m_l_element.md#function-gettext) is limited compared to getting the [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) child and accessing it directly.


If the first child of 'this' is a [**XMLText**](classtinyxml2_1_1_x_m_l_text.md), the [**GetText()**](classtinyxml2_1_1_x_m_l_element.md#function-gettext) returns the character string of the Text node, else null is returned.


This is a convenient method for getting the text of simple contained text: 


'str' will be a pointer to "This is text".


Note that this function can be misleading. If the element foo was created from this XML: 


then the value of str would be null. The first child node isn't a text node, it is another element. From this XML:  [**GetText()**](classtinyxml2_1_1_x_m_l_element.md#function-gettext) will return "This is ". 


        

<hr>



### function InsertNewChildElement 

```C++
XMLElement * tinyxml2::XMLElement::InsertNewChildElement (
    const char * name
) 
```



Convenience method to create a new [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) and add it as last (right) child of this node. Returns the created and inserted element. 


        

<hr>



### function InsertNewComment 

_See_ [_**InsertNewChildElement()**_](classtinyxml2_1_1_x_m_l_element.md#function-insertnewchildelement) _._
```C++
XMLComment * tinyxml2::XMLElement::InsertNewComment (
    const char * comment
) 
```




<hr>



### function InsertNewDeclaration 

_See_ [_**InsertNewChildElement()**_](classtinyxml2_1_1_x_m_l_element.md#function-insertnewchildelement) _._
```C++
XMLDeclaration * tinyxml2::XMLElement::InsertNewDeclaration (
    const char * text
) 
```




<hr>



### function InsertNewText 

_See_ [_**InsertNewChildElement()**_](classtinyxml2_1_1_x_m_l_element.md#function-insertnewchildelement) _._
```C++
XMLText * tinyxml2::XMLElement::InsertNewText (
    const char * text
) 
```




<hr>



### function InsertNewUnknown 

_See_ [_**InsertNewChildElement()**_](classtinyxml2_1_1_x_m_l_element.md#function-insertnewchildelement) _._
```C++
XMLUnknown * tinyxml2::XMLElement::InsertNewUnknown (
    const char * text
) 
```




<hr>



### function Int64Attribute 

_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._
```C++
int64_t tinyxml2::XMLElement::Int64Attribute (
    const char * name,
    int64_t defaultValue=0
) const
```




<hr>



### function Int64Text 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
int64_t tinyxml2::XMLElement::Int64Text (
    int64_t defaultValue=0
) const
```




<hr>



### function IntAttribute 

```C++
int tinyxml2::XMLElement::IntAttribute (
    const char * name,
    int defaultValue=0
) const
```



Given an attribute name, [**IntAttribute()**](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) returns the value of the attribute interpreted as an integer. The default value will be returned if the attribute isn't present, or if there is an error. (For a method with error checking, see [**QueryIntAttribute()**](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute)). 


        

<hr>



### function IntText 

```C++
int tinyxml2::XMLElement::IntText (
    int defaultValue=0
) const
```




<hr>



### function Name 

_Get the name of an element (which is the_ [_**Value()**_](classtinyxml2_1_1_x_m_l_node.md#function-value) _of the node.)._
```C++
inline const char * tinyxml2::XMLElement::Name () const
```




<hr>



### function QueryAttribute [1/8]

```C++
inline XMLError tinyxml2::XMLElement::QueryAttribute (
    const char * name,
    int * value
) const
```



Given an attribute name, [**QueryAttribute()**](classtinyxml2_1_1_x_m_l_element.md#function-queryattribute-18) returns XML\_SUCCESS, XML\_WRONG\_ATTRIBUTE\_TYPE if the conversion can't be performed, or XML\_NO\_ATTRIBUTE if the attribute doesn't exist. It is overloaded for the primitive types, and is a generally more convenient replacement of [**QueryIntAttribute()**](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) and related functions.


If successful, the result of the conversion will be written to 'value'. If not successful, nothing will be written to 'value'. This allows you to provide default value:


 


        

<hr>



### function QueryAttribute [2/8]

```C++
inline XMLError tinyxml2::XMLElement::QueryAttribute (
    const char * name,
    unsigned int * value
) const
```




<hr>



### function QueryAttribute [3/8]

```C++
inline XMLError tinyxml2::XMLElement::QueryAttribute (
    const char * name,
    int64_t * value
) const
```




<hr>



### function QueryAttribute [4/8]

```C++
inline XMLError tinyxml2::XMLElement::QueryAttribute (
    const char * name,
    uint64_t * value
) const
```




<hr>



### function QueryAttribute [5/8]

```C++
inline XMLError tinyxml2::XMLElement::QueryAttribute (
    const char * name,
    bool * value
) const
```




<hr>



### function QueryAttribute [6/8]

```C++
inline XMLError tinyxml2::XMLElement::QueryAttribute (
    const char * name,
    double * value
) const
```




<hr>



### function QueryAttribute [7/8]

```C++
inline XMLError tinyxml2::XMLElement::QueryAttribute (
    const char * name,
    float * value
) const
```




<hr>



### function QueryAttribute [8/8]

```C++
inline XMLError tinyxml2::XMLElement::QueryAttribute (
    const char * name,
    const char ** value
) const
```




<hr>



### function QueryBoolAttribute 

_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._
```C++
inline XMLError tinyxml2::XMLElement::QueryBoolAttribute (
    const char * name,
    bool * value
) const
```




<hr>



### function QueryBoolText 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
XMLError tinyxml2::XMLElement::QueryBoolText (
    bool * bval
) const
```




<hr>



### function QueryDoubleAttribute 

_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._
```C++
inline XMLError tinyxml2::XMLElement::QueryDoubleAttribute (
    const char * name,
    double * value
) const
```




<hr>



### function QueryDoubleText 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
XMLError tinyxml2::XMLElement::QueryDoubleText (
    double * dval
) const
```




<hr>



### function QueryFloatAttribute 

_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._
```C++
inline XMLError tinyxml2::XMLElement::QueryFloatAttribute (
    const char * name,
    float * value
) const
```




<hr>



### function QueryFloatText 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
XMLError tinyxml2::XMLElement::QueryFloatText (
    float * fval
) const
```




<hr>



### function QueryInt64Attribute 

_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._
```C++
inline XMLError tinyxml2::XMLElement::QueryInt64Attribute (
    const char * name,
    int64_t * value
) const
```




<hr>



### function QueryInt64Text 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
XMLError tinyxml2::XMLElement::QueryInt64Text (
    int64_t * uval
) const
```




<hr>



### function QueryIntAttribute 

```C++
inline XMLError tinyxml2::XMLElement::QueryIntAttribute (
    const char * name,
    int * value
) const
```



Given an attribute name, [**QueryIntAttribute()**](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) returns XML\_SUCCESS, XML\_WRONG\_ATTRIBUTE\_TYPE if the conversion can't be performed, or XML\_NO\_ATTRIBUTE if the attribute doesn't exist. If successful, the result of the conversion will be written to 'value'. If not successful, nothing will be written to 'value'. This allows you to provide default value:


 


        

<hr>



### function QueryIntText 

```C++
XMLError tinyxml2::XMLElement::QueryIntText (
    int * ival
) const
```



Convenience method to query the value of a child text node. This is probably best shown by example. Given you have a document is this form: 


The [**QueryIntText()**](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) and similar functions provide a safe and easier way to get to the "value" of x and y.







**Returns:**

XML\_SUCCESS (0) on success, XML\_CAN\_NOT\_CONVERT\_TEXT if the text cannot be converted to the requested type, and XML\_NO\_TEXT\_NODE if there is no child text to query. 





        

<hr>



### function QueryStringAttribute 

_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._
```C++
inline XMLError tinyxml2::XMLElement::QueryStringAttribute (
    const char * name,
    const char ** value
) const
```




<hr>



### function QueryUnsigned64Attribute 

_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._
```C++
inline XMLError tinyxml2::XMLElement::QueryUnsigned64Attribute (
    const char * name,
    uint64_t * value
) const
```




<hr>



### function QueryUnsigned64Text 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
XMLError tinyxml2::XMLElement::QueryUnsigned64Text (
    uint64_t * uval
) const
```




<hr>



### function QueryUnsignedAttribute 

_See_ [_**QueryIntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryintattribute) _._
```C++
inline XMLError tinyxml2::XMLElement::QueryUnsignedAttribute (
    const char * name,
    unsigned int * value
) const
```




<hr>



### function QueryUnsignedText 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
XMLError tinyxml2::XMLElement::QueryUnsignedText (
    unsigned * uval
) const
```




<hr>



### function SetAttribute [1/8]

_Sets the named attribute to value._ 
```C++
inline void tinyxml2::XMLElement::SetAttribute (
    const char * name,
    const char * value
) 
```




<hr>



### function SetAttribute [2/8]

_Sets the named attribute to value._ 
```C++
inline void tinyxml2::XMLElement::SetAttribute (
    const char * name,
    int value
) 
```




<hr>



### function SetAttribute [3/8]

_Sets the named attribute to value._ 
```C++
inline void tinyxml2::XMLElement::SetAttribute (
    const char * name,
    unsigned value
) 
```




<hr>



### function SetAttribute [4/8]

_Sets the named attribute to value._ 
```C++
inline void tinyxml2::XMLElement::SetAttribute (
    const char * name,
    int64_t value
) 
```




<hr>



### function SetAttribute [5/8]

_Sets the named attribute to value._ 
```C++
inline void tinyxml2::XMLElement::SetAttribute (
    const char * name,
    uint64_t value
) 
```




<hr>



### function SetAttribute [6/8]

_Sets the named attribute to value._ 
```C++
inline void tinyxml2::XMLElement::SetAttribute (
    const char * name,
    bool value
) 
```




<hr>



### function SetAttribute [7/8]

_Sets the named attribute to value._ 
```C++
inline void tinyxml2::XMLElement::SetAttribute (
    const char * name,
    double value
) 
```




<hr>



### function SetAttribute [8/8]

_Sets the named attribute to value._ 
```C++
inline void tinyxml2::XMLElement::SetAttribute (
    const char * name,
    float value
) 
```




<hr>



### function SetName 

_Set the name of the element._ 
```C++
inline void tinyxml2::XMLElement::SetName (
    const char * str,
    bool staticMem=false
) 
```




<hr>



### function SetText [1/8]

```C++
void tinyxml2::XMLElement::SetText (
    const char * inText
) 
```



Convenience function for easy access to the text inside an element. Although easy and concise, [**SetText()**](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) is limited compared to creating an [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) child and mutating it directly.


If the first child of 'this' is a [**XMLText**](classtinyxml2_1_1_x_m_l_text.md), [**SetText()**](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) sets its value to the given string, otherwise it will create a first child that is an [**XMLText**](classtinyxml2_1_1_x_m_l_text.md).


This is a convenient method for setting the text of simple contained text: 


Note that this function can be misleading. If the element foo was created from this XML: 


then it will not change "This is text", but rather prefix it with a text element: 


For this XML:  [**SetText()**](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) will generate  


        

<hr>



### function SetText [2/8]

_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._
```C++
void tinyxml2::XMLElement::SetText (
    int value
) 
```




<hr>



### function SetText [3/8]

_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._
```C++
void tinyxml2::XMLElement::SetText (
    unsigned value
) 
```




<hr>



### function SetText [4/8]

_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._
```C++
void tinyxml2::XMLElement::SetText (
    int64_t value
) 
```




<hr>



### function SetText [5/8]

_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._
```C++
void tinyxml2::XMLElement::SetText (
    uint64_t value
) 
```




<hr>



### function SetText [6/8]

_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._
```C++
void tinyxml2::XMLElement::SetText (
    bool value
) 
```




<hr>



### function SetText [7/8]

_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._
```C++
void tinyxml2::XMLElement::SetText (
    double value
) 
```




<hr>



### function SetText [8/8]

_Convenience method for setting text inside an element. See_ [_**SetText()**_](classtinyxml2_1_1_x_m_l_element.md#function-settext-18) _for important limitations._
```C++
void tinyxml2::XMLElement::SetText (
    float value
) 
```




<hr>



### function ShallowClone 

```C++
virtual XMLNode * tinyxml2::XMLElement::ShallowClone (
    XMLDocument * document
) override const
```



Make a copy of this node, but not its children. You may pass in a Document pointer that will be the owner of the new Node. If the 'document' is null, then the node returned will be allocated from the current Document. (this-&gt;[**GetDocument()**](classtinyxml2_1_1_x_m_l_node.md#function-getdocument-22))


Note: if called on a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md), this will return null. 


        
Implements [*tinyxml2::XMLNode::ShallowClone*](classtinyxml2_1_1_x_m_l_node.md#function-shallowclone)


<hr>



### function ShallowEqual 

```C++
virtual bool tinyxml2::XMLElement::ShallowEqual (
    const XMLNode * compare
) override const
```



Test if 2 nodes are the same, but don't test children. The 2 nodes do not need to be in the same Document.


Note: if called on a [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md), this will return false. 


        
Implements [*tinyxml2::XMLNode::ShallowEqual*](classtinyxml2_1_1_x_m_l_node.md#function-shallowequal)


<hr>



### function ToElement [1/2]

_Safely cast to an Element, or null._ 
```C++
inline virtual XMLElement * tinyxml2::XMLElement::ToElement () override
```



Implements [*tinyxml2::XMLNode::ToElement*](classtinyxml2_1_1_x_m_l_node.md#function-toelement-12)


<hr>



### function ToElement [2/2]

```C++
inline virtual const XMLElement * tinyxml2::XMLElement::ToElement () override const
```



Implements [*tinyxml2::XMLNode::ToElement*](classtinyxml2_1_1_x_m_l_node.md#function-toelement-22)


<hr>



### function Unsigned64Attribute 

_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._
```C++
uint64_t tinyxml2::XMLElement::Unsigned64Attribute (
    const char * name,
    uint64_t defaultValue=0
) const
```




<hr>



### function Unsigned64Text 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
uint64_t tinyxml2::XMLElement::Unsigned64Text (
    uint64_t defaultValue=0
) const
```




<hr>



### function UnsignedAttribute 

_See_ [_**IntAttribute()**_](classtinyxml2_1_1_x_m_l_element.md#function-intattribute) _._
```C++
unsigned tinyxml2::XMLElement::UnsignedAttribute (
    const char * name,
    unsigned defaultValue=0
) const
```




<hr>



### function UnsignedText 

_See_ [_**QueryIntText()**_](classtinyxml2_1_1_x_m_l_element.md#function-queryinttext) _._
```C++
unsigned tinyxml2::XMLElement::UnsignedText (
    unsigned defaultValue=0
) const
```




<hr>
## Protected Functions Documentation




### function ParseDeep 

```C++
virtual char * tinyxml2::XMLElement::ParseDeep (
    char * p,
    StrPair * parentEndTag,
    int * curLineNumPtr
) override
```



Implements [*tinyxml2::XMLNode::ParseDeep*](classtinyxml2_1_1_x_m_l_node.md#function-parsedeep)


<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

