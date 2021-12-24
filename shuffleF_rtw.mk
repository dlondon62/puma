###########################################################################
## Makefile generated for component 'shuffleF'. 
## 
## Makefile     : shuffleF_rtw.mk
## Generated on : Sun Dec 12 16:44:25 2021
## Final product: ./shuffleF.a
## Product type : static-library
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile
# MODELLIB                Static library target

PRODUCT_NAME              = shuffleF
MAKEFILE                  = shuffleF_rtw.mk
MATLAB_ROOT               = /Applications/MATLAB_R2021b.app
MATLAB_BIN                = /Applications/MATLAB_R2021b.app/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/maci64
START_DIR                 = /Users/Dennis/Documents/MATLAB/codegen/lib/shuffleF
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = .
C_STANDARD_OPTS           = -fno-common -fexceptions
CPP_STANDARD_OPTS         = -std=c++11 -fno-common -fexceptions
MODELLIB                  = shuffleF.a

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Clang v3.1 | gmake (64-bit Mac)
# Supported Version(s):    3.1
# ToolchainInfo Version:   2021b
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

ARCHS             = x86_64
XCODE_SDK_VER     = $(shell perl $(MATLAB_ROOT)/rtw/c/tools/macsdkver.pl)
XCODE_SDK         = MacOSX$(XCODE_SDK_VER).sdk
XCODE_DEVEL_DIR   = $(shell xcode-select -print-path)
XCODE_SDK_ROOT    = $(XCODE_DEVEL_DIR)/Platforms/MacOSX.platform/Developer/SDKs/$(XCODE_SDK)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Clang C Compiler
CC = xcrun clang

# Linker: Clang Linker
LD = xcrun clang++

# C++ Compiler: Clang C++ Compiler
CPP = xcrun clang++

# C++ Linker: Clang C++ Linker
CPP_LD = xcrun clang++

# Archiver: Clang Archiver
AR = xcrun ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/maci64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(C_STANDARD_OPTS) -mmacosx-version-min=10.14 \
                       -O3
CPPFLAGS             = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(CPP_STANDARD_OPTS) -mmacosx-version-min=10.14 \
                       -O3
CPP_LDFLAGS          = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,$(MATLAB_ARCH_BIN) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR) -L"$(MATLAB_ARCH_BIN)"
CPP_SHAREDLIB_LDFLAGS  = -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) -L"$(MATLAB_ARCH_BIN)" \
                         -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,$(MATLAB_ARCH_BIN) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR) -L"$(MATLAB_ARCH_BIN)"
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) -L"$(MATLAB_ARCH_BIN)" \
                       -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = ./shuffleF.a
