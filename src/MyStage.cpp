#include "MyStage.h"

MyStage::MyStage(AudioSensor *audioSensor, State *state) {
    PhysicalStrip *strip = new PhysicalStrip(array, STRIP_DENSITY);

    addStrip(strip);

    addFx(
        new Rainbow(strip, state)
    );

    addFx(
        new DeepSpace(strip, audioSensor->mono, state, 0x800000, 0x000020)
    );

    setCycleSpeedFx(new CycleSpeed(strip, state));
    setSpeedMeterFx(new SpeedMeter(strip, state));

    setMicGainMeterFx(new MicGainMeter(strip, audioSensor->mono, audioSensor));
    setInputLevelMeterFx(new InputLevelMeter(strip, audioSensor->mono, audioSensor));

    FastLED.addLeds<WS2812SERIAL, STRIP_PIN, BRG>(array, array.size());
    FastLED.setMaxPowerInMilliWatts(1000 * MAX_WATTS);
}
