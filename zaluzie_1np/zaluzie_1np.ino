#include <shutter_unit.h>
#include <platform_arduino.h>
#include <bus_pins_uno.h>

const int PressedTimeoutMs = 1200;       // za jak dlouho od stisku udalost PRESSED
const unsigned long PullTimeMs = 60000;  // za jak dlouho sjede / vyjede žaluzie 
const unsigned long OpenTimeMs =   500;  // potřebný čas na pootevření žaluzie sjeté dolů

// Obyvak leve jizni okno
PlatformIf::Pinout zapojeniObyvakVlevo(
	BusDigital10Pin::D10, 
	BusDigital10Pin::D11,
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

    
ShutterUnit zaluzieObyvakVlevo(platformObyvakVlevo, PressedTimeoutMs, PullTimeMs, OpenTimeMs, 0);
ShutterUnit zaluzieObyvakVpravo(platformObyvakVpravo, PressedTimeoutMs, PullTimeMs, OpenTimeMs, 1);
ShutterUnit zaluzieObyvakTerasa(platformObyvakTerasa, PressedTimeoutMs, PullTimeMs, OpenTimeMs, 2);
ShutterUnit zaluziePracovna(platformPracovna, PressedTimeoutMs, PullTimeMs, OpenTimeMs, 3);


void setup() {

    // POZOR: jen pro debug -> zapisuje do vstupů prvni zaluzie
    // Serial.begin(9600);  // debug prints inside
        
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
}
