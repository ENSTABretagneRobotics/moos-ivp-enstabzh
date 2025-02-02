/************************************************************/
/*    FILE: Pololu.h
/*    ORGN: ENSTA Bretagne Robotics - moos-ivp-enstabretagne
/*    AUTH: Simon Rohou
/*    DATE: 2015
/************************************************************/

class Pololu;

#ifndef Pololu_HEADER
#define Pololu_HEADER

//#include <QObject>

class Pololu/* : public QObject*/
{
  //Q_OBJECT

  public:
    Pololu(std::string device_name);
    ~Pololu();
    
    bool isReady();
    bool isReady(std::string &error_message);

  //public slots:
    bool turnOnRelay(int id, bool turned_on = true);
    bool turnOnBistableRelay(int id_on, int id_off, bool turned_on = true);
    bool emitBips(int bip_number = 1);
    bool setLeftThrusterValue(double value);
    bool setRightThrusterValue(double value);
    bool setVerticalThrusterValue(double value);
    bool setAllThrustersValue(double value);
    void bipOnStartUp();
    void bipOnExit();
    void bipError();

  protected:
    void buzzOn();
    void buzzOff();
    bool setThrusterValue(int id, double value);
    bool setTarget(unsigned char channel, unsigned short target);
    void setErrorMessage(std::string message);
    
  protected:
    int m_pololu;
    bool m_error;
    std::string m_error_message;
};

#endif 