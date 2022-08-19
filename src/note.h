
class Note {
public:
    enum class NoteType {
        whole, half, quarter, eigth, sixteenth, thirty_second };

    Note(NoteType n, bool d, bool r);
    int duration() const;
private:
    NoteType type;
    bool dotted;
    bool rest;
};

