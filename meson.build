project('sorttest', 'c', 'cpp',
  default_options : ['cpp_std=c++14'])

slib = shared_library('sorter', 'sorter.cpp',
  cpp_args : ['-fvisibility=hidden'],
  link_args : '-ldl')

executable('sorttest', 'sorttest.c',
  link_with : slib)
