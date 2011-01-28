#ifdef  __QLEX_LEX_H__
#ifndef __QLEX_LEX_INL__
#define __QLEX_LEX_INL__
//////////////////////////////////////////////////////////////////////////////
//
//    LEX.INL
//
//    Copyright © 2009, Rehno Lindeque. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////

namespace QLex
{
  LexImplementation::LexImplementation(OSIX::SemanticDB& tokenDB) : tokenDB(tokenDB)
  {
  }

  LexImplementation::~LexImplementation()
  {
  }
  
  
  FORCE_INLINE OSIX::SemanticDB& LexImplementation::GetTokenDB()
  {
    return tokenDB;
  }

  FORCE_INLINE const OSIX::SemanticDB& LexImplementation::GetTokenDB() const
  {
    return tokenDB;
  }

  OSIX::SemanticId StringToken(const OSchar* tokenName, const OSchar* value)
  {
  }
  
  OSIX::SemanticId CharToken(const OSchar* tokenName, char value)
  {
  }
  
  OSIX::SemanticId BoundedToken(const OSchar* tokenName, const OSchar* leftBoundingValue, const OSchar* rightBoundingValue, enum LEX_BOUNDED_LINETYPE lineType = MULTI_LINE)
  {
  }
  
}

#endif
#endif
