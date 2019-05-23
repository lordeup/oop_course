#include "CAdvancedStudent.h"

CAdvancedStudent::CAdvancedStudent(const std::string& name, const std::string& surname, const std::string& patronymic, const std::string& address,
	const std::string& universityName, const std::string& studentCardNumber, const std::string& dissertationTopic)
	: CStudentImpl<IAdvancedStudent>(name, surname, patronymic, address, universityName, studentCardNumber)
	, m_dissertationTopic(dissertationTopic)
{
}

std::string CAdvancedStudent::GetDissertationTopic() const
{
	return m_dissertationTopic;
}