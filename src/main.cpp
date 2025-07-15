#include <iostream>

#include "Eigen/Dense"
#include "fmt/color.h"
#include "fmt/ostream.h"

namespace Mycolors
{
    const auto green = fmt::fg(fmt::terminal_color::bright_green) | fmt::emphasis::bold;
    const auto red = fmt::fg(fmt::terminal_color::bright_red) | fmt::emphasis::bold;
    const auto yellow = fmt::fg(fmt::terminal_color::bright_yellow) | fmt::emphasis::bold;
    const auto blue = fmt::fg(fmt::terminal_color::bright_blue) | fmt::emphasis::bold;
}

using Eigen::MatrixXd;

int main(int, char **)
{
    std::cout << "Hello, from template!\n";
    fmt::print(Mycolors::green, "it is a template.\n");

    MatrixXd m(3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            m(i, j) = i * j;
        }
    }
    fmt::print(Mycolors::blue, "[[{}]]\n", fmt::streamed(m));
}
