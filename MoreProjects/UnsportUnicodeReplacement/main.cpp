#include <string>
#include <unordered_map>
#include <codecvt>
#include <locale>
#include <cctype>
#include <iostream>

// Fallback map for unsupported Unicode characters
std::unordered_map<char32_t, std::string> unicode_fallback = {
    {0x03A9, "Omega"},    // Ω
    {0x03C0, "pi"},       // π
    {0x03BC, "u"},        // µ
    {0x00B1, "+-"},       // ±
    {0x00B0, "deg"},      // °
    {0x221E, "infinity"}, // ∞
    {0x2248, "~="},       // ≈
    {0x2260, "!="},       // ≠
    {0x2264, "<="},       // ≤
    {0x2265, ">="},       // ≥
};

// Converts UTF-8 input to a PDF-safe string with spacing-aware fallbacks
std::string replace_unsupported_unicode(const std::string &input_utf8)
{
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    std::u32string utf32 = converter.from_bytes(input_utf8);
    std::string output;

    char lastChar = '\0'; // Track previous character (for spacing logic)

    for (char32_t ch : utf32)
    {
        if (ch < 128)
        {
            // ASCII character
            output += static_cast<char>(ch);
            lastChar = static_cast<char>(ch);
        }
        else if (unicode_fallback.count(ch))
        {
            const std::string &replacement = unicode_fallback[ch];
            if (std::isalnum(static_cast<unsigned char>(lastChar)))
            {
                output += ' '; // Insert space before replacement
            }
            output += replacement;
            lastChar = replacement.back(); // Update with last char of replacement
        }
        else
        {
            // Unknown Unicode character → replace with [?]
            if (std::isalnum(static_cast<unsigned char>(lastChar)))
            {
                output += ' ';
            }
            output += "[?]";
            lastChar = ']';
        }
    }

    return output;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::string input = "Voltage = 5V ±0.2V; Resistance = 10Ω; Angle = 180°; π ≈ 3.14";

    std::string safe_text = replace_unsupported_unicode(input);

    std::cout << safe_text << std::endl;

    return 0;
}