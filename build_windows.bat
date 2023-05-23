rm -rf out/build

if not exist out mkdir out
if not exist out\build (
    mkdir out\build
)

set CMAKE_PROJ_NAME=CPP_CMAKE
cmake -S . -B out/build -G"Visual Studio 16 2019"

setlocal 
cd out/build

"C:\Program Files\Microsoft Visual Studio\2022\Community\Msbuild\Current\Bin\MSBuild.exe" %CMAKE_PROJ_NAME%.sln

cp ./Release/%PROJ_NAME%.mll ../../builds/windows-x64/

endlocal