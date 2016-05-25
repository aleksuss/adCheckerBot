//
// Created by Oleksandr Anyshchenko on 24/05/16.
//

#pragma once

#include <Poco/Net/HTTPSClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/URI.h>

class HttpClient {
public:
    HttpClient(const std::string& url, bool ssl = false);

    std::string makeGetRequest(std::string const& method);
    void setUrl(const std::string& url);

private:
    Poco::URI mUri;
    std::unique_ptr<Poco::Net::HTTPClientSession> mSession;

};


