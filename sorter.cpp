#include<sorter.h>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<dlfcn.h>
#include<unistd.h>
#include<assert.h>

const char *fn_template = R"(
#include<algorithm>

LESS_FUNC

extern "C" void sort_impl(void *data, TYPENAME size) {
  TYPENAME * typed_data = reinterpret_cast<TYPENAME*>(data);
  std::sort(typed_data, typed_data + size, is_less);
}
)";

extern "C" sorter build_sorter(const char *type_str, const char *compare_str) {
    std::string code{fn_template};

    auto func_loc = code.find("LESS_FUNC");
    code.replace(func_loc, 9, compare_str);
    auto type_loc = code.find("TYPENAME");
    while(type_loc != std::string::npos) {
        code.replace(type_loc, 8, type_str);
        type_loc = code.find("TYPENAME");
    }
    FILE *f = fopen("tmpfile.cpp", "w");
    fwrite(code.c_str(), code.size(), 1, f);
    fclose(f);
    assert(system("c++ -O2 -g -shared -fPIC -o libtemp.so tmpfile.cpp") == 0);
    void *h = dlopen("libtemp.so", RTLD_LAZY);
    assert(unlink("libtemp.so") == 0);
    assert(unlink("tmpfile.cpp") == 0);
    void *ptr = dlsym(h, "sort_impl");
    assert(ptr != nullptr);
    return (sorter)ptr;
}
