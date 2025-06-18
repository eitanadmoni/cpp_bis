#include <string>
#include "CalculateException.h"

using std::string;

CalculateException::CalculateException(const string& error) : m_error{ error } 
{} // Initializer List so the block is empty

const string& CalculateException::getError() const { return m_error; }


