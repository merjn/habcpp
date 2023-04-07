#include <drogon/drogon.h>
#include <iostream>
#include <windows.h>
#include <filesystem>
#include <drogon/HttpAppFramework.h>

int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("127.0.0.1", 1338);

    std::cout << "Drogon version: " << drogon::getVersion() << std::endl;

    // Habcpp needs to find the config file.
    // TODO: Make this a relative path - this is stupid as fuck. 
    drogon::app().loadConfigFile("C:\\Users\\Merijn\\Desktop\\Habcpp\\config.json");

    //Run HTTP framework,the method will block in the internal event loop
    drogon::app().run();
    return 0;
}
