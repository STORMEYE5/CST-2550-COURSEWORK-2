#ifndef _TRACK_H
#define _TRACK_H

#include <iostream>
#include <string>

class Track
{
private:
  std::string name;
  std::string artist;
  std::string duration;

public:
  /*
    setters
  */
  void setName(std::string name){    
    this->name = name;
  }
  void setArtist(std::string artist){
    this->artist = artist;
  }
  void setDuration(std::string duration){
    this->duration = duration;
  }

  /*
    Getters
  */
  std::string getName(){
    return name;
  }
  std::string getArtist(){
    return artist;
  }
  std::string getDuration(){
    return duration;
  }
};

#endif
