del /Q Release\Version_Working\Include\*.*
del /Q Release\Version_Working\Lib\Debug\*.*
del /Q Release\Version_Working\Lib\Release\*.*
del /Q Release\Version_Working\Documentation\*.*
del /Q Release\Version_Working\Documentation\Tutorials\*.*
copy /Y Domains\Material\Include\*.* Release\Version_Working\Include\*.*
copy /Y Domains\RenderInstance\Include\*.* Release\Version_Working\Include\*.*
copy /Y Domains\RenderObject\Include\*.* Release\Version_Working\Include\*.*
copy /Y Domains\Scene\Include\*.* Release\Version_Working\Include\*.*
copy /Y Documentation\*.* Release\Version_Working\Documentation\*.*
copy /Y Documentation\Tutorials\*.* Release\Version_Working\Documentation\Tutorials\*.*
copy /Y Documentation\Readme\*.* Release\Version_Working\*.*
copy /Y Documentation\License\*.* Release\Version_Working\*.*
cd Visual Studio Projects
copy /Y ReginaSceneLib\Debug\ReginaSceneLib.lib ..\Release\Version_Working\Lib\Debug\ReginaScene.lib
copy /Y ReginaSceneLib\Release\ReginaSceneLib.lib ..\Release\Version_Working\Lib\Release\ReginaScene.lib
cd..

