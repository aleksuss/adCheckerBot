//
// Created by Oleksandr Anyshchenko on 24/05/16.
//

#pragma once

#include "Handler.h"
#include <Poco/Net/HTTPRequestHandlerFactory.h>

class HandlerFactory : public Poco::Net::HTTPRequestHandlerFactory {

public:
    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request);
};
