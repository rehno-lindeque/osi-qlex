#ifdef  __QLEX_API_H__
#ifndef __QLEX_API_INL__
#define __QLEX_API_INL__
//////////////////////////////////////////////////////////////////////////////
//
//    API.INL
//
//    Copyright © 2009, Rehno Lindeque. All rights reserved.
//
//////////////////////////////////////////////////////////////////////////////

/*                              COMPILER MACROS                             */
#define _this (*(QLex::Lex*)this)

#define cast_id     QLex::Lex::cast_id
#define cast_object QLex::Lex::cast_object

/*                              IMPLEMENTATION                              */
// QSemanticDB
FORCE_INLINE QLex::LexImplementation* QLex::Lex::operator-> ()
{ 
  return &lex;
}

// OSIX
OSIX::Lex* OSI_API_CALL OSIX::LexInit(OSIX::SemanticDB& tokenDB)
{
  return static_cast<OSIX::Lex*>(new QLex::Lex(tokenDB));
}

void OSI_API_CALL OSIX::Lex::BeginAlphabet(const OSchar* alphabetName)
{
  OSIX::SemanticDB& db = _this->GetTokenDB();
  db.DeclareOpenDomain("Lex");
  db.DeclareOpenDomain("Alphabet");
  db.DeclareOpenDomain(alphabetName);
}

void OSI_API_CALL OSIX::Lex::EndAlphabet()
{
  OSIX::SemanticDB& db = _this->GetTokenDB();
  db.CloseDomain();
  db.CloseDomain("Alphabet");
  db.CloseDomain("Lex");
}

void OSI_API_CALL OSIX::Lex::BeginRaw()
{
  OSIX::SemanticDB& db = _this->GetTokenDB();
  db.DeclareOpenDomain("Raw");
}

void OSI_API_CALL OSIX::Lex::EndRaw()
{
  OSIX::SemanticDB& db = _this->GetTokenDB();
  db.CloseDomain("Raw");
}

void OSI_API_CALL OSIX::Lex::BeginNil()
{
  OSIX::SemanticDB& db = _this->GetTokenDB();
  db.DeclareOpenDomain("Nil");
}

void OSI_API_CALL OSIX::Lex::EndNil()
{
  OSIX::SemanticDB& db = _this->GetTokenDB();
  db.CloseDomain("Nil");
  //_this->Build(QLex::TOKENTYPE_NIL);
}

void OSI_API_CALL OSIX::Lex::BeginLex()
{
}

void OSI_API_CALL OSIX::Lex::EndLex()
{
}

void OSI_API_CALL OSIX::Lex::BeginLexSymbols()
{
  OSIX::SemanticDB& db = _this->GetTokenDB();
  db.DeclareOpenDomain("Symbols");
}

void OSI_API_CALL OSIX::Lex::EndLexSymbols()
{
  OSIX::SemanticDB& db = _this->GetTokenDB();
  //_this->Build(QParser::Lexer::TOKENTYPE_LEX_SYMBOL);
  db.CloseDomain("Symbols");
}

void OSI_API_CALL OSIX::Lex::BeginLexWords()
{
  OSIX::SemanticDB& db = _this->GetTokenDB();
  db.DeclareOpenDomain("Words");
}

void OSI_API_CALL OSIX::Lex::EndLexWords()
{
  OSIX::SemanticDB& db = _this->GetTokenDB();
  db.CloseDomain("Words");
}

OSid OSI_API_CALL OSIX::Lex::CharToken(const OSchar* tokenName, char value)
{
  return _this->CharToken(tokenName, value);
}

OSid OSI_API_CALL OSIX::Lex::BoundedToken(const OSchar* tokenName, const OSchar* leftBoundingValue, const OSchar* rightBoundingValue, PARSER_BOUNDED_LINETYPE lineType)
{
  return _this->BoundedToken(tokenName, leftBoundingValue, rightBoundingValue, lineType);
}

  //_this->Build(QParser::Lexer::TOKENTYPE_LEX_WORD);
}

OSid OSI_API_CALL OSIX::Lex::StringToken(const OSchar* tokenName, const OSchar* value)
{
  return _this->StringToken(tokenName, value);
}

OSid OSI_API_CALL OSIX::Lex::CharToken(const OSchar* tokenName, char value)
{
  return _this->CharToken(tokenName, value);
}

OSid OSI_API_CALL OSIX::Lex::BoundedToken(const OSchar* tokenName, const OSchar* leftBoundingValue, const OSchar* rightBoundingValue, PARSER_BOUNDED_LINETYPE lineType)
{
  return _this->BoundedToken(tokenName, leftBoundingValue, rightBoundingValue, lineType);
}

OSIX::SemanticDB& OSIX::GetTokenDB()
{
  return _this->GetTokenDB();
}

const OSIX::SemanticDB& OSIX::GetTokenDB() const
{
  return _this->GetTokenDB();
}

#endif
#endif
