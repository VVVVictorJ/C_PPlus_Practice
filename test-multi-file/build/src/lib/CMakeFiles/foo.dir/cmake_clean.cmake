file(REMOVE_RECURSE
  "../../lib/libfoo.pdb"
  "../../lib/libfoo.so"
  "CMakeFiles/foo.dir/src/foo.cpp.o"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/foo.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
