TARGET := testbed
SRCDIR := src
SRCS := $(shell find $(SRCDIR) -type f -name "*.c")
CFLAGS +=
INCLUDES := -I ../engine/src
LDFLAGS += -L $(BUILD_DIR)/engine -lksge -Wl,-rpath=$(BUILD_DIR)/engine
DEFINES +=

OBJS := $(SRCS:%.c=$(BUILD_DIR)/testbed/%.o)
DEPS := $(OBJS:.o=.d)
CFLAGS += -MMD -MP $(INCLUDES) $(DEFINES)
TARGET := $(BUILD_DIR)/testbed/$(TARGET)
DIRS := $(sort $(dir $(OBJS)))

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking $@..."
	@$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/testbed/%.o: %.c | $(DIRS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	@echo "Creating directory $@..."
	@mkdir -p $@

.PHONY: all

-include $(DEPS)
