#
# This is an example GNUmakefile for my packages
#

# specific names for this package
DICT  = LArLiteApp_Goldenpi0anaDict
SHLIB = libLArLiteApp_Goldenpi0ana.so
SOURCES = $(filter-out $(DICT).cxx, $(wildcard *.cxx))
FMWK_HEADERS = LinkDef.h $(DICT).h
HEADERS = $(filter-out $(FMWK_HEADERS), $(wildcard *.h))
OBJECTS = $(SOURCES:.cxx=.o)

# include options for this package
INCFLAGS  = -I.                       #Include itself
INCFLAGS += $(shell larlite-config --includes)
INCFLAGS += $(shell seltool-config --includes)
INCFLAGS += $(shell larliteapp-config --includes)
INCFLAGS += $(shell basictool-config --includes)


# platform-specific options
OSNAME          = $(shell uname -s)
HOST            = $(shell uname -n)
OSNAMEMODE      = $(OSNAME)

# call kernel specific compiler setup
include $(LARLITE_BASEDIR)/Makefile/Makefile.${OSNAME}

LDFLAGS += $(shell larlite-config --libs)
LDFLAGS += $(shell seltool-config --libs)
LDFLAGS += -L$(LARLITE_LIBDIR) -lLArLiteApp_ERToolBackend


# call the common GNUmakefile
include $(LARLITE_BASEDIR)/Makefile/GNUmakefile.CORE
