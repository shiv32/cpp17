
#include <iostream>

std::string replace_unicode_with_ascii(const std::string &input)
{
    std::string output;
    for (size_t i = 0; i < input.size(); ++i)
    {
        unsigned char c = input[i];

        if ((unsigned char)c == 0xCE && i + 1 < input.size())
        {
            unsigned char next = input[i + 1];
            if (next == 0xA9)
            { // U+03A9 → Ω
                output += "[Omega]";
                ++i;
                continue;
            }
            else if (next == 0xC0)
            { // U+03C0 → π
                output += "pi";
                ++i;
                continue;
            }
        }
        else if ((unsigned char)c == 0xE2 && i + 2 < input.size())
        {
            if ((unsigned char)input[i + 1] == 0x88 && (unsigned char)input[i + 2] == 0x9E)
            { // ∞
                output += "infinity";
                i += 2;
                continue;
            }
        }

        // Default copy
        output += c;
    }
    return output;
}

int main()
{

    system("clear && printf '\e[3J'"); // clean the terminal before output in linux
    
    std::string text = "Voltage = 5V ±0.2V; Resistance = 10Ω";

    std::string safe_text = replace_unicode_with_ascii(text);

    std::cout << safe_text << std::endl;

    return 0;
}