# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/UserFolder/XiaomiCloud/Work/Source/GitHub/UDB-TEST/MDK-ARM/tmp/Template_Linux+TemplateLinux"
  "C:/UserFolder/XiaomiCloud/Work/Source/GitHub/UDB-TEST/MDK-ARM/tmp/1"
  "C:/UserFolder/XiaomiCloud/Work/Source/GitHub/UDB-TEST/MDK-ARM/tmp/Template_Linux+TemplateLinux"
  "C:/UserFolder/XiaomiCloud/Work/Source/GitHub/UDB-TEST/MDK-ARM/tmp/Template_Linux+TemplateLinux/tmp"
  "C:/UserFolder/XiaomiCloud/Work/Source/GitHub/UDB-TEST/MDK-ARM/tmp/Template_Linux+TemplateLinux/src/Template_Linux+TemplateLinux-stamp"
  "C:/UserFolder/XiaomiCloud/Work/Source/GitHub/UDB-TEST/MDK-ARM/tmp/Template_Linux+TemplateLinux/src"
  "C:/UserFolder/XiaomiCloud/Work/Source/GitHub/UDB-TEST/MDK-ARM/tmp/Template_Linux+TemplateLinux/src/Template_Linux+TemplateLinux-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/UserFolder/XiaomiCloud/Work/Source/GitHub/UDB-TEST/MDK-ARM/tmp/Template_Linux+TemplateLinux/src/Template_Linux+TemplateLinux-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/UserFolder/XiaomiCloud/Work/Source/GitHub/UDB-TEST/MDK-ARM/tmp/Template_Linux+TemplateLinux/src/Template_Linux+TemplateLinux-stamp${cfgdir}") # cfgdir has leading slash
endif()
