#pragma once

#if defined _WIN32 || defined __CYGWIN__
  #define DLL_PUBLIC __declspec(dllimport)
#else
  #define DLL_PUBLIC __attribute__ ((visibility ("default")))
#endif


#ifdef __cplusplus
extern "C" {
#endif

typedef void(*sorter)(void *beginning, int size);

DLL_PUBLIC
sorter build_sorter(const char *type_str, const char *comparer);

#ifdef __cplusplus
}
#endif
