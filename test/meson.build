# create the test executable
test_exe = executable('sycontainer_test', 'sycontainer_test.c',
  include_directories : [
    include_directories('..')
  ],
  link_with : [
    shlib
  ]
)
test('sycontainer', test_exe)
