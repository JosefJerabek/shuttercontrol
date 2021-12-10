#include <shutter_control.h>
#include <platform_arduino.h>
#include <bus_pins_uno.h>

const unsigned int LoopDelayMs = 10;
const int PressedTimeoutMs = 1200; // za jak dlouho od stisku udalost PRESSED
const unsigned long PullTimeMs = 60000; // za jak dlouho sjede / vyjede žaluzie 

// Pokoj levý, východní žaluzie 
PlatformIf::Pinout zapojeniPokojLevyVychod(
	BusDigital8Pin::D00, 
	BusDigital8Pin::D01,
	BusDigital10Pin::D10,
	BusDigital10Pin::D11
);

// Pokoj levý, jižní žaluzie 
PlatformIf::Pinout zapojeniPokojLevyJih(
	BusDigital8Pin::D02, 
	BusDigital8Pin::D03,
	BusDigital10Pin::D12,
	BusDigital10Pin::D13
);

// Pokoj pravý, jižní žaluzie 
PlatformIf::Pinout zapojeniPokojPravyJih(
	BusDigital8Pin::D04, 
	BusDigital8Pin::D05,
	BusAnalog::A0, 
	BusAnalog::A1
);

// Pokoj pravý, západní žaluzie 
PlatformIf::Pinout zapojeniPokojPravyZapad(
	BusDigital8Pin::D06, 
	BusDigital8Pin::D07,
	BusAnalog::A2, 
	BusAnalog::A3
);

// Koupelna
PlatformIf::Pinout zapojeniKoupelna(
	BusDigital10Pin::D08, 
	BusDigital10Pin::D09,
	BusAnalog::A4, 
	BusAnalog::A5
);

PlatformArduino * platformPokojLevyVychod = new PlatformArduino(zapojeniPokojLevyVychod); 
PlatformArduino * platformPokojLevyJih = new PlatformArduino(zapojeniPokojLevyJih); 
PlatformArduino * platformPokojPravyJih = new PlatformArduino(zapojeniPokojPravyJih); 
PlatformArduino * platformPokojPravyZapad = new PlatformArduino(zapojeniPokojPravyZapad); 
PlatformArduino * platformKoupelna = new PlatformArduino(zapojeniKoupelna);

ShutterControl zaluziePokojLevyVychod(platformPokojLevyVychod, PressedTimeoutMs, PullTimeMs);
ShutterControl zaluziePokojLevyJih(platformPokojLevyJih, PressedTimeoutMs, PullTimeMs);
ShutterControl zaluziePokojPravyJih(platformPokojPravyJih, PressedTimeoutMs, PullTimeMs);
ShutterControl zaluziePokojPravyZapad(platformPokojPravyZapad, PressedTimeoutMs, PullTimeMs);
ShutterControl zaluzieKoupelna(platformKoupelna, PressedTimeoutMs, PullTimeMs);

void setup() {

	zaluziePokojLevyVychod.Setup();
	zaluziePokojLevyJih.Setup();
	zaluziePokojPravyJih.Setup();
	zaluziePokojPravyZapad.Setup();
	zaluzieKoupelna.Setup();

}


void loop() {

	zaluziePokojLevyVychod.Loop();
	zaluziePokojLevyJih.Loop();
	zaluziePokojPravyJih.Loop();
	zaluziePokojPravyZapad.Loop();
	zaluzieKoupelna.Loop();

	delay(LoopDelayMs);
}
