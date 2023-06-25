pushd build/game/CMakeFiles/Game.dir/src/
gcov *.gcno
popd
lcov --capture --directory build/game/CMakeFiles/Game.dir/src/ --output-file build/gtest_coverage.info
genhtml build/gtest_coverage.info --output-directory code_coverage
