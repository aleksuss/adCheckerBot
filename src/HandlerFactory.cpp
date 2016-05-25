//
// Created by Oleksandr Anyshchenko on 24/05/16.
//

#include "HandlerFactory.h"

Poco::Net::HTTPRequestHandler* HandlerFactory::createRequestHandler(const Poco::Net::HTTPServerRequest& request) {
    return new Handler;
}
