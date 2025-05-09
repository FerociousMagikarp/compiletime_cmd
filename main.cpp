/*
 * MIT License

 * Copyright (c) 2025 FerociousMagikarp

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "ct_cmd.hpp"
#include <iostream>

namespace test_ct_cmd
{

struct filename
{
    using value_type = std::string;

    constexpr static char short_name = 'f';
    constexpr static std::string_view message = "test enter a filename";
    constexpr static bool must = true;
    constexpr static bool ignore_name = true;
    constexpr static std::string_view default_value = "test/filename";
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

    auto parser = ct_cmd::make_parser_ptr<filename, debug>();

    if (!parser->parse(argc, argv))
    {
        std::cerr << parser->get_error() << std::endl;
        return 1;
    }

    if (parser->is_help())
    {
        std::cout << parser->generate_help_message() << std::endl;
        return 0;
    }

    std::cout << parser->get<filename>() << std::endl;

    if (parser->exist<debug>())
    {
        std::cout << "enter debug" << std::endl;
    }

    return 0;
}
