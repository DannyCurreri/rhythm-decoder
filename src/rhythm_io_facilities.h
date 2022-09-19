#ifndef RHYTHM_IO_FACILITIES
#define RHYTHM_IO_FACILITIES

#include "rhythm.h"
#include "note.h"
#include <string>
#include <string_view>

std::pair<int, int> parse_time_sig(std::string);
Note parse_note(std::string_view);

#endif

