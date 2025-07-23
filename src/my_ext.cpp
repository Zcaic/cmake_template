#include <nanobind/nanobind.h>
#include<nanobind/eigen/dense.h>

namespace nb=nanobind;
using namespace nb::literals;

int add(int a, int b=1) { return a + b; }

void mul(nb::DRef<Eigen::MatrixXf> x,int b=2){
    x*=b;
}
void mul(nb::DRef<Eigen::MatrixXd> x,int b=2){
    x*=b;
}

NB_MODULE(my_ext, m) {
    m.def("add", &add,nb::arg("a"),nb::arg("b")=1,"This function adds two numbers and increments if only one is provided.");
    m.def("mul",nb::overload_cast<nb::DRef<Eigen::MatrixXf>,int>(&mul),nb::arg("x"),nb::arg("b")=2,"This function mul a numbers to a matrix without copy.");
    m.def("mul",nb::overload_cast<nb::DRef<Eigen::MatrixXd>,int>(&mul),nb::arg("x"),nb::arg("b")=2,"This function mul a numbers to a matrix without copy.");
}