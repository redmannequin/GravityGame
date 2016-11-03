call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64

pushd bin
cl -Zi /EHsc /MD ../src/main.cpp ../src/window.cpp ../src/ocl.cpp ../src/game.cpp /I F:\GitHub\GravityGame\lib\SDL2-2.0.5\include /I "C:\Program Files (x86)\AMD APP SDK\3.0\include" /link opengl32.lib SDL2.lib SDL2main.lib OpenCL.lib /LIBPATH:F:\GitHub\GravityGame\lib\SDL2-2.0.5\lib\x64  /LIBPATH:"C:\Program Files (x86)\AMD APP SDK\3.0\lib\x86_64" /SUBSYSTEM:CONSOLE
popd