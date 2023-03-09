#ifndef __MAIN_HPP__
#define __MAIN_HPP__

#include <iostream>
#include <string>

using namespace std;

/*
* Size of readed data homework wants 6 but it can be pre-defined 
*/
#define SIZEOFBUFFER        10

/*
* Size of Class depents to enumator
*/
#define SIZEOFTEMPCLASS     2   /* Owen & Heater */

enum
{
    OWEN = 0,
    HEATER ,
};

/*
* Indoor Type temp sensor enumarator
*/
typedef enum
{
  METAL_BOX = 0,
  PLASTIC_BOX ,
  OPEN_BOX,
} IndoorType;

/*
* Outdoot Type temp sensor enumarator
*/
typedef enum
{
  OPEN_AREA = 0,
  FACTORY_AREA,
  HOME,
} OutdoorType;



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
  virtual double returnTemp( int inputBuffer[] ) = 0;
};


/*
* Owen Temperature Class
*/
class owenTemperature:public temperatureVal
{

private:
  const float owenTempConst = 1.05;   /* homework is has to be but just written for Cpp review */
  /********************************/
  int typeConst;
  IndoorType type;
  /********************************/
public:
  /* Constructor */
  owenTemperature (double _typeConst, IndoorType _type);
  /************************************/
  double returnTemp( int inputBuffer[] );
};

/*
* Heater Temperature class
*/
class heaterTemperature:public temperatureVal
{

private:
  const float   heaterTempConst = 1.15; /* homework is has to be but just written for Cpp review */
  /********************************/
  int           typeConst;
  OutdoorType   type;
  /********************************/
public:
  /* Constructor */
  heaterTemperature (double _typeConst, OutdoorType _type);
  /************************************/
  double returnTemp( int inputBuffer[] );
    
};














#endif				/* __MAIN_HPP__ */
