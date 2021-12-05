#include <shutter_control.h>
#include <platform_arduino.h>
#include <bus_pins_uno.h>

const unsigned int LoopDelayMs = 10;
const int PressedTimeoutMs = 1200; // za jak dlouho od stisku udalost PRESSED

// Obyvak leve jizni okno
PlatformIf::Pinout zapojeniObyvakVlevo(
	BusDigital8Pin::D00, 
	BusDigital8Pin::D01,
	BusAnalog::A0, 
	BusAnalog::A1
);
  
// Obyvak prave jizni okno
PlatformIf::Pinout zapojeniObyvakVpravo(
	BusDigital8Pin::D02, 
	BusDigital8Pin::D03,
	BusAnalog::A2, 
	BusAnalog::A3
);

// Obyvak smer terasa
PlatformIf::Pinout zapojeniObyvakTerasa(
	BusDigital8Pin::D04, 
	BusDigital8Pin::D05,
	BusAnalog::A4, 
	BusAnalog::A5
);

PlatformIf::Pinout zapojeniPracovna(
	BusDigital8Pin::D06, 
	BusDigital8Pin::D07,
	BusDigital10Pin::D08,
	BusDigital10Pin::D09
);

PlatformArduino * platformObyvakVlevo = new PlatformArduino(zapojeniObyvakVlevo);
PlatformArduino * platformObyvakVpravo = new PlatformArduino(zapojeniObyvakVpravo);
PlatformArduino * platformObyvakTerasa = new PlatformArduino(zapojeniObyvakTerasa);
PlatformArduino * platformPracovna = new PlatformArduino(zapojeniPracovna);

    
ShutterControl zaluzieObyvakVlevo(platformObyvakVlevo, PressedTimeoutMs);
ShutterControl zaluzieObyvakVpravo(platformObyvakVpravo, PressedTimeoutMs);
ShutterControl zaluzieObyvakTerasa(platformObyvakTerasa, PressedTimeoutMs);
ShutterControl zaluziePracovna(platformPracovna, PressedTimeoutMs);


void setup() {

  	zaluzieObyvakVlevo.Setup();
	zaluzieObyvakVpravo.Setup();
	zaluzieObyvakTerasa.Setup();
	zaluziePracovna.Setup();

}


void loop() {

  	zaluzieObyvakVlevo.Loop();
	zaluzieObyvakVpravo.Loop();
	zaluzieObyvakTerasa.Loop();
	zaluziePracovna.Loop();

	delay(LoopDelayMs);
}
