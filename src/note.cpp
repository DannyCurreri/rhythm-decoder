#include "note.h"

/* To be used for smallest note type (currently 32nd note).
   All other note durations will be relative to this value.
   The value is selected so that all defined note vales, including
   dotted notes and any desired tuplets, can be expressed as integers. */
constexpr int BASE_DURATION = 6;

Note::Note(NoteType n) :type_{n}
{
}

Note::Note(NoteType n, bool d) :type_{n}, dotted_{d}
{
}

Note::Note(NoteType n, bool d, bool r)
    :type_{n}, dotted_{d}, rest_{r}
{
}

int Note::duration() const
{
    int res = BASE_DURATION;
    switch (type_) {
        case NoteType::whole:      res *= 32;  break;
        case NoteType::half:       res *= 16;  break;
        case NoteType::quarter:    res *=  8;  break;
        case NoteType::eighth:     res *=  4;  break;
        case NoteType::sixteenth:  res *=  2;  break;
    }
    if (dotted_) {
        res /= 2;
        res *= 3;
    }
    return res;
}
