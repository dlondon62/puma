###########################################################################
## Makefile generated for component 'shuffleF'. 
## 
## Makefile     : shuffleF_rtw.mk
## Generated on : Sun Dec 12 16:44:25 2021
## Final product: ./shuffleF.a
## Product type : static-library
## 
###########################################################################
SHUFFLE_MAKE_DIR          = /Users/Dima/Dennis/shuffleF
SHUFFLE_MAKE_FILENAME     = shuffleF_rtw_new.mk
include $(SHUFFLE_MAKE_DIR)/$(SHUFFLE_MAKE_FILENAME)
SAMPLE_SRCS               = $(START_DIR)/sample/sample.cpp
SAMPLE_BIN                = shuffleF_sample

$(SAMPLE_BIN): $(SAMPLE_SRCS) $(PRODUCT)
	$(CPP) "$<" $(START_DIR)/$(PRODUCT) $(INCLUDES) $(CPP_LDFLAGS) $(CPP_STANDARD_OPTS) $(SAMPLE_DEBUG) -o "$@"

all_binaries : $(SAMPLE_BIN)

clean_binaries : 
	$(ECHO) "### Deleting all binaries..."
	$(RM) $(SAMPLE_BIN)
	$(ECHO) "### Deleted all binaries"


