TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        yanujz_core/cli/tokenizer/cli_tokenizer.cpp \
        yanujz_core/stl/string/string.cpp \
        yanujz_core/utils/crc/crc16/crc16.cpp \
        yanujz_core/utils/crc/crc32/crc32.cpp \
        yanujz_core/utils/crc/crc8/crc8.cpp \
        yanujz_core/utils/crc/crc_utils.cpp \
        yanujz_core/utils/math/math_utils.cpp \
        yanujz_core/utils/pad/pad_utils.cpp \
        yanujz_core/utils/str/str_utils.cpp \
        yanujz_core/utils/swap/swap_utils.cpp \
        yanujz_core/utils/ungrouped/ungrouped.cpp

HEADERS += \
    yanujz_core/cli/commands/cli_commands.hpp \
    yanujz_core/cli/tokenizer/cli_tokenizer.h \
    yanujz_core/defines/ascii/ascii.h \
    yanujz_core/defines/bit_manipulation.h \
    yanujz_core/defines/cast.h \
    yanujz_core/defines/defines.h \
    yanujz_core/defines/prepoc_math.h \
    yanujz_core/fifo/fifo.hpp \
    yanujz_core/hashmap/hashmap.hpp \
    yanujz_core/list/list.hpp \
    yanujz_core/stl/err/err.h \
    yanujz_core/stl/fifo/fifo.hpp \
    yanujz_core/stl/hashmap/hashmap.hpp \
    yanujz_core/stl/list/dl_list/dl_list.hpp \
    yanujz_core/stl/list/list.h \
    yanujz_core/stl/list/list.hpp \
    yanujz_core/stl/list/sl_list/sl_list.hpp \
    yanujz_core/stl/stack/stack.hpp \
    yanujz_core/stl/string/string.h \
    yanujz_core/stl/vector/vector.hpp \
    yanujz_core/string/string.h \
    yanujz_core/typedef.h \
    yanujz_core/utils/crc/crc16/crc16.h \
    yanujz_core/utils/crc/crc32/crc32.h \
    yanujz_core/utils/crc/crc8/crc8.h \
    yanujz_core/utils/crc/crc_utils.h \
    yanujz_core/utils/crypto/crypto_utils.h \
    yanujz_core/utils/math/math_utils.h \
    yanujz_core/utils/pad/pad_utils.h \
    yanujz_core/utils/str/str_utils.h \
    yanujz_core/utils/swap/swap_utils.h \
    yanujz_core/utils/ungrouped/ungrouped.h \
    yanujz_core/utils/utils.h \
    yanujz_core/vector/vector.hpp \
    yanujz_core/yanujz_core.h \
    yanujz_core/ytype.h
