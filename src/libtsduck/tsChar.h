//----------------------------------------------------------------------------
//
// TSDuck - The MPEG Transport Stream Toolkit
// Copyright (c) 2005-2017, Thierry Lelegard
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
// THE POSSIBILITY OF SUCH DAMAGE.
//
//----------------------------------------------------------------------------
//!
//!  @file
//!  Unicode characters.
//!
//----------------------------------------------------------------------------

#pragma once
#include "tsPlatform.h"
#include <cwctype>

namespace ts {
    class String;

    //!
    //! UTF-16 character.
    //!
    typedef char16_t Char;

    //!
    //! Check if a character is a space.
    //! @param [in] c A character.
    //! @return True if @a c is a space, tab, new line character.
    //!
    TSDUCKDLL inline bool IsSpace(Char c)
    {
        return std::iswspace(wint_t(c)) != 0;
    }

    //!
    //! Check if a character is printable according to the current C locale.
    //! @param [in] c A character.
    //! @return True if @a c is a printable character.
    //!
    TSDUCKDLL inline bool IsPrintable(Char c)
    {
        return std::iswprint(wint_t(c)) != 0;
    }

    //!
    //! Check if a character is a decimal digit.
    //! @param [in] c A character.
    //! @return True if @a c is a decimal digit.
    //!
    TSDUCKDLL inline bool IsDigit(Char c)
    {
        return std::iswdigit(wint_t(c)) != 0;
    }

    //!
    //! Check if a character is an hexadecimal digit.
    //! @param [in] c A character.
    //! @return True if @a c is an hexadecimal digit.
    //!
    TSDUCKDLL inline bool IsHexa(Char c)
    {
        return std::iswxdigit(wint_t(c)) != 0;
    }

    //!
    //! Check if a character is a lower case letter.
    //! @param [in] c A character.
    //! @return True if @a c is a lower case letter.
    //!
    TSDUCKDLL bool IsLower(Char c);

    //!
    //! Check if a character is an upper case letter.
    //! @param [in] c A character.
    //! @return True if @a c is an upper case letter.
    //!
    TSDUCKDLL bool IsUpper(Char c);

    //!
    //! Convert a character to lowercase.
    //! @param [in] c A character to convert to lowercase.
    //! @return @a c converted to lowercase.
    //!
    TSDUCKDLL Char ToLower(Char c);

    //!
    //! Convert a character to uppercase.
    //! @param [in] c A character to convert to uppercase.
    //! @return @a c converted to uppercase.
    //!
    TSDUCKDLL Char ToUpper(Char c);

    //!
    //! Check if a character contains an accent.
    //! @param [in] c A character.
    //! @return True if @a c contains an accent.
    //!
    TSDUCKDLL bool IsAccented(Char c);

    //!
    //! Remove all forms of accent or composition from a character.
    //! @param [in] c A character.
    //! @return A string containing @a c without accent. This is a string and not a char
    //! since composed characters can be translated as two characters.
    //!
    TSDUCKDLL String RemoveAccent(Char c);

    //!
    //! Convert a character into its corresponding HTML sequence.
    //! @param [in] c A character.
    //! @return A string containing the html sequence for @a c.
    //!
    TSDUCKDLL String ToHTML(Char c);

