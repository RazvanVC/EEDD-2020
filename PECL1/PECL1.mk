##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=PECL1
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=C:/Users/necok/OneDrive/Escritorio/clase/estructuras_de__datos/EEDD-2020
ProjectPath            :=C:/Users/necok/OneDrive/Escritorio/clase/estructuras_de__datos/EEDD-2020/PECL1
IntermediateDirectory  :=../build-$(ConfigurationName)/PECL1
OutDir                 :=../build-$(ConfigurationName)/PECL1
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=necok
Date                   :=15/01/2021
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=..\build-$(ConfigurationName)\bin\$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=../build-$(ConfigurationName)/PECL1/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECL1/NodoPila.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECL1/paciente.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECL1/PilaPacientes.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECL1/ArbolUrgencia.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/PECL1/NodoArbol.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/PECL1/.d $(Objects) 
	@if not exist "..\build-$(ConfigurationName)\PECL1" mkdir "..\build-$(ConfigurationName)\PECL1"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@if not exist "..\build-$(ConfigurationName)\PECL1" mkdir "..\build-$(ConfigurationName)\PECL1"
	@if not exist ""..\build-$(ConfigurationName)\bin"" mkdir ""..\build-$(ConfigurationName)\bin""

../build-$(ConfigurationName)/PECL1/.d:
	@if not exist "..\build-$(ConfigurationName)\PECL1" mkdir "..\build-$(ConfigurationName)\PECL1"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/PECL1/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/PECL1/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/necok/OneDrive/Escritorio/clase/estructuras_de__datos/EEDD-2020/PECL1/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECL1/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECL1/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECL1/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/PECL1/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECL1/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/PECL1/NodoPila.cpp$(ObjectSuffix): NodoPila.cpp ../build-$(ConfigurationName)/PECL1/NodoPila.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/necok/OneDrive/Escritorio/clase/estructuras_de__datos/EEDD-2020/PECL1/NodoPila.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoPila.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECL1/NodoPila.cpp$(DependSuffix): NodoPila.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECL1/NodoPila.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECL1/NodoPila.cpp$(DependSuffix) -MM NodoPila.cpp

../build-$(ConfigurationName)/PECL1/NodoPila.cpp$(PreprocessSuffix): NodoPila.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECL1/NodoPila.cpp$(PreprocessSuffix) NodoPila.cpp

../build-$(ConfigurationName)/PECL1/paciente.cpp$(ObjectSuffix): paciente.cpp ../build-$(ConfigurationName)/PECL1/paciente.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/necok/OneDrive/Escritorio/clase/estructuras_de__datos/EEDD-2020/PECL1/paciente.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/paciente.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECL1/paciente.cpp$(DependSuffix): paciente.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECL1/paciente.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECL1/paciente.cpp$(DependSuffix) -MM paciente.cpp

../build-$(ConfigurationName)/PECL1/paciente.cpp$(PreprocessSuffix): paciente.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECL1/paciente.cpp$(PreprocessSuffix) paciente.cpp

../build-$(ConfigurationName)/PECL1/PilaPacientes.cpp$(ObjectSuffix): PilaPacientes.cpp ../build-$(ConfigurationName)/PECL1/PilaPacientes.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/necok/OneDrive/Escritorio/clase/estructuras_de__datos/EEDD-2020/PECL1/PilaPacientes.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PilaPacientes.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECL1/PilaPacientes.cpp$(DependSuffix): PilaPacientes.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECL1/PilaPacientes.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECL1/PilaPacientes.cpp$(DependSuffix) -MM PilaPacientes.cpp

../build-$(ConfigurationName)/PECL1/PilaPacientes.cpp$(PreprocessSuffix): PilaPacientes.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECL1/PilaPacientes.cpp$(PreprocessSuffix) PilaPacientes.cpp

../build-$(ConfigurationName)/PECL1/ArbolUrgencia.cpp$(ObjectSuffix): ArbolUrgencia.cpp ../build-$(ConfigurationName)/PECL1/ArbolUrgencia.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/necok/OneDrive/Escritorio/clase/estructuras_de__datos/EEDD-2020/PECL1/ArbolUrgencia.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ArbolUrgencia.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECL1/ArbolUrgencia.cpp$(DependSuffix): ArbolUrgencia.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECL1/ArbolUrgencia.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECL1/ArbolUrgencia.cpp$(DependSuffix) -MM ArbolUrgencia.cpp

../build-$(ConfigurationName)/PECL1/ArbolUrgencia.cpp$(PreprocessSuffix): ArbolUrgencia.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECL1/ArbolUrgencia.cpp$(PreprocessSuffix) ArbolUrgencia.cpp

../build-$(ConfigurationName)/PECL1/NodoArbol.cpp$(ObjectSuffix): NodoArbol.cpp ../build-$(ConfigurationName)/PECL1/NodoArbol.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/necok/OneDrive/Escritorio/clase/estructuras_de__datos/EEDD-2020/PECL1/NodoArbol.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NodoArbol.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/PECL1/NodoArbol.cpp$(DependSuffix): NodoArbol.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/PECL1/NodoArbol.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/PECL1/NodoArbol.cpp$(DependSuffix) -MM NodoArbol.cpp

../build-$(ConfigurationName)/PECL1/NodoArbol.cpp$(PreprocessSuffix): NodoArbol.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/PECL1/NodoArbol.cpp$(PreprocessSuffix) NodoArbol.cpp


-include ../build-$(ConfigurationName)/PECL1//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


