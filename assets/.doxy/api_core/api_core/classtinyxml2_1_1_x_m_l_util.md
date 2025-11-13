

# Class tinyxml2::XMLUtil



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**XMLUtil**](classtinyxml2_1_1_x_m_l_util.md)












































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**ConvertUTF32ToUTF8**](#function-convertutf32toutf8) (unsigned long input, char \* output, int \* length) <br> |
|  const char \* | [**GetCharacterRef**](#function-getcharacterref) (const char \* p, char \* value, int \* length) <br> |
|  bool | [**IsNameChar**](#function-isnamechar) (unsigned char ch) <br> |
|  bool | [**IsNameStartChar**](#function-isnamestartchar) (unsigned char ch) <br> |
|  bool | [**IsPrefixHex**](#function-isprefixhex) (const char \* p) <br> |
|  bool | [**IsUTF8Continuation**](#function-isutf8continuation) (const char p) <br> |
|  bool | [**IsWhiteSpace**](#function-iswhitespace) (char p) <br> |
|  const char \* | [**ReadBOM**](#function-readbom) (const char \* p, bool \* hasBOM) <br> |
|  void | [**SetBoolSerialization**](#function-setboolserialization) (const char \* writeTrue, const char \* writeFalse) <br> |
|  const char \* | [**SkipWhiteSpace**](#function-skipwhitespace-12) (const char \* p, int \* curLineNumPtr) <br> |
|  char \* | [**SkipWhiteSpace**](#function-skipwhitespace-22) (char \*const p, int \* curLineNumPtr) <br> |
|  bool | [**StringEqual**](#function-stringequal) (const char \* p, const char \* q, int nChar=INT\_MAX) <br> |
|  bool | [**ToBool**](#function-tobool) (const char \* str, bool \* value) <br> |
|  bool | [**ToDouble**](#function-todouble) (const char \* str, double \* value) <br> |
|  bool | [**ToFloat**](#function-tofloat) (const char \* str, float \* value) <br> |
|  bool | [**ToInt**](#function-toint) (const char \* str, int \* value) <br> |
|  bool | [**ToInt64**](#function-toint64) (const char \* str, int64\_t \* value) <br> |
|  void | [**ToStr**](#function-tostr-17) (int v, char \* buffer, int bufferSize) <br> |
|  void | [**ToStr**](#function-tostr-27) (unsigned v, char \* buffer, int bufferSize) <br> |
|  void | [**ToStr**](#function-tostr-37) (bool v, char \* buffer, int bufferSize) <br> |
|  void | [**ToStr**](#function-tostr-47) (float v, char \* buffer, int bufferSize) <br> |
|  void | [**ToStr**](#function-tostr-57) (double v, char \* buffer, int bufferSize) <br> |
|  void | [**ToStr**](#function-tostr-67) (int64\_t v, char \* buffer, int bufferSize) <br> |
|  void | [**ToStr**](#function-tostr-77) (uint64\_t v, char \* buffer, int bufferSize) <br> |
|  bool | [**ToUnsigned**](#function-tounsigned) (const char \* str, unsigned \* value) <br> |
|  bool | [**ToUnsigned64**](#function-tounsigned64) (const char \* str, uint64\_t \* value) <br> |


























## Public Static Functions Documentation




### function ConvertUTF32ToUTF8 

```C++
static void tinyxml2::XMLUtil::ConvertUTF32ToUTF8 (
    unsigned long input,
    char * output,
    int * length
) 
```




<hr>



### function GetCharacterRef 

```C++
static const char * tinyxml2::XMLUtil::GetCharacterRef (
    const char * p,
    char * value,
    int * length
) 
```




<hr>



### function IsNameChar 

```C++
static inline bool tinyxml2::XMLUtil::IsNameChar (
    unsigned char ch
) 
```




<hr>



### function IsNameStartChar 

```C++
static inline bool tinyxml2::XMLUtil::IsNameStartChar (
    unsigned char ch
) 
```




<hr>



### function IsPrefixHex 

```C++
static inline bool tinyxml2::XMLUtil::IsPrefixHex (
    const char * p
) 
```




<hr>



### function IsUTF8Continuation 

```C++
static inline bool tinyxml2::XMLUtil::IsUTF8Continuation (
    const char p
) 
```




<hr>



### function IsWhiteSpace 

```C++
static inline bool tinyxml2::XMLUtil::IsWhiteSpace (
    char p
) 
```




<hr>



### function ReadBOM 

```C++
static const char * tinyxml2::XMLUtil::ReadBOM (
    const char * p,
    bool * hasBOM
) 
```




<hr>



### function SetBoolSerialization 

```C++
static void tinyxml2::XMLUtil::SetBoolSerialization (
    const char * writeTrue,
    const char * writeFalse
) 
```




<hr>



### function SkipWhiteSpace [1/2]

```C++
static inline const char * tinyxml2::XMLUtil::SkipWhiteSpace (
    const char * p,
    int * curLineNumPtr
) 
```




<hr>



### function SkipWhiteSpace [2/2]

```C++
static inline char * tinyxml2::XMLUtil::SkipWhiteSpace (
    char *const p,
    int * curLineNumPtr
) 
```




<hr>



### function StringEqual 

```C++
static inline bool tinyxml2::XMLUtil::StringEqual (
    const char * p,
    const char * q,
    int nChar=INT_MAX
) 
```




<hr>



### function ToBool 

```C++
static bool tinyxml2::XMLUtil::ToBool (
    const char * str,
    bool * value
) 
```




<hr>



### function ToDouble 

```C++
static bool tinyxml2::XMLUtil::ToDouble (
    const char * str,
    double * value
) 
```




<hr>



### function ToFloat 

```C++
static bool tinyxml2::XMLUtil::ToFloat (
    const char * str,
    float * value
) 
```




<hr>



### function ToInt 

```C++
static bool tinyxml2::XMLUtil::ToInt (
    const char * str,
    int * value
) 
```




<hr>



### function ToInt64 

```C++
static bool tinyxml2::XMLUtil::ToInt64 (
    const char * str,
    int64_t * value
) 
```




<hr>



### function ToStr [1/7]

```C++
static void tinyxml2::XMLUtil::ToStr (
    int v,
    char * buffer,
    int bufferSize
) 
```




<hr>



### function ToStr [2/7]

```C++
static void tinyxml2::XMLUtil::ToStr (
    unsigned v,
    char * buffer,
    int bufferSize
) 
```




<hr>



### function ToStr [3/7]

```C++
static void tinyxml2::XMLUtil::ToStr (
    bool v,
    char * buffer,
    int bufferSize
) 
```




<hr>



### function ToStr [4/7]

```C++
static void tinyxml2::XMLUtil::ToStr (
    float v,
    char * buffer,
    int bufferSize
) 
```




<hr>



### function ToStr [5/7]

```C++
static void tinyxml2::XMLUtil::ToStr (
    double v,
    char * buffer,
    int bufferSize
) 
```




<hr>



### function ToStr [6/7]

```C++
static void tinyxml2::XMLUtil::ToStr (
    int64_t v,
    char * buffer,
    int bufferSize
) 
```




<hr>



### function ToStr [7/7]

```C++
static void tinyxml2::XMLUtil::ToStr (
    uint64_t v,
    char * buffer,
    int bufferSize
) 
```




<hr>



### function ToUnsigned 

```C++
static bool tinyxml2::XMLUtil::ToUnsigned (
    const char * str,
    unsigned * value
) 
```




<hr>



### function ToUnsigned64 

```C++
static bool tinyxml2::XMLUtil::ToUnsigned64 (
    const char * str,
    uint64_t * value
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

