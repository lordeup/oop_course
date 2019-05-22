#pragma once
#include "CPersonImpl.h"
#include "IPerson.h"

class CWorker : public CPersonImpl<IPerson>
{
};