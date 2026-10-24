cls
rmdir /s /q build

cmake -S . -B build -DCMAKE_BUILD_TYPE=Release -G Ninja
cmake --build build
