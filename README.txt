HOW DOES THE APPLICATION WORK AND IS ANYTHING NEEDED FOR IT TO RUN PROPERLY?

Our game is based on one central window that rotates between different widgets like StartScreen and BossLevel, and connects the widgets based on the order we decided best for the game’s timeline. In order to run the game, no resources external to Qt are required, since everything is already included in the project files. The project file also contains a resource file (.qrc) that outlines our .jpg(s), .mp3(s), and .png(s). That file is required to run the project correctly, and if eliminated, errors will occur. Qt 5.14.1 MinGW 32-bit is required to run the game. Qt 5.14.1 MinGW 64-bit will work as well.
Clean the program in case any errors occur.


APP INSTRUCTIONS

Upon opening the main Qt project file (.pro), press the green “Run” button to build and start the application. The first screen you will encounter is the start (title) screen. The timeline of the application is laid out in an intuitive fashion, allowing you to proceed to the instructions of the game, the “map” allowing for the game’s level selection, and the gameplay itself. Whether the player loses or wins, appropriate screens are displayed.

For the purpose of evaluation, all levels are unlocked from the beginning for convenient access. In a developers' final release, only the WaterNation level would be unlocked at first. Once beaten, EarthNation level would be unlocked. Once that is beaten, the final boss (FireNation) level would be unlocked.

For WaterNation level, only the standard bullet (fired with Space key) is unlocked.
For EarthNation level, the water bomb (fired with B key) and standard bullet (fired with Space key) are unlocked.
For FireNation level, the invincibility ability (activated with V key), water bomb (fired with B key), and standard bullet (fired with Space key) are unlocked.

Press the X on the top corner to quit the game.