

# Class tinyxml2::MemPoolT

**template &lt;int ITEM\_SIZE&gt;**



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**MemPoolT**](classtinyxml2_1_1_mem_pool_t.md)








Inherits the following classes: [tinyxml2::MemPool](classtinyxml2_1_1_mem_pool.md)














## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**MemPoolT**](#enum-mempoolt)  <br> |








































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void \* | [**Alloc**](#function-alloc) () override<br> |
|  void | [**Clear**](#function-clear) () <br> |
|  int | [**CurrentAllocs**](#function-currentallocs) () const<br> |
| virtual void | [**Free**](#function-free) (void \* mem) override<br> |
| virtual int | [**ItemSize**](#function-itemsize) () override const<br> |
|   | [**MemPoolT**](#function-mempoolt-12) () <br> |
| virtual void | [**SetTracked**](#function-settracked) () override<br> |
|  void | [**Trace**](#function-trace) (const char \* name) <br> |
|  int | [**Untracked**](#function-untracked) () const<br> |
|   | [**~MemPoolT**](#function-mempoolt) () <br> |


## Public Functions inherited from tinyxml2::MemPool

See [tinyxml2::MemPool](classtinyxml2_1_1_mem_pool.md)

| Type | Name |
| ---: | :--- |
| virtual void \* | [**Alloc**](classtinyxml2_1_1_mem_pool.md#function-alloc) () = 0<br> |
| virtual void | [**Free**](classtinyxml2_1_1_mem_pool.md#function-free) (void \*) = 0<br> |
| virtual int | [**ItemSize**](classtinyxml2_1_1_mem_pool.md#function-itemsize) () const = 0<br> |
|   | [**MemPool**](classtinyxml2_1_1_mem_pool.md#function-mempool) () <br> |
| virtual void | [**SetTracked**](classtinyxml2_1_1_mem_pool.md#function-settracked) () = 0<br> |
| virtual  | [**~MemPool**](classtinyxml2_1_1_mem_pool.md#function-mempool) () <br> |






















































## Public Types Documentation




### enum MemPoolT 

```C++
enum tinyxml2::MemPoolT::MemPoolT {
    ITEMS_PER_BLOCK = (4 * 1024) / ITEM_SIZE
};
```




<hr>
## Public Functions Documentation




### function Alloc 

```C++
inline virtual void * tinyxml2::MemPoolT::Alloc () override
```



Implements [*tinyxml2::MemPool::Alloc*](classtinyxml2_1_1_mem_pool.md#function-alloc)


<hr>



### function Clear 

```C++
inline void tinyxml2::MemPoolT::Clear () 
```




<hr>



### function CurrentAllocs 

```C++
inline int tinyxml2::MemPoolT::CurrentAllocs () const
```




<hr>



### function Free 

```C++
inline virtual void tinyxml2::MemPoolT::Free (
    void * mem
) override
```



Implements [*tinyxml2::MemPool::Free*](classtinyxml2_1_1_mem_pool.md#function-free)


<hr>



### function ItemSize 

```C++
inline virtual int tinyxml2::MemPoolT::ItemSize () override const
```



Implements [*tinyxml2::MemPool::ItemSize*](classtinyxml2_1_1_mem_pool.md#function-itemsize)


<hr>



### function MemPoolT [1/2]

```C++
inline tinyxml2::MemPoolT::MemPoolT () 
```




<hr>



### function SetTracked 

```C++
inline virtual void tinyxml2::MemPoolT::SetTracked () override
```



Implements [*tinyxml2::MemPool::SetTracked*](classtinyxml2_1_1_mem_pool.md#function-settracked)


<hr>



### function Trace 

```C++
inline void tinyxml2::MemPoolT::Trace (
    const char * name
) 
```




<hr>



### function Untracked 

```C++
inline int tinyxml2::MemPoolT::Untracked () const
```




<hr>



### function ~MemPoolT 

```C++
inline tinyxml2::MemPoolT::~MemPoolT () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

