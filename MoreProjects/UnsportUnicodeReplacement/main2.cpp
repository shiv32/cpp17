#include <iostream>
#include <unordered_map>
#include <string>
#include <codecvt>
#include <locale>

// Replacement map: Unicode to ASCII string
#include <unordered_map>
#include <string>

std::unordered_map<char32_t, std::string> unicode_fallback = {
    // Greek Capital Letters
    {0x0391, "Alpha"},
    {0x0392, "Beta"},
    {0x0393, "Gamma"},
    {0x0394, "Delta"},
    {0x0395, "Epsilon"},
    {0x0396, "Zeta"},
    {0x0397, "Eta"},
    {0x0398, "Theta"},
    {0x0399, "Iota"},
    {0x039A, "Kappa"},
    {0x039B, "Lambda"},
    {0x039C, "Mu"},
    {0x039D, "Nu"},
    {0x039E, "Xi"},
    {0x039F, "Omicron"},
    {0x03A0, "Pi"},
    {0x03A1, "Rho"},
    {0x03A3, "Sigma"},
    {0x03A4, "Tau"},
    {0x03A5, "Upsilon"},
    {0x03A6, "Phi"},
    {0x03A7, "Chi"},
    {0x03A8, "Psi"},
    {0x03A9, "Omega"},

    // Greek Small Letters
    {0x03B1, "alpha"},
    {0x03B2, "beta"},
    {0x03B3, "gamma"},
    {0x03B4, "delta"},
    {0x03B5, "epsilon"},
    {0x03B6, "zeta"},
    {0x03B7, "eta"},
    {0x03B8, "theta"},
    {0x03B9, "iota"},
    {0x03BA, "kappa"},
    {0x03BB, "lambda"},
    {0x03BC, "mu"},
    {0x03BD, "nu"},
    {0x03BE, "xi"},
    {0x03BF, "omicron"},
    {0x03C0, "pi"},
    {0x03C1, "rho"},
    {0x03C3, "sigma"},
    {0x03C4, "tau"},
    {0x03C5, "upsilon"},
    {0x03C6, "phi"},
    {0x03C7, "chi"},
    {0x03C8, "psi"},
    {0x03C9, "omega"},

    // Common math/logic symbols
    {0x00B1, "+-"},           // ±
    {0x00B0, "deg"},          // °
    {0x221E, "infinity"},     // ∞
    {0x2260, "!="},           // ≠
    {0x2264, "<="},           // ≤
    {0x2265, ">="},           // ≥
    {0x2248, "~="},           // ≈
    {0x2192, "->"},           // →
    {0x2190, "<-"},           // ←
    {0x2022, "*"},            // •
    {0x03D5, "phi"},          // ϕ (variant)
};


std::string replace_unsupported_unicode(const std::string &input_utf8)
{
    // Convert UTF-8 to UTF-32
    std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
    std::u32string utf32_str = converter.from_bytes(input_utf8);

    std::string output;

    for (char32_t ch : utf32_str)
    {
        if (ch < 128)
        {
            // ASCII-safe
            output += static_cast<char>(ch);
        }
        else if (unicode_fallback.count(ch))
        {
            output += unicode_fallback[ch]; // Replace with mapped text
        }
        else
        {
            output += "[?]"; // Unknown replacement
        }
    }

    return output;
}

int main()
{
    system("clear && printf '\e[3J'"); // clean the terminal before output in linux

    std::string input = "Voltage = 5V ±0.2V; Resistance = 10Ω; Angle = 180°; π ≈ 3.14";

    std::string safe = replace_unsupported_unicode(input);

    std::cout << "input:     " << input << std::endl;
    std::cout << "Converted: " << safe << std::endl;

    // Output: Converted: Voltage = 5V +-0.2V; Resistance = 10[Omega]; Angle = 180[?]; pi ≈ 3.14

    // Use `safe` string in HPDF_Page_ShowText()
}
