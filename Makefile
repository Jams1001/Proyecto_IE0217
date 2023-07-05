PROJECT_DIR = qt/IE0217
BUILD_DIR = build
CMAKE = cmake
MAKE = make
APP = IE0217
CXXFLAGS = -Wall


MAIN_FILE = main
FUN_FILE = fun
HEADERS_FILE = header
BUILD_DIR = build
SRC_DIR = qt/IE0217


AUTHOR = "Jorge Mora (jorgeadan.mora@ucr.ac.cr) B95222"
VERSION = "0.1"
DATE = "2023-07-05"
COPYRIGHT = "Copyright (c) 2023"
PROJECT_NAME = "Proyecto Final - IE0217"
PROJECT_NUMBER = 1.0

DOXYFILE = Doxygen_Project

all: build run clean documentation dfirefox

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


$(DOXYFILE): $(SRC_DIR)
	echo 'PROJECT_NAME           = $(PROJECT_NAME)' > $(DOXYFILE)
	echo 'PROJECT_NUMBER         = $(PROJECT_NUMBER)' >> $(DOXYFILE)
	echo 'PROJECT_BRIEF          = "Author: $(AUTHOR)"' >> $(DOXYFILE)
	echo 'OUTPUT_DIRECTORY       = ./' >> $(DOXYFILE)
	echo 'CREATE_SUBDIRS         = NO' >> $(DOXYFILE)
	echo 'OPTIMIZE_OUTPUT_FOR_C  = NO' >> $(DOXYFILE)
	echo 'GENERATE_HTML          = YES' >> $(DOXYFILE)
	echo 'GENERATE_LATEX         = NO' >> $(DOXYFILE)
	echo 'QUIET                  = YES' >> $(DOXYFILE)
	find $(SRC_DIR) -name '*.h' -exec echo 'INPUT += {}' >> $(DOXYFILE) \;

documentation: $(DOXYFILE)
	doxygen $(DOXYFILE)

dfirefox:
	firefox ./html/index.html
