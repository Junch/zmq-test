@echo off 
set config=Release
set folder=_build-x64

@mkdir %folder% >nul
pushd %folder% >nul

@echo on

cmake -A x64 -DCPPZMQ_BUILD_TESTS=OFF ..
cmake --build . --config %config%

@echo off
popd >nul
