#pragma once

#include <string>
#include <vector>
#include "Subscriber.h"

class ServiceDetails
{
protected:
	std::string name;
	std::string description;

	std::vector<Subscriber> subscribers;

public:
	ServiceDetails(const std::string& serviceName, const std::string& serviceDescription);

	virtual ~ServiceDetails();

	virtual void addSubscriber(const Subscriber& subscriber);

	virtual void removeSubscriber(const std::string& subscriberName);

	virtual const std::vector<Subscriber>& getSubscribers() const;

	const std::string& getName() const { return name; }
	const std::string& getDescription() const { return description; }
};

