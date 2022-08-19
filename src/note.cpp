#include "note.h"

namespace {
    constexpr int BASE_DURATION = 6;
}

Note::Note(NoteType n, bool d, bool r)
    :type(n), dotted(d), rest(r)
{}

int Note::duration() const
{
    int res = BASE_DURATION;
    switch (type) {
        case NoteType::whole:
            res *= 2;
        case NoteType::half:
            res *= 2;
        case NoteType::quarter:
            res *= 2;
        case NoteType::eigth:
            res *= 2;
        case NoteType::sixteenth:
            res *= 2;
        case NoteType::thirty_second:
            res *= 1;
    }

    if (dotted) {
        res *= 3;
        res /= 2;
    }

    return res;
}
