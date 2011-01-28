#ifndef __QLEX_LEX_H__
#define __QLEX_LEX_H__
//////////////////////////////////////////////////////////////////////////////
//
//    LEX.H
//
//    Copyright © 2009, Rehno Lindeque. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////
/*                               DOCUMENTATION                              */
/*
    DESCRIPTION:
      QLex base implementation.
*/

/*                              COMPILER MACROS                             */
#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable:4311)
# pragma warning(disable:4312)
#endif

namespace QLex
{
/*                                  CLASSES                                 */
  class LexImplementation : public Base::Object
  {
  public:
    // Constructor
    INLINE LexImplementation(OSIX::SemanticDB& tokenDB);

    // Destructor
    virtual ~LexImplementation();
    
    // Token store
    OSIX::SemanticDB& GetTokenDB();
    const OSIX::SemanticDB& GetTokenDB() const;  
    
    // Tokens
    OSIX::SemanticId StringToken(const OSchar* tokenName, const OSchar* value);
    OSIX::SemanticId CharToken(const OSchar* tokenName, char value);
    //OSIX::SemanticId KeywordToken(const OSchar* keyword) { return StringToken(keyword, keyword); }
    OSIX::SemanticId BoundedToken(const OSchar* tokenName, const OSchar* leftBoundingValue, const OSchar* rightBoundingValue, enum LEX_BOUNDED_LINETYPE lineType = MULTI_LINE);
    
  protected:
    OSIX::SemanticDB& tokenDB;    // Token database
  };
}

/*                                   INCLUDES                               */
#include "lex.inl"

#endif
