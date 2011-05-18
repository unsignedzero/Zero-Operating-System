//Created by David Tran (UnsignedZero)
//for the simple purpose of OS detection
//Verison 1.2.1.0

//OS DETECTION IMPLEMENTATION

#ifndef ZOS_CPP
 #define ZOS_CPP true

#ifndef ZOS_H
 #include "ZOS.H"
 #ifndef ZOS_H
  #error ZOS.H does not exist.\
   OSP HEADER/DECLARATION Missing!
 #endif
#endif

#include <sstream>
#include <fstream>

namespace zx{

///--------------------------------------------------------------------

//A=1 Pause
//A=2 Clear screen

 void OSP(int a) {

  #if(ZX_ZOS_DEBUG==true)
    if (a == 1) {std::cout << "Pausing!\n"; }
    else if (a == 2) { std::cout << "Clearing Screen!\n"; }
  #endif

  if (ZX_OS == 1) {
    if (a == 1) {
      system("pause");
      }
    if (a == 2) {
      system("cls");
      }
    }

  if ( (ZX_OS == 2) || (ZX_OS == 3) ) {
    if (a == 1) {
      system("read -sn 1 -p \"Press any key to continue...\\n\"");
      }
    if (a == 2) {
      system("clear");
      }
    }

 }

///--------------------------------------------------------------------

//A=1 +Read Only/Hidden
//A=2 -RO
//A=3 Create FILE
//A=4 Delete FILE

void OSP(int a, std::string fname) {

static std::stringstream fpaper //file scratch paper;
(std::stringstream::in | std::stringstream::out);

fpaper.str("");

  #if(ZX_ZOS_DEBUG==true)
    if (a == 1) { std::cout << "Making file read only!\n"; }
    else if (a == 2) { std::cout << "Removing Read Only Status!\n"; }
    else if (a == 3) { std::cout << "Making file!\n"; }
    else if (a == 4) { std::cout << "Shredding File!\n"; }
  #endif

  if (ZX_OS == 1) {

    if ((a >= 1) || (a <= 3)){
      std::ofstream ftest;
      fpaper << "attrib ";
      fpaper << fname;

      if (a == 1) { fpaper << " +r +a +s +h"; }
      if (a == 2) {
        fpaper << " -s -h -r";
        system((fpaper.str()).c_str());
        fpaper << " +s +h";
        }
      if (a == 3) { fpaper << " +r +s +h";
        ftest.open( fname.c_str());
      }
    ftest.close();
    }
    if (a == 4) {
      fpaper << "del " << fname << " /F /Q";
      }

    system((fpaper.str()).c_str());
    }

  if ( (ZX_OS == 2) || (ZX_OS == 3) ) {

    if (a <= 2) { fpaper << "chmod ";
      if (a == 1) { fpaper << "440 ."; }
      if (a == 2) { fpaper << "660 ."; }
      }
    if (a == 3) { fpaper << "touch ."; }
    if (a == 4) { fpaper << "shred -f -u -z "; }

    fpaper << fname;
    system((fpaper.str()).c_str());
    }

  fpaper.str("");

}

///--------------------------------------------------------------------

}

#endif
