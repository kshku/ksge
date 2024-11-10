rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

TARGET := ksge.dll
SRCDIR := src
SRCS := $(call rwildcard,$(SRCDIR)/,*.c)
CFLAGS := -fdeclspec -Wall -Wextra -g
INCLUDES :=
LDFLAGS := -shared -g
DEFINES := -DS_EXPORTS

BUILD_DIR := $(BUILD_DIR)/engine
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
CFLAGS += -MMD -MP $(INCLUDES) $(DEFINES)
TARGET := $(BUILD_DIR)/$(TARGET)
DIRS := $(sort $(dir $(OBJS)))

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking $@..."
	@$(CC) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.c | $(DIRS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	@echo "Creating directory $@..."
	@mkdir $(subst /,\,$@)

.PHONY: all

-include $(DEPS)
