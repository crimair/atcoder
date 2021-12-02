# Last modified: 2021/11/26 15:55:11 (matsukura)

#################################################
# user config
#################################################
COMPILER := gcc
#COMPILER := 
#CROSS_COMPILE := arm-altera-eabi-
CROSS_COMPILE := 

TARGET        := testrun
TARGET_RUN    := ./testrun

SRC_DIRS      := .
INCLUDE_DIRS  :=
LINKER_SCRIPT :=
LDSLIBS       :=
LDLIBS        :=

USER_FLAGS    := -DLOCAL_DEBUG -O0 -std=c++17 -Wshadow -Wall -Wno-sign-compare -D_GLIBCXX_DEBUG

#################################################
# macro
#################################################
# recursive wildcard macro
rwildcard=$(foreach dir,$(1),$(wildcard $(dir)/$(2)))
# each macro
each=$(foreach dir,$(1),$(2)$(dir)$(3))

# CFLAGS := -O2 -mfloat-abi=softfp -march=armv7-a -mtune=cortex-a9 -mcpu=cortex-a9 -Wall -Wstrict-prototypes -std=c99 -fdata-sections -ffunction-sections -I$(HWLIBS_ROOT)/include
# ASFLAGS :=  -march=armv7-a -mcpu=cortex-a9
# LINKER_SCRIPT := altera-socfpga-unhosted.ld
CSRC   := $(call rwildcard,$(SRC_DIRS),*.c)
CXXSRC := $(call rwildcard,$(SRC_DIRS),*.cpp)
ASRC   := $(call rwildcard,$(SRC_DIRS),*.s)

OBJ := $(patsubst %.c, %.o, $(CSRC))
OBJ += $(patsubst %.cpp, %.o, $(CXXSRC))
OBJ += $(patsubst %.s, %.o, $(ASRC))

CFLAGS := -O2 -Wall \
	$(call each,$(INCLUDE_DIRS),-I) \
	$(USER_FLAGS) \
	
CXXFLAGS := -O2 -Wall \
	$(call each,$(INCLUDE_DIRS),-I) \
	$(USER_FLAGS) \
	
LDFLAGS := \
	$(call each,$(LDSLIBS)) \
	$(call each,$(LINKER_SCRIPT),-T) \
	$(call each,$(LDLIBS),-l) \
	
ASFLAGS := \

ifeq ($(COMPILER),gcc)
	CC  := $(CROSS_COMPILE)gcc
	CXX := $(CROSS_COMPILE)gcc
	LD  := $(CROSS_COMPILE)g++
	NM  := $(CROSS_COMPILE)nm
	OD  := $(CROSS_COMPILE)objdump
	OC  := $(CROSS_COMPILE)objcopy
	AS  := $(CROSS_COMPILE)as
else
	CC  := clang
	CXX := clang++
	LD  := clang++
	NM  := llvm-nm
	OD  := llvm-objdump
	OC  := llvm-objcopy
	AS  := llvm-as
endif


.PHONY: all
all: $(TARGET)
	$(TARGET_RUN)

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp Makefile
	$(CXX) $(CFLAGS) -c $< -o $@

%.o: %.s Makefile
	$(AS) $(ASFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(LD) $(OBJ) $(LDFLAGS) -o $@
	$(OD) -d $@ > $@.objdump
	$(NM) $@ > $@.map
#	$(OC) -O binary $(TARGET) $(BIN)
#	$(MKI) -A arm -O u-boot -T standalone -C none -a 0x20100000 -e 0 -d $(BIN)  $(BIN).img

.PHONY: clean
clean:
	rm -f $(OBJ) $(TARGET) *.objdump *.map
