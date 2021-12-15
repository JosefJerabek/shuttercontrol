#include "../libraries/shutter_unit/shutter_unit.h"
#include "../libraries/shutter_unit/platform_pc.h"

#include "../libraries/shutter_unit/global.h"

#define SWITCH_UP_PIN   12
#define SWITCH_DOWN_PIN 13
#define POWER_UP_PIN     8
#define POWER_DOWN_PIN   9
#define STATE_PIN_0  4
#define STATE_PIN_1  3
#define STATE_PIN_2  2
#define EVENT_PIN_0  1
#define EVENT_PIN_1  0

const int PressedTimeoutMs = 1200;       // za jak dlouho od stisku udalost PRESSED
const unsigned long PullTimeMs = 60000;  // za jak dlouho sjede / vyjede žaluzie 
const unsigned long OpenTimeMs =   500;  // potřebný čas na pootevření žaluzie sjeté dolů


/// Scénář pro natáčení
PlatformPc::InputSwitching scenaryRotate()
{
    PlatformPc::InputSwitching inputSwitching;
    
    inputSwitching.TimeStepMs = 1000;    
    inputSwitching.Values[inputSwitching.ValuesSize++] = IoState::IO_NONE;  
    inputSwitching.Values[inputSwitching.ValuesSize++] = IoState::IO_UP;  
    inputSwitching.Values[inputSwitching.ValuesSize++] = IoState::IO_NONE;  
    inputSwitching.Values[inputSwitching.ValuesSize++] = IoState::IO_DOWN;  
    inputSwitching.Values[inputSwitching.ValuesSize++] = IoState::IO_NONE;  

    return inputSwitching;
}


/// Scénář pro sjetí a vyjetí
PlatformPc::InputSwitching scenaryPullDownUp(){

    PlatformPc::InputSwitching inputSwitching;
    
    inputSwitching.TimeStepMs = 1000;    

    inputSwitching.Values[1] = IoState::IO_UP;  
    inputSwitching.Values[2] = IoState::IO_UP;
    inputSwitching.Values[3] = IoState::IO_UP;

    inputSwitching.Values[70] = IoState::IO_DOWN;
    inputSwitching.Values[71] = IoState::IO_DOWN;
    inputSwitching.Values[72] = IoState::IO_DOWN;
    
    inputSwitching.ValuesSize = 150;
    
    return inputSwitching;

}


int main() {
    
    const PlatformIf::Pinout pinout(10, 11, 100, 101);
    
    //const PlatformPc::InputSwitching inputSwitching = scenaryRotate();
    const PlatformPc::InputSwitching inputSwitching = scenaryPullDownUp();
    
    PlatformPc * platform = new PlatformPc(pinout, inputSwitching);
        
    ShutterUnit shutterControl(platform, PressedTimeoutMs, PullTimeMs, OpenTimeMs, 0);
 
    shutterControl.Setup();
    
    for (int i=0; i < inputSwitching.ValuesSize; ++i) {
        shutterControl.Loop();
        platform->DoStep();
    }  
    
    return 0;
}