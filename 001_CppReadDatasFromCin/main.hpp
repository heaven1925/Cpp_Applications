#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <iostream>
#include <string>

using namespace std;

#define SIZEOFBUFFER        6
#define SIZEOFTEMPCLASS     2   /* Owen & Heater */

#define IDEAL_OWEN_CONST    1
#define IDEAL_HEATER_CONST  1

typedef enum
{
  METAL_BOX = 0,
  PLASTIC_BOX ,
  OPEN_BOX,
} IndoorType;

typedef enum
{
  OPEN_AREA = 0,
  FACTORY_AREA,
  HOME,
} OutdoorType;

enum
{
    OWEN = 0,
    HEATER ,
};

/*
* Temperature Main Class
*/
class temperatureVal
{

private:
  static int inputBuffer[10];
  string outputMsg;
public:
  /* Destructor */
  virtual ~temperatureVal() {};
  /* Temp forms */
  virtual double returnTemp( int inputBuffer[] , int inputCount ) = 0;
};


/*
* Owen Temperature Class
*/
class owenTemperature:public temperatureVal
{

private:
  const float owenTempConst = IDEAL_OWEN_CONST;
  /********************************/
  int typeConst;
  IndoorType type;
  /********************************/
public:
  /* Constructor */
  owenTemperature (double _typeConst, IndoorType _type);
  /************************************/
  double returnTemp( int inputBuffer[] , int inputCount );
};

/*
* Heater Temperature class
*/
class heaterTemperature:public temperatureVal
{

private:
  const float   heaterTempConst = IDEAL_HEATER_CONST;
  /********************************/
  int           typeConst;
  OutdoorType   type;
  /********************************/
public:
  /* Constructor */
  heaterTemperature (double _typeConst, OutdoorType _type);
  /************************************/
  double returnTemp( int inputBuffer[] , int inputCount );
    
};














#endif				/* __MAIN_HPP__ */
