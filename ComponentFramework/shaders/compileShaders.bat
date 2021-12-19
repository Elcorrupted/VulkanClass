@echo off
rem "rem" means remark Mircrosoft's comment in a .bat file
rem Scott does not like .bat files at all -insert rant plus an added jab at Microsoft as a whole-

rem drag and drop a file will set %1 to the name of the file
set filename=%1

rem the next line will remove the quotation marks from the file name
set filename=%filename:"=%

rem append the '.spv' suffix on the compiled glsl output file
set output=%filename%.spv
echo Compiling:  %filename%

rem if the old output file exists delete it.
if exist %output% ( del %output% )
rem get the path to your install version of Vulkan
C:/VulkanSDK/1.2.189.2/Bin32/glslc.exe -c "%filename%" -o "%output%"
echo Created spv file: %output%
pause