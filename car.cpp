/*----------------------------------------------------------
*				HTBLA-Leonding / Klasse: <your class>
* ---------------------------------------------------------
* Exercise Number: 5
* Title:			car.h
* Author:			Dionis Raci
* Due Date:		november 24, 2017
* ----------------------------------------------------------
* Description:
* Car abstract data type demo.
* ----------------------------------------------------------
*/

#include <stdio.h>
#include "car.h"
#define MAX_ACCELERATION_RATE_AIXAM 1.0
#define MAX_ACCELERATION_RATE_FIAT 2.26
#define MAX_ACCELERATION_RATE_JEEP 3.14
#define MIN_ACCELERATION_RATE -8
#define MAX_SPEED_AIXAM 45
#define MAX_SPEED_FIAT 170
#define MAX_SPEED_JEEP 196

int round_speed(double speed);

struct CarType{
  enum type type;
  enum color color;
  double fill_level;
  double acceleration_rate;
  double speed;
  bool rented;
};

static struct CarType A1 {AIXAM, RED, 16, 0, 0, false};
static struct CarType M1 {FIAT_MULTIPLA, GREEN, 65, 0, 0, false};
static struct CarType M2 {FIAT_MULTIPLA, BLUE, 65, 0, 0, false};
static struct CarType M3 {FIAT_MULTIPLA, ORANGE, 65, 0, 0, false};
static struct CarType J1 {JEEP, SILVER, 80, 0, 0, false};
static struct CarType J2 {JEEP, BLACK, 80, 0, 0, false};

void init(){
  A1 = {AIXAM, RED, 16, 0, 0, false};
  M1 = {FIAT_MULTIPLA, GREEN, 65, 0, 0, false};
  M2 = {FIAT_MULTIPLA, BLUE, 65, 0, 0, false};
  M3 = {FIAT_MULTIPLA, ORANGE, 65, 0, 0, false};
  J1 = {JEEP, SILVER, 80, 0, 0, false};
  J2 = {JEEP, BLACK, 80, 0, 0, false};
}
Car get_car(type x){
  Car returnCar;
  if (x == AIXAM) {
    if (!A1.rented) {
      A1.rented = true;
      returnCar = &A1;
    }
    else {return 0;}
  }
  else if (x == FIAT_MULTIPLA) {
    if (!M1.rented) {
      M1.rented = true;
      returnCar = &M1;
    }
    else if (!M2.rented) {
      M2.rented = true;
      returnCar = &M2;
    }
    else if (!M3.rented) {
      M3.rented = true;
      returnCar = &M3;
    }
    else {return 0;}
  }
  else if (x == JEEP) {
    if (!J1.rented) {
      J1.rented = true;
      returnCar = &J1;
    }
    else if (!J2.rented) {
      J2.rented = true;
      returnCar = &J2;
    }
    else {return 0;}
}
  return returnCar;
}
type get_type(Car car){
  return car->type;
}
color get_color(Car car){
  return car->color;
}
int get_fill_level(Car car){
  return car->fill_level;
}
double get_acceleration_rate(Car car){
  return car->acceleration_rate;
}
int get_speed(Car car){

  return round_speed(car->speed);
}

void accelerate(Car car){
  car->speed += car->acceleration_rate * 3.6;
  
  if (car->type == AIXAM) {
    if (car->speed > MAX_SPEED_AIXAM) {
      car->speed = MAX_SPEED_AIXAM;
    }
  }
  if (car->type == FIAT_MULTIPLA) {
    if (car->speed > MAX_SPEED_FIAT) {
      car->speed = MAX_SPEED_FIAT;
    }
  }
  if (car->type == JEEP) {
    if (car->speed > MAX_SPEED_JEEP) {
      car->speed = MAX_SPEED_JEEP;
    }
  }

}

void set_acceleration_rate(Car car, double acceleration_rate){
if (acceleration_rate < MIN_ACCELERATION_RATE) {
    acceleration_rate = MIN_ACCELERATION_RATE;
  }
  else if (car->type == AIXAM) {
    if (acceleration_rate > MAX_ACCELERATION_RATE_AIXAM) {
      car->acceleration_rate = MAX_ACCELERATION_RATE_AIXAM;
    }
    else{
      car->acceleration_rate = acceleration_rate;
    }
  }
  else if (car->type == FIAT_MULTIPLA) {
    if (acceleration_rate > MAX_ACCELERATION_RATE_FIAT) {
      car->acceleration_rate = MAX_ACCELERATION_RATE_FIAT;
    }
    else{
      car->acceleration_rate = acceleration_rate;
    }
  }
  else if (car->type == JEEP) {
    if (acceleration_rate > MAX_ACCELERATION_RATE_JEEP) {
      car->acceleration_rate = MAX_ACCELERATION_RATE_JEEP;
    }
    else{
      car->acceleration_rate = acceleration_rate;
    }
  }

}
int round_speed(double speed)
{
  return speed + 0.5;
}
