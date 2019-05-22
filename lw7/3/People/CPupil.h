#pragma once
#include "CPersonImpl.h"
#include "IPerson.h"

class CPupil : public CPersonImpl<IPerson>
{
};