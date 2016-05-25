//
// Created by Oleksandr Anyshchenko on 24/05/16.
//

#pragma once

#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPRequestHandler.h>

class Handler : public Poco::Net::HTTPRequestHandler {

public:

    void handleRequest(Poco::Net::HTTPServerRequest &req, Poco::Net::HTTPServerResponse &resp);

};


