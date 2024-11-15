SHELL := powershell.exe
.SHELLFLAGS := -NoProfile -NoInteractive -Command

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

all: $(DIRS) $(TARGET)

clean:
	@Write-Output "Cleaning testbed..."
	@if (Test-Path $(BUILD_DIR)/testbed) { Remove-Item -Recurse -Force $(BUILD_DIR)/testbed }

$(TARGET): $(OBJS)
	@Write-Output "Linking $@..."
	@$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/testbed/%.o: %.c
	@Write-Output "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIRS):
	@Write-Output "Creating directory $@..."
	@if (!(Test-Path $@)) { New-Item -ItemType Directory -Path $@ | Out-Null }

.PHONY: all clean

-include $(DEPS)
