//
// Created by Oleksandr Anyshchenko on 24/05/16.
//

#include <iostream>
#include "Handler.h"

void Handler::handleRequest(Poco::Net::HTTPServerRequest &request, Poco::Net::HTTPServerResponse &response) {

    std::cout << "in request: " << request.getHost() << std::endl;
    response.setStatus(Poco::Net::HTTPServerResponse::HTTP_OK);
    std::ostream& out = response.send();

    out << "hello";
}