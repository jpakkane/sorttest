project('sorttest', 'c', 'cpp')

slib = shared_library('sorter', 'sorter.cpp',
  cpp_args : ['-fvisibility=hidden'],
  link_args : '-ldl')

executable('sorttest', 'sorttest.c',
  link_with : slib)
