project('sycontainer', 'c',
  version : '1.0',
  default_options : [
    'warning_level=3'
  ]
)

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_SYCONTAINER']

shlib = shared_library('sycontainer', 'sycontainer.c',
  install : true,
  c_args : lib_args,
  gnu_symbol_visibility : 'hidden',
)

test_exe = executable('sycontainer_test', 'sycontainer_test.c',
  link_with : shlib)
test('sycontainer', test_exe)

# Make this library usable as a Meson subproject.
sycontainer_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : shlib)

# Make this library usable from the system's
# package manager.
install_headers('sycontainer.h', subdir : 'sycontainer')

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'sycontainer',
  filebase : 'sycontainer',
  description : 'Container for multiple types of data',
  subdirs : 'sycontainer',
  libraries : shlib,
  version : '0.1',
)

# Generating spec templates for RPM files
rpm = import('rpm')
rpm.generate_spec_template()
