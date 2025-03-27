# make sure we use gcc as C compiler
CC := gcc

BUILD := ./bin

TARGET_DIR = src

TARGETS := $(wildcard $(TARGET_DIR)/*.c)
OUTPUTS := $(patsubst %.c, $(BUILD)/%.o, $(TARGETS))

FLAGS := -Wall -lm

all: mkdirs $(OUTPUTS)
	$(CC) $(OUTPUTS) main.c -o $(BUILD)/main

$(BUILD)/%.o: %.c
	$(CC) $^ -c -o $@ $(FLAGS) $(DEBUG)

mkdirs:
	mkdir -p $(BUILD)
	mkdir -p $(BUILD)/src

clean:
	rm -r $(BUILD)
