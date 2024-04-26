CC = gcc
TARGET = demo
SOURCE = demo.c b64_codec.c
OBJECT = $(SOURCE:.c=.o)

ifdef B64_DEBUG
CFLAGS += -D_B64_DEBUG
endif

$(TARGET): $(OBJECT) 
	$(CC) -o $(TARGET) $(OBJECT)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY : clean

clean : 
		rm $(TARGET) $(OBJECT)