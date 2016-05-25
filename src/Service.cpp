//
// Created by Oleksandr Anyshchenko on 24/05/16.
//

#include "HttpClient.h"
#include "Service.h"
#include "HandlerFactory.h"
#include <Poco/JSON/Parser.h>
#include <Poco/Net/HTTPServer.h>

constexpr std::string TOKEN = "";

Service::Service() : ServerApplication() { }

int Service::main(const std::vector<std::string>& args) {

    auto prettyPrint = [](std::string const& data) {
        Poco::JSON::Parser parser;
        auto obj = parser.parse(data);
        std::cout << obj.toString() << std::endl;
    };

    try {
        Poco::Net::HTTPServerParams::Ptr params = Poco::Net::HTTPServerParams::Ptr(new Poco::Net::HTTPServerParams);
        Poco::Net::HTTPRequestHandlerFactory::Ptr handlerFactory = Poco::Net::HTTPRequestHandlerFactory::Ptr(new HandlerFactory);

        params->setSoftwareVersion("1.0");

        Poco::Net::HTTPServer server(handlerFactory, 9090, params);

        HttpClient sslClient("https://api.telegram.org/bot" + TOKEN, true);
        std::string method = "/sendMessage?chat_id=444086&text=Hello From C";
        auto result = sslClient.makeGetRequest(method);
        prettyPrint(result);

        server.start();
        waitForTerminationRequest();
        server.stop();
    } catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }

    return EXIT_OK;
}
