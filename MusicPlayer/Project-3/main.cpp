#include <QCoreApplication>
#include <QMediaPlayer>
#include <QUrl>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QString appDir = QCoreApplication::applicationDirPath();
    // QString musicDir = appDir + "/../music/test2.wav";
    QString musicDir = appDir + "/../music/test.mp3";

    // if (argc < 2)
    // {
    //     std::cerr << "Usage: ./musicPlayer <file.mp3>\n";
    //     return 1;
    // }

    QMediaPlayer player;

    player.setMedia(QUrl::fromLocalFile(musicDir));
    // player.setMedia(QUrl::fromLocalFile(QString::fromUtf8(argv[1])));

    player.setVolume(100); // 0 - 100
    player.play();

    return app.exec();
}
