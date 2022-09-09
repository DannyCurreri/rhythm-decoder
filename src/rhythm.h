#ifndef RHYTHM_H
#define RHYTHM_H
#include "note.h"
#include <vector>
#include <utility>
#include <string>

/* Converts a time signature <top>/<bottom> to an Orff signature.
 The Orff signature is expressed as a std::pair, where the first
 member is beats per measure and the second is note value of the beat. */
std::pair<int, Note> orff_signature(int top, int bottom);


class RhythmicPiece {
public:
    // represents the number of subdivisions to be counted in each beat
    enum class CountSystem { one, two, three, four, six };

    // A vector of Note objects, defined in note.h
    using Bar = std::vector<Note>;

    // constructor takes an Orff time signature.
    // Perhaps should modify this constructor to take a standard time sig
    // as its argument, and move the orff_signature function's logic here.
    RhythmicPiece(std::pair<int, Note> sig);

    // if Bar is valid, pushes to back of bars, else throws
    void append(Bar);

    // first item in pair is false if the note is a rest
    // second item in pair the # of counts belonging to each note
    std::vector<std::pair<bool, int>> counts() const;

    // returns appropriate note value for decoding this piece
    int key() const;

    // true if this piece has a compound meter e.g. 6/8
    bool is_compound() const { return beat.dotted(); }

    // returns the CountSystem appropriate for this RhythmicPiece
    CountSystem count_system() const;

    // writes this RhythmicPiece's counts to a string
    std::string write() const;
private:
    Note beat;    // note value of primary beat in this piece's time sig
    int beats_per_measure;
    std::vector<Bar> bars;

    int simple_key() const;
    int compound_key() const;
};

#endif

