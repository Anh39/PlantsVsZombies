#include "loadbar.h"
#include <math.h>
using namespace std;

LoadBar::LoadBar() {
    this->Name = "LoadBar";
    this->textDelay = 1;
    this->textTime = 0;
    this->maxDotCount = 3;
    this->dotCount = 0;
    this->loadingText = "Loading";
    this->loading = false;
    this->ballSize = Vector2(50, 50);

    this->dirtPart = new TextureRect();
    Texture* dirtTexture = new Texture("asset/menu/LoadBar_dirt.png");
    this->dirtPart->texture = dirtTexture;
    this->dirtPart->position = Vector2(0, 0);
    this->dirtPart->size = Vector2(500, 100);

    this->grassPart = new ProgressRect();
    Texture* grassTexture = new Texture("asset/menu/LoadBar_grass.png");
    this->grassPart->texture = grassTexture;
    this->grassPart->position = Vector2(0, 0);
    this->grassPart->size = Vector2(480, 25);

    this->loadingTextRect = new TextRect();
    this->loadingTextRect->SetText(this->loadingText);
    this->loadingTextRect->SetColor(Color(255, 0, 0));
    this->loadingTextRect->position = Vector2(100, 25);
    this->loadingTextRect->size = Vector2(250, 40);

    this->grassBall = new TextureRect();
    Texture* grassBallTexture = new Texture("asset/menu/SodRollCap.png");
    this->grassBall->texture = grassBallTexture;
    this->grassBall->position = this->grassPart->position;
    this->grassBall->size = this->ballSize;
    this->grassBall->position.y = -this->grassBall->size.y+25;

    this->AddChildren(this->dirtPart);
    this->AddChildren(this->grassPart);
    this->AddChildren(this->grassBall);
    this->AddChildren(this->loadingTextRect);
}
LoadBar::~LoadBar() {

}
void LoadBar::Update(float delta) {
    if (loading) {
        this->textTime += delta;
        if (this->textTime >= this->textDelay) {
            this->textTime = 0;
            this->dotCount += 1;
            if (this->dotCount > this->maxDotCount) {
                this->dotCount = 0;
            }
            std::string loadingText = this->loadingText;
            for(int i=0 ; i<this->dotCount; i++) {
                loadingText += ".";
            }
            this->loadingTextRect->SetText(loadingText);
            this->loadingTextRect->size.x = 250+dotCount*21;
        }
    } else {
        Rect dirtRect = this->dirtPart->GetRect();
        dirtRect.SetPosition(this->dirtPart->GetAbsolutePosition());
        if (dirtRect.Contain(MouseEvent::Position())) {
            this->loadingTextRect->SetColor(Color(255, 255, 0));
            if (MouseEvent::JustPressed(MouseType::MouseLeft)) {
                if (this->startGameFunction) {
                    this->startGameFunction();
                }
            }
        } else {
            this->loadingTextRect->SetColor(Color(255, 0, 0));
        }
    }

}
void LoadBar::Start() {
    this->loadingTextRect->SetText(this->loadingText);
    this->loading = true;
    this->grassBall->isVisible = true;
}
void LoadBar::Progress(float percent) {
    if (percent > 1) percent = 1;
    if (percent < 0) percent = 0;
    this->grassPart->Progress(percent);
    this->grassBall->position.x = this->grassPart->size.x*percent-(this->ballSize.x/2*(2-percent));
    this->grassBall->size = this->ballSize*(2-percent);
    this->grassBall->position.y = -this->grassBall->size.y+25;
    if (percent >= 1) {
        this->grassBall->isVisible = false;
    } else {
        this->grassBall->isVisible = true;
    }
}
void LoadBar::Stop() {
    this->loadingTextRect->SetText("Start game");
    this->loadingTextRect->size.x = 200;
    this->loading = false;
    this->grassBall->isVisible = false;
}