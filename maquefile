CC = g++
CFLAGS = -Wall -std=c++11

MAIN_FILE = main
FUN_FILE = fun
HEADERS_FILE = header
BUILD_DIR = build
SRC_DIR = src

AUTHOR = "Jorge Mora (jorgeadan.mora@ucr.ac.cr) B95222"
VERSION = "0.1"
DATE = "2023-05-15"
COPYRIGHT = "Copyright (c) 2023"
PROJECT_NAME = "tarea3 - IE0217"
PROJECT_NUMBER = 1.0

DOXYFILE = Doxygen_Jams

all: build run clean

$(SRC_DIR):
	mkdir -p $(SRC_DIR)

$(SRC_DIR)/$(MAIN_FILE).cpp: $(SRC_DIR)
	if [ ! -f $(SRC_DIR)/$(MAIN_FILE).cpp ]; then \
	echo '#include "$(HEADERS_FILE).hpp"' > $(SRC_DIR)/$(MAIN_FILE).cpp; \
	echo '' >> $(SRC_DIR)/$(MAIN_FILE).cpp; \
	echo 'int main() {' >> $(SRC_DIR)/$(MAIN_FILE).cpp; \
	echo '  func_inicial();' >> $(SRC_DIR)/$(MAIN_FILE).cpp; \
	echo '  return 0;' >> $(SRC_DIR)/$(MAIN_FILE).cpp; \
	echo '}' >> $(SRC_DIR)/$(MAIN_FILE).cpp; \
	fi

$(SRC_DIR)/$(FUN_FILE).cpp: $(SRC_DIR)
	if [ ! -f $(SRC_DIR)/$(FUN_FILE).cpp ]; then \
	echo '#include "$(HEADERS_FILE).hpp"' > $(SRC_DIR)/$(FUN_FILE).cpp; \
	echo '' >> $(SRC_DIR)/$(FUN_FILE).cpp; \
	echo 'void func_inicial() {' >> $(SRC_DIR)/$(FUN_FILE).cpp; \
	echo '  // Esta función no hace nada' >> $(SRC_DIR)/$(FUN_FILE).cpp; \
	echo '};' >> $(SRC_DIR)/$(FUN_FILE).cpp; \
	fi

$(SRC_DIR)/$(HEADERS_FILE).hpp: $(SRC_DIR)
	if [ ! -f $(SRC_DIR)/$(HEADERS_FILE).hpp ]; then \
	echo '/**' > $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * @file $(HEADERS_FILE).hpp' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * @author $(AUTHOR)' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * @brief This code creates something cool' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * @version $(VERSION)' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * @date $(DATE)' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * ' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * @code {.cpp}' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '  int main() {' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '    //Implementation' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '  return 0;' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '  }' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * @endcode' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * ' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * @copyright$(COPYRIGHT)' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' * ' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo ' */' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '#ifndef HEADER_HPP' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '#define HEADER_HPP' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '#include <iostream>' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo 'void func_inicial();' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	echo '#endif //HEADER_HPP' >> $(SRC_DIR)/$(HEADERS_FILE).hpp; \
	fi

build: 
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) ./$(SRC_DIR)/$(MAIN_FILE).cpp ./$(SRC_DIR)/$(FUN_FILE).cpp -o ./$(BUILD_DIR)/output.out

run: 
	./$(BUILD_DIR)/output.out

clean:
	rm -rf $(BUILD_DIR)

$(DOXYFILE):
	echo 'PROJECT_NAME           = $(PROJECT_NAME)' > $(DOXYFILE)
	echo 'PROJECT_NUMBER           = $(PROJECT_NUMBER)' >> $(DOXYFILE)
	echo 'PROJECT_BRIEF          = "Author: $(AUTHOR)"' >> $(DOXYFILE)
	echo 'OUTPUT_DIRECTORY       = ./' >> $(DOXYFILE)
	echo 'CREATE_SUBDIRS         = NO' >> $(DOXYFILE)
	echo 'OPTIMIZE_OUTPUT_FOR_C  = NO' >> $(DOXYFILE)
	echo 'INPUT                  = $(SRC_DIR)/$(HEADERS_FILE).hpp' >> $(DOXYFILE)
	echo 'FILE_PATTERNS          = *.hpp' >> $(DOXYFILE)
	echo 'GENERATE_HTML          = YES' >> $(DOXYFILE)
	echo 'GENERATE_LATEX         = NO' >> $(DOXYFILE)
	echo 'QUIET                  = YES' >> $(DOXYFILE)

documentation:
	doxygen $(DOXYFILE)

dfirefox:
	firefox ./html/index.html

dChrome:
	google-chrome ./html/index.html

.PHONY: all build run clean dfirefox dChrome $(SRC_DIR)

