#pragma once
#include "CPersonImpl.h"
#include "IPerson.h"

class CTeacher : public CPersonImpl<IPerson>
{
};