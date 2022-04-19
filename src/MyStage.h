#ifndef MyStage_h
#define MyStage_h

#include "Stage.h"
#include "AudioSensor.h"
#include "State.h"

class MyStage : public Stage {
    private:
        const static uint16_t STRIP_COUNT = 100;
        const static uint16_t STRIP_DENSITY = 144;
        const static uint8_t STRIP_PIN = CH1_PIN;

        const static uint8_t MAX_WATTS = 10;
        
        CRGBArray<STRIP_COUNT> array;

    public:
        MyStage(AudioSensor *audioSensor, State *state);
};

#endif
