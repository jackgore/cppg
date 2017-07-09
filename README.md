# cppg
cppg generates .cc and .h files for c++

Requires no dependencies. Simppy run `make` to build the project.

Create a file containing a list of classnames and give to cppg for stdin.

Example input file: 

**classnames.in:**

```
GameObject
Player
```

`./cppg < classnames.in`

For example GameObject files look like this:

**gameobject.h**
```
#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__
class GameObject {

};
#endif
```

**gameobject.cc**
```
#include "gameobject.h"
```
