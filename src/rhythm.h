#ifndef RHYTHM_H
#define RHYTHM_H
#include "note.h"
#include <vector>
#include <utility>

/* Converts a time signature <top>/<bottom> to an Orff signature.
 The Orff signature is expressed as a std::pair, where the first
 member is beats per measure and the second is note value of the beat. */
std::pair<int, Note> orff_signature(int top, int bottom);

class RhythmicPiece {
public:
    using Bar = std::vector<Note>;
    RhythmicPiece(std::pair<int, Note> sig);
    /* checks if Bar is valid for this object's time signature and
     if not, throws exception; if valid, appends Bar to notes vector */
    void append(Bar);
    int key() const;      // returns note value to use for decoding rhythm
    bool is_compound() const { return beat.is_dotted(); }
private:
    Note beat;            // note value of primary beat in time sig
    int beats_per_measure;
    std::vector<Bar> bars;

    int simple_key() const;
    int compound_key() const;
};

#endif

