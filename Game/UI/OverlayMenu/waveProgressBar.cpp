#include "waveProgressBar.h"
#include <math.h>
using namespace std;


WaveProgressBar::WaveProgressBar() {
    this->frontTextureRect = new TextureRect();
    this->frontTextureRect->texture = new Texture("asset/menu/FlagMeterFront.png");
    this->backTextureRect = new ProgressRect();
    this->backTextureRect->texture = new Texture("asset/menu/FlagMeterBack.png");
    this->zombieHead = new TextureRect();
    this->zombieHead->texture = new Texture("asset/menu/FlagMeterZombie.png");

    this->AddChildren(this->frontTextureRect);
    this->AddChildren(this->backTextureRect);
    this->AddChildren(this->zombieHead);


    this->handlers = vector<TextureRect*>();
    this->flags = vector<TextureRect*>();

    this->progress = 0;
    this->numWave = 0;
}

WaveProgressBar::~WaveProgressBar() {

}
void WaveProgressBar::SetSize(const Vector2& size) {
    Vector2 partSize = Vector2(size.y/2, size.y/2);
    this->size = size;
    this->frontTextureRect->size = size;
    this->backTextureRect->size = size;
    this->zombieHead->position.y = partSize.y/2;
    this->zombieHead->size = partSize;

    if (this->numWave == 0) return;
    float step = size.x/this->numWave;
    for(int i=0; i<this->numWave; i++) {
        TextureRect* handler = this->handlers[i];
        TextureRect* flag = this->flags[i];
        handler->position.y = partSize.y/2;
        handler->size = partSize;
        flag->position.y = partSize.y/2;
        flag->size = partSize;
        handler->position.x = step*i;
        flag->position.x = step*i;
    }
}
void WaveProgressBar::SetNumWave(int numWave) {
    this->numWave = numWave;
    for (auto child : this->handlers)
    {
        child->Delete();
    }
    this->handlers.clear();
    for (auto child: this->flags) {
        child->Delete();
    }
    this->flags.clear();
    for(int i=0; i<numWave; i++) {
        TextureRect* handler = new TextureRect();
        handler->texture = new Texture("asset/menu/FlagMeterHandle.png");
        this->AddChildren(handler);
        this->handlers.push_back(handler);

        TextureRect* flag = new TextureRect();
        flag->texture = new Texture("asset/menu/FlagMeterFlag.png");
        this->AddChildren(flag);
        this->flags.push_back(flag);
    }
    this->SetSize(this->size);
}

void WaveProgressBar::SetProgress(float progress) {
    if (progress < 0) progress = 0;
    if (progress > 1) progress = 1;
    progress = 1.0-progress;
    this->progress = progress;
    this->backTextureRect->Progress(progress);
    this->zombieHead->position.x = this->size.x * progress - this->zombieHead->size.x / 2;

    int flagDown = ceil(progress*this->numWave);
    for(int i=0; i<flagDown; i++) {
        this->flags[i]->position.y = this->size.y/4;
    }
    for(int i=flagDown; i<this->numWave; i++) {
        this->flags[i]->position.y = 0;
    }
}
Vector2 WaveProgressBar::GetSize() {
    return this->size;
}
int WaveProgressBar::GetNumWave() {
    return this->numWave;
}

float WaveProgressBar::GetProgress() {
    return 1.0-this->progress;
}

void WaveProgressBar::Update(float delta) {
    if (KeyboardEvent::IsPressing(KeyboardType::F5)) {
        this->SetProgress(this->GetProgress()+0.1*delta);
    }
}
