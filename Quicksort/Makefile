# make sure we use gcc as C compiler
CC := gcc

BUILD := ./bin

TARGETS := $(wildcard *.c)
OUTPUTS := $(patsubst %.c, $(BUILD)/%, $(TARGETS))

FLAGS := -Wall -lm -ggdb

all: mkdirs $(OUTPUTS)

$(BUILD)/%: %.c
	$(CC) $^ -o $@ $(FLAGS) $(DEBUG)

mkdirs:
	mkdir -p $(BUILD)

clean:
	rm -r $(BUILD)
