# make sure we use gcc as C compiler
CC := gcc

BUILD := ./bin

INCLUDE_DIR := ./include

TARGETS := $(wildcard *.c)
OUTPUTS := $(patsubst %.c, $(BUILD)/%, $(TARGETS))

DEBUG = -ggdb
FLAGS := -Wall -Wextra -Wpedantic -I$(INCLUDE_DIR)

all: mkdirs $(OUTPUTS)

$(BUILD)/%: %.c
	$(CC) $^ -o $@ $(FLAGS) $(DEBUG)

mkdirs:
	mkdir -p $(BUILD)

clean:
	rm -r $(BUILD)
