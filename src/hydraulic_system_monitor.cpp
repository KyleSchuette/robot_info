#include <string>

class HydraulicSystemMonitor {
private:
  std::string hydraulic_oil_temperature;
  std::string hydraulic_oil_tank_fill_level;
  std::string hydraulic_oil_pressure;

public:
  HydraulicSystemMonitor() {
    hydraulic_oil_temperature = "45C";
    hydraulic_oil_tank_fill_level = "100%";
    hydraulic_oil_pressure = "250 bar";
  }

  // Individual getters
  std::string getHydraulicOilTemperature() const { return hydraulic_oil_temperature; }
  std::string getHydraulicOilTankFillLevel() const { return hydraulic_oil_tank_fill_level; }
  std::string getHydraulicOilPressure() const { return hydraulic_oil_pressure; }

  // Optional: one method to get all as formatted string
  std::string getAllHydraulicData() const {
    return "Temp: " + hydraulic_oil_temperature +
           ", Fill Level: " + hydraulic_oil_tank_fill_level +
           ", Pressure: " + hydraulic_oil_pressure;
  }
};
