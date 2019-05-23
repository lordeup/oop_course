#define CATCH_CONFIG_MAIN
#include "../../3/People/CAdvancedStudent.h"
#include "../../3/People/CPupil.h"
#include "../../3/People/CStudent.h"
#include "../../3/People/CTeacher.h"
#include "../../3/People/CWorker.h"
#include <catch2/catch.hpp>
#include <string>

TEST_CASE("Person")
{
	std::string name = "Donald";
	std::string surname = "Joseph";
	std::string patronymic = "Quinn";
	std::string address = "8104 E Nora Ave";

	SECTION("CPupil")
	{
		CPupil pupil(name, surname, patronymic, address, "Phillips Academy", "9A");
		CHECK(pupil.GetName() == name);
		CHECK(pupil.GetSurname() == surname);
		CHECK(pupil.GetPatronymic() == patronymic);
		CHECK(pupil.GetAddress() == address);
		CHECK(pupil.GetSchoolName() == "Phillips Academy");
		CHECK(pupil.GetSchoolClassName() == "9A");
	}

	SECTION("CStudent")
	{
		CStudent student(name, surname, patronymic, address, "Yale University", "s1170511716");
		CHECK(student.GetName() == name);
		CHECK(student.GetSurname() == surname);
		CHECK(student.GetPatronymic() == patronymic);
		CHECK(student.GetAddress() == address);
		CHECK(student.GetUniversityName() == "Yale University");
		CHECK(student.GetStudentCardNumber() == "s1170511716");
	}

	SECTION("CAdvancedStudent")
	{
		CAdvancedStudent advancedStudent(name, surname, patronymic, address, "Yale University", "s1170519636", "Development of a programming language concept");
		CHECK(advancedStudent.GetName() == name);
		CHECK(advancedStudent.GetSurname() == surname);
		CHECK(advancedStudent.GetPatronymic() == patronymic);
		CHECK(advancedStudent.GetAddress() == address);
		CHECK(advancedStudent.GetUniversityName() == "Yale University");
		CHECK(advancedStudent.GetStudentCardNumber() == "s1170519636");
		CHECK(advancedStudent.GetDissertationTopic() == "Development of a programming language concept");
	}

	SECTION("CTeacher")
	{
		CTeacher teacher(name, surname, patronymic, address, "OOP");
		CHECK(teacher.GetName() == name);
		CHECK(teacher.GetSurname() == surname);
		CHECK(teacher.GetPatronymic() == patronymic);
		CHECK(teacher.GetAddress() == address);
		CHECK(teacher.GetSubjectName() == "OOP");
	}

	SECTION("CWorker")
	{
		CWorker worker(name, surname, patronymic, address, "Programmer");
		CHECK(worker.GetName() == name);
		CHECK(worker.GetSurname() == surname);
		CHECK(worker.GetPatronymic() == patronymic);
		CHECK(worker.GetAddress() == address);
		CHECK(worker.GetSpecialty() == "Programmer");
	}
}