PRODUCT_TYPE = "static-library"
BUILD_TYPE = "Static Library"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR) -I/Users/Dennis/Documents/MATLAB -I$(START_DIR)/CXSparse/Include -I$(START_DIR)/CXSparse/SuiteSparse_config -I$(START_DIR)/CXSparse/CXSparseSupport -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=shuffleF

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/CXSparse/Source/cs_add_ri.c $(START_DIR)/CXSparse/Source/cs_add_ci.c $(START_DIR)/CXSparse/Source/cs_amd_ri.c $(START_DIR)/CXSparse/Source/cs_amd_ci.c $(START_DIR)/CXSparse/Source/cs_chol_ri.c $(START_DIR)/CXSparse/Source/cs_chol_ci.c $(START_DIR)/CXSparse/Source/cs_cholsol_ri.c $(START_DIR)/CXSparse/Source/cs_cholsol_ci.c $(START_DIR)/CXSparse/Source/cs_counts_ri.c $(START_DIR)/CXSparse/Source/cs_counts_ci.c $(START_DIR)/CXSparse/Source/cs_cumsum_ri.c $(START_DIR)/CXSparse/Source/cs_cumsum_ci.c $(START_DIR)/CXSparse/Source/cs_dfs_ri.c $(START_DIR)/CXSparse/Source/cs_dfs_ci.c $(START_DIR)/CXSparse/Source/cs_dmperm_ri.c $(START_DIR)/CXSparse/Source/cs_dmperm_ci.c $(START_DIR)/CXSparse/Source/cs_droptol_ri.c $(START_DIR)/CXSparse/Source/cs_droptol_ci.c $(START_DIR)/CXSparse/Source/cs_dropzeros_ri.c $(START_DIR)/CXSparse/Source/cs_dropzeros_ci.c $(START_DIR)/CXSparse/Source/cs_dupl_ri.c $(START_DIR)/CXSparse/Source/cs_dupl_ci.c $(START_DIR)/CXSparse/Source/cs_entry_ri.c $(START_DIR)/CXSparse/Source/cs_entry_ci.c $(START_DIR)/CXSparse/Source/cs_etree_ri.c $(START_DIR)/CXSparse/Source/cs_etree_ci.c $(START_DIR)/CXSparse/Source/cs_fkeep_ri.c $(START_DIR)/CXSparse/Source/cs_fkeep_ci.c $(START_DIR)/CXSparse/Source/cs_gaxpy_ri.c $(START_DIR)/CXSparse/Source/cs_gaxpy_ci.c $(START_DIR)/CXSparse/Source/cs_happly_ri.c $(START_DIR)/CXSparse/Source/cs_happly_ci.c $(START_DIR)/CXSparse/Source/cs_house_ri.c $(START_DIR)/CXSparse/Source/cs_house_ci.c $(START_DIR)/CXSparse/Source/cs_ipvec_ri.c $(START_DIR)/CXSparse/Source/cs_ipvec_ci.c $(START_DIR)/CXSparse/Source/cs_load_ri.c $(START_DIR)/CXSparse/Source/cs_load_ci.c $(START_DIR)/CXSparse/Source/cs_lsolve_ri.c $(START_DIR)/CXSparse/Source/cs_lsolve_ci.c $(START_DIR)/CXSparse/Source/cs_ltsolve_ri.c $(START_DIR)/CXSparse/Source/cs_ltsolve_ci.c $(START_DIR)/CXSparse/Source/cs_lu_ri.c $(START_DIR)/CXSparse/Source/cs_lu_ci.c $(START_DIR)/CXSparse/Source/cs_lusol_ri.c $(START_DIR)/CXSparse/Source/cs_lusol_ci.c $(START_DIR)/CXSparse/Source/cs_malloc_ri.c $(START_DIR)/CXSparse/Source/cs_malloc_ci.c $(START_DIR)/CXSparse/Source/cs_maxtrans_ri.c $(START_DIR)/CXSparse/Source/cs_maxtrans_ci.c $(START_DIR)/CXSparse/Source/cs_multiply_ri.c $(START_DIR)/CXSparse/Source/cs_multiply_ci.c $(START_DIR)/CXSparse/Source/cs_norm_ri.c $(START_DIR)/CXSparse/Source/cs_norm_ci.c $(START_DIR)/CXSparse/Source/cs_permute_ri.c $(START_DIR)/CXSparse/Source/cs_permute_ci.c $(START_DIR)/CXSparse/Source/cs_pinv_ri.c $(START_DIR)/CXSparse/Source/cs_pinv_ci.c $(START_DIR)/CXSparse/Source/cs_post_ri.c $(START_DIR)/CXSparse/Source/cs_post_ci.c $(START_DIR)/CXSparse/Source/cs_print_ri.c $(START_DIR)/CXSparse/Source/cs_print_ci.c $(START_DIR)/CXSparse/Source/cs_pvec_ri.c $(START_DIR)/CXSparse/Source/cs_pvec_ci.c $(START_DIR)/CXSparse/Source/cs_qr_ri.c $(START_DIR)/CXSparse/Source/cs_qr_ci.c $(START_DIR)/CXSparse/Source/cs_qrsol_ri.c $(START_DIR)/CXSparse/Source/cs_qrsol_ci.c $(START_DIR)/CXSparse/Source/cs_scatter_ri.c $(START_DIR)/CXSparse/Source/cs_scatter_ci.c $(START_DIR)/CXSparse/Source/cs_scc_ri.c $(START_DIR)/CXSparse/Source/cs_scc_ci.c $(START_DIR)/CXSparse/Source/cs_schol_ri.c $(START_DIR)/CXSparse/Source/cs_schol_ci.c $(START_DIR)/CXSparse/Source/cs_sqr_ri.c $(START_DIR)/CXSparse/Source/cs_sqr_ci.c $(START_DIR)/CXSparse/Source/cs_symperm_ri.c $(START_DIR)/CXSparse/Source/cs_symperm_ci.c $(START_DIR)/CXSparse/Source/cs_tdfs_ri.c $(START_DIR)/CXSparse/Source/cs_tdfs_ci.c $(START_DIR)/CXSparse/Source/cs_transpose_ri.c $(START_DIR)/CXSparse/Source/cs_transpose_ci.c $(START_DIR)/CXSparse/Source/cs_compress_ri.c $(START_DIR)/CXSparse/Source/cs_compress_ci.c $(START_DIR)/CXSparse/Source/cs_updown_ri.c $(START_DIR)/CXSparse/Source/cs_updown_ci.c $(START_DIR)/CXSparse/Source/cs_usolve_ri.c $(START_DIR)/CXSparse/Source/cs_usolve_ci.c $(START_DIR)/CXSparse/Source/cs_utsolve_ri.c $(START_DIR)/CXSparse/Source/cs_utsolve_ci.c $(START_DIR)/CXSparse/Source/cs_util_ri.c $(START_DIR)/CXSparse/Source/cs_util_ci.c $(START_DIR)/CXSparse/Source/cs_reach_ri.c $(START_DIR)/CXSparse/Source/cs_reach_ci.c $(START_DIR)/CXSparse/Source/cs_spsolve_ri.c $(START_DIR)/CXSparse/Source/cs_spsolve_ci.c $(START_DIR)/CXSparse/Source/cs_ereach_ri.c $(START_DIR)/CXSparse/Source/cs_ereach_ci.c $(START_DIR)/CXSparse/Source/cs_leaf_ri.c $(START_DIR)/CXSparse/Source/cs_leaf_ci.c $(START_DIR)/CXSparse/Source/cs_randperm_ri.c $(START_DIR)/CXSparse/Source/cs_randperm_ci.c $(START_DIR)/CXSparse/Source/cs_operator_ri.c $(START_DIR)/CXSparse/Source/cs_operator_ci.c $(START_DIR)/CXSparse/CXSparseSupport/solve_from_lu.c $(START_DIR)/CXSparse/CXSparseSupport/solve_from_qr.c $(START_DIR)/CXSparse/CXSparseSupport/makeCXSparseMatrix.c $(START_DIR)/CXSparse/CXSparseSupport/unpackCXStruct.c $(START_DIR)/shuffleF_data.c $(START_DIR)/rt_nonfinite.c $(START_DIR)/rtGetNaN.c $(START_DIR)/rtGetInf.c $(START_DIR)/shuffleF_initialize.c $(START_DIR)/shuffleF_terminate.c $(START_DIR)/shuffleF.c $(START_DIR)/combineVectorElements.c $(START_DIR)/permute.c $(START_DIR)/bsxfun.c $(START_DIR)/repmat.c $(START_DIR)/ind2sub.c $(START_DIR)/mtimes.c $(START_DIR)/sparse.c $(START_DIR)/sum.c $(START_DIR)/squeeze.c $(START_DIR)/mldivide.c $(START_DIR)/xnrm2.c $(START_DIR)/sparse1.c $(START_DIR)/CXSparseAPI.c $(START_DIR)/mtimes1.c $(START_DIR)/power.c $(START_DIR)/chol.c $(START_DIR)/insertionsort.c $(START_DIR)/introsort.c $(START_DIR)/heapsort.c $(START_DIR)/fillIn.c $(START_DIR)/xgeqp3.c $(START_DIR)/shuffleF_emxutil.c $(START_DIR)/shuffleF_emxAPI.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = cs_add_ri.o cs_add_ci.o cs_amd_ri.o cs_amd_ci.o cs_chol_ri.o cs_chol_ci.o cs_cholsol_ri.o cs_cholsol_ci.o cs_counts_ri.o cs_counts_ci.o cs_cumsum_ri.o cs_cumsum_ci.o cs_dfs_ri.o cs_dfs_ci.o cs_dmperm_ri.o cs_dmperm_ci.o cs_droptol_ri.o cs_droptol_ci.o cs_dropzeros_ri.o cs_dropzeros_ci.o cs_dupl_ri.o cs_dupl_ci.o cs_entry_ri.o cs_entry_ci.o cs_etree_ri.o cs_etree_ci.o cs_fkeep_ri.o cs_fkeep_ci.o cs_gaxpy_ri.o cs_gaxpy_ci.o cs_happly_ri.o cs_happly_ci.o cs_house_ri.o cs_house_ci.o cs_ipvec_ri.o cs_ipvec_ci.o cs_load_ri.o cs_load_ci.o cs_lsolve_ri.o cs_lsolve_ci.o cs_ltsolve_ri.o cs_ltsolve_ci.o cs_lu_ri.o cs_lu_ci.o cs_lusol_ri.o cs_lusol_ci.o cs_malloc_ri.o cs_malloc_ci.o cs_maxtrans_ri.o cs_maxtrans_ci.o cs_multiply_ri.o cs_multiply_ci.o cs_norm_ri.o cs_norm_ci.o cs_permute_ri.o cs_permute_ci.o cs_pinv_ri.o cs_pinv_ci.o cs_post_ri.o cs_post_ci.o cs_print_ri.o cs_print_ci.o cs_pvec_ri.o cs_pvec_ci.o cs_qr_ri.o cs_qr_ci.o cs_qrsol_ri.o cs_qrsol_ci.o cs_scatter_ri.o cs_scatter_ci.o cs_scc_ri.o cs_scc_ci.o cs_schol_ri.o cs_schol_ci.o cs_sqr_ri.o cs_sqr_ci.o cs_symperm_ri.o cs_symperm_ci.o cs_tdfs_ri.o cs_tdfs_ci.o cs_transpose_ri.o cs_transpose_ci.o cs_compress_ri.o cs_compress_ci.o cs_updown_ri.o cs_updown_ci.o cs_usolve_ri.o cs_usolve_ci.o cs_utsolve_ri.o cs_utsolve_ci.o cs_util_ri.o cs_util_ci.o cs_reach_ri.o cs_reach_ci.o cs_spsolve_ri.o cs_spsolve_ci.o cs_ereach_ri.o cs_ereach_ci.o cs_leaf_ri.o cs_leaf_ci.o cs_randperm_ri.o cs_randperm_ci.o cs_operator_ri.o cs_operator_ci.o solve_from_lu.o solve_from_qr.o makeCXSparseMatrix.o unpackCXStruct.o shuffleF_data.o rt_nonfinite.o rtGetNaN.o rtGetInf.o shuffleF_initialize.o shuffleF_terminate.o shuffleF.o combineVectorElements.o permute.o bsxfun.o repmat.o ind2sub.o mtimes.o sparse.o sum.o squeeze.o mldivide.o xnrm2.o sparse1.o CXSparseAPI.o mtimes1.o power.o chol.o insertionsort.o introsort.o heapsort.o fillIn.o xgeqp3.o shuffleF_emxutil.o shuffleF_emxAPI.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -lm

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


