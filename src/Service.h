//
// Created by Oleksandr Anyshchenko on 24/05/16.
//

#pragma once

#include <Poco/Util/ServerApplication.h>

class Service : public Poco::Util::ServerApplication {

public:
    Service();
    int main(const std::vector<std::string> &args);
};
