CC := clang
CFLAGS := -Wall -Wextra -g
DEFINES := -DS_DEBUG
LDFLAGS := -g
BUILD_DIR := build

SUBDIRS := engine testbed

export BUILD_DIR := $(CURDIR)/$(BUILD_DIR)
export CC
export CFLAGS
export LDFLAGS
export DEFINES

all: $(BUILD_DIR) $(SUBDIRS)

clean:
	@echo "Cleaning..."
	@rmdir /s /q $(subst /,\,$(BUILD_DIR))

$(SUBDIRS): | $(BUILD_DIR)
	@$(MAKE) -C $@ -f Makefile.windows.mak
	@echo --------------------------------------------

$(BUILD_DIR):
	@echo "Creating directory $(BUILD_DIR)..."
	@mkdir $(subst /,\,$(BUILD_DIR))

.PHONY: all, clean, $(SUBDIRS)
