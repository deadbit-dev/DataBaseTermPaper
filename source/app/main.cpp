#include <iostream>
#include <stdexcept>

#include "application.h"

int main(int argc, const char* argv[])
{
    Application app;

    try
    {
        app.init(argc, argv);
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}