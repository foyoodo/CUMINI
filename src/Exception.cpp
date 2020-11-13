#include "../include/Exception.h"

namespace CUMINI {

Exception::Exception(std::string message, long lineNumber, std::string fileName)
    : m_message(message), m_lineNumber(lineNumber), m_fileName(fileName) {}

Exception::Exception(const Exception &another)
    : std::exception(another), m_message(another.m_message),
      m_lineNumber(another.m_lineNumber), m_fileName(another.m_fileName) {}

Exception::~Exception() throw() = default;

Exception &Exception::operator=(const Exception &another) {
  m_message = another.m_message;
  m_lineNumber = another.m_lineNumber;
  m_fileName = another.m_fileName;
  return *this;
}

std::string Exception::message() const { return m_message; }

long Exception::lineNumber() const { return m_lineNumber; }

std::string Exception::fileName() const { return m_fileName; }

Exception *Exception::clone() const { return new Exception(*this); }

} // namespace CUMINI
