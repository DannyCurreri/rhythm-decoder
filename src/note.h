#ifndef NOTE_H
#define NOTE_H

class Note {
public:
    enum class NoteType {
        whole, half, quarter, eighth, sixteenth, thirty_second };

    // constructor is only given a NoteType, which is always required
    // dotted and rest and both assigned false
    Note(NoteType);

    // constructor is given one Boolean argument in addition to NoteType
    // dotted is assigned argument value, rest is assigned false
    Note(NoteType, bool);

    // constructor with arguments for all member data items
    Note(NoteType, bool, bool);

    // returns this note's duration
    // this is implemented by using some constant value to represent
    // the smallest possible note duration, and all other note's durations
    // are expressed as an integer multiple of this constant in a way
    // that preserves the correct musical relationships between these notes.
    int duration() const;

    bool dotted()   const  { return dotted_; }
    bool rest()     const  { return rest_; }
    NoteType type() const  { return type_; }
private:
    NoteType type_;
    bool dotted_ {false};
    bool rest_ {false};
};

#endif

