#include <catch2/catch_test_macros.hpp>
#include "note.h"

TEST_CASE("get 32nd note duration")
{
    Note note(Note::NoteType::thirty_second, false, false);
    REQUIRE( note.duration() == 6 );
}

TEST_CASE("get dotted 32nd note duration")
{
    Note note(Note::NoteType::thirty_second, true, false);
    REQUIRE( note.duration() == 9 );
}

TEST_CASE("get whole note duration")
{
    Note note(Note::NoteType::whole, false, false);
    REQUIRE( note.duration() == 192 );
}

TEST_CASE("get dotted whole note duration")
{
    Note note(Note::NoteType::whole, true, false);
    REQUIRE( note.duration() == 288 );
}

TEST_CASE("get quarter note duration")
{
    Note note(Note::NoteType::quarter, false, false);
    REQUIRE( note.duration() == 48 );
}

TEST_CASE("get dotted quarter note duration")
{
    Note note(Note::NoteType::quarter, true, false);
    REQUIRE( note.duration() == 72 );
}
