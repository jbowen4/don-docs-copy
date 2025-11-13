

# Class tinyxml2::StrPair



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**StrPair**](classtinyxml2_1_1_str_pair.md)






















## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**Mode**](#enum-mode)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**Empty**](#function-empty) () const<br> |
|  const char \* | [**GetStr**](#function-getstr) () <br> |
|  char \* | [**ParseName**](#function-parsename) (char \* in) <br> |
|  char \* | [**ParseText**](#function-parsetext) (char \* in, const char \* endTag, int strFlags, int \* curLineNumPtr) <br> |
|  void | [**Reset**](#function-reset) () <br> |
|  void | [**Set**](#function-set) (char \* start, char \* end, int flags) <br> |
|  void | [**SetInternedStr**](#function-setinternedstr) (const char \* str) <br> |
|  void | [**SetStr**](#function-setstr) (const char \* str, int flags=0) <br> |
|   | [**StrPair**](#function-strpair-12) () <br> |
|  void | [**TransferTo**](#function-transferto) (StrPair \* other) <br> |
|   | [**~StrPair**](#function-strpair) () <br> |




























## Public Types Documentation




### enum Mode 

```C++
enum tinyxml2::StrPair::Mode {
    NEEDS_ENTITY_PROCESSING = 0x01,
    NEEDS_NEWLINE_NORMALIZATION = 0x02,
    NEEDS_WHITESPACE_COLLAPSING = 0x04,
    TEXT_ELEMENT = NEEDS_ENTITY_PROCESSING | NEEDS_NEWLINE_NORMALIZATION,
    TEXT_ELEMENT_LEAVE_ENTITIES = NEEDS_NEWLINE_NORMALIZATION,
    ATTRIBUTE_NAME = 0,
    ATTRIBUTE_VALUE = NEEDS_ENTITY_PROCESSING | NEEDS_NEWLINE_NORMALIZATION,
    ATTRIBUTE_VALUE_LEAVE_ENTITIES = NEEDS_NEWLINE_NORMALIZATION,
    COMMENT = NEEDS_NEWLINE_NORMALIZATION
};
```




<hr>
## Public Functions Documentation




### function Empty 

```C++
inline bool tinyxml2::StrPair::Empty () const
```




<hr>



### function GetStr 

```C++
const char * tinyxml2::StrPair::GetStr () 
```




<hr>



### function ParseName 

```C++
char * tinyxml2::StrPair::ParseName (
    char * in
) 
```




<hr>



### function ParseText 

```C++
char * tinyxml2::StrPair::ParseText (
    char * in,
    const char * endTag,
    int strFlags,
    int * curLineNumPtr
) 
```




<hr>



### function Reset 

```C++
void tinyxml2::StrPair::Reset () 
```




<hr>



### function Set 

```C++
inline void tinyxml2::StrPair::Set (
    char * start,
    char * end,
    int flags
) 
```




<hr>



### function SetInternedStr 

```C++
inline void tinyxml2::StrPair::SetInternedStr (
    const char * str
) 
```




<hr>



### function SetStr 

```C++
void tinyxml2::StrPair::SetStr (
    const char * str,
    int flags=0
) 
```




<hr>



### function StrPair [1/2]

```C++
inline tinyxml2::StrPair::StrPair () 
```




<hr>



### function TransferTo 

```C++
void tinyxml2::StrPair::TransferTo (
    StrPair * other
) 
```




<hr>



### function ~StrPair 

```C++
tinyxml2::StrPair::~StrPair () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

