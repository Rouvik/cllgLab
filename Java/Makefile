CC := javac

BUILD := ./bin

TARGETS := $(wildcard *.java)
OUTPUTS = $(patsubst %.java, $(BUILD)/%.class, $(TARGETS))

FLAGS := -d $(BUILD)

all: mkdirs $(OUTPUTS)

$(BUILD)/%.class: %.java
	$(CC) $^ $(FLAGS)

mkdirs:
	mkdir -p $(BUILD)

clean:
	rm -r $(BUILD)
