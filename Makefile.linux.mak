CC := clang
BUILD_DIR := build
SUBDIRS := engine testbed

export BUILD_DIR := $(CURDIR)/$(BUILD_DIR)
export CC

all: $(BUILD_DIR) $(SUBDIRS)

clean:
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR)

$(SUBDIRS): | $(BUILD_DIR)
	@$(MAKE) -C $@ -f Makefile.linux.mak
	@echo --------------------------------------------

$(BUILD_DIR):
	@echo "Creating directory $(BUILD_DIR)..."
	@mkdir -p $(BUILD_DIR)

.PHONY: all, clean, $(SUBDIRS)
