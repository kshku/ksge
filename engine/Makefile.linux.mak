TARGET := libksge.so
SRCDIR := src
SRCS := $(shell find $(SRCDIR) -type f -name "*.c")
CFLAGS += -fvisibility=hidden -fPIC
INCLUDES := -I $(SRCDIR)
LDFLAGS += -shared
DEFINES += -DS_EXPORTS

OBJS := $(SRCS:%.c=$(BUILD_DIR)/engine/%.o)
DEPS := $(OBJS:.o=.d)
CFLAGS += -MMD -MP $(INCLUDES) $(DEFINES)
TARGET := $(BUILD_DIR)/engine/$(TARGET)
DIRS := $(sort $(dir $(OBJS)))

all: $(TARGET)

clean:
	@echo "Cleaning engine..."
	@rm -rf $(BUILD_DIR)/engine

$(TARGET): $(OBJS)
	@echo "Linking $@..."
	@$(CC) $(LDFLAGS) $^ -o $@

$(BUILD_DIR)/engine/%.o: %.c | $(DIRS)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	@echo "Creating directory $@..."
	@mkdir -p $@

.PHONY: all clean

-include $(DEPS)
