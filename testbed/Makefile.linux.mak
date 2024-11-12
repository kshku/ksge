TARGET := testbed
SRCDIR := src
SRCS := $(shell find $(SRCDIR) -type f -name "*.c")
CFLAGS := -Wall -Wextra -g
INCLUDES := -I ../engine/src
LDFLAGS := -L $(BUILD_DIR)/engine -lksge -Wl,-rpath=../engine -g
DEFINES :=

BUILD_DIR := $(BUILD_DIR)/testbed
OBJS := $(SRCS:%.c=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
CFLAGS += -MMD -MP $(INCLUDES) $(DEFINES)
TARGET := $(BUILD_DIR)/$(TARGET)
DIRS := $(sort $(dir $(OBJS)))

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking $@..."
	@$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: %.c | $(DIRS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	@echo "Creating directory $@..."
	@mkdir -p $@

.PHONY: all

-include $(DEPS)
