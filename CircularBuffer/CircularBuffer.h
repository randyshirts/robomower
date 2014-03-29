#ifndef CircularBuffer_h
#define CircularBuffer_h

#include "Arduino.h"

#define CIRCBUF_SIZE 256    //Modulus operations only work on powers of 2

class CircularBuffer
{
  public:
    unsigned char buf[CIRCBUF_SIZE];
    int head;
    int tail;
    int count;
    
    void init_buf(CircularBuffer *_this);
    int empty(CircularBuffer *_this);
    int full(CircularBuffer *_this);
    void pull(CircularBuffer *_this, void* msg, int getSize);
    void push(CircularBuffer *_this, const unsigned char c);
    void flush_buf(CircularBuffer *_this, const int clearBuffer);
  
  private:
    int modulo_inc(int index, int incSize, const int mod);
};


#endif
