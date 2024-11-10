#pragma once

#include "ServiceDetails.h"

class HourlyWeatherService : public ServiceDetails
{
public:
	HourlyWeatherService(const std::string& serviceName, const std::string& serviceDescription);
};

