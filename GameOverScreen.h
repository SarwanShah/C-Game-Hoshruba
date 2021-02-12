#pragmaonce
#include "Screen.h"
#include "LTexture.h"

class GameOverScreen: public Screen
{
private:
    LTexture* m_gSpriteSheetTexture;
    Button* Btn;
public:
    bool init();
    void LoadMedia();
    void Close();
};
