# C++ Rocks paper scissors game

I have interpreted the following requirements:

* A game that can have N turns. I will finish the game earlier than N if there is already a winner.
* Rock beats scissors.
* Scissors beat paper.
* Paper beats rock.
* Player inputs the desired hand on each turn
* The CPU randomly selects a hand

## Execute game
To build and test use cmake:
```bash
mkdir build
cd build
cmake ../
cmake --build .
ctest .
cd ..
```
After that the main binary can be found in `build/bin/Game`.

There are precompiled binaries in the `precompiled` folder.

## Architecture
The game revolves around 5 main classes.
1. Config: This class holds configuration parameters of the game (such as default turns or random seed). Even though it is only two members this class makes it easy to add configuration parameters on the future and the rest of classes will have access to it during construction.
2. Game: This class is just the top level aggregate that holds all the game entities and runs the top level game sequence
3. Input: This class abstracts the user input and input validation
4. Hand: This class represents a Hand (player or CPU) and allows to compare two hands to see which won.
5. TurnEngine: This class contains the logic that executes turns and also keeps scores of the different turns

## Folder structure

* game: Static Game library with all classes.
* game.exe: The executable main.cpp file.
* test: All the unit tests (using google test framework).
* .github: Contains github actions for CI. It builds, tests and uses a linter for every commit.
* .vscode: Configuration for VSCode editor.
* code_coverage: Pregenerated code coverage report obtained by running `run_code_coverage.sh`.
* precompiled: Precompiled binaries ready to use.

