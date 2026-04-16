# make sure we use iverilog as Verilog compiler
CC := iverilog

BUILD := ./bin
TESTBENCH := ./testbench
COMPONENT := ./component
TARGETS := $(wildcard $(TESTBENCH)/*.v)
OUTPUTS = $(TARGETS:$(TESTBENCH)/%.v=$(BUILD)/%.vvp)

FLAGS := -I$(COMPONENT)

all: mkdirs $(OUTPUTS)

$(BUILD)/%.vvp: $(TESTBENCH)/%.v
	$(CC) $^ -o $@ $(FLAGS) $(DEBUG)

mkdirs: $(BUILD)

$(BUILD):
	mkdir -p $(BUILD)

clean:
	rm -r $(BUILD)
