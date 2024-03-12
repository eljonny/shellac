##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=shellac
ConfigurationName      :=Debug
WorkspacePath          :=/home/jhyry/Code/shellac
ProjectPath            :=/home/jhyry/Code/shellac
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jonathan Hyry
Date                   :=11/03/24
CodeLitePath           :=/home/jhyry/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="shellac.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/errorHandler.c$(ObjectSuffix) $(IntermediateDirectory)/shellOps.c$(ObjectSuffix) $(IntermediateDirectory)/shellTUI.c$(ObjectSuffix) $(IntermediateDirectory)/fsh.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/errorHandler.c$(ObjectSuffix): errorHandler.c $(IntermediateDirectory)/errorHandler.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/jhyry/Code/shellac/errorHandler.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/errorHandler.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/errorHandler.c$(DependSuffix): errorHandler.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/errorHandler.c$(ObjectSuffix) -MF$(IntermediateDirectory)/errorHandler.c$(DependSuffix) -MM errorHandler.c

$(IntermediateDirectory)/errorHandler.c$(PreprocessSuffix): errorHandler.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/errorHandler.c$(PreprocessSuffix) errorHandler.c

$(IntermediateDirectory)/shellOps.c$(ObjectSuffix): shellOps.c $(IntermediateDirectory)/shellOps.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/jhyry/Code/shellac/shellOps.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/shellOps.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/shellOps.c$(DependSuffix): shellOps.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/shellOps.c$(ObjectSuffix) -MF$(IntermediateDirectory)/shellOps.c$(DependSuffix) -MM shellOps.c

$(IntermediateDirectory)/shellOps.c$(PreprocessSuffix): shellOps.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/shellOps.c$(PreprocessSuffix) shellOps.c

$(IntermediateDirectory)/shellTUI.c$(ObjectSuffix): shellTUI.c $(IntermediateDirectory)/shellTUI.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/jhyry/Code/shellac/shellTUI.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/shellTUI.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/shellTUI.c$(DependSuffix): shellTUI.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/shellTUI.c$(ObjectSuffix) -MF$(IntermediateDirectory)/shellTUI.c$(DependSuffix) -MM shellTUI.c

$(IntermediateDirectory)/shellTUI.c$(PreprocessSuffix): shellTUI.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/shellTUI.c$(PreprocessSuffix) shellTUI.c

$(IntermediateDirectory)/fsh.c$(ObjectSuffix): fsh.c $(IntermediateDirectory)/fsh.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/jhyry/Code/shellac/fsh.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/fsh.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/fsh.c$(DependSuffix): fsh.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/fsh.c$(ObjectSuffix) -MF$(IntermediateDirectory)/fsh.c$(DependSuffix) -MM fsh.c

$(IntermediateDirectory)/fsh.c$(PreprocessSuffix): fsh.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/fsh.c$(PreprocessSuffix) fsh.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


