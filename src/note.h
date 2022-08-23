#ifndef NOTE_H
#define NOTE_H

class Note {
public:
    enum class NoteType {
        whole, half, quarter, eigth, sixteenth, thirty_second };

    Note(NoteType, bool);
    int duration() const;
    bool is_dotted() const { return dotted; }
private:
    NoteType type;
    bool dotted;
};

#endif

