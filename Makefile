#コンパイラとフラグの設定
CC = gcc
CFLAGS = -Wall -ILib

#ディレクトリ
APP_DIR = app
COM_DIR = com_args
HEAP_DIR = heap
INPUT_DIR = input_device
STM_DIR = stm

# ソースファイルとオブジェクトファイルの設定
APP_FILES = $(wildcard $(APP_DIR)/*.c)
COM_FILES = $(wildcard $(COM_DIR)/*.c)
HEAP_FILES = $(wildcard $(HEAP_DIR)/*.c)
INPUT_FILES = $(wildcard $(INPUT_DIR)/*.c)
STM_FILES = $(wildcard $(STM_DIR)/*.c)
OBJ_FILES = $(APP_FILES:.c=.o) $(COM_FILES:.c=.o) $(HEAP_FILES:.c=.o) $(INPUT_FILES:.c=.o) $(STM_FILES:.c=.o)

#実行ファイル名
TARGET = statepro

#ルール定義
all: $(TARGET)
$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

#オブジェクトファイルのルール
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#クリーンアップのルール
clean:
	rm -f $(APP_DIR)/*.o $(COM_DIR)/*.o $(HEAP_DIR)/*.o $(INPUT_DIR)/*.o $(STM_DIR)/*.o $(TARGET)

.PHONY = all clean

