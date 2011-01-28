#ifndef __QLEX_API_H__
#define __QLEX_API_H__
//////////////////////////////////////////////////////////////////////////////
//
//    API.H
//
//    Copyright © 2009, Rehno Lindeque. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////
/*                               DOCUMENTATION                              */
/*
    DESCRIPTION:
      QLex API for OpenLex 0.1.
*/
/*                              COMPILER MACROS                             */
#ifdef _MSC_VER
# define STDEXT_NAMESPACE stdext
#else
# define STDEXT_NAMESPACE __gnu_cxx
#endif
        
/*                                 INCLUDES                                 */
// OpenLex
#include <osix/lex/lex.hpp>
#ifdef _DEBUG
# include <osix/lex/lexdbg.hpp>
#endif

// BaseLex
#include <baselex/baselex.h>

// QLex
#include "lex.h"


// STL

// STL extensions
/*#ifdef _MSC_VER
# include <ext/stdio_filebuf.h>?
#else
# include <ext/stdio_filebuf.h>
#endif*/

// CLib
//#include <memory.h>

// Boost
//#include <boost/bimap.hpp>


namespace QLex
{
/*                            FORWARD DECLARATIONS                          */
  class LexImplementation;

/*                                   TYPES                                  */

  
/*                                  CLASSES                                 */  
  class Lex : public BaseLex::Lex
  {
  public:
    // Constructor
    FORCE_INLINE Lex(OSIX::SemanticDB& tokenDB) : lex(tokenDB) {}
    
    // Semantic DB implementation
    LexImplementation* operator-> ();
    
    // Implementation object
    LexImplementation lex;
    
    // Debug classes
#   ifdef _DEBUG
      class LexDbg : public OSIX::LexDbg
      {
      public:
        INLINE Lex& GetLex() { return *(Lex*)(((uint8*)this) - offsetof(Lex, lexDbg)); }
      } LexDbg;
#   endif
  };
}

/*                                   INCLUDES                               */
// Inline implementation
#ifdef OSI_STATIC_C_BUILD
#include "api.inl"
#endif

#endif
