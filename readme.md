# Sorting speed experiment

An experiment to see if you can provide a shared library with a C API
that does sorting as fast as C++'s `std::sort`.

Times:

    qsort from C stdlib: 14.8s
    std::sort from C++:   8.5s
    live codegen:         8.8s
