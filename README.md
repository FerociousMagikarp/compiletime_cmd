# compiletime_cmd

## Why
I know command-line parsing is obviously supposed to be a runtime thing, so why did I even even make this compile-time build parameter parsing library? Probably because it's just fun to write this way! :clown_face: Let's be real: this library has zero practical value whatsoever.

And these sentences were writen by DeepSeek. :see_no_evil:

## Usage
``` C++
#include "ct_cmd.hpp"
#include <iostream>

namespace test_ct_cmd // namespace is not necessary
{

struct filename // the struct name (or class name) is the name of this argument
{
    using value_type = std::string; // use `value_type` to set the value type

    constexpr static char short_name = 'f'; // use `short_name` to set the short name of this argument
    constexpr static std::string_view message = "test enter a filename"; // use `message` to set the help message
    constexpr static bool must = true; // use `must` if this argument is necessary
    constexpr static bool ignore_name = true; // use `ignore_name` to set this argument without specific option name.
                                              // only one or none argument can set this config
    constexpr static std::string_view default_value = "test/filename"; // use `default_value` to set default value
};

struct debug
{
    constexpr static char short_name = 'd';
    constexpr static std::string_view message = "test no value type";
};

} // namespace test_ct_cmd

int main(int argc, char** argv)
{
    using namespace test_ct_cmd;

    auto parser = ct_cmd::make_parser_ptr<filename, debug>(); // create a parser

    if (!parser->parse(argc, argv)) // return true if success else return false
    {
        std::cerr << parser->get_error() << std::endl; // use `get_error()->std::string_view` when parse failed
        return 1;
    }

    if (parser->is_help()) // argument `--help` or `-?` will make `is_help()->bool` return true
    {
        std::cout << parser->generate_help_message() << std::endl; // to generate help message
        return 0;
    }

    std::cout << parser->get<filename>() << std::endl; // use `get<argement-class>()->const auto&` to get the value
                                                       // when this argument is not `must` and do not have a default value, please check the existence

    if (parser->exist<debug>()) // check the existence
    {
        std::cout << "enter debug" << std::endl;
    }

    return 0;
}

```
