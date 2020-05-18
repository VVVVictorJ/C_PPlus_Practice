file(REMOVE_RECURSE
  "../../lib/libfoo.a"
  "../../lib/libfoo.pdb"
  "CMakeFiles/foo_static.dir/src/foo.cpp.o"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/foo_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
