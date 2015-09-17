FILE(REMOVE_RECURSE
  "CMakeFiles/DEPS"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/DEPS.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
