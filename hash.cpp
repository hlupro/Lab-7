#include "hash.h"
size_t hash(size_t x)
{
  //will be used for 2^32
  size_t w = 32;
  //value below w but not too small
  size_t p = 13;
  //ten-digit prime
  size_t a = 5754853343;
  //
  size_t ax = a*x;
  //variable in order to avoid mismatch data types
  size_t one = 1;

  //another way to do ax mod 2^w using bitwise operators AKA binary mask
  size_t axModW = ax & ((one<<w) - one);
  //another way to divide by 2^(w-p) essentially cutting off the bits
  size_t hash = axModW >> (w-p);
  return hash;
}

//function for size_t
void toHex(size_t x)
{
  cout << x << "'s hash value in hex is ";
  //changes cout to display numbers in hex then reverts back to dec
  std::cout << "0x" << std::hex << hash(x) << std::dec << std::endl;
}

//function for string
void toHex(string str)
{
  cout << str << "'s hash value in hex is ";
  std::cout << "0x" << std::hex << hash(str) << std::dec << std::endl;
}

//First function that hashes a string by adding the individual characters
// together and then hasing that sum.
size_t hash(string str)
{
  size_t sum = 0;
  int size = str.length();
  for (int i = 0; i < size; i++)
  {
    sum += str[i];
  }
  return hash(sum);
}

//Similar to the first hash function but this one takes position into account
//by multiplying each char by i+1 before adding it to the sum.
size_t hash2(string str)
{
  size_t sum = 0;
  int size = str.length();
  for (int i = 0; i < size; i++)
  {
    sum += (str[i] * (i+1));
  }
  return hash(sum);
}
