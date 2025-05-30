#include <mpg123.h>
#include <portaudio.h>
#include <iostream>
#include <string>
#include <vector>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 512

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./mp3player <file.mp3>\n";
        return 1;
    }

    std::string filename = argv[1];

    mpg123_init();
    mpg123_handle *mh = mpg123_new(NULL, NULL);
    mpg123_open(mh, filename.c_str());

    long rate;
    int channels, encoding;
    mpg123_getformat(mh, &rate, &channels, &encoding);
    mpg123_format_none(mh);
    mpg123_format(mh, rate, channels, encoding);

    size_t buffer_size = mpg123_outblock(mh);
    std::vector<unsigned char> buffer(buffer_size);
    size_t done = 0;

    Pa_Initialize();
    PaStream *stream;
    Pa_OpenDefaultStream(&stream, 0, channels, paInt16, rate, FRAMES_PER_BUFFER, nullptr, nullptr);
    Pa_StartStream(stream);

    while (mpg123_read(mh, buffer.data(), buffer_size, &done) == MPG123_OK)
    {
        Pa_WriteStream(stream, buffer.data(), done / (channels * 2));
    }

    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();
    mpg123_close(mh);
    mpg123_delete(mh);
    mpg123_exit();

    std::cout << "Playback finished.\n";

    return 0;
}
