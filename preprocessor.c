#include <stdio.h>//tell the compiler to add stdio.h file from System Libraries to the current source file
#include "header.h"// tells the compiler to get header.h from the local directory.
//------------------------------------------------------------------------------------------------------

#undef  LIMIT
#define  LIMIT 20//This two means to tell the compiler to undefine existing LIMIT and set it as 20.

//<-------------------------------------------------------------------------------------------------
#ifndef LIMIT
   #define LIMIT 50
#endif//These three tells the compiler to define LIMIT, only if LIMIT isn't already defined.

//--------------------------------------------------------------------------------------------------
#ifdef LIMIT
   /* our statements here */#endif
//This tells the compiler to do the process the statements enclosed if LIMIT is defined.
