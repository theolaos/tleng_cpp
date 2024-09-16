#include <pybind11/pybind11.h>

#include "mymath.h"


#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(tleng3, m) {
    m.doc() = R"rpdoc(
    
    Tleng3 Example plugin

    Written in CPP

    .. currentmodule:: tleng3

    .. autosummery::
        :toctree: _generate

        add
        subtract
    
    )rpdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers
        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", &subtract, R"pbdoc(
        Add two numbers
        Some other explanation about the add function.
    )pbdoc");


#ifdef VERSION_INFO
    m.attr("__version__") = MACRO_STRINGIFY(VERSION_INFO);
#else
    m.attr("__version__") = "dev";
#endif
}
