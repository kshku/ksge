TARGET := libksge.so
SRCDIR := src
SRCS := $(shell find $(SRCDIR) -type f -name "*.c")
CFLAGS := -fPIC -Wall -Wextra
INCLUDES :=
LDFLAGS := -shared
DEFINES := -DS_EXPORTS

BUILD_DIR := $(BUILD_DIR)/engine
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
CFLAGS += -MMD -MP $(INCLUDES) $(DEFINES)
TARGET := $(BUILD_DIR)/$(TARGET)

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking $@..."
	@$(CC) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: %.c
	@echo "Creating directory $(dir $@)..."
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all

-include $(DEPS)
