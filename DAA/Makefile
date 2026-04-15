# make sure we use gcc as C compiler
CC := gcc

BUILD := ./bin

TARGETS := $(wildcard *.c)
OUTPUTS := $(patsubst %.c, $(BUILD)/%, $(TARGETS))

FLAGS := -Wall -O0

all: $(OUTPUTS)

$(BUILD)/%: %.c | mkdirs
	$(CC) $^ -o $@ $(FLAGS) $(DEBUG)

mkdirs: $(BUILD)

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -r $(BUILD)
