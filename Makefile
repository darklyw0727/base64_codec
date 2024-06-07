ifeq ("$(ROOT_PATH)","")
ROOT_PATH=$(shell pwd | sed 's/\/common.*//')
endif

include $(ROOT_PATH)/build/build-include.mk

OBJS = b64_codec.o

SHARE_LIB = libb64codec.so
STATIC_LIB = libb64codec.a

CFLAGS += -Os -Wall -Werror -fPIC

ifdef B64_DEBUG
CFLAGS += -D_B64_DEBUG
endif

ARFLAGS = -c -r

.PHONY: clean install

all: $(SHARE_LIB) $(STATIC_LIB)

$(PROJECT): $(PRJOBJS)
	@echo " LD     $@"
	@$(CC) $(PRJLDFLAGS) -o $@ $(PRJOBJS)
	@echo " STRIP  $@"
	@$(STRIP) $@

$(SHARE_LIB): $(OBJS)
	@echo " LD	$@ $^"
	@$(CC) -Werror -shared -Wl,--whole-archive,-soname,$@ -o $@ $^ -Wl,--no-whole-archive $(LD_FLAGS)

$(STATIC_LIB): $(OBJS)
	@echo " AR	$@ $^"
	@$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	@echo " CC	$@"
	@$(CC) $(CFLAGS) -g -c -o $@ $^

clean:
	$(RM) *.o $(SHARE_LIB) $(STATIC_LIB) $(PROJECT)

install: all
	cp -af $(SHARE_LIB) $(LIB_FOLDER)
