

# Namespace tinyxml2



[**Namespace List**](namespaces.md) **>** [**tinyxml2**](namespacetinyxml2.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**DynArray**](classtinyxml2_1_1_dyn_array.md) &lt;class T, INITIAL\_SIZE&gt;<br> |
| class | [**MemPool**](classtinyxml2_1_1_mem_pool.md) <br> |
| class | [**MemPoolT**](classtinyxml2_1_1_mem_pool_t.md) &lt;ITEM\_SIZE&gt;<br> |
| class | [**StrPair**](classtinyxml2_1_1_str_pair.md) <br> |
| class | [**XMLAttribute**](classtinyxml2_1_1_x_m_l_attribute.md) <br> |
| class | [**XMLComment**](classtinyxml2_1_1_x_m_l_comment.md) <br> |
| class | [**XMLConstHandle**](classtinyxml2_1_1_x_m_l_const_handle.md) <br> |
| class | [**XMLDeclaration**](classtinyxml2_1_1_x_m_l_declaration.md) <br> |
| class | [**XMLDocument**](classtinyxml2_1_1_x_m_l_document.md) <br> |
| class | [**XMLElement**](classtinyxml2_1_1_x_m_l_element.md) <br> |
| class | [**XMLHandle**](classtinyxml2_1_1_x_m_l_handle.md) <br> |
| class | [**XMLNode**](classtinyxml2_1_1_x_m_l_node.md) <br> |
| class | [**XMLPrinter**](classtinyxml2_1_1_x_m_l_printer.md) <br> |
| class | [**XMLText**](classtinyxml2_1_1_x_m_l_text.md) <br> |
| class | [**XMLUnknown**](classtinyxml2_1_1_x_m_l_unknown.md) <br> |
| class | [**XMLUtil**](classtinyxml2_1_1_x_m_l_util.md) <br> |
| class | [**XMLVisitor**](classtinyxml2_1_1_x_m_l_visitor.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**Whitespace**](#enum-whitespace)  <br> |
| enum  | [**XMLError**](#enum-xmlerror)  <br> |
















































## Public Types Documentation




### enum Whitespace 

```C++
enum tinyxml2::Whitespace {
    PRESERVE_WHITESPACE,
    COLLAPSE_WHITESPACE,
    PEDANTIC_WHITESPACE
};
```




<hr>



### enum XMLError 

```C++
enum tinyxml2::XMLError {
    XML_SUCCESS = 0,
    XML_NO_ATTRIBUTE,
    XML_WRONG_ATTRIBUTE_TYPE,
    XML_ERROR_FILE_NOT_FOUND,
    XML_ERROR_FILE_COULD_NOT_BE_OPENED,
    XML_ERROR_FILE_READ_ERROR,
    XML_ERROR_PARSING_ELEMENT,
    XML_ERROR_PARSING_ATTRIBUTE,
    XML_ERROR_PARSING_TEXT,
    XML_ERROR_PARSING_CDATA,
    XML_ERROR_PARSING_COMMENT,
    XML_ERROR_PARSING_DECLARATION,
    XML_ERROR_PARSING_UNKNOWN,
    XML_ERROR_EMPTY_DOCUMENT,
    XML_ERROR_MISMATCHED_ELEMENT,
    XML_ERROR_PARSING,
    XML_CAN_NOT_CONVERT_TEXT,
    XML_NO_TEXT_NODE,
    XML_ELEMENT_DEPTH_EXCEEDED,
    XML_ERROR_COUNT
};
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

