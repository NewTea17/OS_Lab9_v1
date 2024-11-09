#include "ServiceDetails.h"

ServiceDetails::ServiceDetails(const std::string& serviceName, const std::string& serviceDescription)
	: name(serviceName), description(serviceDescription) 
{}

ServiceDetails::~ServiceDetails()
{}

void ServiceDetails::addSubscriber(const Subscriber & subscriber)
{
	subscribers.push_back(subscriber);
}

void ServiceDetails::removeSubscriber(const std::string& subscriberName)
{
	subscribers.erase(std::remove_if(subscribers.begin(), subscribers.end(),
		[&](const Subscriber& s) { return s.name == subscriberName; }),
		subscribers.end());
}

const std::vector<Subscriber>& ServiceDetails::getSubscribers() const
{
	return subscribers;
}
