//Created by David Tran (UnsignedZero)
//for the simple purpose of OS detection
//Verison 1.2.1.0

/* Operation System Pointer
 * The goal of this header is allow the programmer
 * to use simple CLI functions without having
 * to take in account the OS he or she is
 * currently programing in.
 *
 */

//OS DETECTION HEADER/DECLARATION

#ifndef ZOS_H
#define ZOS_H true

#define ZX_ZOS_CLI "\nZX_ZOS> "

//Doesn't do anything currently
/*
#ifndef ZX_ZOS_WARNING
 #define ZX_ZOS_WARNING false
#ifndef
*/

#ifndef ZX_ZOS_DEBUG
 #define ZX_ZOS_DEBUG false
#endif

#ifndef ZX_ZOS_CONST
 #define ZX_ZOS_CONST false
#endif

#if defined( _WIN32 )
# define ZX_OS 1
#endif

#if defined ( __linux )
# define ZX_OS 2
#endif

#if defined ( __APPLE__ )
# define ZX_OS 3
#endif

#ifndef ZX_OS
# define ZX_OS 0
#endif

#include <string>

namespace zx {

///Prototype Function//////////////////////////////////////////////////

   void OSP(int);
   // Call Aliases
    void OSP(int* b){ OSP(*b); }
    #if ZX_ZOS_CONST
      void OSP( const int b ) { int a = b; OSP(a); }
      void OSP( int* const b ) { int a = *b; OSP(a); }
      void OSP( const int* b ) { int a = *b; OSP(a); }
      void OSP( const int* const b ) { int a = *b; OSP(a); }
    #endif

    /* Operation System Pointer (Basic)
     * Allows use of simple CLI functions regardless of OS
     * A=1 Pause
     * A=2 Clear screen
     *
     * A=10 Shutdown... (default 1 minutes)
     */


  void OSP(int, std::string);
  // Call Aliases
   void OSP(int b, std::string* d ){ std::string c = *d; OSP(b,c); }
   void OSP(int* b, std::string d ){ int a = *b; OSP(a,d); }
	 void OSP(int* b, std::string* d ){ int a = *b; std::string c = *d; OSP(a,c); }
   #if ZX_ZOS_CONST
   /* Greyed out below are the three original options along
    * with the the four "initial options"
    */

   //void OSP(const int b, std::string d){ int a = b; OSP(a,d); }
   //void OSP(int b, const std::string d){ std::string c = *d; OSP(b,c); }
   /*void OSP(const int b, const std::string d){ int a = b; std::string c = *d; OSP(a,c); }*/

	 //void OSP(int b, std::string d){ OSP(b,d); }
	   void OSP(int b, const std::string d){ std::string c = d; OSP(b,c); }
   //void OSP(int b, std::string* d){ std::string c = *d; OSP(b,c); }
	   void OSP(int b, std::string* const d){ std::string c = *d; OSP(b,c); }
	   void OSP(int b, const std::string* d){std::string c = *d; OSP(b,c); }
	   void OSP(int b, const std::string* const d){ std::string c = *d; OSP(b,c); }

	   void OSP(const int b, std::string d){ int a = *b; OSP(a,d); }
	   void OSP(const int b, const std::string d){ int a = *b; std::string c = d; OSP(a,c); }
	   void OSP(const int b, std::string* d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(const int b, std::string* const d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(const int b, const std::string* d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(const int b, const std::string* const d){ int a = *b; std::string c = *d; OSP(a,c); }

   //void OSP(int* b, std::string d){ int a = *b; OSP(a,d); }
	   void OSP(int* b, const std::string d){ int a = *b; std::string c = d; OSP(a,c); }
   //void OSP(int* b, std::string* d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(int* b, std::string* const d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(int* b, const std::string* d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(int* b, const std::string* const d){ int a = *b; std::string c = *d; OSP(a,c); }

	   void OSP(int* const b, std::string d){ int a = *b; OSP(a,d); }
	   void OSP(int* const b, const std::string d){ int a = *b; std::string c = d; OSP(a,c); }
	   void OSP(int* const b, std::string* d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(int* const b, std::string* const d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(int* const b, const std::string* d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(int* const b, const std::string* const d){ int a = *b; std::string c = *d; OSP(a,c); }

	   void OSP(const int* b, std::string d){ int a = *b; OSP(a,d); }
	   void OSP(const int* b, const std::string d){ int a = *b; std::string c = d; OSP(a,c); }
	   void OSP(const int* b, std::string* d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(const int* b, std::string* const d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(const int* b, const std::string* d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(const int* b, const std::string* const d){ int a = *b; std::string c = *d; OSP(a,c); }

	   void OSP(const int* const b, std::string d){ int a = *b; OSP(a,d); }
	   void OSP(const int* const b, const std::string d){ int a = *b; std::string c = d; OSP(a,c); }
	   void OSP(const int* const b, std::string* d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(const int* const b, std::string* const d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(const int* const b, const std::string* d){ int a = *b; std::string c = *d; OSP(a,c); }
	   void OSP(const int* const b, const std::string* const d){ int a = *b; std::string c = *d; OSP(a,c); }
   #endif

   /* Operation System Pointer (File)
    * Allows use of simple CLI file functions
    * A=1 +Read Only/Hidden
    * A=2 -RO
    * A=3 Create FILE
    * A=4 Delete FILE
    */

///Prototype Function//////////////////////////////////////////////////

}

#ifndef ZOS_CPP
 #include "ZOS.cpp"
 #ifndef ZOS_CPP
  #error ZOS.CPP does not exist.\
  OSP IMPLEMENTATION Missing!
 #endif
#endif

#endif


