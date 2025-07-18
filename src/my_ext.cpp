#include <nanobind/nanobind.h>

namespace nb=nanobind;
using namespace nb::literals;

int add(int a, int b=1) { return a + b; }

NB_MODULE(my_ext, m) {
    m.def("add", &add,nb::arg("a"),nb::arg("b")=1,"This function adds two numbers and increments if only one is provided.");
}