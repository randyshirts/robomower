
#include "CircularBuffer.h"


//Initialize all member variables of the class
void CircularBuffer::init_buf(CircularBuffer *_this)
{
  //Clear buf, head, tail, and count
  _this->head = 0;
  _this->tail = 0;
  _this->count = 0;
  memset(_this->buf, 0, sizeof(_this->buf));

}

//Check the count member variable, return true if it is zero
int CircularBuffer::empty(CircularBuffer *_this)
{
  return (0 == _this->count); 
}

//Check the count member variable, return true if it is greater or equal to max
int CircularBuffer::full(CircularBuffer *_this)
{
  return(_this->count >= CIRCBUF_SIZE);
}

//Copy the message of msgSize bytes from (buf + tail) to msg
//Make sure we don' lose messages that split from the end of buf to the beginning
//Update the tail and count by adding msgSize to tail and subtracting it from count
void CircularBuffer::pull(CircularBuffer *_this, void* msg, int msgSize)
{
  int splitMsg;

  if(_this->count > 0)
  {
    //We don't want to throw away any messages
    //  See if the tail is near the end of the buffer
    if((CIRCBUF_SIZE - this->tail - msgSize) >= 0)
    {
        //Copy the message from (buf+tail) to msg
        memcpy(msg, (this->buf + this->tail), msgSize);
    }
    else
    {
      splitMsg = (CIRCBUF_SIZE - this->tail);   //# of bytes before end of buffer
      //Copy up to the end of the buffer
      memcpy(msg, (this->buf + this->tail), splitMsg);
      //Copy the rest of the message from the start of the buffer
      memcpy(((unsigned char*)msg + splitMsg), this->buf, (msgSize - splitMsg));
    }
    //Update the tail and count, modulo_inc does the wrapping of buf (255 to 0)
    _this->tail = modulo_inc(_this->tail, msgSize, CIRCBUF_SIZE);
    _this->count -= msgSize;
  }
}

//Place one byte on the buffer and update head and count
void CircularBuffer::push(CircularBuffer *_this, const unsigned char c)
{
  if(_this->count < CIRCBUF_SIZE)
  {
    _this->buf[_this->head] = c;
    _this->head = modulo_inc (_this->head, 1, CIRCBUF_SIZE);
    ++_this->count;  
  }
}

//Clear all member varables in the buffer, same as init
void CircularBuffer::flush_buf(CircularBuffer *_this, const int clearBuffer)
{
    _this->count = 0;
    _this->head = 0;
    _this->tail = 0;
    if(clearBuffer)
    {
      memset(_this->buf, 0, sizeof(_this->buf));  
    }
}

// Add incSize to index (head or tail) and wrap if needed (255 to 0)
int CircularBuffer::modulo_inc(int index, int incSize, const int mod)
{
  return ((index + incSize) % mod);
}


