#pragma once
#include "CPersonImpl.h"

template <typename Base>
class CStudentImpl : public CPersonImpl<Base>
{
public:
	CStudentImpl(const std::string& name, const std::string& surname, const std::string& patronymic, const std::string& address,
		const std::string& universityName, const std::string& studentCardNumber)
		: CPersonImpl<Base>(name, surname, patronymic, address)
		, m_universityName(universityName)
		, m_studentCardNumber(studentCardNumber)
	{
	}

	virtual ~CStudentImpl() = default;

	std::string GetUniversityName() const override
	{
		return m_universityName;
	}

	std::string GetStudentCardNumber() const override
	{
		return m_studentCardNumber;
	}

private:
	std::string m_universityName;
	std::string m_studentCardNumber;
};
