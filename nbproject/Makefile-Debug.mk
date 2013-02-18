#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AbstractBlockStore.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/DirectBlockFile.o \
	${OBJECTDIR}/CachedBlockStore.o \
	${OBJECTDIR}/KeyValueDB.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f2

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/diskexperiment

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/diskexperiment: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/diskexperiment ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/AbstractBlockStore.o: AbstractBlockStore.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/AbstractBlockStore.o AbstractBlockStore.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.cpp

${OBJECTDIR}/DirectBlockFile.o: DirectBlockFile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/DirectBlockFile.o DirectBlockFile.cpp

${OBJECTDIR}/CachedBlockStore.o: CachedBlockStore.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/CachedBlockStore.o CachedBlockStore.cpp

${OBJECTDIR}/KeyValueDB.o: KeyValueDB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/KeyValueDB.o KeyValueDB.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/BlockIOTest.o ${TESTDIR}/tests/BlockIOTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} -lcppunit 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/KeyValueTest.o ${TESTDIR}/tests/KeyValueTestRunner.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS} -lcppunit -lcppunit 


${TESTDIR}/tests/BlockIOTest.o: tests/BlockIOTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/BlockIOTest.o tests/BlockIOTest.cpp


${TESTDIR}/tests/BlockIOTestRunner.o: tests/BlockIOTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/BlockIOTestRunner.o tests/BlockIOTestRunner.cpp


${TESTDIR}/tests/KeyValueTest.o: tests/KeyValueTest.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/KeyValueTest.o tests/KeyValueTest.cpp


${TESTDIR}/tests/KeyValueTestRunner.o: tests/KeyValueTestRunner.cpp 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.cc) -g -I. -I. -MMD -MP -MF $@.d -o ${TESTDIR}/tests/KeyValueTestRunner.o tests/KeyValueTestRunner.cpp


${OBJECTDIR}/AbstractBlockStore_nomain.o: ${OBJECTDIR}/AbstractBlockStore.o AbstractBlockStore.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/AbstractBlockStore.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/AbstractBlockStore_nomain.o AbstractBlockStore.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/AbstractBlockStore.o ${OBJECTDIR}/AbstractBlockStore_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/DirectBlockFile_nomain.o: ${OBJECTDIR}/DirectBlockFile.o DirectBlockFile.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/DirectBlockFile.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/DirectBlockFile_nomain.o DirectBlockFile.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/DirectBlockFile.o ${OBJECTDIR}/DirectBlockFile_nomain.o;\
	fi

${OBJECTDIR}/CachedBlockStore_nomain.o: ${OBJECTDIR}/CachedBlockStore.o CachedBlockStore.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/CachedBlockStore.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/CachedBlockStore_nomain.o CachedBlockStore.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/CachedBlockStore.o ${OBJECTDIR}/CachedBlockStore_nomain.o;\
	fi

${OBJECTDIR}/KeyValueDB_nomain.o: ${OBJECTDIR}/KeyValueDB.o KeyValueDB.cpp 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/KeyValueDB.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/KeyValueDB_nomain.o KeyValueDB.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/KeyValueDB.o ${OBJECTDIR}/KeyValueDB_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/diskexperiment

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
