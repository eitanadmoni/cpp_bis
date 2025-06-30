#include <string>
#include "hashException.h"

using std::string;

HashException::HashException(const string& error) : m_error{ error }
{} // Initializer List so the block is empty

const string& HashException::getError() const { return m_error; }

bool HashException::operator== (HashException& otherException) {
	if (this->getError() == otherException.getError()) {
		return true;
	}
	return false;
}