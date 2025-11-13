

# Class tinyxml2::MemPool



[**ClassList**](annotated.md) **>** [**tinyxml2**](namespacetinyxml2.md) **>** [**MemPool**](classtinyxml2_1_1_mem_pool.md)










Inherited by the following classes: [tinyxml2::MemPoolT](classtinyxml2_1_1_mem_pool_t.md),  [tinyxml2::MemPoolT](classtinyxml2_1_1_mem_pool_t.md),  [tinyxml2::MemPoolT](classtinyxml2_1_1_mem_pool_t.md),  [tinyxml2::MemPoolT](classtinyxml2_1_1_mem_pool_t.md),  [tinyxml2::MemPoolT](classtinyxml2_1_1_mem_pool_t.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void \* | [**Alloc**](#function-alloc) () = 0<br> |
| virtual void | [**Free**](#function-free) (void \*) = 0<br> |
| virtual int | [**ItemSize**](#function-itemsize) () const = 0<br> |
|   | [**MemPool**](#function-mempool) () <br> |
| virtual void | [**SetTracked**](#function-settracked) () = 0<br> |
| virtual  | [**~MemPool**](#function-mempool) () <br> |




























## Public Functions Documentation




### function Alloc 

```C++
virtual void * tinyxml2::MemPool::Alloc () = 0
```




<hr>



### function Free 

```C++
virtual void tinyxml2::MemPool::Free (
    void *
) = 0
```




<hr>



### function ItemSize 

```C++
virtual int tinyxml2::MemPool::ItemSize () const = 0
```




<hr>



### function MemPool 

```C++
inline tinyxml2::MemPool::MemPool () 
```




<hr>



### function SetTracked 

```C++
virtual void tinyxml2::MemPool::SetTracked () = 0
```




<hr>



### function ~MemPool 

```C++
inline virtual tinyxml2::MemPool::~MemPool () 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/tinyxml2.h`