    //
    // The following constants define all characters which can be
    // represented in ISO 8859 character sets.
    // See http://www.unicode.org/Public/MAPPINGS/ISO8859
    //
    static const Char CHAR_NULL                                   = Char(0x0000); //!< ISO-8859 Unicode character.
    static const Char START_OF_HEADING                            = Char(0x0001); //!< ISO-8859 Unicode character.
    static const Char START_OF_TEXT                               = Char(0x0002); //!< ISO-8859 Unicode character.
    static const Char END_OF_TEXT                                 = Char(0x0003); //!< ISO-8859 Unicode character.
    static const Char END_OF_TRANSMISSION                         = Char(0x0004); //!< ISO-8859 Unicode character.
    static const Char ENQUIRY                                     = Char(0x0005); //!< ISO-8859 Unicode character.
    static const Char ACKNOWLEDGE                                 = Char(0x0006); //!< ISO-8859 Unicode character.
    static const Char BELL                                        = Char(0x0007); //!< ISO-8859 Unicode character.
    static const Char BACKSPACE                                   = Char(0x0008); //!< ISO-8859 Unicode character.
    static const Char HORIZONTAL_TABULATION                       = Char(0x0009); //!< ISO-8859 Unicode character.
    static const Char LINE_FEED                                   = Char(0x000A); //!< ISO-8859 Unicode character.
    static const Char VERTICAL_TABULATION                         = Char(0x000B); //!< ISO-8859 Unicode character.
    static const Char FORM_FEED                                   = Char(0x000C); //!< ISO-8859 Unicode character.
    static const Char CARRIAGE_RETURN                             = Char(0x000D); //!< ISO-8859 Unicode character.
    static const Char SHIFT_OUT                                   = Char(0x000E); //!< ISO-8859 Unicode character.
    static const Char SHIFT_IN                                    = Char(0x000F); //!< ISO-8859 Unicode character.
    static const Char DATA_LINK_ESCAPE                            = Char(0x0010); //!< ISO-8859 Unicode character.
    static const Char DEVICE_CONTROL_ONE                          = Char(0x0011); //!< ISO-8859 Unicode character.
    static const Char DEVICE_CONTROL_TWO                          = Char(0x0012); //!< ISO-8859 Unicode character.
    static const Char DEVICE_CONTROL_THREE                        = Char(0x0013); //!< ISO-8859 Unicode character.
    static const Char DEVICE_CONTROL_FOUR                         = Char(0x0014); //!< ISO-8859 Unicode character.
    static const Char NEGATIVE_ACKNOWLEDGE                        = Char(0x0015); //!< ISO-8859 Unicode character.
    static const Char SYNCHRONOUS_IDLE                            = Char(0x0016); //!< ISO-8859 Unicode character.
    static const Char END_OF_TRANSMISSION_BLOCK                   = Char(0x0017); //!< ISO-8859 Unicode character.
    static const Char CANCEL                                      = Char(0x0018); //!< ISO-8859 Unicode character.
    static const Char END_OF_MEDIUM                               = Char(0x0019); //!< ISO-8859 Unicode character.
    static const Char SUBSTITUTE                                  = Char(0x001A); //!< ISO-8859 Unicode character.
    static const Char ESCAPE                                      = Char(0x001B); //!< ISO-8859 Unicode character.
    static const Char FILE_SEPARATOR                              = Char(0x001C); //!< ISO-8859 Unicode character.
    static const Char GROUP_SEPARATOR                             = Char(0x001D); //!< ISO-8859 Unicode character.
    static const Char RECORD_SEPARATOR                            = Char(0x001E); //!< ISO-8859 Unicode character.
    static const Char UNIT_SEPARATOR                              = Char(0x001F); //!< ISO-8859 Unicode character.
    static const Char SPACE                                       = Char(0x0020); //!< ISO-8859 Unicode character.
    static const Char EXCLAMATION_MARK                            = Char(0x0021); //!< ISO-8859 Unicode character.
    static const Char QUOTATION_MARK                              = Char(0x0022); //!< ISO-8859 Unicode character.
    static const Char NUMBER_SIGN                                 = Char(0x0023); //!< ISO-8859 Unicode character.
    static const Char DOLLAR_SIGN                                 = Char(0x0024); //!< ISO-8859 Unicode character.
    static const Char PERCENT_SIGN                                = Char(0x0025); //!< ISO-8859 Unicode character.
    static const Char AMPERSAND                                   = Char(0x0026); //!< ISO-8859 Unicode character.
    static const Char APOSTROPHE                                  = Char(0x0027); //!< ISO-8859 Unicode character.
    static const Char LEFT_PARENTHESIS                            = Char(0x0028); //!< ISO-8859 Unicode character.
    static const Char RIGHT_PARENTHESIS                           = Char(0x0029); //!< ISO-8859 Unicode character.
    static const Char ASTERISK                                    = Char(0x002A); //!< ISO-8859 Unicode character.
    static const Char PLUS_SIGN                                   = Char(0x002B); //!< ISO-8859 Unicode character.
    static const Char COMMA                                       = Char(0x002C); //!< ISO-8859 Unicode character.
    static const Char HYPHEN_MINUS                                = Char(0x002D); //!< ISO-8859 Unicode character.
    static const Char FULL_STOP                                   = Char(0x002E); //!< ISO-8859 Unicode character.
    static const Char SOLIDUS                                     = Char(0x002F); //!< ISO-8859 Unicode character.
    static const Char DIGIT_ZERO                                  = Char(0x0030); //!< ISO-8859 Unicode character.
    static const Char DIGIT_ONE                                   = Char(0x0031); //!< ISO-8859 Unicode character.
    static const Char DIGIT_TWO                                   = Char(0x0032); //!< ISO-8859 Unicode character.
    static const Char DIGIT_THREE                                 = Char(0x0033); //!< ISO-8859 Unicode character.
    static const Char DIGIT_FOUR                                  = Char(0x0034); //!< ISO-8859 Unicode character.
    static const Char DIGIT_FIVE                                  = Char(0x0035); //!< ISO-8859 Unicode character.
    static const Char DIGIT_SIX                                   = Char(0x0036); //!< ISO-8859 Unicode character.
    static const Char DIGIT_SEVEN                                 = Char(0x0037); //!< ISO-8859 Unicode character.
    static const Char DIGIT_EIGHT                                 = Char(0x0038); //!< ISO-8859 Unicode character.
    static const Char DIGIT_NINE                                  = Char(0x0039); //!< ISO-8859 Unicode character.
    static const Char COLON                                       = Char(0x003A); //!< ISO-8859 Unicode character.
    static const Char SEMICOLON                                   = Char(0x003B); //!< ISO-8859 Unicode character.
    static const Char LESS_THAN_SIGN                              = Char(0x003C); //!< ISO-8859 Unicode character.
    static const Char EQUALS_SIGN                                 = Char(0x003D); //!< ISO-8859 Unicode character.
    static const Char GREATER_THAN_SIGN                           = Char(0x003E); //!< ISO-8859 Unicode character.
    static const Char QUESTION_MARK                               = Char(0x003F); //!< ISO-8859 Unicode character.
    static const Char COMMERCIAL_AT                               = Char(0x0040); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_A                      = Char(0x0041); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_B                      = Char(0x0042); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_C                      = Char(0x0043); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_D                      = Char(0x0044); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_E                      = Char(0x0045); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_F                      = Char(0x0046); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_G                      = Char(0x0047); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_H                      = Char(0x0048); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_I                      = Char(0x0049); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_J                      = Char(0x004A); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_K                      = Char(0x004B); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_L                      = Char(0x004C); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_M                      = Char(0x004D); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_N                      = Char(0x004E); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_O                      = Char(0x004F); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_P                      = Char(0x0050); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_Q                      = Char(0x0051); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_R                      = Char(0x0052); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_S                      = Char(0x0053); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_T                      = Char(0x0054); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U                      = Char(0x0055); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_V                      = Char(0x0056); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_W                      = Char(0x0057); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_X                      = Char(0x0058); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_Y                      = Char(0x0059); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_Z                      = Char(0x005A); //!< ISO-8859 Unicode character.
    static const Char LEFT_SQUARE_BRACKET                         = Char(0x005B); //!< ISO-8859 Unicode character.
    static const Char REVERSE_SOLIDUS                             = Char(0x005C); //!< ISO-8859 Unicode character.
    static const Char RIGHT_SQUARE_BRACKET                        = Char(0x005D); //!< ISO-8859 Unicode character.
    static const Char CIRCUMFLEX_ACCENT                           = Char(0x005E); //!< ISO-8859 Unicode character.
    static const Char LOW_LINE                                    = Char(0x005F); //!< ISO-8859 Unicode character.
    static const Char GRAVE_ACCENT                                = Char(0x0060); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_A                        = Char(0x0061); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_B                        = Char(0x0062); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_C                        = Char(0x0063); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_D                        = Char(0x0064); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_E                        = Char(0x0065); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_F                        = Char(0x0066); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_G                        = Char(0x0067); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_H                        = Char(0x0068); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_I                        = Char(0x0069); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_J                        = Char(0x006A); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_K                        = Char(0x006B); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_L                        = Char(0x006C); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_M                        = Char(0x006D); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_N                        = Char(0x006E); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_O                        = Char(0x006F); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_P                        = Char(0x0070); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_Q                        = Char(0x0071); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_R                        = Char(0x0072); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_S                        = Char(0x0073); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_T                        = Char(0x0074); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U                        = Char(0x0075); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_V                        = Char(0x0076); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_W                        = Char(0x0077); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_X                        = Char(0x0078); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_Y                        = Char(0x0079); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_Z                        = Char(0x007A); //!< ISO-8859 Unicode character.
    static const Char LEFT_CURLY_BRACKET                          = Char(0x007B); //!< ISO-8859 Unicode character.
    static const Char VERTICAL_LINE                               = Char(0x007C); //!< ISO-8859 Unicode character.
    static const Char RIGHT_CURLY_BRACKET                         = Char(0x007D); //!< ISO-8859 Unicode character.
    static const Char TILDE                                       = Char(0x007E); //!< ISO-8859 Unicode character.
    static const Char CHAR_DELETE                                 = Char(0x007F); //!< ISO-8859 Unicode character.
    static const Char NO_BREAK_SPACE                              = Char(0x00A0); //!< ISO-8859 Unicode character.
    static const Char INVERTED_EXCLAMATION_MARK                   = Char(0x00A1); //!< ISO-8859 Unicode character.
    static const Char CENT_SIGN                                   = Char(0x00A2); //!< ISO-8859 Unicode character.
    static const Char POUND_SIGN                                  = Char(0x00A3); //!< ISO-8859 Unicode character.
    static const Char CURRENCY_SIGN                               = Char(0x00A4); //!< ISO-8859 Unicode character.
    static const Char YEN_SIGN                                    = Char(0x00A5); //!< ISO-8859 Unicode character.
    static const Char BROKEN_BAR                                  = Char(0x00A6); //!< ISO-8859 Unicode character.
    static const Char SECTION_SIGN                                = Char(0x00A7); //!< ISO-8859 Unicode character.
    static const Char DIAERESIS                                   = Char(0x00A8); //!< ISO-8859 Unicode character.
    static const Char COPYRIGHT_SIGN                              = Char(0x00A9); //!< ISO-8859 Unicode character.
    static const Char FEMININE_ORDINAL_INDICATOR                  = Char(0x00AA); //!< ISO-8859 Unicode character.
    static const Char LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK   = Char(0x00AB); //!< ISO-8859 Unicode character.
    static const Char NOT_SIGN                                    = Char(0x00AC); //!< ISO-8859 Unicode character.
    static const Char SOFT_HYPHEN                                 = Char(0x00AD); //!< ISO-8859 Unicode character.
    static const Char REGISTERED_SIGN                             = Char(0x00AE); //!< ISO-8859 Unicode character.
    static const Char MACRON                                      = Char(0x00AF); //!< ISO-8859 Unicode character.
    static const Char DEGREE_SIGN                                 = Char(0x00B0); //!< ISO-8859 Unicode character.
    static const Char PLUS_MINUS_SIGN                             = Char(0x00B1); //!< ISO-8859 Unicode character.
    static const Char SUPERSCRIPT_TWO                             = Char(0x00B2); //!< ISO-8859 Unicode character.
    static const Char SUPERSCRIPT_THREE                           = Char(0x00B3); //!< ISO-8859 Unicode character.
    static const Char ACUTE_ACCENT                                = Char(0x00B4); //!< ISO-8859 Unicode character.
    static const Char MICRO_SIGN                                  = Char(0x00B5); //!< ISO-8859 Unicode character.
    static const Char PILCROW_SIGN                                = Char(0x00B6); //!< ISO-8859 Unicode character.
    static const Char MIDDLE_DOT                                  = Char(0x00B7); //!< ISO-8859 Unicode character.
    static const Char CEDILLA                                     = Char(0x00B8); //!< ISO-8859 Unicode character.
    static const Char SUPERSCRIPT_ONE                             = Char(0x00B9); //!< ISO-8859 Unicode character.
    static const Char MASCULINE_ORDINAL_INDICATOR                 = Char(0x00BA); //!< ISO-8859 Unicode character.
    static const Char RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK  = Char(0x00BB); //!< ISO-8859 Unicode character.
    static const Char VULGAR_FRACTION_ONE_QUARTER                 = Char(0x00BC); //!< ISO-8859 Unicode character.
    static const Char VULGAR_FRACTION_ONE_HALF                    = Char(0x00BD); //!< ISO-8859 Unicode character.
    static const Char VULGAR_FRACTION_THREE_QUARTERS              = Char(0x00BE); //!< ISO-8859 Unicode character.
    static const Char INVERTED_QUESTION_MARK                      = Char(0x00BF); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_A_WITH_GRAVE           = Char(0x00C0); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_A_WITH_ACUTE           = Char(0x00C1); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX      = Char(0x00C2); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_A_WITH_TILDE           = Char(0x00C3); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS       = Char(0x00C4); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE      = Char(0x00C5); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_AE                     = Char(0x00C6); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_C_WITH_CEDILLA         = Char(0x00C7); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_E_WITH_GRAVE           = Char(0x00C8); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_E_WITH_ACUTE           = Char(0x00C9); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX      = Char(0x00CA); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS       = Char(0x00CB); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_I_WITH_GRAVE           = Char(0x00CC); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_I_WITH_ACUTE           = Char(0x00CD); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX      = Char(0x00CE); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS       = Char(0x00CF); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_ETH                    = Char(0x00D0); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_N_WITH_TILDE           = Char(0x00D1); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_O_WITH_GRAVE           = Char(0x00D2); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_O_WITH_ACUTE           = Char(0x00D3); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX      = Char(0x00D4); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_O_WITH_TILDE           = Char(0x00D5); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS       = Char(0x00D6); //!< ISO-8859 Unicode character.
    static const Char MULTIPLICATION_SIGN                         = Char(0x00D7); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_O_WITH_STROKE          = Char(0x00D8); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U_WITH_GRAVE           = Char(0x00D9); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U_WITH_ACUTE           = Char(0x00DA); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX      = Char(0x00DB); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS       = Char(0x00DC); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_Y_WITH_ACUTE           = Char(0x00DD); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_THORN                  = Char(0x00DE); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_SHARP_S                  = Char(0x00DF); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_A_WITH_GRAVE             = Char(0x00E0); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_A_WITH_ACUTE             = Char(0x00E1); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX        = Char(0x00E2); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_A_WITH_TILDE             = Char(0x00E3); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_A_WITH_DIAERESIS         = Char(0x00E4); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_A_WITH_RING_ABOVE        = Char(0x00E5); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_AE                       = Char(0x00E6); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_C_WITH_CEDILLA           = Char(0x00E7); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_E_WITH_GRAVE             = Char(0x00E8); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_E_WITH_ACUTE             = Char(0x00E9); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX        = Char(0x00EA); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_E_WITH_DIAERESIS         = Char(0x00EB); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_I_WITH_GRAVE             = Char(0x00EC); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_I_WITH_ACUTE             = Char(0x00ED); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX        = Char(0x00EE); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_I_WITH_DIAERESIS         = Char(0x00EF); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_ETH                      = Char(0x00F0); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_N_WITH_TILDE             = Char(0x00F1); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_O_WITH_GRAVE             = Char(0x00F2); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_O_WITH_ACUTE             = Char(0x00F3); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX        = Char(0x00F4); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_O_WITH_TILDE             = Char(0x00F5); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_O_WITH_DIAERESIS         = Char(0x00F6); //!< ISO-8859 Unicode character.
    static const Char DIVISION_SIGN                               = Char(0x00F7); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_O_WITH_STROKE            = Char(0x00F8); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U_WITH_GRAVE             = Char(0x00F9); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U_WITH_ACUTE             = Char(0x00FA); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX        = Char(0x00FB); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U_WITH_DIAERESIS         = Char(0x00FC); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_Y_WITH_ACUTE             = Char(0x00FD); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_THORN                    = Char(0x00FE); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_Y_WITH_DIAERESIS         = Char(0x00FF); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_A_WITH_MACRON          = Char(0x0100); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_A_WITH_MACRON            = Char(0x0101); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_A_WITH_BREVE           = Char(0x0102); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_A_WITH_BREVE             = Char(0x0103); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_A_WITH_OGONEK          = Char(0x0104); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_A_WITH_OGONEK            = Char(0x0105); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_C_WITH_ACUTE           = Char(0x0106); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_C_WITH_ACUTE             = Char(0x0107); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_C_WITH_CIRCUMFLEX      = Char(0x0108); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_C_WITH_CIRCUMFLEX        = Char(0x0109); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_C_WITH_DOT_ABOVE       = Char(0x010A); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_C_WITH_DOT_ABOVE         = Char(0x010B); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_C_WITH_CARON           = Char(0x010C); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_C_WITH_CARON             = Char(0x010D); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_D_WITH_CARON           = Char(0x010E); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_D_WITH_CARON             = Char(0x010F); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_D_WITH_STROKE          = Char(0x0110); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_D_WITH_STROKE            = Char(0x0111); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_E_WITH_MACRON          = Char(0x0112); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_E_WITH_MACRON            = Char(0x0113); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_E_WITH_DOT_ABOVE       = Char(0x0116); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_E_WITH_DOT_ABOVE         = Char(0x0117); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_E_WITH_OGONEK          = Char(0x0118); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_E_WITH_OGONEK            = Char(0x0119); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_E_WITH_CARON           = Char(0x011A); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_E_WITH_CARON             = Char(0x011B); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_G_WITH_CIRCUMFLEX      = Char(0x011C); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_G_WITH_CIRCUMFLEX        = Char(0x011D); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_G_WITH_BREVE           = Char(0x011E); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_G_WITH_BREVE             = Char(0x011F); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_G_WITH_DOT_ABOVE       = Char(0x0120); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_G_WITH_DOT_ABOVE         = Char(0x0121); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_G_WITH_CEDILLA         = Char(0x0122); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_G_WITH_CEDILLA           = Char(0x0123); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_H_WITH_CIRCUMFLEX      = Char(0x0124); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_H_WITH_CIRCUMFLEX        = Char(0x0125); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_H_WITH_STROKE          = Char(0x0126); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_H_WITH_STROKE            = Char(0x0127); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_I_WITH_TILDE           = Char(0x0128); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_I_WITH_TILDE             = Char(0x0129); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_I_WITH_MACRON          = Char(0x012A); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_I_WITH_MACRON            = Char(0x012B); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_I_WITH_OGONEK          = Char(0x012E); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_I_WITH_OGONEK            = Char(0x012F); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_I_WITH_DOT_ABOVE       = Char(0x0130); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_DOTLESS_I                = Char(0x0131); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_J_WITH_CIRCUMFLEX      = Char(0x0134); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_J_WITH_CIRCUMFLEX        = Char(0x0135); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_K_WITH_CEDILLA         = Char(0x0136); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_K_WITH_CEDILLA           = Char(0x0137); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_KRA                      = Char(0x0138); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_L_WITH_ACUTE           = Char(0x0139); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_L_WITH_ACUTE             = Char(0x013A); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_L_WITH_CEDILLA         = Char(0x013B); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_L_WITH_CEDILLA           = Char(0x013C); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_L_WITH_CARON           = Char(0x013D); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_L_WITH_CARON             = Char(0x013E); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_L_WITH_STROKE          = Char(0x0141); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_L_WITH_STROKE            = Char(0x0142); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_N_WITH_ACUTE           = Char(0x0143); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_N_WITH_ACUTE             = Char(0x0144); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_N_WITH_CEDILLA         = Char(0x0145); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_N_WITH_CEDILLA           = Char(0x0146); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_N_WITH_CARON           = Char(0x0147); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_N_WITH_CARON             = Char(0x0148); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_ENG                    = Char(0x014A); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_ENG                      = Char(0x014B); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_O_WITH_MACRON          = Char(0x014C); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_O_WITH_MACRON            = Char(0x014D); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_O_WITH_DOUBLE_ACUTE    = Char(0x0150); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_O_WITH_DOUBLE_ACUTE      = Char(0x0151); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LIGATURE_OE                   = Char(0x0152); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LIGATURE_OE                     = Char(0x0153); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_R_WITH_ACUTE           = Char(0x0154); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_R_WITH_ACUTE             = Char(0x0155); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_R_WITH_CEDILLA         = Char(0x0156); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_R_WITH_CEDILLA           = Char(0x0157); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_R_WITH_CARON           = Char(0x0158); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_R_WITH_CARON             = Char(0x0159); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_S_WITH_ACUTE           = Char(0x015A); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_S_WITH_ACUTE             = Char(0x015B); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_S_WITH_CIRCUMFLEX      = Char(0x015C); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_S_WITH_CIRCUMFLEX        = Char(0x015D); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_S_WITH_CEDILLA         = Char(0x015E); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_S_WITH_CEDILLA           = Char(0x015F); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_S_WITH_CARON           = Char(0x0160); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_S_WITH_CARON             = Char(0x0161); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_T_WITH_CEDILLA         = Char(0x0162); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_T_WITH_CEDILLA           = Char(0x0163); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_T_WITH_CARON           = Char(0x0164); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_T_WITH_CARON             = Char(0x0165); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_T_WITH_STROKE          = Char(0x0166); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_T_WITH_STROKE            = Char(0x0167); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U_WITH_TILDE           = Char(0x0168); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U_WITH_TILDE             = Char(0x0169); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U_WITH_MACRON          = Char(0x016A); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U_WITH_MACRON            = Char(0x016B); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U_WITH_BREVE           = Char(0x016C); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U_WITH_BREVE             = Char(0x016D); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U_WITH_RING_ABOVE      = Char(0x016E); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U_WITH_RING_ABOVE        = Char(0x016F); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U_WITH_DOUBLE_ACUTE    = Char(0x0170); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U_WITH_DOUBLE_ACUTE      = Char(0x0171); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_U_WITH_OGONEK          = Char(0x0172); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_U_WITH_OGONEK            = Char(0x0173); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_W_WITH_CIRCUMFLEX      = Char(0x0174); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_W_WITH_CIRCUMFLEX        = Char(0x0175); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_Y_WITH_CIRCUMFLEX      = Char(0x0176); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_Y_WITH_CIRCUMFLEX        = Char(0x0177); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_Y_WITH_DIAERESIS       = Char(0x0178); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_Z_WITH_ACUTE           = Char(0x0179); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_Z_WITH_ACUTE             = Char(0x017A); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_Z_WITH_DOT_ABOVE       = Char(0x017B); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_Z_WITH_DOT_ABOVE         = Char(0x017C); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_Z_WITH_CARON           = Char(0x017D); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_Z_WITH_CARON             = Char(0x017E); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_S_WITH_COMMA_BELOW     = Char(0x0218); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_S_WITH_COMMA_BELOW       = Char(0x0219); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_T_WITH_COMMA_BELOW     = Char(0x021A); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_T_WITH_COMMA_BELOW       = Char(0x021B); //!< ISO-8859 Unicode character.
    static const Char CARON                                       = Char(0x02C7); //!< ISO-8859 Unicode character.
    static const Char BREVE                                       = Char(0x02D8); //!< ISO-8859 Unicode character.
    static const Char DOT_ABOVE                                   = Char(0x02D9); //!< ISO-8859 Unicode character.
    static const Char OGONEK                                      = Char(0x02DB); //!< ISO-8859 Unicode character.
    static const Char DOUBLE_ACUTE_ACCENT                         = Char(0x02DD); //!< ISO-8859 Unicode character.
    static const Char GREEK_YPOGEGRAMMENI                         = Char(0x037A); //!< ISO-8859 Unicode character.
    static const Char GREEK_TONOS                                 = Char(0x0384); //!< ISO-8859 Unicode character.
    static const Char GREEK_DIALYTIKA_TONOS                       = Char(0x0385); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_ALPHA_WITH_TONOS       = Char(0x0386); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_EPSILON_WITH_TONOS     = Char(0x0388); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_ETA_WITH_TONOS         = Char(0x0389); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_IOTA_WITH_TONOS        = Char(0x038A); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_OMICRON_WITH_TONOS     = Char(0x038C); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_UPSILON_WITH_TONOS     = Char(0x038E); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_OMEGA_WITH_TONOS       = Char(0x038F); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_IOTA_WITH_DIALYTIKA_AND_TONOS = Char(0x0390); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_ALPHA                  = Char(0x0391); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_BETA                   = Char(0x0392); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_GAMMA                  = Char(0x0393); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_DELTA                  = Char(0x0394); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_EPSILON                = Char(0x0395); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_ZETA                   = Char(0x0396); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_ETA                    = Char(0x0397); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_THETA                  = Char(0x0398); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_IOTA                   = Char(0x0399); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_KAPPA                  = Char(0x039A); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_LAMDA                  = Char(0x039B); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_MU                     = Char(0x039C); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_NU                     = Char(0x039D); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_XI                     = Char(0x039E); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_OMICRON                = Char(0x039F); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_PI                     = Char(0x03A0); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_RHO                    = Char(0x03A1); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_SIGMA                  = Char(0x03A3); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_TAU                    = Char(0x03A4); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_UPSILON                = Char(0x03A5); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_PHI                    = Char(0x03A6); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_CHI                    = Char(0x03A7); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_PSI                    = Char(0x03A8); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_OMEGA                  = Char(0x03A9); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_IOTA_WITH_DIALYTIKA    = Char(0x03AA); //!< ISO-8859 Unicode character.
    static const Char GREEK_CAPITAL_LETTER_UPSILON_WITH_DIALYTIKA = Char(0x03AB); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_ALPHA_WITH_TONOS         = Char(0x03AC); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_EPSILON_WITH_TONOS       = Char(0x03AD); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_ETA_WITH_TONOS           = Char(0x03AE); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_IOTA_WITH_TONOS          = Char(0x03AF); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_UPSILON_WITH_DIALYTIKA_AND_TONOS = Char(0x03B0); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_ALPHA                    = Char(0x03B1); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_BETA                     = Char(0x03B2); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_GAMMA                    = Char(0x03B3); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_DELTA                    = Char(0x03B4); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_EPSILON                  = Char(0x03B5); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_ZETA                     = Char(0x03B6); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_ETA                      = Char(0x03B7); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_THETA                    = Char(0x03B8); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_IOTA                     = Char(0x03B9); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_KAPPA                    = Char(0x03BA); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_LAMDA                    = Char(0x03BB); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_MU                       = Char(0x03BC); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_NU                       = Char(0x03BD); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_XI                       = Char(0x03BE); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_OMICRON                  = Char(0x03BF); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_PI                       = Char(0x03C0); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_RHO                      = Char(0x03C1); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_FINAL_SIGMA              = Char(0x03C2); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_SIGMA                    = Char(0x03C3); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_TAU                      = Char(0x03C4); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_UPSILON                  = Char(0x03C5); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_PHI                      = Char(0x03C6); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_CHI                      = Char(0x03C7); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_PSI                      = Char(0x03C8); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_OMEGA                    = Char(0x03C9); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_IOTA_WITH_DIALYTIKA      = Char(0x03CA); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_UPSILON_WITH_DIALYTIKA   = Char(0x03CB); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_OMICRON_WITH_TONOS       = Char(0x03CC); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_UPSILON_WITH_TONOS       = Char(0x03CD); //!< ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_OMEGA_WITH_TONOS         = Char(0x03CE); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_IO                  = Char(0x0401); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_DJE                 = Char(0x0402); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_GJE                 = Char(0x0403); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_UKRAINIAN_IE        = Char(0x0404); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_DZE                 = Char(0x0405); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_BYELORUSSIAN_UKRAINIAN_I = Char(0x0406); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_YI                  = Char(0x0407); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_JE                  = Char(0x0408); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_LJE                 = Char(0x0409); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_NJE                 = Char(0x040A); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_TSHE                = Char(0x040B); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_KJE                 = Char(0x040C); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_SHORT_U             = Char(0x040E); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_DZHE                = Char(0x040F); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_A                   = Char(0x0410); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_BE                  = Char(0x0411); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_VE                  = Char(0x0412); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_GHE                 = Char(0x0413); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_DE                  = Char(0x0414); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_IE                  = Char(0x0415); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_ZHE                 = Char(0x0416); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_ZE                  = Char(0x0417); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_I                   = Char(0x0418); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_SHORT_I             = Char(0x0419); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_KA                  = Char(0x041A); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_EL                  = Char(0x041B); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_EM                  = Char(0x041C); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_EN                  = Char(0x041D); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_O                   = Char(0x041E); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_PE                  = Char(0x041F); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_ER                  = Char(0x0420); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_ES                  = Char(0x0421); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_TE                  = Char(0x0422); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_U                   = Char(0x0423); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_EF                  = Char(0x0424); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_HA                  = Char(0x0425); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_TSE                 = Char(0x0426); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_CHE                 = Char(0x0427); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_SHA                 = Char(0x0428); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_SHCHA               = Char(0x0429); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_HARD_SIGN           = Char(0x042A); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_YERU                = Char(0x042B); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_SOFT_SIGN           = Char(0x042C); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_E                   = Char(0x042D); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_YU                  = Char(0x042E); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_CAPITAL_LETTER_YA                  = Char(0x042F); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_A                     = Char(0x0430); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_BE                    = Char(0x0431); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_VE                    = Char(0x0432); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_GHE                   = Char(0x0433); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_DE                    = Char(0x0434); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_IE                    = Char(0x0435); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_ZHE                   = Char(0x0436); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_ZE                    = Char(0x0437); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_I                     = Char(0x0438); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_SHORT_I               = Char(0x0439); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_KA                    = Char(0x043A); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_EL                    = Char(0x043B); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_EM                    = Char(0x043C); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_EN                    = Char(0x043D); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_O                     = Char(0x043E); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_PE                    = Char(0x043F); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_ER                    = Char(0x0440); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_ES                    = Char(0x0441); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_TE                    = Char(0x0442); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_U                     = Char(0x0443); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_EF                    = Char(0x0444); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_HA                    = Char(0x0445); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_TSE                   = Char(0x0446); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_CHE                   = Char(0x0447); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_SHA                   = Char(0x0448); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_SHCHA                 = Char(0x0449); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_HARD_SIGN             = Char(0x044A); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_YERU                  = Char(0x044B); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_SOFT_SIGN             = Char(0x044C); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_E                     = Char(0x044D); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_YU                    = Char(0x044E); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_YA                    = Char(0x044F); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_IO                    = Char(0x0451); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_DJE                   = Char(0x0452); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_GJE                   = Char(0x0453); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_UKRAINIAN_IE          = Char(0x0454); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_DZE                   = Char(0x0455); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_BYELORUSSIAN_UKRAINIAN_I = Char(0x0456); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_YI                    = Char(0x0457); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_JE                    = Char(0x0458); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_LJE                   = Char(0x0459); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_NJE                   = Char(0x045A); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_TSHE                  = Char(0x045B); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_KJE                   = Char(0x045C); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_SHORT_U               = Char(0x045E); //!< ISO-8859 Unicode character.
    static const Char CYRILLIC_SMALL_LETTER_DZHE                  = Char(0x045F); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_ALEF                          = Char(0x05D0); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_BET                           = Char(0x05D1); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_GIMEL                         = Char(0x05D2); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_DALET                         = Char(0x05D3); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_HE                            = Char(0x05D4); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_VAV                           = Char(0x05D5); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_ZAYIN                         = Char(0x05D6); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_HET                           = Char(0x05D7); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_TET                           = Char(0x05D8); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_YOD                           = Char(0x05D9); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_FINAL_KAF                     = Char(0x05DA); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_KAF                           = Char(0x05DB); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_LAMED                         = Char(0x05DC); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_FINAL_MEM                     = Char(0x05DD); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_MEM                           = Char(0x05DE); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_FINAL_NUN                     = Char(0x05DF); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_NUN                           = Char(0x05E0); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_SAMEKH                        = Char(0x05E1); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_AYIN                          = Char(0x05E2); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_FINAL_PE                      = Char(0x05E3); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_PE                            = Char(0x05E4); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_FINAL_TSADI                   = Char(0x05E5); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_TSADI                         = Char(0x05E6); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_QOF                           = Char(0x05E7); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_RESH                          = Char(0x05E8); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_SHIN                          = Char(0x05E9); //!< ISO-8859 Unicode character.
    static const Char HEBREW_LETTER_TAV                           = Char(0x05EA); //!< ISO-8859 Unicode character.
    static const Char ARABIC_COMMA                                = Char(0x060C); //!< ISO-8859 Unicode character.
    static const Char ARABIC_SEMICOLON                            = Char(0x061B); //!< ISO-8859 Unicode character.
    static const Char ARABIC_QUESTION_MARK                        = Char(0x061F); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_HAMZA                         = Char(0x0621); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_ALEF_WITH_MADDA_ABOVE         = Char(0x0622); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_ALEF_WITH_HAMZA_ABOVE         = Char(0x0623); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_WAW_WITH_HAMZA_ABOVE          = Char(0x0624); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_ALEF_WITH_HAMZA_BELOW         = Char(0x0625); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_YEH_WITH_HAMZA_ABOVE          = Char(0x0626); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_ALEF                          = Char(0x0627); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_BEH                           = Char(0x0628); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_TEH_MARBUTA                   = Char(0x0629); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_TEH                           = Char(0x062A); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_THEH                          = Char(0x062B); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_JEEM                          = Char(0x062C); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_HAH                           = Char(0x062D); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_KHAH                          = Char(0x062E); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_DAL                           = Char(0x062F); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_THAL                          = Char(0x0630); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_REH                           = Char(0x0631); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_ZAIN                          = Char(0x0632); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_SEEN                          = Char(0x0633); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_SHEEN                         = Char(0x0634); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_SAD                           = Char(0x0635); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_DAD                           = Char(0x0636); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_TAH                           = Char(0x0637); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_ZAH                           = Char(0x0638); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_AIN                           = Char(0x0639); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_GHAIN                         = Char(0x063A); //!< ISO-8859 Unicode character.
    static const Char ARABIC_TATWEEL                              = Char(0x0640); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_FEH                           = Char(0x0641); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_QAF                           = Char(0x0642); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_KAF                           = Char(0x0643); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_LAM                           = Char(0x0644); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_MEEM                          = Char(0x0645); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_NOON                          = Char(0x0646); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_HEH                           = Char(0x0647); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_WAW                           = Char(0x0648); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_ALEF_MAKSURA                  = Char(0x0649); //!< ISO-8859 Unicode character.
    static const Char ARABIC_LETTER_YEH                           = Char(0x064A); //!< ISO-8859 Unicode character.
    static const Char ARABIC_FATHATAN                             = Char(0x064B); //!< ISO-8859 Unicode character.
    static const Char ARABIC_DAMMATAN                             = Char(0x064C); //!< ISO-8859 Unicode character.
    static const Char ARABIC_KASRATAN                             = Char(0x064D); //!< ISO-8859 Unicode character.
    static const Char ARABIC_FATHA                                = Char(0x064E); //!< ISO-8859 Unicode character.
    static const Char ARABIC_DAMMA                                = Char(0x064F); //!< ISO-8859 Unicode character.
    static const Char ARABIC_KASRA                                = Char(0x0650); //!< ISO-8859 Unicode character.
    static const Char ARABIC_SHADDA                               = Char(0x0651); //!< ISO-8859 Unicode character.
    static const Char ARABIC_SUKUN                                = Char(0x0652); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_KO_KAI                       = Char(0x0E01); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_KHO_KHAI                     = Char(0x0E02); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_KHO_KHUAT                    = Char(0x0E03); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_KHO_KHWAI                    = Char(0x0E04); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_KHO_KHON                     = Char(0x0E05); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_KHO_RAKHANG                  = Char(0x0E06); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_NGO_NGU                      = Char(0x0E07); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_CHO_CHAN                     = Char(0x0E08); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_CHO_CHING                    = Char(0x0E09); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_CHO_CHANG                    = Char(0x0E0A); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SO_SO                        = Char(0x0E0B); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_CHO_CHOE                     = Char(0x0E0C); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_YO_YING                      = Char(0x0E0D); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_DO_CHADA                     = Char(0x0E0E); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_TO_PATAK                     = Char(0x0E0F); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_THO_THAN                     = Char(0x0E10); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_THO_NANGMONTHO               = Char(0x0E11); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_THO_PHUTHAO                  = Char(0x0E12); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_NO_NEN                       = Char(0x0E13); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_DO_DEK                       = Char(0x0E14); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_TO_TAO                       = Char(0x0E15); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_THO_THUNG                    = Char(0x0E16); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_THO_THAHAN                   = Char(0x0E17); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_THO_THONG                    = Char(0x0E18); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_NO_NU                        = Char(0x0E19); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_BO_BAIMAI                    = Char(0x0E1A); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_PO_PLA                       = Char(0x0E1B); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_PHO_PHUNG                    = Char(0x0E1C); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_FO_FA                        = Char(0x0E1D); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_PHO_PHAN                     = Char(0x0E1E); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_FO_FAN                       = Char(0x0E1F); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_PHO_SAMPHAO                  = Char(0x0E20); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_MO_MA                        = Char(0x0E21); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_YO_YAK                       = Char(0x0E22); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_RO_RUA                       = Char(0x0E23); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_RU                           = Char(0x0E24); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_LO_LING                      = Char(0x0E25); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_LU                           = Char(0x0E26); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_WO_WAEN                      = Char(0x0E27); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SO_SALA                      = Char(0x0E28); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SO_RUSI                      = Char(0x0E29); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SO_SUA                       = Char(0x0E2A); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_HO_HIP                       = Char(0x0E2B); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_LO_CHULA                     = Char(0x0E2C); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_O_ANG                        = Char(0x0E2D); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_HO_NOKHUK                    = Char(0x0E2E); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_PAIYANNOI                    = Char(0x0E2F); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_A                       = Char(0x0E30); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_MAI_HAN_AKAT                 = Char(0x0E31); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_AA                      = Char(0x0E32); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_AM                      = Char(0x0E33); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_I                       = Char(0x0E34); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_II                      = Char(0x0E35); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_UE                      = Char(0x0E36); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_UEE                     = Char(0x0E37); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_U                       = Char(0x0E38); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_UU                      = Char(0x0E39); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_PHINTHU                      = Char(0x0E3A); //!< ISO-8859 Unicode character.
    static const Char THAI_CURRENCY_SYMBOL_BAHT                   = Char(0x0E3F); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_E                       = Char(0x0E40); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_AE                      = Char(0x0E41); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_O                       = Char(0x0E42); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_AI_MAIMUAN              = Char(0x0E43); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_SARA_AI_MAIMALAI             = Char(0x0E44); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_LAKKHANGYAO                  = Char(0x0E45); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_MAIYAMOK                     = Char(0x0E46); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_MAITAIKHU                    = Char(0x0E47); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_MAI_EK                       = Char(0x0E48); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_MAI_THO                      = Char(0x0E49); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_MAI_TRI                      = Char(0x0E4A); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_MAI_CHATTAWA                 = Char(0x0E4B); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_THANTHAKHAT                  = Char(0x0E4C); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_NIKHAHIT                     = Char(0x0E4D); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_YAMAKKAN                     = Char(0x0E4E); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_FONGMAN                      = Char(0x0E4F); //!< ISO-8859 Unicode character.
    static const Char THAI_DIGIT_ZERO                             = Char(0x0E50); //!< ISO-8859 Unicode character.
    static const Char THAI_DIGIT_ONE                              = Char(0x0E51); //!< ISO-8859 Unicode character.
    static const Char THAI_DIGIT_TWO                              = Char(0x0E52); //!< ISO-8859 Unicode character.
    static const Char THAI_DIGIT_THREE                            = Char(0x0E53); //!< ISO-8859 Unicode character.
    static const Char THAI_DIGIT_FOUR                             = Char(0x0E54); //!< ISO-8859 Unicode character.
    static const Char THAI_DIGIT_FIVE                             = Char(0x0E55); //!< ISO-8859 Unicode character.
    static const Char THAI_DIGIT_SIX                              = Char(0x0E56); //!< ISO-8859 Unicode character.
    static const Char THAI_DIGIT_SEVEN                            = Char(0x0E57); //!< ISO-8859 Unicode character.
    static const Char THAI_DIGIT_EIGHT                            = Char(0x0E58); //!< ISO-8859 Unicode character.
    static const Char THAI_DIGIT_NINE                             = Char(0x0E59); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_ANGKHANKHU                   = Char(0x0E5A); //!< ISO-8859 Unicode character.
    static const Char THAI_CHARACTER_KHOMUT                       = Char(0x0E5B); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_B_WITH_DOT_ABOVE       = Char(0x1E02); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_B_WITH_DOT_ABOVE         = Char(0x1E03); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_D_WITH_DOT_ABOVE       = Char(0x1E0A); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_D_WITH_DOT_ABOVE         = Char(0x1E0B); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_F_WITH_DOT_ABOVE       = Char(0x1E1E); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_F_WITH_DOT_ABOVE         = Char(0x1E1F); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_M_WITH_DOT_ABOVE       = Char(0x1E40); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_M_WITH_DOT_ABOVE         = Char(0x1E41); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_P_WITH_DOT_ABOVE       = Char(0x1E56); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_P_WITH_DOT_ABOVE         = Char(0x1E57); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_S_WITH_DOT_ABOVE       = Char(0x1E60); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_S_WITH_DOT_ABOVE         = Char(0x1E61); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_T_WITH_DOT_ABOVE       = Char(0x1E6A); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_T_WITH_DOT_ABOVE         = Char(0x1E6B); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_W_WITH_GRAVE           = Char(0x1E80); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_W_WITH_GRAVE             = Char(0x1E81); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_W_WITH_ACUTE           = Char(0x1E82); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_W_WITH_ACUTE             = Char(0x1E83); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_W_WITH_DIAERESIS       = Char(0x1E84); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_W_WITH_DIAERESIS         = Char(0x1E85); //!< ISO-8859 Unicode character.
    static const Char LATIN_CAPITAL_LETTER_Y_WITH_GRAVE           = Char(0x1EF2); //!< ISO-8859 Unicode character.
    static const Char LATIN_SMALL_LETTER_Y_WITH_GRAVE             = Char(0x1EF3); //!< ISO-8859 Unicode character.
    static const Char LEFT_TO_RIGHT_MARK                          = Char(0x200E); //!< ISO-8859 Unicode character.
    static const Char RIGHT_TO_LEFT_MARK                          = Char(0x200F); //!< ISO-8859 Unicode character.
    static const Char HORIZONTAL_BAR                              = Char(0x2015); //!< ISO-8859 Unicode character.
    static const Char DOUBLE_LOW_LINE                             = Char(0x2017); //!< ISO-8859 Unicode character.
    static const Char LEFT_SINGLE_QUOTATION_MARK                  = Char(0x2018); //!< ISO-8859 Unicode character.
    static const Char RIGHT_SINGLE_QUOTATION_MARK                 = Char(0x2019); //!< ISO-8859 Unicode character.
    static const Char LEFT_DOUBLE_QUOTATION_MARK                  = Char(0x201C); //!< ISO-8859 Unicode character.
    static const Char RIGHT_DOUBLE_QUOTATION_MARK                 = Char(0x201D); //!< ISO-8859 Unicode character.
    static const Char DOUBLE_LOW_9_QUOTATION_MARK                 = Char(0x201E); //!< ISO-8859 Unicode character.
    static const Char EURO_SIGN                                   = Char(0x20AC); //!< ISO-8859 Unicode character.
    static const Char DRACHMA_SIGN                                = Char(0x20AF); //!< ISO-8859 Unicode character.
    static const Char NUMERO_SIGN                                 = Char(0x2116); //!< ISO-8859 Unicode character.
    //
    // Supplemental characters, not in ISO 8859 mapping files at unicode.org
    //
    static const Char LATIN_SMALL_F_WITH_HOOK                     = Char(0x0192); //!< Non-ISO-8859 Unicode character.
    static const Char MODIFIER_LETTER_CIRCUMFLEX_ACCENT           = Char(0x02C6); //!< Non-ISO-8859 Unicode character.
    static const Char SMALL_TILDE                                 = Char(0x02DC); //!< Non-ISO-8859 Unicode character.
    static const Char GREEK_SMALL_LETTER_THETA_SYMBOL             = Char(0x03D1); //!< Non-ISO-8859 Unicode character.
    static const Char GREEK_UPSILON_WITH_HOOK_SYMBOL              = Char(0x03D2); //!< Non-ISO-8859 Unicode character.
    static const Char GREEK_PI_SYMBOL                             = Char(0x03D6); //!< Non-ISO-8859 Unicode character.
    static const Char EN_SPACE                                    = Char(0x2002); //!< Non-ISO-8859 Unicode character.
    static const Char EM_SPACE                                    = Char(0x2003); //!< Non-ISO-8859 Unicode character.
    static const Char THIN_SPACE                                  = Char(0x2009); //!< Non-ISO-8859 Unicode character.
    static const Char ZERO_WIDTH_NON_JOINER                       = Char(0x200C); //!< Non-ISO-8859 Unicode character.
    static const Char ZERO_WIDTH_JOINER                           = Char(0x200D); //!< Non-ISO-8859 Unicode character.
    static const Char EN_DASH                                     = Char(0x2013); //!< Non-ISO-8859 Unicode character.
    static const Char EM_DASH                                     = Char(0x2014); //!< Non-ISO-8859 Unicode character.
    static const Char SINGLE_LOW_9_QUOTATION_MARK                 = Char(0x201A); //!< Non-ISO-8859 Unicode character.
    static const Char DAGGER                                      = Char(0x2020); //!< Non-ISO-8859 Unicode character.
    static const Char DOUBLE_DAGGER                               = Char(0x2021); //!< Non-ISO-8859 Unicode character.
    static const Char BULLET                                      = Char(0x2022); //!< Non-ISO-8859 Unicode character.
    static const Char HORIZONTAL_ELLIPSIS                         = Char(0x2026); //!< Non-ISO-8859 Unicode character.
    static const Char PER_MILLE_SIGN                              = Char(0x2030); //!< Non-ISO-8859 Unicode character.
    static const Char PRIME                                       = Char(0x2032); //!< Non-ISO-8859 Unicode character.
    static const Char DOUBLE_PRIME                                = Char(0x2033); //!< Non-ISO-8859 Unicode character.
    static const Char SINGLE_LEFT_POINTING_ANGLE_QUOTATION_MARK   = Char(0x2039); //!< Non-ISO-8859 Unicode character.
    static const Char SINGLE_RIGHT_POINTING_ANGLE_QUOTATION_MARK  = Char(0x203A); //!< Non-ISO-8859 Unicode character.
    static const Char OVERLINE                                    = Char(0x203E); //!< Non-ISO-8859 Unicode character.
    static const Char FRACTION_SLASH                              = Char(0x2044); //!< Non-ISO-8859 Unicode character.
    static const Char BLACKLETTER_CAPITAL_I                       = Char(0x2111); //!< Non-ISO-8859 Unicode character.
    static const Char SCRIPT_CAPITAL_P                            = Char(0x2118); //!< Non-ISO-8859 Unicode character.
    static const Char BLACKLETTER_CAPITAL_R                       = Char(0x211C); //!< Non-ISO-8859 Unicode character.
    static const Char TRADE_MARK_SIGN                             = Char(0x2122); //!< Non-ISO-8859 Unicode character.
    static const Char ALEF_SYMBOL                                 = Char(0x2135); //!< Non-ISO-8859 Unicode character.
    static const Char LEFTWARDS_ARROW                             = Char(0x2190); //!< Non-ISO-8859 Unicode character.
    static const Char UPWARDS_ARROW                               = Char(0x2191); //!< Non-ISO-8859 Unicode character.
    static const Char RIGHTWARDS_ARROW                            = Char(0x2192); //!< Non-ISO-8859 Unicode character.
    static const Char DOWNWARDS_ARROW                             = Char(0x2193); //!< Non-ISO-8859 Unicode character.
    static const Char LEFT_RIGHT_ARROW                            = Char(0x2194); //!< Non-ISO-8859 Unicode character.
    static const Char DOWNWARDS_ARROW_WITH_CORNER_LEFTWARDS       = Char(0x21B5); //!< Non-ISO-8859 Unicode character.
    static const Char LEFTWARDS_DOUBLE_ARROW                      = Char(0x21D0); //!< Non-ISO-8859 Unicode character.
    static const Char UPWARDS_DOUBLE_ARROW                        = Char(0x21D1); //!< Non-ISO-8859 Unicode character.
    static const Char RIGHTWARDS_DOUBLE_ARROW                     = Char(0x21D2); //!< Non-ISO-8859 Unicode character.
    static const Char DOWNWARDS_DOUBLE_ARROW                      = Char(0x21D3); //!< Non-ISO-8859 Unicode character.
    static const Char LEFT_RIGHT_DOUBLE_ARROW                     = Char(0x21D4); //!< Non-ISO-8859 Unicode character.
    static const Char FOR_ALL                                     = Char(0x2200); //!< Non-ISO-8859 Unicode character.
    static const Char PARTIAL_DIFFERENTIAL                        = Char(0x2202); //!< Non-ISO-8859 Unicode character.
    static const Char THERE_EXISTS                                = Char(0x2203); //!< Non-ISO-8859 Unicode character.
    static const Char EMPTY_SET                                   = Char(0x2205); //!< Non-ISO-8859 Unicode character.
    static const Char NABLA                                       = Char(0x2207); //!< Non-ISO-8859 Unicode character.
    static const Char ELEMENT_OF                                  = Char(0x2208); //!< Non-ISO-8859 Unicode character.
    static const Char NOT_AN_ELEMENT_OF                           = Char(0x2209); //!< Non-ISO-8859 Unicode character.
    static const Char CONTAINS_AS_MEMBER                          = Char(0x220B); //!< Non-ISO-8859 Unicode character.
    static const Char N_ARY_PRODUCT                               = Char(0x220F); //!< Non-ISO-8859 Unicode character.
    static const Char N_ARY_SUMATION                              = Char(0x2211); //!< Non-ISO-8859 Unicode character.
    static const Char MINUS_SIGN                                  = Char(0x2212); //!< Non-ISO-8859 Unicode character.
    static const Char ASTERISK_OPERATOR                           = Char(0x2217); //!< Non-ISO-8859 Unicode character.
    static const Char SQUARE_ROOT                                 = Char(0x221A); //!< Non-ISO-8859 Unicode character.
    static const Char PROPORTIONAL_TO                             = Char(0x221D); //!< Non-ISO-8859 Unicode character.
    static const Char CHAR_INFINITY                               = Char(0x221E); //!< Non-ISO-8859 Unicode character.
    static const Char ANGLE                                       = Char(0x2220); //!< Non-ISO-8859 Unicode character.
    static const Char LOGICAL_AND                                 = Char(0x2227); //!< Non-ISO-8859 Unicode character.
    static const Char LOGICAL_OR                                  = Char(0x2228); //!< Non-ISO-8859 Unicode character.
    static const Char INTERSECTION                                = Char(0x2229); //!< Non-ISO-8859 Unicode character.
    static const Char UNION                                       = Char(0x222A); //!< Non-ISO-8859 Unicode character.
    static const Char INTEGRAL                                    = Char(0x222B); //!< Non-ISO-8859 Unicode character.
    static const Char THEREFORE                                   = Char(0x2234); //!< Non-ISO-8859 Unicode character.
    static const Char TILDE_OPERATOR                              = Char(0x223C); //!< Non-ISO-8859 Unicode character.
    static const Char APPROXIMATELY_EQUAL_TO                      = Char(0x2245); //!< Non-ISO-8859 Unicode character.
    static const Char ALMOST_EQUAL_TO                             = Char(0x2248); //!< Non-ISO-8859 Unicode character.
    static const Char NOT_EQUAL_TO                                = Char(0x2260); //!< Non-ISO-8859 Unicode character.
    static const Char IDENTICAL_TO                                = Char(0x2261); //!< Non-ISO-8859 Unicode character.
    static const Char LESS_THAN_OR_EQUAL_TO                       = Char(0x2264); //!< Non-ISO-8859 Unicode character.
    static const Char GREATER_THAN_OR_EQUAL_TO                    = Char(0x2265); //!< Non-ISO-8859 Unicode character.
    static const Char SUBSET_OF                                   = Char(0x2282); //!< Non-ISO-8859 Unicode character.
    static const Char SUPERSET_OF                                 = Char(0x2283); //!< Non-ISO-8859 Unicode character.
    static const Char NOT_A_SUBSET_OF                             = Char(0x2284); //!< Non-ISO-8859 Unicode character.
    static const Char SUBSET_OF_OR_EQUAL_TO                       = Char(0x2286); //!< Non-ISO-8859 Unicode character.
    static const Char SUPERSET_OF_OR_EQUAL_TO                     = Char(0x2287); //!< Non-ISO-8859 Unicode character.
    static const Char CIRCLED_PLUS                                = Char(0x2295); //!< Non-ISO-8859 Unicode character.
    static const Char CIRCLED_TIMES                               = Char(0x2297); //!< Non-ISO-8859 Unicode character.
    static const Char UP_TACK                                     = Char(0x22A5); //!< Non-ISO-8859 Unicode character.
    static const Char DOT_OPERATOR                                = Char(0x22C5); //!< Non-ISO-8859 Unicode character.
    static const Char LEFT_CEILING                                = Char(0x2308); //!< Non-ISO-8859 Unicode character.
    static const Char RIGHT_CEILING                               = Char(0x2309); //!< Non-ISO-8859 Unicode character.
    static const Char LEFT_FLOOR                                  = Char(0x230A); //!< Non-ISO-8859 Unicode character.
    static const Char RIGHT_FLOOR                                 = Char(0x230B); //!< Non-ISO-8859 Unicode character.
    static const Char LEFT_POINTING_ANGLE_BRACKET                 = Char(0x2329); //!< Non-ISO-8859 Unicode character.
    static const Char RIGHT_POINTING_ANGLE_BRACKET                = Char(0x232A); //!< Non-ISO-8859 Unicode character.
    static const Char LOZENGE                                     = Char(0x25CA); //!< Non-ISO-8859 Unicode character.
    static const Char BLACK_SPADE_SUIT                            = Char(0x2660); //!< Non-ISO-8859 Unicode character.
    static const Char BLACK_CLUB_SUIT                             = Char(0x2663); //!< Non-ISO-8859 Unicode character.
    static const Char BLACK_HEART_SUIT                            = Char(0x2665); //!< Non-ISO-8859 Unicode character.
    static const Char BLACK_DIAMOND_SUIT                          = Char(0x2666); //!< Non-ISO-8859 Unicode character.
}