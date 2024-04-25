CC = gcc
TARGET = demo
SOURCE = demo.c b64_codec.c
OBJECT = $(SOURCE:.c=.o)

$(TARGET): $(OBJECT) 
	$(CC) -o $(TARGET) $(OBJECT)

%.o: %.c
	$(CC) -c $< -o $@

.PHONY : clean

clean : 
		rm $(TARGET) $(OBJECT)