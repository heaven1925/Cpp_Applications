/*******************************************************************************
  * @file    main.cpp
  * @author	 Atakan ERTEKiN
  * @version V1.0.0
  * @date	 09.03.2023
  * @rev     V1.0.0
  * @brief	 Sensor read homework in order to do review OOP Cpp Architecture
********************************************************************************/

#include "main.hpp"

owenTemperature::owenTemperature (double _typeConst, IndoorType _type)
{
    this->type = _type;
    
    switch(type)
    {
        case  METAL_BOX     : this->typeConst = _typeConst * 1.11 ; break;
        case  PLASTIC_BOX   : this->typeConst = _typeConst * 1.22 ; break;
        case  OPEN_BOX      : this->typeConst = _typeConst * 1.33 ; break;
        default:              this->typeConst = _typeConst * 1    ; break;
    }
}

heaterTemperature::heaterTemperature (double _typeConst, OutdoorType _type)
{
    this->type = _type;
    
    switch(type)
    {
        case  OPEN_AREA     : this->typeConst = _typeConst * 1.44 ; break;
        case  FACTORY_AREA  : this->typeConst = _typeConst * 1.55 ; break;
        case  HOME          : this->typeConst = _typeConst * 1.66 ; break;
        default:              this->typeConst = _typeConst * 1    ; break;
    }
    
}


double owenTemperature::returnTemp( int inputBuffer[] )
{
    double temperatureHandle = 0;
    
    for(int loopVal = 0; loopVal < SIZEOFBUFFER; loopVal++)
    {
        temperatureHandle += inputBuffer[loopVal];
    }
    
    return ( ( temperatureHandle / 10.0 ) * this->owenTempConst ) ;
}

double heaterTemperature::returnTemp( int inputBuffer[] )
{
    double temperatureHandle = 0;
    
    for(int loopVal = 0; loopVal < SIZEOFBUFFER; loopVal++)
    {
        temperatureHandle += inputBuffer[loopVal];
    }
    
    return ( ( temperatureHandle / 10.0 ) * this->heaterTempConst ) ;
}

/* State Machine Configurations */
typedef enum
{
    MAINState_INIT     = 0 ,
    MAINState_ROUTINE      ,
    MAINState_PROCESS      ,
    MAINState_SUSPEND    
}MAINState_Type;

MAINState_Type MAINState = MAINState_INIT;

/* Global Variable definition for raw sensor data array */
int rawData[SIZEOFTEMPCLASS][SIZEOFBUFFER] = {0};

int main ()
{
  temperatureVal* owenTemp; 
  temperatureVal* heaterTemp;
 
  while(1)
  {
      if( MAINState_SUSPEND == MAINState )
      {
          cout << "Main code going to suspend ! " << endl;
          break;
      }
      else
      {
        switch( MAINState )
        {
          case MAINState_INIT : 
          
            /* Create object for temperature */
            owenTemp      = new owenTemperature( 2.55 , OPEN_BOX );
            heaterTemp    = new heaterTemperature( 3.22 , FACTORY_AREA );
          
            cout << "Init succesfull Class 0 is OWEN , Class 1 is HEATER " << endl;
          
            MAINState = MAINState_ROUTINE;
          
          break;
          
          case MAINState_ROUTINE :
            
            /* Get sensor parameters with scanf */
            cout << "Routine State On Going" << endl;
            
            for( int classCount = 0; classCount < SIZEOFTEMPCLASS ; classCount++)
            {
                if( classCount == OWEN )
                {
                    cout << "Enter 10 Owen Parameters " << endl;
                }
                else if( classCount == HEATER )
                {
                    cout << "Enter 10 Heater Parameters " << endl;
                }
                else
                {
                    cout << "Class Error " << endl;
                    MAINState = MAINState_SUSPEND;
                    break;
                }
                
                for(int loopVal = 0 ; loopVal < SIZEOFBUFFER ; loopVal++)
                {
                    cout << "Enter Class " << classCount << " Raw Data " << loopVal << " = " << endl;
                    /* Enter Raw Datas */
                    cin >> rawData[classCount][loopVal];
                    
                    if( rawData[classCount][loopVal] == -1 )
                    { /* Check -1 parameter entering situation */
                        cout << "-1 val has been entered !" << endl;
                        MAINState = MAINState_SUSPEND;
                        break;
                    }
                    else if( rawData[classCount][loopVal] < 0 || rawData[classCount][loopVal] > 255 )
                    { /* check overflow condition in order to 8 bit adc val */
                        cout << "Sensor analog val entered !" << endl;
                        MAINState = MAINState_SUSPEND;
                        break;
                    }
                    else
                    { /* keep continue gets data's */
                        continue;
                    }
                }
                
             if( MAINState_SUSPEND == MAINState )
             { /* -1 val entered while data collecting, break data handling */
                 break;
             }
             
            }
            
            if( MAINState_SUSPEND == MAINState )
            { /* Sensor data gathering has been failed execute state machine */
                 break;
            }
            else
            { /* All sensor data's are gathered go process state */
                 MAINState = MAINState_PROCESS;
            }
            
            
          break;
          
          case MAINState_PROCESS :
          
          /* Process State Activated */
          cout << "Process State is Running !" << endl;
          
          /* Process State for print variables */
          cout << "OWEN TEMP SENSOR VALUE   = " << owenTemp->returnTemp( &rawData[OWEN][0] )   << endl;
          cout << "HEATER TEMP SENSOR VALUE = " << heaterTemp->returnTemp( &rawData[HEATER][0] ) << endl;
          
          MAINState = MAINState_ROUTINE;
          
          break;
          
          default:
          
          /* Undefined state gets code suspend state */
          MAINState = MAINState_SUSPEND;
          
          break;
        }
        
      }    
  }
  
  cout << "Program Done !" << endl;
  
  return 0;
}
