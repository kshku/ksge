rwildcard = $(wildcard $1$2) $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2))

TARGET := testbed.exe
SRCDIR := src
SRCS := $(call rwildcard,$(SRCDIR)/,*.c)
CFLAGS += -fdeclspec
INCLUDES := -I ../engine/src
LDFLAGS += -L $(BUILD_DIR)/engine -lksge
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
	@mkdir $(subst /,\,$@)

.PHONY: all

-include $(DEPS)
