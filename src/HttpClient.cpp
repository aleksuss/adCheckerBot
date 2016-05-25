//
// Created by Oleksandr Anyshchenko on 24/05/16.
//

#include <iostream>
#include <Poco/StreamCopier.h>
#include <sstream>
#include "HttpClient.h"


HttpClient::HttpClient(const std::string &url, bool ssl) : mUri(url) {

    if (ssl)
        mSession.reset(new Poco::Net::HTTPSClientSession());
    else
        mSession.reset(new Poco::Net::HTTPClientSession());

    mSession->setHost(mUri.getHost());
    mSession->setPort(mUri.getPort());
}


std::string HttpClient::makeGetRequest(std::string const& method) {
    std::string result;

    try {
        auto path = mUri.getPathAndQuery() + method;
        Poco::Net::HTTPRequest request(Poco::Net::HTTPRequest::HTTP_GET, path);
        Poco::Net::HTTPResponse response;

        mSession->sendRequest(request);

        auto &body = mSession->receiveResponse(response);
        std::ostringstream stream;
        Poco::StreamCopier::copyStream(body, stream);
        std::cout << response.getReasonForStatus(response.getStatus()) << std::endl;
        result = stream.str();
    } catch(Poco::Exception& e) {
        std::cerr << "Exception: " << e.displayText() << std::endl;
    }

    return result;
}

void HttpClient::setUrl(const std::string& url) {
    mUri.clear();
    mUri = url;

    mSession->reset();
    mSession->setHost(mUri.getHost());
    mSession->setPort(mUri.getPort());
}
