# AoC2019
My solutions to [Advent of Code 2019](https://adventofcode.com/2019) reworked to use C++20 modules.

### Working setup:
This project is/was possible to build with:
- Microsoft Visual Studio Community *2019 16.7.2*
- Windows SDK Version *10.18362.0*
- Platform Toolset *v142* (should be the VS2019 one)
- C++ Language Standard *std:c\+\+latest* ofc, as of now it's partial implementation of C++20


### Troubleshooting:
1. **I can't get Utils to build**
   - For a clean build of Utils, You need 3 consecutive builds in total.
2. **C2230 could not find module 'xxx'**
   - As above - if module 'xxx' gets built in the first build, then all files that import it will get built in the next build at the earliest.