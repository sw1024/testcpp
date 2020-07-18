SW_THIRDPART=$(THIRDPART)

CXX=c++8.3
LIB_PATH := \
    -L$(SW_THIRDPART)/gcc-8.3.0/lib/gcc/x86_64-redhat-linux/8.3.0/ \
    -L$(SW_THIRDPART)/gcc-8.3.0/lib64 \
    -L$(SW_THIRDPART)/lua/lib -llua\
	
    #-L$(SW_THIRDPART)/log4cxx/lib/ -llog4cxx \

#	-L/usr/local/apr/lib -lapr-1 \
#	-L/usr/local/apr-util/lib -laprutil-1 \

INC_PATH := \
    -I$(SW_THIRDPART)/gcc-8.3.0/include/c++/8.3.0/ \
    -I$(SW_THIRDPART)/lua/include/ \

   # -I$(SW_THIRDPART)/log4cxx/include/ \
#	-I/usr/local/apr/include \

#	-I/usr/local/apr-util/include \
#	-I/usr/include\

SW_COMPILE_OPT= -std=gnu++17 -g -g3 -Wall -Werror $(INC_PATH)
SW_DEBUG_LINK_OPT= $(LIB_PATH) -lpthread

TARGET_PATH = ./bin
OBJO_PATH = .obj
OBJECTS := $(wildcard $(arg)*.cpp)
OBJO := $(patsubst %.cpp,$(OBJO_PATH)/%.o,$(OBJECTS))
ALLTARGET:=$(patsubst %.cpp,$(TARGET_PATH)/%,$(OBJECTS))
OBJD := $(OBJO:$(OBJO_PATH)/%.o=$(OBJO_PATH)/%.d)

all:$(ALLTARGET)

-include $(OBJD)
$(OBJD): $(OBJO_PATH)/%.d:./%.cpp
	@$(CXX) -M $(SW_COMPILE_OPT) $< > $@.$$$$; sed 's,\($*\)\.o[ :]*,$(OBJO_PATH)/\1.o $@ : ,g' < $@.$$$$ > $@; rm -f $@.$$$$

$(ALLTARGET): $(TARGET_PATH)/%:$(OBJO_PATH)/%.o
	@if [ ! -d "$(TARGET_PATH)" ]; then mkdir -pv $(TARGET_PATH); fi
	$(CXX) $(SW_COMPILE_OPT) $(SW_DEBUG_LINK_OPT) $< -o $@


$(OBJO): $(OBJO_PATH)/%.o:./%.cpp
	@if [ ! -d "$(OBJO_PATH)" ]; then mkdir -pv $(OBJO_PATH); fi
	$(CXX) -c $(SW_COMPILE_OPT) $< -o $@

clean:
	@-rm -rf .obj/
	@-rm -rf .obj/.*.d


.PHONY: test clean
