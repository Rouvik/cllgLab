# make sure we use iverilog as Verilog compiler
CC := iverilog

BUILD := ./bin
TESTBENCH := ./testbench
COMPONENT := ./component

DIRS_TO_TARGET = $(shell find $(TESTBENCH) -mindepth 1 -type d)
DIRS_TO_BUILD = $(DIRS_TO_TARGET:$(TESTBENCH)/%=$(BUILD)/%)

TARGETS := $(shell find $(TESTBENCH) -name '*.v')
OUTPUTS = $(TARGETS:$(TESTBENCH)/%.v=$(BUILD)/%.vvp)

FLAGS := -I$(COMPONENT)

all: mkdirs $(OUTPUTS)

$(BUILD)/%.vvp: $(TESTBENCH)/%.v
	$(CC) $^ -o $@ $(FLAGS) $(DEBUG)

mkdirs: $(BUILD) $(DIRS_TO_BUILD)

$(BUILD):
	mkdir -p $(BUILD)

$(DIRS_TO_BUILD):
	mkdir -p $(DIRS_TO_BUILD)

sbin:
	@if [ -d "$(dir)" ]; then ln -sfn $(dir) ./sbin && echo "Shortcut built!"; else printf "dir=\"$(dir)\" doesnt exist or is not a directory\nUsage: make sbin dir=<directory>\n"; fi

rsbin:
	rm -f ./sbin

clean:
	rm -r $(BUILD)
