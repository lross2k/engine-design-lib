// Contents of DLLDefines.h from the CMake documentation
#ifndef _MyLibrary_DLLDEFINES_H_
#define _MyLibrary_DLLDEFINES_H_

/* Cmake will define MyLibrary_EXPORTS on Windows when it
configures to build a shared library. If you are going to use
another build system on windows or create the visual studio
projects by hand you need to define MyLibrary_EXPORTS when
building a DLL on windows.
*/
// We are using the Visual Studio Compiler and building Shared libraries

#if defined (_WIN32)
  #if defined(applib_EXPORTS)
    #define  APPLIB_EXPORT __declspec(dllexport)
  #else
    #define  APPLIB_EXPORT //__declspec(dllimport)  // Didn't allow for STATIC compilation
  #endif /* MyLibrary_EXPORTS */
#else /* defined (_WIN32) */
 #define APPLIB_EXPORT
#endif

#endif // _MyLibrary_DLLDEFINES_H_
