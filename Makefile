#PROTECTED REGION ID(Starter::Makefile) ENABLED START#
#=============================================================================
#
# file :        Makefile
#
# description : Makefile to generate a TANGO device server.
#
# project :     Starter for Tango Administration
#
# $Author$
#
# $Revision$
#
# $Log$
#
#=============================================================================
#                This file is generated by POGO
#        (Program Obviously used to Generate tango Object)
#=============================================================================
#
#
#=============================================================================
# MAKE_ENV is the path to find common environment to buil project
#
MAKE_ENV = /segfs/tango/cppserver/env

#=============================================================================
# PACKAGE_NAME is the name of the library/device/exe you want to build
#
PACKAGE_NAME = Starter
MAJOR_VERS   = 6
MINOR_VERS   = 5
RELEASE      = $(MAJOR_VERS).$(MINOR_VERS)

# #=============================================================================
# # RELEASE_TYPE
# # - DEBUG     : debug symbols - no optimization
# # - OPTIMIZED : no debug symbols - optimization level set to O2
# #-----------------------------------------------------------------------------
RELEASE_TYPE = DEBUG

#=============================================================================
# OUTPUT_TYPE can be one of the following :
#   - 'STATIC_LIB' for a static library (.a)
#   - 'SHARED_LIB' for a dynamic library (.so)
#   - 'DEVICE' for a device server (will automatically include and link
#            with Tango dependencies)
#   - 'SIMPLE_EXE' for an executable with no dependency (for exemple the test tool
#                of a library with no Tango dependencies)
#
OUTPUT_TYPE = DEVICE

#=============================================================================
# OUTPUT_DIR  is the directory which contains the build result.
# if not set, the standard location is :
#	- $HOME/DeviceServers if OUTPUT_TYPE is DEVICE
#	- ../bin for others
#
OUTPUT_DIR = ./bin/$(BIN_DIR)



#=============================================================================
# INC_DIR_USER is the list of all include path needed by your sources
#   - for a device server, tango dependencies are automatically appended
#   - '-I ../include' and '-I .' are automatically appended in all cases
#
#
INC_DIR_USER= -I . 

#=============================================================================
# LFLAGS_USR is the list of user link flags
#   - for a device server, tango libraries directories are automatically appended
#   - '-ldl -lpthread' is automatically appended in all cases
#
# !!! ATTENTION !!!
# Be aware that the order matters. 
# For example if you must link with libA, and if libA depends itself on libB
# you must use '-lA -lB' in this order as link flags, otherwise you will get
# 'undefined reference' errors
#
LFLAGS_USR+= -Wl,-z,now -Wl,-z,relro -pie


#=============================================================================
# CXXFLAGS_USR lists the compilation flags specific for your library/device/exe
# This is the place where to put your compile-time macros using '-Dmy_macro'
#
# -DACE_HAS_EXCEPTIONS -D__ACE_INLINE__ for ACE
#
CXXFLAGS_USR+= -Wall -Wextra -D_FORTIFY_SOURCE=2 -O1 -fpie -fstack-protector


#=============================================================================
# TANGO_REQUIRED 
# - TRUE  : your project depends on TANGO
# - FALSE : your project does not depend on TANGO
#-----------------------------------------------------------------------------
# - NOTE : if PROJECT_TYPE is set to DEVICE, TANGO will be auto. added
#-----------------------------------------------------------------------------  
TANGO_REQUIRED = TRUE



#=============================================================================
#	include Standard TANGO compilation options
#
include $(MAKE_ENV)/tango.opt

#=============================================================================
#	POST_PROCESSING: action to be done after normal make.
#	e.g.:  change executable file name, .....
#POST_PROCESSING = \
#	mv bin/$(BIN_DIR)/$(PACKAGE_NAME) bin/$(BIN_DIR)/$(PACKAGE_NAME)_DS

#=============================================================================
# SVC_OBJS is the list of all objects needed to make the output
#
SVC_INCL =  $(PACKAGE_NAME).h $(PACKAGE_NAME)Class.h


SVC_OBJS =      \
            $(OBJDIR)/$(PACKAGE_NAME).o \
            $(OBJDIR)/$(PACKAGE_NAME)Class.o \
            $(OBJDIR)/$(PACKAGE_NAME)StateMachine.o \
			$(OBJDIR)/$(PACKAGE_NAME)Util.o \
			$(OBJDIR)/CheckProcessUtil.o \
			$(OBJDIR)/PingThread.o \
			$(OBJDIR)/StartProcessThread.o \
			$(OBJDIR)/ClassFactory.o  \
            $(OBJDIR)/main.o 

#=============================================================================
#	include common targets
#
include $(MAKE_ENV)/common_target.opt




SVN_TAG_REV  = Release-$(RELEASE)
SVN_SVC_PATH = $(SVN_TCS)/classes/cpp/starter
tag:
	@echo "Tagging  $(PACKAGE_NAME)  for $(SVN_TAG_REV)"
	svn copy  $(SVN_SVC_PATH)/trunk \
	          $(SVN_SVC_PATH)/tags/$(PACKAGE_NAME)-$(SVN_TAG_REV)



WWW_HOST=webserv02
WWW_HOME=/ftp/pub/cs/tango
put_ftp:
	scp -rp $(TANGO_HOME)/bin/win64/Starter.exe          $(WWW_HOME)/Starter/win64/Starter.exe
	scp -rp $(TANGO_HOME)/bin/win64/service/Starter.exe  $(WWW_HOME)/Starter/win64/service/Starter.exe

#PROTECTED REGION END#