prebuild : 


download : $(PRODUCT)


execute : download


###########################################################################
## FINAL TARGET
###########################################################################

#---------------------------------
# Create a static library         
#---------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating static library "$(PRODUCT)" ..."
	$(AR) $(ARFLAGS)  $(PRODUCT) $(OBJS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : /Users/Dennis/Documents/MATLAB/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : /Users/Dennis/Documents/MATLAB/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/CXSparse/Source/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/CXSparse/Source/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/CXSparse/CXSparseSupport/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/CXSparse/CXSparseSupport/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


cs_add_ri.o : $(START_DIR)/CXSparse/Source/cs_add_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_add_ci.o : $(START_DIR)/CXSparse/Source/cs_add_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_amd_ri.o : $(START_DIR)/CXSparse/Source/cs_amd_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_amd_ci.o : $(START_DIR)/CXSparse/Source/cs_amd_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_chol_ri.o : $(START_DIR)/CXSparse/Source/cs_chol_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_chol_ci.o : $(START_DIR)/CXSparse/Source/cs_chol_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_cholsol_ri.o : $(START_DIR)/CXSparse/Source/cs_cholsol_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_cholsol_ci.o : $(START_DIR)/CXSparse/Source/cs_cholsol_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_counts_ri.o : $(START_DIR)/CXSparse/Source/cs_counts_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_counts_ci.o : $(START_DIR)/CXSparse/Source/cs_counts_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_cumsum_ri.o : $(START_DIR)/CXSparse/Source/cs_cumsum_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_cumsum_ci.o : $(START_DIR)/CXSparse/Source/cs_cumsum_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_dfs_ri.o : $(START_DIR)/CXSparse/Source/cs_dfs_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_dfs_ci.o : $(START_DIR)/CXSparse/Source/cs_dfs_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_dmperm_ri.o : $(START_DIR)/CXSparse/Source/cs_dmperm_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_dmperm_ci.o : $(START_DIR)/CXSparse/Source/cs_dmperm_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_droptol_ri.o : $(START_DIR)/CXSparse/Source/cs_droptol_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_droptol_ci.o : $(START_DIR)/CXSparse/Source/cs_droptol_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_dropzeros_ri.o : $(START_DIR)/CXSparse/Source/cs_dropzeros_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_dropzeros_ci.o : $(START_DIR)/CXSparse/Source/cs_dropzeros_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_dupl_ri.o : $(START_DIR)/CXSparse/Source/cs_dupl_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_dupl_ci.o : $(START_DIR)/CXSparse/Source/cs_dupl_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_entry_ri.o : $(START_DIR)/CXSparse/Source/cs_entry_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_entry_ci.o : $(START_DIR)/CXSparse/Source/cs_entry_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_etree_ri.o : $(START_DIR)/CXSparse/Source/cs_etree_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_etree_ci.o : $(START_DIR)/CXSparse/Source/cs_etree_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_fkeep_ri.o : $(START_DIR)/CXSparse/Source/cs_fkeep_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_fkeep_ci.o : $(START_DIR)/CXSparse/Source/cs_fkeep_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_gaxpy_ri.o : $(START_DIR)/CXSparse/Source/cs_gaxpy_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_gaxpy_ci.o : $(START_DIR)/CXSparse/Source/cs_gaxpy_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_happly_ri.o : $(START_DIR)/CXSparse/Source/cs_happly_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_happly_ci.o : $(START_DIR)/CXSparse/Source/cs_happly_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_house_ri.o : $(START_DIR)/CXSparse/Source/cs_house_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_house_ci.o : $(START_DIR)/CXSparse/Source/cs_house_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_ipvec_ri.o : $(START_DIR)/CXSparse/Source/cs_ipvec_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_ipvec_ci.o : $(START_DIR)/CXSparse/Source/cs_ipvec_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_load_ri.o : $(START_DIR)/CXSparse/Source/cs_load_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_load_ci.o : $(START_DIR)/CXSparse/Source/cs_load_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_lsolve_ri.o : $(START_DIR)/CXSparse/Source/cs_lsolve_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_lsolve_ci.o : $(START_DIR)/CXSparse/Source/cs_lsolve_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_ltsolve_ri.o : $(START_DIR)/CXSparse/Source/cs_ltsolve_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_ltsolve_ci.o : $(START_DIR)/CXSparse/Source/cs_ltsolve_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_lu_ri.o : $(START_DIR)/CXSparse/Source/cs_lu_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_lu_ci.o : $(START_DIR)/CXSparse/Source/cs_lu_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_lusol_ri.o : $(START_DIR)/CXSparse/Source/cs_lusol_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_lusol_ci.o : $(START_DIR)/CXSparse/Source/cs_lusol_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_malloc_ri.o : $(START_DIR)/CXSparse/Source/cs_malloc_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_malloc_ci.o : $(START_DIR)/CXSparse/Source/cs_malloc_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_maxtrans_ri.o : $(START_DIR)/CXSparse/Source/cs_maxtrans_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_maxtrans_ci.o : $(START_DIR)/CXSparse/Source/cs_maxtrans_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_multiply_ri.o : $(START_DIR)/CXSparse/Source/cs_multiply_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_multiply_ci.o : $(START_DIR)/CXSparse/Source/cs_multiply_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_norm_ri.o : $(START_DIR)/CXSparse/Source/cs_norm_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_norm_ci.o : $(START_DIR)/CXSparse/Source/cs_norm_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_permute_ri.o : $(START_DIR)/CXSparse/Source/cs_permute_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_permute_ci.o : $(START_DIR)/CXSparse/Source/cs_permute_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_pinv_ri.o : $(START_DIR)/CXSparse/Source/cs_pinv_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_pinv_ci.o : $(START_DIR)/CXSparse/Source/cs_pinv_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_post_ri.o : $(START_DIR)/CXSparse/Source/cs_post_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_post_ci.o : $(START_DIR)/CXSparse/Source/cs_post_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_print_ri.o : $(START_DIR)/CXSparse/Source/cs_print_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_print_ci.o : $(START_DIR)/CXSparse/Source/cs_print_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_pvec_ri.o : $(START_DIR)/CXSparse/Source/cs_pvec_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_pvec_ci.o : $(START_DIR)/CXSparse/Source/cs_pvec_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_qr_ri.o : $(START_DIR)/CXSparse/Source/cs_qr_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_qr_ci.o : $(START_DIR)/CXSparse/Source/cs_qr_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_qrsol_ri.o : $(START_DIR)/CXSparse/Source/cs_qrsol_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_qrsol_ci.o : $(START_DIR)/CXSparse/Source/cs_qrsol_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_scatter_ri.o : $(START_DIR)/CXSparse/Source/cs_scatter_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_scatter_ci.o : $(START_DIR)/CXSparse/Source/cs_scatter_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_scc_ri.o : $(START_DIR)/CXSparse/Source/cs_scc_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_scc_ci.o : $(START_DIR)/CXSparse/Source/cs_scc_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_schol_ri.o : $(START_DIR)/CXSparse/Source/cs_schol_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_schol_ci.o : $(START_DIR)/CXSparse/Source/cs_schol_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_sqr_ri.o : $(START_DIR)/CXSparse/Source/cs_sqr_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_sqr_ci.o : $(START_DIR)/CXSparse/Source/cs_sqr_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_symperm_ri.o : $(START_DIR)/CXSparse/Source/cs_symperm_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_symperm_ci.o : $(START_DIR)/CXSparse/Source/cs_symperm_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_tdfs_ri.o : $(START_DIR)/CXSparse/Source/cs_tdfs_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_tdfs_ci.o : $(START_DIR)/CXSparse/Source/cs_tdfs_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_transpose_ri.o : $(START_DIR)/CXSparse/Source/cs_transpose_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_transpose_ci.o : $(START_DIR)/CXSparse/Source/cs_transpose_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_compress_ri.o : $(START_DIR)/CXSparse/Source/cs_compress_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_compress_ci.o : $(START_DIR)/CXSparse/Source/cs_compress_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_updown_ri.o : $(START_DIR)/CXSparse/Source/cs_updown_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_updown_ci.o : $(START_DIR)/CXSparse/Source/cs_updown_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_usolve_ri.o : $(START_DIR)/CXSparse/Source/cs_usolve_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_usolve_ci.o : $(START_DIR)/CXSparse/Source/cs_usolve_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_utsolve_ri.o : $(START_DIR)/CXSparse/Source/cs_utsolve_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_utsolve_ci.o : $(START_DIR)/CXSparse/Source/cs_utsolve_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_util_ri.o : $(START_DIR)/CXSparse/Source/cs_util_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_util_ci.o : $(START_DIR)/CXSparse/Source/cs_util_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_reach_ri.o : $(START_DIR)/CXSparse/Source/cs_reach_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_reach_ci.o : $(START_DIR)/CXSparse/Source/cs_reach_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_spsolve_ri.o : $(START_DIR)/CXSparse/Source/cs_spsolve_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_spsolve_ci.o : $(START_DIR)/CXSparse/Source/cs_spsolve_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_ereach_ri.o : $(START_DIR)/CXSparse/Source/cs_ereach_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_ereach_ci.o : $(START_DIR)/CXSparse/Source/cs_ereach_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_leaf_ri.o : $(START_DIR)/CXSparse/Source/cs_leaf_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_leaf_ci.o : $(START_DIR)/CXSparse/Source/cs_leaf_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_randperm_ri.o : $(START_DIR)/CXSparse/Source/cs_randperm_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_randperm_ci.o : $(START_DIR)/CXSparse/Source/cs_randperm_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_operator_ri.o : $(START_DIR)/CXSparse/Source/cs_operator_ri.c
	$(CC) $(CFLAGS) -o "$@" "$<"


cs_operator_ci.o : $(START_DIR)/CXSparse/Source/cs_operator_ci.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solve_from_lu.o : $(START_DIR)/CXSparse/CXSparseSupport/solve_from_lu.c
	$(CC) $(CFLAGS) -o "$@" "$<"


solve_from_qr.o : $(START_DIR)/CXSparse/CXSparseSupport/solve_from_qr.c
	$(CC) $(CFLAGS) -o "$@" "$<"


makeCXSparseMatrix.o : $(START_DIR)/CXSparse/CXSparseSupport/makeCXSparseMatrix.c
	$(CC) $(CFLAGS) -o "$@" "$<"


unpackCXStruct.o : $(START_DIR)/CXSparse/CXSparseSupport/unpackCXStruct.c
	$(CC) $(CFLAGS) -o "$@" "$<"


shuffleF_data.o : $(START_DIR)/shuffleF_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


shuffleF_initialize.o : $(START_DIR)/shuffleF_initialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"


shuffleF_terminate.o : $(START_DIR)/shuffleF_terminate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


shuffleF.o : $(START_DIR)/shuffleF.c
	$(CC) $(CFLAGS) -o "$@" "$<"


combineVectorElements.o : $(START_DIR)/combineVectorElements.c
	$(CC) $(CFLAGS) -o "$@" "$<"


permute.o : $(START_DIR)/permute.c
	$(CC) $(CFLAGS) -o "$@" "$<"


bsxfun.o : $(START_DIR)/bsxfun.c
	$(CC) $(CFLAGS) -o "$@" "$<"


repmat.o : $(START_DIR)/repmat.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ind2sub.o : $(START_DIR)/ind2sub.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mtimes.o : $(START_DIR)/mtimes.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sparse.o : $(START_DIR)/sparse.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sum.o : $(START_DIR)/sum.c
	$(CC) $(CFLAGS) -o "$@" "$<"


squeeze.o : $(START_DIR)/squeeze.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mldivide.o : $(START_DIR)/mldivide.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2.o : $(START_DIR)/xnrm2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


sparse1.o : $(START_DIR)/sparse1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


CXSparseAPI.o : $(START_DIR)/CXSparseAPI.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mtimes1.o : $(START_DIR)/mtimes1.c
	$(CC) $(CFLAGS) -o "$@" "$<"


power.o : $(START_DIR)/power.c
	$(CC) $(CFLAGS) -o "$@" "$<"


chol.o : $(START_DIR)/chol.c
	$(CC) $(CFLAGS) -o "$@" "$<"


insertionsort.o : $(START_DIR)/insertionsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


introsort.o : $(START_DIR)/introsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


heapsort.o : $(START_DIR)/heapsort.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fillIn.o : $(START_DIR)/fillIn.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgeqp3.o : $(START_DIR)/xgeqp3.c
	$(CC) $(CFLAGS) -o "$@" "$<"


shuffleF_emxutil.o : $(START_DIR)/shuffleF_emxutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


shuffleF_emxAPI.o : $(START_DIR)/shuffleF_emxAPI.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


