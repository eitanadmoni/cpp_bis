#pragma once
#include <string>

class CalculateException
{
public:
	/**
	* Builder for CalculateException class
	* @param string that describe the error
	* @return A CalculateException item
	*/
	CalculateException(const std::string& error);

	/**
	* CalculateException method to get the error massege
	* @return Exception massege
	*/
	const std::string& getError() const;

private:
	std::string m_error;
};
