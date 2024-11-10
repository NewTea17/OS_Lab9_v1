#pragma once

#include "ServiceDetails.h"

class DailyExchangeRateService : public ServiceDetails
{
public:
	DailyExchangeRateService(const std::string& serviceName, const std::string& serviceDescription);
};

