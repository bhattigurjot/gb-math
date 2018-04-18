# gb-math

## Overview
gb-math is a small C++ math library mainly concerned with vectors and matrices.

## Including in your project
You can download the **gb-math.h** header file from the include directory from [here](https://github.com/bhattigurjot/gb-math). Include this header file in your cpp file as:
```cpp
#include "gb-math.h"
```

## Documentation
You can begin using the library as documented below.
### Vector2 Class
There are 3 types of Vector2 that you can use, i.e. 
* **Vector2i** - 2D Vector of integer
* **Vector2f** - 2D Vector of float 
* **Vector2d** - 2D Vector of double 

You can define Vector2 by yourself as:
```cpp
Vector2<Typename> vec;
```

#### Members
> **x**: x value/component of the 2D vector
> 
> **y**: y value/component of the 2D vector

#### Constructors
> Default Constructor with default x ans y values as 0
>
> Vector2i()

```cpp
Vector2i vec; // vec.x = 0 and vec.y = 0

Vector2i* p_vec = new Vector2i; // p_vec->x = 0 and p_vec_>y = 0
```

> Constructor with values
>
> Vector2i(x,y)

```cpp
Vector2i vec(3,4); // vec.x = 3 and vec.y = 4

Vector2i* p_vec = new Vector2i(4, 6); // p_vec->x = 4 and p_vec_>y = 6
```
