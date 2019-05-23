#include "CPupil.h"

CPupil::CPupil(const std::string& name, const std::string& surname, const std::string& patronymic, const std::string& address,
	const std::string& schoolName, const std::string& schoolClassName)
	: CPersonImpl<IPupil>(name, surname, patronymic, address)
	, m_schoolName(schoolName)
	, m_schoolClassName(schoolClassName)
{
}

std::string CPupil::GetSchoolName() const
{
	return m_schoolName;
}

std::string CPupil::GetSchoolClassName() const
{
	return m_schoolClassName;
}