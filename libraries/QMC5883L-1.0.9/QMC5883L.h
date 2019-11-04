#pragma once
#ifndef QMC5883L_H
#define QMC5883L_H

class QMC5883L {
public:
  QMC5883L();
  void init();
  void reset();
  int  ready();
  void reconfig();
  
  float readHeading();
  int readRaw( int16_t *x, int16_t *y, int16_t *z, int16_t *t );

  void resetCalibration();
  void setSamplingRate( int rate );
  void setRange( int range );
  void setOversampling( int ovl );
  float SetDeclination( int declination_degs , int declination_mins, char declination_dir );
  
private:
  int16_t xhigh, xlow;
  int16_t yhigh, ylow;
  uint8_t addr;
  uint8_t mode;
  uint8_t rate;
  uint8_t range;
  uint8_t oversampling;
    
  protected:
  float declination_offset_radians;
};

#endif
