CC = gcc
TARGET = build/switch-inspector
SOURCE = src/main.c

CFLAGS = -std=c11 -Wall -Wextra -O2
USB_FLAGS = $(shell pkg-config --cflags --libs libusb-1.0)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SOURCE)
	mkdir -p build
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET) $(USB_FLAGS)

clean:
	rm -rf build
