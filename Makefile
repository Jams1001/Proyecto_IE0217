PROJECT_DIR = qt/IE0217
BUILD_DIR = build
CMAKE = cmake
MAKE = make
APP = IE0217
CXXFLAGS = -Wall

all: build run clean

build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && \
	$(CMAKE) ../$(PROJECT_DIR) && \
	$(MAKE)

run:
	./$(BUILD_DIR)/$(APP)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all build run clean
